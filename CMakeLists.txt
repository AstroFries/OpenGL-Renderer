cmake_minimum_required(VERSION 3.20)

project("Renderer"
    VERSION 1.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

find_package(OpenGL REQUIRED)
if (NOT OpenGL_FOUND)
    message(FATAL_ERROR "OpenGL not found")
endif()

include_directories(${OPENGL_INCLUDE_DIR})
link_directories(${OPENGL_LIBRARIES})
link_directories(${OPENGL_gl_LIBRARY})

add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)
#PUBLIC means, every target that linked glad will get the include_directories:[external/glad/include]
include_directories(${PROJECT_SOURCE_DIR}/external/glfw/include)

#In every executable, glad and glfw are both to linked.


add_subdirectory(src)
add_subdirectory(external/glfw)
