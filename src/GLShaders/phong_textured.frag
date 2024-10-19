#version 330 core

#define DIRECTIONAL_LIGHTS_COUNT 1
#define POINT_LIGHTS_COUNT 1
#define SPOT_LIGHT_COUNT 1

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    vec3 emission;
    float shininess;
};

struct DirectionalLight {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    vec3 direction;
};

struct PointLight {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    vec3 position;

    float constant;
    float linear;
    float quadratic;
};

struct SpotLight {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    vec3 position;

    float constant;
    float linear;
    float quadratic;

    float innerCutOff;
    float outerCutOff;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

uniform vec3 viewPos;
uniform Material material;
uniform DirectionalLight directionalLights[DIRECTIONAL_LIGHTS_COUNT];
uniform PointLight pointLights[POINT_LIGHTS_COUNT];
uniform SpotLight spotLights[SPOT_LIGHT_COUNT];

void main() {
    FragColor = vec4(1.0);
}