#pragma once
#include "Include\GL\glew.h"
#include "Include\CBMini\CBMiniFW.h"
#include <iostream>


// initialize a GLSL program with vertex and fragment shader
// returns 0 if fail, 1 if success
static int CreateShaderProgram(cbmini::cbfw::GLSLProgram *program, const char *VertexShader, const char *FragmentShader)
{
	if (program)
	{
		//// the result will be multiplicative so that if anything fails it will be zero
		int result = 1;

		//// load some shaders
		//// ****
		cbmini::cbfw::GLSLShader testVertShader, testFragShader;
		result *= testVertShader.CreateFromFile(cbmini::cbfw::GLSL_VERTEX_SHADER, VertexShader);
		result *= testFragShader.CreateFromFile(cbmini::cbfw::GLSL_FRAGMENT_SHADER, FragmentShader);

		// attach them to the program
		result *= program->AttachShader(&testVertShader);
		result *= program->AttachShader(&testFragShader);

		// link and validate
		result *= program->LinkProgram();
		result *= program->ValidateProgram();

		// done
		return result;
	}
	return 0;
}

// initialize a GLSL program with vertex, fragment, and geometry shader
// returns 0 if fail, 1 if success
static int CreateShaderProgram(cbmini::cbfw::GLSLProgram *program, const char *VertexShader, const char *FragmentShader, const char *GeometryShader)
{
	if (program)
	{
		//// the result will be multiplicative so that if anything fails it will be zero
		int result = 1;

		//// load some shaders
		//// ****
		cbmini::cbfw::GLSLShader testVertShader, testFragShader, testGeomShader;
		result *= testVertShader.CreateFromFile(cbmini::cbfw::GLSL_VERTEX_SHADER, VertexShader);
		result *= testFragShader.CreateFromFile(cbmini::cbfw::GLSL_FRAGMENT_SHADER, FragmentShader);
		result *= testGeomShader.CreateFromFile(cbmini::cbfw::GLSL_GEOMETRY_SHADER, GeometryShader);

		// attach them to the program
		result *= program->AttachShader(&testVertShader);
		result *= program->AttachShader(&testFragShader);
		result *= program->AttachShader(&testGeomShader);

		// link and validate
		result *= program->LinkProgram();
		result *= program->ValidateProgram();

		// done
		return result;
	}
	return 0;
}


//loads all of our shaders in game
//lets us use all of our shader throughout our game easy
class Shader
{
public:
	Shader()
	{
		inGameMenuShader = new cbmini::cbfw::GLSLProgram;
		HealthShader = new cbmini::cbfw::GLSLProgram;
		ShaderProgram = new cbmini::cbfw::GLSLProgram;
		HDR_BP_Shader = new cbmini::cbfw::GLSLProgram;
		HDR_Box_Blur_Shader = new cbmini::cbfw::GLSLProgram;
		HDR_G_Blur_X_Shader = new cbmini::cbfw::GLSLProgram;
		HDR_G_Blur_Y_Shader = new cbmini::cbfw::GLSLProgram;
		HDR_Final_Shader = new cbmini::cbfw::GLSLProgram;
		NormalMap_Shader = new cbmini::cbfw::GLSLProgram;
		Particle_Shader = new cbmini::cbfw::GLSLProgram;
		rippleShader = new cbmini::cbfw::GLSLProgram;
		meshSkinningShader = new cbmini::cbfw::GLSLProgram;
		interiorShader = new cbmini::cbfw::GLSLProgram;
		mainMenuShader = new cbmini::cbfw::GLSLProgram;
	}
	~Shader()
	{
	}

	void LoadShaders(GLenum err)
	{
		//make sure GLEW initialized properly and load shaders
		if(GLEW_OK == err)
		{
			if(!CreateShaderProgram(rippleShader, "Shaders/portal/ripple/ripple_v.glsl",  "Shaders/portal/ripple/ripple_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}
			if(!CreateShaderProgram(ShaderProgram, "Shaders/passthru_v.glsl",  "Shaders/passthru_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}
			if(!CreateShaderProgram(inGameMenuShader, "Shaders/menupassthru_v.glsl",  "Shaders/menupassthru_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}
			if(!CreateShaderProgram(HealthShader, "Shaders/healthpassthru_v.glsl",  "Shaders/healthpassthru_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}
			if(!CreateShaderProgram(HDR_BP_Shader, "Shaders/HDR/HDR_BP_v.glsl",  "Shaders/HDR/HDR_BP_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}

			if(!CreateShaderProgram(HDR_Box_Blur_Shader, "Shaders/HDR/HDR_Box_Blur_v.glsl",  "Shaders/HDR/HDR_Box_Blur_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}

			if(!CreateShaderProgram(HDR_G_Blur_X_Shader, "Shaders/HDR/HDR_G_Blur_X_v.glsl",  "Shaders/HDR/HDR_G_Blur_X_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}

			if(!CreateShaderProgram(HDR_G_Blur_Y_Shader, "Shaders/HDR/HDR_G_Blur_Y_v.glsl",  "Shaders/HDR/HDR_G_Blur_Y_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}

			if(!CreateShaderProgram(HDR_Final_Shader, "Shaders/HDR/HDR_Final_v.glsl",  "Shaders/HDR/HDR_Final_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}

			if(!CreateShaderProgram(NormalMap_Shader, "Shaders/normalMap/normalMap_v.glsl",  "Shaders/normalMap/normalMap_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}

			if(!CreateShaderProgram(Particle_Shader, "Shaders/particles/passThruPt_v.glsl",  "Shaders/particles/applyTexture_f.glsl", "Shaders/particles/pt2quad_g.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}

			if(!CreateShaderProgram(meshSkinningShader, "Shaders/meshSkinning/skinning_v.glsl", "Shaders/passthru_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}

			if(!CreateShaderProgram(interiorShader, "Shaders/interior/interior_v.glsl", "Shaders/interior/interior_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}

			if(!CreateShaderProgram(mainMenuShader, "Shaders/mainMenu/menu_v.glsl", "Shaders/mainMenu/menu_f.glsl"))
			{
				std::cout << "ERROR, Could not load shader(s)" << std::endl;
			}
		}
		else
		{
			std::cout << "ERROR, Could not initialize GLEW" << std::endl;
		}
	}

	cbmini::cbfw::GLSLProgram *inGameMenuShader;
	cbmini::cbfw::GLSLProgram *HealthShader;
	cbmini::cbfw::GLSLProgram *ShaderProgram;
	cbmini::cbfw::GLSLProgram *HDR_BP_Shader;
	cbmini::cbfw::GLSLProgram *HDR_Final_Shader;
	cbmini::cbfw::GLSLProgram *HDR_Box_Blur_Shader;
	cbmini::cbfw::GLSLProgram *HDR_G_Blur_X_Shader;
	cbmini::cbfw::GLSLProgram *HDR_G_Blur_Y_Shader;
	cbmini::cbfw::GLSLProgram *NormalMap_Shader;
	cbmini::cbfw::GLSLProgram *Particle_Shader;
	cbmini::cbfw::GLSLProgram *rippleShader;
	cbmini::cbfw::GLSLProgram *meshSkinningShader;
	cbmini::cbfw::GLSLProgram *interiorShader;
	cbmini::cbfw::GLSLProgram *mainMenuShader;
};

