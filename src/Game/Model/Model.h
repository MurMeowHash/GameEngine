#pragma once

#include "Mesh.h"
#include <assimp/scene.h>

class Model : public GameObject, public IRenderable {
private:
    static const std::string TEXTURES_DIRECTORY;
    std::string directory;
    std::vector<Mesh *> meshes;
    NODISCARD const aiScene *loadModel(const char *modelPath);
    void processNode(aiNode *node, const aiScene *scene, GameObject *parent);
public:
    explicit Model(const char *modelPath);
    void render() override;
};