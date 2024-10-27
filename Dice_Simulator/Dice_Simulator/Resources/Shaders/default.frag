#version 330 core
//Code is from:Compulsory-2-3DProg/OpenGLSession0/Resources/Shaders/default.frag
// Github Link: https://github.com/HansPluss/Compulsory-2-3DProg.git 
// Outputs colors in RGBA
out vec4 FragColor;

// Inputs the color from the Vertex Shader
in vec3 color;
in vec2 TexCoords; 

// Uniforms
uniform sampler2D ourTexture; 

struct Material {
    vec3 diffuse; 
};

void main() {
    Material mat; 
    mat.diffuse = vec3(texture(ourTexture, TexCoords));
    vec3 finalColor = mat.diffuse * color; 

    FragColor = vec4(finalColor, 1.0f);  // Use finalColor instead of texture color
}
