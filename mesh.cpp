#include "headers/mesh.h"
#include <GL/glew.h>
#include <vector>
#include <iostream>

// The mesh is responsible for sending vertex data in the proper format to the gpu to
// be stored and processed

// Constructor
Mesh::Mesh(Vertex* vertices, unsigned int numVertices) {
    drawCount = numVertices;

    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> textures;

    positions.reserve(numVertices);
    textures.reserve(numVertices);

    for (unsigned int i=0; i<numVertices; i++) {
        positions.push_back(*vertices[i].GetPos());
        textures.push_back(*vertices[i].GetTexture());
    }

    glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);


    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[TEXTURE_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(textures[0]), &textures[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);

    
}

// Deconstructor
Mesh::~Mesh() {
    glDeleteVertexArrays(1, &vertexArrayObject);
}

// Draw vertex arrays to the screen, i think
void Mesh::Draw() {
    glBindVertexArray(vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, drawCount);
    //glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}