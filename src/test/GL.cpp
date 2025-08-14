#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){//detect ESC
        glfwSetWindowShouldClose(window, true);
    }
}

int main(){
    std::cout << 1 << std::endl;
    glfwInit();
    //Init
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//major3:3.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//minor3:x.3, so here Use VERSION 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//core profile
    //glfwWindowHint to set profile of window

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);//??

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){//Load GLAD
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);//To draw
        processInput(window);//Detect ESC
        glfwPollEvents();    
    }
    return 0;
}