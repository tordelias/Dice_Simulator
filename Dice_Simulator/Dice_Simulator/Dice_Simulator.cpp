#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Resources/Camera/Camera.h"
#include "Resources/Shaders/shaderClass.h"
#include <memory>
#include <string>
#include "Resources/Window.h"

//includes
#include "Manager/EntityManager.h"
#include "Entity.h" 
#include "Component/Component.h"
#include "System/SpawnSystem.h"

void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

int main()
{
	// ---------------------------------------------------------------------------------------------------------------------------
	//                                                        Window
	// ---------------------------------------------------------------------------------------------------------------------------
	Window window;
	window.CreateWindow(SCR_WIDTH, SCR_HEIGHT, "Dice Simulator");

    // ---------------------------------------------------------------------------------------------------------------------------
    //                                                        Camera & Shader
    // ---------------------------------------------------------------------------------------------------------------------------
    std::shared_ptr<Shader> shaderProgram = std::make_shared<Shader>("Resources/Shaders/default.vert", "Resources/Shaders/default.frag");
    shaderProgram->Activate();
    std::shared_ptr<Camera> camera = std::make_shared<Camera>(SCR_WIDTH, SCR_HEIGHT, glm::vec3(0.0f, 2.0f, 0.0f));
    // ---------------------------------------------------------------------------------------------------------------------------
	//                                                        Initialize bellow
    // ---------------------------------------------------------------------------------------------------------------------------
	std::shared_ptr<EntityManager> manager = std::make_shared<EntityManager>(shaderProgram);
	std::shared_ptr<SpawnSystem> spawnSystem = std::make_shared<SpawnSystem>(manager);

    spawnSystem->SpawnEntity(0, 0, 0, "Resources/Texture/Textures/skybox.jpg", "Cube", 1000.0f);
    spawnSystem->SpawnEntity(0, 0, -10, "Resources/Texture/Textures/beako.png");
	spawnSystem->SpawnEntity(2, 0, -10, "Resources/Texture/Textures/beako.png");
	spawnSystem->SpawnEntity(-2, 0, -10, "");


    // ---------------------------------------------------------------------- -----------------------------------------------------
    //                                                        Textures
    // ---------------------------------------------------------------------------------------------------------------------------

    glEnable(GL_DEPTH_TEST);

    // ---------------------------------------------------------------------------------------------------------------------------
    //                                                        Main Loop
    // ---------------------------------------------------------------------------------------------------------------------------
    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        processInput(window.GetWindow());
        camera->Inputs(window.GetWindow());
        glm::mat4 viewproj = camera->Matrix(45.0f, 0.1f, 1000.0f, *shaderProgram, "camMatrix");        //Set render distance and FOV
    // ---------------------------------------------------------------------------------------------------------------------------
       
		spawnSystem->input(window.GetWindow());
		manager->Render(viewproj);




    // ---------------------------------------------------------------------------------------------------------------------------
        glfwSwapBuffers(window.GetWindow());
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
