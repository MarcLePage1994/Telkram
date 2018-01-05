#version 330 compatibility 

uniform vec4 globalAmbient; //cameraPosition; //, lightColor, lightPosition;

//////////////////////////////////////
struct Light
{
	vec4 position;
	vec4 color;

	//for spot lights
	float spotCutoff;
	float spotExponent;
	vec3 spotDirection; //determines the axis of the cone of light (where the light is pointing
	float linearConstant;
	float quadraticConstant; 
};

const int MAX_LIGHTS = 8; 
uniform Light gameLights[MAX_LIGHTS]; 
///////////////////////////////////////////

in vec2 texture_coordinate;
uniform sampler2D my_color_texture;

uniform int numLights; 

in vec3 P;
in vec3 N;

in vec4 colorTest; 

in vec3 lightPos[MAX_LIGHTS];

layout (location=0) out vec4 fragColour0; //the color of the scene

void main()
{
	//set the color to the global ambient color
	vec4 color = globalAmbient;
	float shininess = 10.0;
	float att, dist;

	vec3 emissive = vec3(0.0, 0.0, 0.0);
	 
	//***PER PIXEL LIGHTS***
	//compute the emissive term
	int max_lights;
	if(numLights <= MAX_LIGHTS)
	{
		max_lights = numLights;
	}
	else
	{
		max_lights = MAX_LIGHTS;
	}

	for(int index = 0; index < max_lights; index++)
	{
		//bring the light's position into eye coordinates
		//vec3 lightPos = (gl_ModelViewMatrix * vec4(gameLights[index].position.xyz, 1.0f)).xyz;
		vec3 lightPos =  gameLights[index].position.xyz; 

		//compute the diffuse term
		vec3 L = normalize(lightPos - P); //inceident light ray
	
		float diffuseLight = max(dot(N,L),0);

		//vec3 diffuse = lightColor.xyz * diffuseLight; 
		vec3 diffuse = gameLights[index].color.xyz * diffuseLight; 

		//compute the specular term
		vec3 V = normalize(-P); //eye or viewer vector (we are in eye corrdinates, so eyePos is 0,0,0)
		vec3 H = normalize(L + V); //halfway vector
	
		float specularLight = pow(max(dot(N,H),0),shininess);

		vec3 specular = gameLights[index].color.xyz * specularLight;
	
		//compute the distance to the light source
		dist = length(lightPos - P);  

		//if the light is a directional light
		if(gameLights[index].position.w == 0.0)
		{
			att = 1.0;
			color.xyz += att * (emissive + diffuse + specular);
		}
		//if the light is a spotlight
		else if(gameLights[index].spotCutoff <= 90.0)
		{
			float spotEffect = dot(normalize(gameLights[index].spotDirection), normalize(-L));
			if (spotEffect > cos((3.141592654 / 180.0) * gameLights[index].spotCutoff)) //the cos function only takes radians
			{
				spotEffect = pow(spotEffect, gameLights[index].spotExponent);
				att = spotEffect / (0.5 + 0.0001 * dist + 0.0002 * dist * dist); 
        
				color.xyz += att * (emissive + diffuse  + specular);
			}
		}
		//else the light is a point light
		else
		{
			att = 1.0 / (0.5 + gameLights[index].linearConstant * dist + gameLights[index].quadraticConstant * dist * dist); //linearConstant = 0.0001f and quadraticConstant = 0.0002f

			color.xyz += att * (emissive + diffuse + specular); 
		}
	}

	fragColour0 = texture2D(my_color_texture, texture_coordinate).rgba * color;
}