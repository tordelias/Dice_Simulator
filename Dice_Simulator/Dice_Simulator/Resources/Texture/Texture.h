#pragma once
#include "stb/stb_image.h"
#include "../Shaders/shaderClass.h"

//Code is from: tordelias/Compulsory-3/OpenGlsession0/Texture.h
//Github Link: https://github.com/tordelias/Compulsory-3.git

class Texture
{
	int ID; 
public:
	unsigned int texture;

	Texture(const char* texture1, Shader shaderProgram);

};

