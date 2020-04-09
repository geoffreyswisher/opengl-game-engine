// Fragment Shader
// Responsible for coloring the pixels of the triangle

#version 130

in vec3 pixelColor;
in vec2 texturePos;

uniform sampler2D inTexture;

void main() {
    gl_FragColor = texture(inTexture, texturePos);
    //gl_FragColor = vec4(pixelColor, 1.0);
}