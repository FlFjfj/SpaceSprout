find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(SOIL CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(GLEW REQUIRED)

include_directories(OpenGL glfw3 SOIL ${GLEW_SOURCE})
file(GLOB GameStateSources ./*.h ./*.cpp)
add_library(GlUtils ${GameStateSources})
