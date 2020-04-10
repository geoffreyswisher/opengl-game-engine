// Fragment Shader
// Responsible for coloring the pixels of the triangle

#version 130

varying vec2 texPos0;

uniform sampler2D inTexture;

void main() {
    gl_FragColor = texture(inTexture, texPos0);
}