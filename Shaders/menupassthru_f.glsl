#version 330 compatibility 

in vec2 texture_coordinate;
uniform sampler2D my_color_texture;

void main()
{
	gl_FragColor = texture2D(my_color_texture, texture_coordinate).rgba;
}