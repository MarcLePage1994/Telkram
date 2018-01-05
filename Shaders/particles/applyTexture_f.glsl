
#version 330 compatibility 

in vertex	//comes directly from geometry shader
{
	vec2 texcoord;
}data;

uniform sampler2D diffuseMap;
uniform float alpha;

void main()
{
	vec4 diffuse = texture(diffuseMap, data.texcoord) * vec4(1.0, 1.0, 1.0, alpha);
	gl_FragColor = diffuse;
}