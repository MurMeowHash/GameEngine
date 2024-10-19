#pragma once

#include "../GameObject.h"
#include "../IRenderable.h"
#include "Vertex.h"
#include "../Material/BasicMaterial.h"
#include "../Texture/Texture2D.h"
#include <vector>
#include <assimp/scene.h>

class Mesh : public GameObject, public IRenderable {
private:
    static constexpr GLuint POSITION_LOCATION{0};
    static constexpr GLuint NORMAL_LOCATION{1};
    static constexpr GLuint TEX_COORDS_LOCATION{2};
    static constexpr GLint POSITION_COMPONENTS_COUNT{3};
    static constexpr GLint NORMAL_COMPONENTS_COUNT{3};
    static constexpr GLint TEX_COORDS_COMPONENTS_COUNT{2};
    GLuint VBO;
    GLuint EBO;
    GLuint VAO;
    glm::mat3 normal;
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    BasicMaterial *material;
    void copyVertexData(aiMesh *mesh);
    void copyFacesData(aiMesh *mesh);
    void copyMaterialData(aiMaterial *mat, const std::string &texDirectory);
    static Texture2D *getTexture(aiMaterial *mat, aiTextureType type, const std::string &texDirectory);
    void setUpBuffers();
protected:
    void updateTransform() override;
public:
    Mesh(const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices, BasicMaterial *material = nullptr);
    Mesh(aiMesh *mesh, aiMaterial *mat, const std::string &texDirectory);
    void render() override;
};