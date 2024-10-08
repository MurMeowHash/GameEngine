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
        src/ManagersSystem/IGameManager.h
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
        src/ManagersSystem/GameManager.cpp
        src/ManagersSystem/GameManager.h
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
)

target_link_libraries(Drone_Game ${LIBS})