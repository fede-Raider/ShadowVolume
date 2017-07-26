#version 430
layout (location=0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;

out vec3 VPosition;

uniform mat4 ModelViewMatrix;

void main()
{ 
	VPosition = (ModelViewMatrix * vec4(VertexPosition,1.0)).xyz;
}