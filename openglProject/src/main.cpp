#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <memory>
#include <thread>
#include <chrono>
#include <stdlib.h>

#include "openGLSource/Renderer.h"
#include "openGLSource/VertexBuffer.h"
#include "openGLSource/IndexBuffer.h"
#include "openGLSource/VertexArray.h"
#include "openGLSource/Shader.h"
#include "openGLSource/VertexBufferLayout.h"

#include "OpenGLShapeRenderer.h"
#include "OpenGlDrawer.h"

#include "Screen.h"
#include "Circle.h"
#include "Rectangle.h"
#include "TerminalDrawer.h"


extern "C"      //USE NVIDIA DEDICATED GRAPHICS CARD
{
    __declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}

GLFWwindow* initOpenGL() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        exit(-1);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(-1);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        std::cerr << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    return window;
}


int main(void)
{
    auto window = initOpenGL();

    OpenGLShapeRenderer openGLShapeRenderer{};

    std::vector<std::unique_ptr<Shape>> shapeVector;

    shapeVector.push_back(std::make_unique<Circle>(0.4, 0.0, 0.0, std::make_unique<OpenGLDrawer>(&openGLShapeRenderer)));
    
    shapeVector.push_back(std::make_unique<Rectangle>(0.5, 0.5, 0.5, 0.5, std::make_unique<OpenGLDrawer>(&openGLShapeRenderer)));


    shapeVector.push_back(std::make_unique<Rectangle>(4, 4, 15, 15, std::make_unique<TerminalDrawer>()));

    int i = 0;

    auto start = std::chrono::high_resolution_clock::now();
    auto end = start;

    while (!glfwWindowShouldClose(window)) {

        i++;

        if (i % 60 == 0) {
            start = end;
            end = std::chrono::high_resolution_clock::now();
            std::cout << 1000*60.0 / std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
        }
        auto& circle = dynamic_cast<Circle&>(*(shapeVector[0]));
        circle.getX() = 0 + 0.5 * sin(i / 4.0);
        circle.getY() = 0 + 0.5 * cos(i / 4.0);

        for (auto& shape : shapeVector) {
            shape->draw();
        }

        Screen::get().print();
        openGLShapeRenderer.render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}