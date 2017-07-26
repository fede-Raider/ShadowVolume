#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 ModelViewMatrix;
uniform mat4 ProjMatrix;
uniform mat3 NormalMatrix;

out vec3 Position;
out vec3 Normal;

void main()
{
    Normal = normalize( NormalMatrix * vec3(0.0f, 1.0f, 0.0f));
	Position = vec3( ModelViewMatrix * vec4(aPos,1.0) );
    gl_Position = ProjMatrix * vec4(Position,1.0);
}