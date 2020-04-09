#include "headers/shader.h"
#include <fstream>
#include <iostream>


// Constructor
Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    program = glCreateProgram();  // intialization

    // creates shader with specified type of shader from filename
    shaders[0] = CreateShader(LoadShader(vertexShaderPath), GL_VERTEX_SHADER);
    shaders[1] = CreateShader(LoadShader(fragmentShaderPath), GL_FRAGMENT_SHADER);

    // attaches the created shaders to the shader program
    for (unsigned int i = 0; i < NUM_SHADERS; i ++) {
        glAttachShader(program, shaders[i]);
    }

    // for the shaders in the program: attribute position is the first attribute
    glBindAttribLocation(program, 0, "position");
    glBindAttribLocation(program, 1, "color");

    // compiles the program with shaders into one program
    glLinkProgram(program);
    CheckShaderError(program, GL_LINK_STATUS, true, "Program linking failed!  ");

    // validates that the program is working
    glValidateProgram(program);
    CheckShaderError(program, GL_VALIDATE_STATUS, true, "Program validation failed!  ");
}


// Deconstructor
Shader::~Shader() {
    for (unsigned int i = 0; i < NUM_SHADERS; i ++) {
        glDetachShader(program, shaders[i]);
        glDeleteShader(shaders[i]);
    }

    glDeleteProgram(program);
}

// Binds the screen to the given shader program, I think
void Shader::Bind() {
    glUseProgram(program);
    glUniform1i(glGetUniformLocation(program, "inTexture"), 0);
}


// Turns the text from LoadShader into compiled OpenGL format
GLuint Shader::CreateShader(const std::string& text, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);

    if (shader == 0) {
        std::cerr << "Shader creation failed!" << std::endl;
    }

    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];
    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLengths[0] = text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);

    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Shader compilation failed!  ");

    return shader;
}

// generic function to load shader from file and add the \n to each line
std::string Shader::LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else
    {
		std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}


// generic error checking function
void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}