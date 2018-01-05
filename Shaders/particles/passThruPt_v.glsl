
#version 330 compatibility 

layout (location=0) in vec4 position;

//uniform mat4 modelview;
//uniform mat4 projection;

void main()
{
	gl_Position = /*projection*modelview*/ position;
}