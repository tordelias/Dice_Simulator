#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Resources/Camera/Camera.h"
#include "Core/Shaders/shaderClass.h"
#include <memory>
#include <string>

//includes
#include "Manager/EntityManager.h"
#include "Entity.h" 
#include "Texture/Texture.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);  // Dynamic window size
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Dice Simulator", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    // ---------------------------------------------------------------------------------------------------------------------------
    //                                                        Camera & Shader
    // ---------------------------------------------------------------------------------------------------------------------------
    std::shared_ptr<Shader> shaderProgram = std::make_shared<Shader>("Resources/Shaders/default.vert", "Resources/Shaders/default.frag");
    shaderProgram->Activate();
    std::shared_ptr<Camera> camera = std::make_shared<Camera>(SCR_WIDTH, SCR_HEIGHT, glm::vec3(0.0f, 2.0f, 0.0f));
    // ---------------------------------------------------------------------------------------------------------------------------
	//                                                        Initialize bellow
    // ---------------------------------------------------------------------------------------------------------------------------
	std::shared_ptr<EntityManager> manager = std::make_shared<EntityManager>();

	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entity->AddComponent<TransformComponent>(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f));
	entity->AddComponent<MeshComponent>("Cube", glm::vec3(1.0f, 1.0f, 1.0f), "Texture/Textures/beako.png");
	manager->AddEntity(*entity);


    // ---------------------------------------------------------------------------------------------------------------------------
    //                                                        Textures
    // ---------------------------------------------------------------------------------------------------------------------------
	Texture texture("Texture/Textures/beako.png", shaderProgram);

    glEnable(GL_DEPTH_TEST);

    // ---------------------------------------------------------------------------------------------------------------------------
    //                                                        Main Loop
    // ---------------------------------------------------------------------------------------------------------------------------
    while (!glfwWindowShouldClose(window))
    {
        class Texture
        {
									int ID; 
        public:
									unsigned int texture;

									Texture(const char* texture1, Shader& shaderProgram);

        };
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        processInput(window);
        camera->Inputs(window);
        glm::mat4 viewproj = camera->Matrix(45.0f, 0.1f, 1000.0f, *shaderProgram, "camMatrix");        //Set render distance and FOV
    // ---------------------------------------------------------------------------------------------------------------------------
        glBindTexture(GL_TEXTURE_2D, texture.texture);
		manager->Render(shaderProgram, viewproj);




    // ---------------------------------------------------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
