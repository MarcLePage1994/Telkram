#version 330 compatibility

out vec2 texture_coordinate;

layout(location=0) in vec4 position;
layout(location=8) in vec2 texcoord;

void main()
{
	//set the position of the current vertex
	gl_Position = gl_ModelViewProjectionMatrix * position;

	texture_coordinate = texcoord; 
}