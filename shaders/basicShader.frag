// Fragment Shader
// Responsible for coloring the pixels of the triangle

#version 130

varying vec2 texPos0;
varying vec3 mixColor;

uniform sampler2D inTexture;

void main() {
    //gl_FragColor = texture(inTexture, texPos0);
    gl_FragColor = mix(texture(inTexture, texPos0), vec4(mixColor, 1.0), 0.3);
}