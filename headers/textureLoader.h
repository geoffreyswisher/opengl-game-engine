#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <string>

class TextureLoader {
    public:
        TextureLoader(const std::string& texturePath);
        
        virtual ~TextureLoader();

    protected:
    private:
        unsigned char* data;
};

#endif