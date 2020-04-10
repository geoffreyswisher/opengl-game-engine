// Vertex Shader
// Draws the vertices of the triangle

#version 130

attribute vec3 position;
attribute vec2 texture;
attribute vec3 color;

varying vec2 texPos0;
varying vec3 mixColor;

void main() {
    gl_Position = vec4(position, 1.0);
    texPos0 = texture;
    mixColor = color;
}