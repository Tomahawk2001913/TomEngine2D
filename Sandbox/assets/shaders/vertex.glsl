#version 330 core

layout(location = 0) in vec2 coordinates;

out vec2 textureCoords;

uniform mat4 projectionMatrix = mat4(1.0);
uniform mat4 modelMatrix = mat4(1.0);

void main() {
	gl_Position = projectionMatrix * modelMatrix * vec4(coordinates, 1.0, 1.0);
	textureCoords = vec2(coordinates);
}