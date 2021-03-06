#version 330 core

in vec2 textureCoords;

out vec4 color;

uniform sampler2D theTexture;

void main() {
	color = texture(theTexture, textureCoords) * vec4(1.0, 1.0, 1.0, 1.0);
}