#include "Mesh.h"
#include "../../ManagersSystem/Managers.h"
#include "../../Debug/Debug.h"
#include "../Material/TextureMaterial.h"

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices, BasicMaterial *material)
: vertices{vertices}, indices{indices}, material{material} {
    if(material == nullptr) {
        this->material = Managers::getResourceManager()->getDefaultMaterial();
    }
    setUpBuffers();
}

Mesh::Mesh(aiMesh *mesh, aiMaterial *mat, const std::string &texDirectory) {
    if(mesh == nullptr) {
        Debug::logError("MESH", "IMPORT_MESH_CAN_NOT_BE_NULL");
        return;
    }
    copyVertexData(mesh);
    copyFacesData(mesh);
    if(mat == nullptr) {
        material = Managers::getResourceManager()->getDefaultMaterial();
    } else {
        copyMaterialData(mat, texDirectory);
    }
    setUpBuffers();
}

void Mesh::copyVertexData(aiMesh *mesh) {
    for(GLuint i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;
        vertex.setPosition(mesh->mVertices[i]);
        if(mesh->HasNormals()) {
            vertex.setNormal(mesh->mNormals[i]);
        } else {
            Debug::logError("MESH", "DOES_NOT_HAVE_NORMALS", mesh->mName.C_Str());
        }
        if(mesh->mTextureCoords[0]) {
            vertex.setTexCoords(mesh->mTextureCoords[0][i]);
        } else {
            Debug::logError("MESH", "DOES_NOT_HAVE_TEXTURE_COORDINATES", mesh->mName.C_Str());
        }
        vertices.push_back(vertex);
    }
}

void Mesh::copyFacesData(aiMesh *mesh) {
    for(GLuint i = 0; i < mesh->mNumFaces; i++) {
        const aiFace &face = mesh->mFaces[i];
        for(GLuint j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }
}

void Mesh::copyMaterialData(aiMaterial *mat, const std::string &texDirectory) {
    Texture2D *diffuseMap = getTexture(mat, aiTextureType::aiTextureType_DIFFUSE, texDirectory);
    Texture2D *specularMap = getTexture(mat, aiTextureType::aiTextureType_SPECULAR, texDirectory);
    GLfloat shininess;
    if(mat->Get(AI_MATKEY_SHININESS, shininess) == AI_SUCCESS) {
        shininess = ShinyMaterial::shininessToNormalized(shininess);
        material = new TextureMaterial{diffuseMap, specularMap, shininess};
    } else {
        material = new TextureMaterial{diffuseMap, specularMap};
    }
}

Texture2D *Mesh::getTexture(aiMaterial *mat, aiTextureType type, const std::string &texDirectory) {
    GLuint texCount = mat->GetTextureCount(type);
    if(texCount == 0) {
        Debug::logError("MODEL", "DOES_NOT_HAVE_TEXTURES");
        return nullptr;
    }
    aiString texName;
    mat->GetTexture(type, 0, &texName);
    std::string texPath = texDirectory + texName.C_Str();
    return new Texture2D{texPath.c_str()};
}

void Mesh::setUpBuffers() {
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)),
                 vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(indices.size() * sizeof(GLuint)),
                 indices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(POSITION_LOCATION, POSITION_COMPONENTS_COUNT, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void*)0);
    glVertexAttribPointer(NORMAL_LOCATION, NORMAL_COMPONENTS_COUNT, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glVertexAttribPointer(TEX_COORDS_LOCATION, TEX_COORDS_COMPONENTS_COUNT, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::updateTransform() {
    GameObject::updateTransform();
    normal = glm::transpose(glm::inverse(rotationOperand));
}

void Mesh::render() {
    Shader *shader = material->getShader();
    Scene *activeScene = Managers::getSceneManager()->getActiveScene();
    Camera *activeCamera = activeScene->getActiveCamera();
    shader->use();
    shader->setMat4("model", getModelTransform());
    shader->setMat3("normal", normal);
    shader->setMat4("view", activeCamera->getViewTransform());
    shader->setMat4("projection", activeCamera->getProjectionTransform());
    shader->setVec3("viewPos", activeCamera->getGlobalPos());
    material->apply();
    activeScene->applyLight(shader);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, nullptr);
}