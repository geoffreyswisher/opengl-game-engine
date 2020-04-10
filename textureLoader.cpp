#include "headers/textureLoader.h"
#include <GL/glew.h>
#include <string>
#include <iostream>
#include <cassert>

#define STB_IMAGE_IMPLEMENTATION
#include "dependencies/stb_image.h"


TextureLoader::TextureLoader(const std::string& texturePath) {

    // Load the data from the image into a texture
    int width, height, nrChannels;
    data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);

    // Check for loading error
    if (!data) {
        std::cerr << "Error loading texture" << std::endl;
    }

    // Generate the texture and reference with ID
    glGenTextures(1, &textureID);

    // Specify the type of texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Specify the parameters for the texture
    // Repeat the image on x and y
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Returns the average of the four elements closest to the center of the pixel being textured
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Generates the textured image
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