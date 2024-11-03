#include "Window.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Camera/Camera.h"

void Window::CreateWindow(int width, int height, const char* title)
{
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glViewport(0, 0, width, height);
}

void Window::ResizeWindow(int width, int height, std::shared_ptr<Camera> camera)
{
	if (!window)
	{
		std::cerr << "Window not created" << std::endl;
		return;
	}
	std::cout << "Resizing window to " << width << "x" << height << std::endl;
	camera->UpdateWindow(width, height);
	glfwSetWindowSize(window, width, height);
	glViewport(0, 0, width, height);
}

glm::vec2 Window::GetWindowSize()
{
	if (window)
	{
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		std::cout << "Window size is " << width << "x" << height << std::endl;
		return glm::vec2(width, height);
	}
	std::cerr << "Window not created" << std::endl;
    return glm::vec2();
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
