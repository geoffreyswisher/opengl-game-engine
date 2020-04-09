// Vertex Shader
// Draws the vertices of the triangle

#version 330 core

attribute vec3 position;
attribute vec3 color;
out vec3 pixelColor;

void main() {
    gl_Position = vec4(position, 1.0);
    pixelColor = color;
}