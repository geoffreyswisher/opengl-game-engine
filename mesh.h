#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

class Vertex {
    public:
        Vertex(const glm::vec3& pos) {
            this->pos = pos;
        }

    protected:
    private:
        glm::vec3 pos;
};


class Mesh {
    public:
        Mesh(Vertex* vertices, unsigned int numVertices);

        void Draw();

        virtual ~Mesh();

    protected:
    private:
        enum {
            POSITION_VB,

            NUM_BUFFERS
        };

        GLuint vertexArrayObject;
        GLuint vertexArrayBuffers[NUM_BUFFERS];
        unsigned int drawCount;

};


#endif