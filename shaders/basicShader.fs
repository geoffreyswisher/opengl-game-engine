// Fragment Shader
// Responsible for coloring the pixels of the triangle

#version 330 core

in vec3 pixelColor;

void main() {
    gl_FragColor = vec4(pixelColor, 1.0);
}