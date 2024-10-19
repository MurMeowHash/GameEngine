#include "Model.h"
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include "../../Debug/Debug.h"

const std::string Model::TEXTURES_DIRECTORY{"/Textures/"};

Model::Model(const char *modelPath) {
    const aiScene *scene = loadModel(modelPath);
    if(scene == nullptr) {
        Debug::logError("MODEL", "FAILED_TO_LOAD", modelPath);
        return;
    }
    processNode(scene->mRootNode, scene, this);
}

const aiScene *Model::loadModel(const char *modelPath) {
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(modelPath, aiProcess_Triangulate | aiProcess_FlipUVs);
    if(!scene) {
        return nullptr;
    }
    if(scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE
    || !scene->mRootNode) {
        return nullptr;
    }
    std::string path;
    directory = path.substr(0, path.find_last_of('/')) + TEXTURES_DIRECTORY;
    return scene;
}

void Model::processNode(aiNode *node, const aiScene *scene, GameObject *parent) {
    for(GLuint i = 0; i < node->mNumMeshes; i++) {
        aiMesh *rawMesh = scene->mMeshes[node->mMeshes[i]];
        auto convertedMesh = new Mesh{rawMesh, scene->mMaterials[rawMesh->mMaterialIndex], directory};
        meshes.emplace_back(convertedMesh);
        parent->addChild(convertedMesh);
    }

    if(node->mNumChildren > 0) {
        auto currentNode = new GameObject;
        parent->addChild(currentNode);
        for(GLuint i = 0; i < node->mNumChildren; i++) {
            processNode(node->mChildren[i], scene, currentNode);
        }
    }
}

void Model::render() {
    for(Mesh *mesh : meshes) {
        mesh->render();
    }
}