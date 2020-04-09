#include "mesh.h"
#include <GL/glew.h>

// The mesh is responsible for sending vertex data in the proper format to the gpu to
// be stored and processed

// Constructor
Mesh::Mesh(Vertex* vertices, unsigned int numVertices) {
    drawCount = numVertices;

    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[NUM_BUFFERS]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

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

    glBindVertexArray(0);
}