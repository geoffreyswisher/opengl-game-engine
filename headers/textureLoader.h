#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <string>
#include <GL/glew.h>

class TextureLoader {
    public:
        TextureLoader(const std::string& texturePath);
        
        void Bind(unsigned int unit);

        virtual ~TextureLoader();

    protected:
    private:
        GLuint textureID;
        unsigned char* data;
};

#endif