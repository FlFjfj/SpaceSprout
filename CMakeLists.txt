cmake_minimum_required(VERSION 3.6)
project(GlutGl)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(SOIL CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES player/Player.cpp player/Player.h player/PlayerController.h
        main.cpp GameState/MainGame.h GameState/MainGame.cpp GlUtils/Shader.cpp GlUtils/Shader.h GlUtils/Mesh.cpp
        GlUtils/Mesh.h GlUtils/Camera.cpp GlUtils/Camera.h GlUtils/Texture.cpp GlUtils/Texture.h
        GlUtils/Engine.cpp GlUtils/Engine.h GlUtils/OrthographicCamera.cpp GlUtils/OrthographicCamera.h
        GlUtils/SpriteBatch.cpp GlUtils/SpriteBatch.h GlUtils/MeshLoader.cpp GlUtils/MeshLoader.h
        World.cpp World.h player/PlayerController.cpp environment/Terrain.cpp environment/Terrain.h GameState/MainMenu.cpp GameState/MainMenu.h GameState/ProgramBase.cpp GameState/ProgramBase.h GlUtils/BitmapFont.cpp GlUtils/BitmapFont.h GameState/GameOver.cpp GameState/GameOver.h environment/Lizard.cpp environment/Lizard.h environment/GameObject.cpp environment/GameObject.h environment/Tail.cpp environment/Tail.h)

add_executable(SpaceSprout ${SOURCE_FILES})
target_link_libraries(SpaceSprout ${OPENGL_gl_LIBRARY} glfw SOIL glm GLEW::GLEW)

