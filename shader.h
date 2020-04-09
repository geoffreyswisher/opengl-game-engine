#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader {
    public:
        Shader(const std::string& filename);

        void Bind();

        std::string LoadShader(const std::string& fileName);
        void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

        GLuint CreateShader(const std::string& text, GLenum shaderType);

        virtual ~Shader();

    protected:
    private:
        static const unsigned int NUM_SHADERS = 2;
        GLuint program;
        GLuint shaders[NUM_SHADERS];

};



#endif