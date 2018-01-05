#version 330 compatibility 

out vec2 texture_coordinate;

out vec3 P;
out vec3 N;

layout(location=0) in vec4 position;
layout(location=2) in vec3 normal; 
layout(location=8) in vec2 texcoord;

void main()
{
	//set the position of the current vertex
	P = (gl_ModelViewMatrix * position).xyz;
	gl_Position = gl_ModelViewProjectionMatrix * position;

	//transform the normal into eye space and normalize the result
	N =  normalize(gl_NormalMatrix * normal); 

	//texture_coordinate = vec2(gl_MultiTexCoord0); 
	texture_coordinate = texcoord; 
}