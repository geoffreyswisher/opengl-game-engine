#include "headers/textureLoader.h"
#include <GL/glew.h>
#include <string>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "dependencies/stb_image.h"
#include <cassert>


TextureLoader::TextureLoader(const std::string& texturePath) {
    int width, height, nrChannels;
    data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);

    if (!data) {
        std::cerr << "Error loading texture" << std::endl;
    }

    
    glGenTextures(1, &textureID);

    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(textureID);
}

TextureLoader::~TextureLoader() {
    stbi_image_free(data);
}

void TextureLoader::Bind(unsigned int unit) {

    assert(unit >= 0 && unit <= 31);

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, textureID);
}