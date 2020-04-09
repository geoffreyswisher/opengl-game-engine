// Vertex Shader
// Draws the vertices of the triangle

#version 130

attribute vec3 position;
attribute vec3 color;
attribute vec2 texture;
out vec3 pixelColor;
out vec2 texturePos;

void main() {
    gl_Position = vec4(position, 1.5);
    pixelColor = color;
    texturePos = texture;
}