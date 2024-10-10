#include "TextureMaterial.h"
#include "../../ManagersSystem/Managers.h"

TextureMaterial::TextureMaterial(Texture2D *diffuse, Texture2D *specular, GLfloat shininess,
                                 const glm::vec3 &emission)
                                 : ShinyMaterial(ShaderType::TextureShader, "TEXTURE_SHADER",
                                                 shininess, emission) {
    //TODO: assign texture units
    setDiffuse(diffuse);
    setSpecular(specular);
}

void TextureMaterial::setDiffuse(Texture2D *diffuseMap) {
    setMap(diffuseMap, diffuse);
}

void TextureMaterial::setSpecular(Texture2D *specularMap) {
    setMap(specularMap, specular);
}

void TextureMaterial::setMap(Texture2D *src, Texture2D *&dest) {
    if(src == nullptr) {
        dest = Managers::getResourceManager()->getDefaultTexture();
    } else {
        dest = src;
    }
}

bool TextureMaterial::apply() {
    if(ShinyMaterial::apply()) {
        glActiveTexture(GL_TEXTURE0);
        diffuse->bind();
        glActiveTexture(GL_TEXTURE1);
        specular->bind();
        return true;
    }
    return false;
}
