#version 330 compatibility

out vec2 texture_coordinate;

layout(location=0) in vec4 position;

void main()
{
	//set the position of the current vertex
	gl_Position = gl_ModelViewProjectionMatrix * position;

	texture_coordinate = vec2(gl_MultiTexCoord0); 
}