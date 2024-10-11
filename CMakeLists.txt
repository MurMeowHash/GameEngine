cmake_minimum_required(VERSION 3.29)
project(Drone_Game)

set(CMAKE_CXX_STANDARD 17)
set(INCLUDES_DIR ./dependency/includes)
set(SOURCE_DIR ./dependency/lib)

add_library(GLAD ${INCLUDES_DIR}/glad/glad.c)
add_library(STB_IMAGE ${INCLUDES_DIR}/stb/stb_image.cpp)
set(LIBS glfw3 assimp GLAD STB_IMAGE)

include_directories(${INCLUDES_DIR})
link_directories(${SOURCE_DIR})

add_executable(Drone_Game
        src/main.cpp
        src/ManagersSystem/ResourceManager.h
        src/ManagersSystem/ResourceManager.cpp
        src/ManagersSystem/ShaderManager.h
        src/ManagersSystem/ShaderManager.cpp
        src/ManagersSystem/Managers.h
        src/ManagersSystem/Managers.cpp
        src/Debug/Debug.h
        src/Debug/Debug.cpp
        src/Error/Error.h
        src/Error/Error.cpp
        src/Game/Game.cpp
        src/Game/Game.h
        src/utils/utils.cpp
        src/utils/utils.h
        src/Game/IUpdatable.h
        src/Game/Time.cpp
        src/Game/Time.h
        src/Shader/Shader.cpp
        src/Shader/Shader.h
        src/Shader/ShaderType.h
        src/Dispose/IDisposable.h
        src/Game/Input/Input.cpp
        src/Game/Input/Input.h
        src/Game/Input/InputKey.h
        src/Game/Input/KeyState.h
        src/Game/GameObject.cpp
        src/Game/GameObject.h
        src/Game/Camera/Camera.cpp
        src/Game/Camera/Camera.h
        src/Game/Screen/Screen.cpp
        src/Game/Screen/Screen.h
        src/Game/Scene/Scene.cpp
        src/Game/Scene/Scene.h
        src/Game/Texture/Texture2D.cpp
        src/Game/Texture/Texture2D.h
        src/Game/Texture/TextureFiltration.h
        src/Game/Texture/TextureWrap.h
        src/ManagersSystem/ManagerState.h
        src/ManagersSystem/AbstractManager.cpp
        src/ManagersSystem/AbstractManager.h
        src/Application/Application.cpp
        src/Application/Application.h
        src/Game/Material/ShinyMaterial.cpp
        src/Game/Material/ShinyMaterial.h
        src/Game/Material/BasicMaterial.cpp
        src/Game/Material/BasicMaterial.h
        src/Game/Material/ColorMaterial.cpp
        src/Game/Material/ColorMaterial.h
        src/Game/Material/TextureMaterial.cpp
        src/Game/Material/TextureMaterial.h
        src/Game/Light/Light.cpp
        src/Game/Light/Light.h
        src/Game/Light/DirectionalLight.cpp
        src/Game/Light/DirectionalLight.h
        src/Game/Light/PointLight.cpp
        src/Game/Light/PointLight.h
        src/Game/Light/SpotLight.cpp
        src/Game/Light/SpotLight.h
        src/Game/Material/LightMaterial.cpp
        src/Game/Material/LightMaterial.h
)

target_link_libraries(Drone_Game ${LIBS})