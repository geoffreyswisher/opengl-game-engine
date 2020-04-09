#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

class Vertex {
    public:
        Vertex(const glm::vec3& pos, const glm::vec3& color, const glm::vec2& texture) {
            this->pos = pos;
            this->color = color;
            this->texture = texture;
        }

    protected:
    private:
        glm::vec3 pos;
        glm::vec3 color;
        glm::vec2 texture;
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