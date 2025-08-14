add_executable(GL_TEST test/GL.cpp)
target_include_directories(GL_TEST PUBLIC OpenGL::GL)
target_link_libraries(GL_TEST PUBLIC OpenGL::GL glfw glad)