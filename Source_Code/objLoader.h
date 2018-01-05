#pragma once 
#include "Include\CBMini\CBMiniFW.h"
#include "BVH_FileLoader.h"
#include "texture.h"
#include "Include/SFML/Graphics.hpp"
#include "Include/SFML/OpenGL.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "MathClass.h"
#include <list>

//First, let’s create a data structure to hold our object's data
typedef struct objData
{
	Vec3f vertex;
	Vec3f normal;
	Vec3f uvCoord;
}DATA;

//Then, our simplest primitive: a triangle (stores the indinces of the data)
typedef struct objTriangles
{
	sf::Vector3i t_vertexIndex;
	sf::Vector3i t_uvIndex;
	sf::Vector3i t_normalIndex;
}TRIANGLE;

//Finally, our object
typedef struct objOject
{
	int maxTriangles;
	TRIANGLE *triangle;
	DATA *points; 
}OBJECT;

/////////////////////////////////////////////////////////////////////////////////

class objLoader
{
public:
	objLoader()
	{
		numTriangles = 0;
		vbo = new cbmini::cbfw::VertexBuffer;
	}
	~objLoader()
	{
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////

	void LoadOBJ(char *filename, int maxTriangles)
	{	
		objFile = fopen(filename, "r");
		//When the file cannot be opened (e.g., we don't have permission or it doesn't exist when opening for reading), fopen() will return NULL.
		if (objFile == NULL)
		{
			std::cout << "ERROR, could not open OBJ file" << std::endl;
			//fclose(objFile);
			return;
		}

		model.triangle = new TRIANGLE[maxTriangles + 5];	//plus 5 to prevent stack overflow
		model.points = new DATA[maxTriangles * 3]; 
		model.maxTriangles = maxTriangles;

		//dynamically intialize arrays, saves memory
		vertex = new float[(maxTriangles * 3) * 3]; 
		normals = new float[(maxTriangles * 3) * 3];
		texcoords = new float[(maxTriangles * 3) * 2];

		vertexIndex = 0;
		normalIndex = 0;
		uvIndex = 0;
		_textUV[2] = 0.0f;

		
		while(1)	//while true
		{
			int res = fscanf(objFile, "%s", line);
			//checks for end of file (EOF)
			if(res == EOF)
			{
				break;
			}

			//vertices
			else if(strcmp(line, "v") == 0)
			{
				fscanf(objFile, "%f %f %f\n", &XYZ[0], &XYZ[1], &XYZ[2]);
				model.points[vertexIndex].vertex = XYZ;
				vertexIndex++;
			}
			//texture coordinates
			else if(strcmp(line, "vt") == 0)
			{
				fscanf(objFile, "%f %f\n", &_textUV[0], &_textUV[1]);
				model.points[uvIndex].uvCoord = _textUV;
				uvIndex++;
			}

			//normals
			else if(strcmp(line, "vn") == 0)
			{
				fscanf(objFile, "%f %f %f\n", &_normal[0], &_normal[1], &_normal[2]);
				model.points[normalIndex].normal = _normal; 
				normalIndex++;
			}

			//faces
			else if(strcmp(line, "f") == 0)
			{
				int triangluated = fscanf(objFile, "%i/%i/%i %i/%i/%i %i/%i/%i\n", &f_vertexIndex.x, &f_uvIndex.x, &f_normalIndex.x, &f_vertexIndex.y, &f_uvIndex.y, &f_normalIndex.y, &f_vertexIndex.z, &f_uvIndex.z, &f_normalIndex.z);
				//checks to see if the model is triangulated
				if(triangluated%3 != 0)
				{
					cout << "ERROR, file is not triangulated" << endl;
					return;
				}

				model.triangle[numTriangles].t_vertexIndex = f_vertexIndex;
				model.triangle[numTriangles].t_uvIndex = f_uvIndex;
				model.triangle[numTriangles].t_normalIndex = f_normalIndex;

				numTriangles++;
			}
			
		}

		//sort into arrays to be rendered
		int i = 0;
		int k = 0;
		int t = 0;
		for(; t < numTriangles; t++, i+=9, k+=6)
		{
			f_vertexIndex = model.triangle[t].t_vertexIndex;
			f_uvIndex = model.triangle[t].t_uvIndex;
			f_normalIndex = model.triangle[t].t_normalIndex;

			//first vertex
			normals[i] = model.points[f_normalIndex.x-1].normal[0];	
			normals[i + 1] = model.points[f_normalIndex.x-1].normal[1];
			normals[i + 2] = model.points[f_normalIndex.x-1].normal[2];
				
			texcoords[k] = model.points[f_uvIndex.x-1].uvCoord[0];
			texcoords[k + 1] = model.points[f_uvIndex.x-1].uvCoord[1];

			vertex[i] = model.points[f_vertexIndex.x-1].vertex[0];
			vertex[i + 1] = model.points[f_vertexIndex.x-1].vertex[1];
			vertex[i + 2] = model.points[f_vertexIndex.x-1].vertex[2];
				
			//second vertex
			normals[i + 3] = model.points[f_normalIndex.y-1].normal[0];	
			normals[i + 4] = model.points[f_normalIndex.y-1].normal[1];
			normals[i + 5] = model.points[f_normalIndex.y-1].normal[2];
				
			texcoords[k + 2] = model.points[f_uvIndex.y-1].uvCoord[0];
			texcoords[k + 3] = model.points[f_uvIndex.y-1].uvCoord[1];

			vertex[i + 3] = model.points[f_vertexIndex.y-1].vertex[0];
			vertex[i + 4] = model.points[f_vertexIndex.y-1].vertex[1];
			vertex[i + 5] = model.points[f_vertexIndex.y-1].vertex[2];

			//third vertex
			normals[i + 6] = model.points[f_normalIndex.z-1].normal[0];	
			normals[i + 7] = model.points[f_normalIndex.z-1].normal[1];
			normals[i + 8] = model.points[f_normalIndex.z-1].normal[2];
				
			texcoords[k + 4] = model.points[f_uvIndex.z-1].uvCoord[0];
			texcoords[k + 5] = model.points[f_uvIndex.z-1].uvCoord[1];

			vertex[i + 6] = model.points[f_vertexIndex.z-1].vertex[0];
			vertex[i + 7] = model.points[f_vertexIndex.z-1].vertex[1];
			vertex[i + 8] = model.points[f_vertexIndex.z-1].vertex[2];
		}
		
		vbo->Initialize(numTriangles * 3, true, true, false, false);
		vbo->AddVertices(vertex);
		vbo->AddNormals(normals);
		vbo->AddTexcoords(texcoords);

		fclose(objFile);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	void LoadOBJWithJointWieghts(char *filename, int maxTriangles, Skeleton *modelSkel)
	{	
		theSkeleton = modelSkel;

		objFile = fopen(filename, "r");
		//When the file cannot be opened (e.g., we don't have permission or it doesn't exist when opening for reading), fopen() will return NULL.
		if (objFile == NULL)
		{
			std::cout << "ERROR, could not open OBJ file" << std::endl;
			fclose(objFile);
			return;
		}

		model.triangle = new TRIANGLE[maxTriangles + 5];	//plus 5 to prevent stack overflow
		model.points = new DATA[maxTriangles * 3]; 
		model.maxTriangles = maxTriangles;

		//dynamically intialize arrays, saves memory
		jointWeights = new float[(maxTriangles * 3) * 4];
		jointIndices = new float[(maxTriangles * 3) * 4];

		vertex = new float[(maxTriangles * 3) * 3]; 
		normals = new float[(maxTriangles * 3) * 3];
		texcoords = new float[(maxTriangles * 3) * 2];

		vertexIndex = 0;
		normalIndex = 0;
		uvIndex = 0;
		_textUV[2] = 0.0f;
		jointIndex = 0;

		
		while(1)	//while true
		{
			int res = fscanf(objFile, "%s", line);
			//checks for end of file (EOF)
			if(res == EOF)
			{
				break;
			}

			//vertices
			else if(strcmp(line, "v") == 0)
			{
				fscanf(objFile, "%f %f %f\n", &XYZ[0], &XYZ[1], &XYZ[2]);
				model.points[vertexIndex].vertex = XYZ;
				vertexIndex++;
			}
			//texture coordinates
			else if(strcmp(line, "vt") == 0)
			{
				fscanf(objFile, "%f %f\n", &_textUV[0], &_textUV[1]);
				model.points[uvIndex].uvCoord = _textUV;
				uvIndex++;
			}

			//normals
			else if(strcmp(line, "vn") == 0)
			{
				fscanf(objFile, "%f %f %f\n", &_normal[0], &_normal[1], &_normal[2]);
				model.points[normalIndex].normal = _normal; 
				normalIndex++;
			}

			//faces
			else if(strcmp(line, "f") == 0)
			{
				int triangluated = fscanf(objFile, "%i/%i/%i %i/%i/%i %i/%i/%i\n", &f_vertexIndex.x, &f_uvIndex.x, &f_normalIndex.x, &f_vertexIndex.y, &f_uvIndex.y, &f_normalIndex.y, &f_vertexIndex.z, &f_uvIndex.z, &f_normalIndex.z);
				//checks to see if the model is triangulated
				if(triangluated%3 != 0)
				{
					cout << "ERROR, file is not triangulated" << endl;
					return;
				}

				model.triangle[numTriangles].t_vertexIndex = f_vertexIndex;
				model.triangle[numTriangles].t_uvIndex = f_uvIndex;
				model.triangle[numTriangles].t_normalIndex = f_normalIndex;

				numTriangles++;
			}
			
		}

		//sort into arrays to be rendered
		sf::Vector2u imageSize, pixelCoord;
		float weight;
		int i = 0;
		int k = 0;
		int t = 0;
		for(; t < numTriangles; t++, i+=9, k+=6)
		{
			f_vertexIndex = model.triangle[t].t_vertexIndex;
			f_uvIndex = model.triangle[t].t_uvIndex;
			f_normalIndex = model.triangle[t].t_normalIndex;

		////////first vertex
			normals[i] = model.points[f_normalIndex.x-1].normal[0];	
			normals[i + 1] = model.points[f_normalIndex.x-1].normal[1];
			normals[i + 2] = model.points[f_normalIndex.x-1].normal[2];
				
			texcoords[k] = model.points[f_uvIndex.x-1].uvCoord[0];
			texcoords[k + 1] = model.points[f_uvIndex.x-1].uvCoord[1];

			vertex[i] = model.points[f_vertexIndex.x-1].vertex[0];
			vertex[i + 1] = model.points[f_vertexIndex.x-1].vertex[1];
			vertex[i + 2] = model.points[f_vertexIndex.x-1].vertex[2];

			//find joints weight for vertex from weight map
			//max 4 joint influences per vertex
			int jointCounter = 0;
			unsigned int j = 0;
			for(; j < theSkeleton->allJoints.size(); j++)
			{
				//we have found all of the joints that we need
				if(jointCounter >= 4)
				{
					break;
				}

				imageSize = theSkeleton->allJoints[j]->weightMap->texMap.getSize();
				pixelCoord.x = int(model.points[f_uvIndex.x-1].uvCoord[0] * (imageSize.x - 1));	//image pixels goes from 0 to size - 1
				pixelCoord.y = int(model.points[f_uvIndex.x-1].uvCoord[1] * (imageSize.y - 1));
				pixelCoord.y = (imageSize.y - 1) - pixelCoord.y;	//do this since y-axis goes in opposite way
				weight = (theSkeleton->allJoints[j]->weightMap->texMap.getPixel(pixelCoord.x, pixelCoord.y)).r / 255.0f; //divide by 255 to clamp value from 0 to 1

				if(weight > 0.0f)
				{
					jointWeights[jointIndex] = weight;
					jointIndices[jointIndex] = float(j); 
					//cout << jointWeights[jointIndex] << endl;
					jointIndex++;
					jointCounter++;
				}
			}

			//fill in the remaining data
			if(j >= theSkeleton->allJoints.size())
			{
				for(int fill = jointCounter; fill < 4; fill++)
				{
					jointWeights[jointIndex] = 0.001f;
					jointIndices[jointIndex] = 0.0f; 
					//cout << jointWeights[jointIndex] << endl;
					jointIndex++;
				}
			}

			////normalze weights results so when adding the values together results in one
			//float sum = jointWeights[jointIndex] + jointWeights[jointIndex - 1] + jointWeights[jointIndex - 2] + jointWeights[jointIndex - 3];
			//jointWeights[jointIndex] = jointWeights[jointIndex] / sum; 
			//jointWeights[jointIndex - 1] = jointWeights[jointIndex - 1] / sum; 
			//jointWeights[jointIndex - 2] = jointWeights[jointIndex - 2] / sum; 
			//jointWeights[jointIndex - 3] = jointWeights[jointIndex - 3] / sum; 
				
		/////////second vertex
			normals[i + 3] = model.points[f_normalIndex.y-1].normal[0];	
			normals[i + 4] = model.points[f_normalIndex.y-1].normal[1];
			normals[i + 5] = model.points[f_normalIndex.y-1].normal[2];
				
			texcoords[k + 2] = model.points[f_uvIndex.y-1].uvCoord[0];
			texcoords[k + 3] = model.points[f_uvIndex.y-1].uvCoord[1];

			vertex[i + 3] = model.points[f_vertexIndex.y-1].vertex[0];
			vertex[i + 4] = model.points[f_vertexIndex.y-1].vertex[1];
			vertex[i + 5] = model.points[f_vertexIndex.y-1].vertex[2];

			//find joints weight for vertex from weight map
			//max 4 joint influences per vertex
			jointCounter = 0;
			j = 0;
			for(; j < theSkeleton->allJoints.size(); j++)
			{
				//we have found all of the joints that we need
				if(jointCounter >= 4)
				{
					break;
				}

				imageSize = theSkeleton->allJoints[j]->weightMap->texMap.getSize();
				pixelCoord.x = int(model.points[f_uvIndex.y-1].uvCoord[0] * (imageSize.x - 1));
				pixelCoord.y = int(model.points[f_uvIndex.y-1].uvCoord[1] * (imageSize.y - 1)); //image pixels goes from 0 to size - 1
				pixelCoord.y = (imageSize.y - 1) - pixelCoord.y; //do this since y-axis goes in opposite way
				weight = (theSkeleton->allJoints[j]->weightMap->texMap.getPixel(pixelCoord.x, pixelCoord.y)).r / 255.0f; //divide by 255 to clamp value from 0 to 1

				if(weight > 0.0f)
				{
					jointWeights[jointIndex] = weight;
					jointIndices[jointIndex] = float(j); 
					//cout << jointWeights[jointIndex] << endl;
					jointIndex++;
					jointCounter++;
				}
			}

			//fill in the remaining data 
			if(j >= theSkeleton->allJoints.size())
			{
				for(int fill = jointCounter; fill < 4; fill++)
				{
					jointWeights[jointIndex] = 0.001f;
					jointIndices[jointIndex] = 0.0f; 
					//cout << jointWeights[jointIndex] << endl;
					jointIndex++;
				}
			}

			////normalze weights results so when adding the values together results in one
			//sum = jointWeights[jointIndex] + jointWeights[jointIndex - 1] + jointWeights[jointIndex - 2] + jointWeights[jointIndex - 3];
			//jointWeights[jointIndex] = jointWeights[jointIndex] / sum; 
			//jointWeights[jointIndex - 1] = jointWeights[jointIndex - 1] / sum; 
			//jointWeights[jointIndex - 2] = jointWeights[jointIndex - 2] / sum; 
			//jointWeights[jointIndex - 3] = jointWeights[jointIndex - 3] / sum; 

		////////third vertex
			normals[i + 6] = model.points[f_normalIndex.z-1].normal[0];	
			normals[i + 7] = model.points[f_normalIndex.z-1].normal[1];
			normals[i + 8] = model.points[f_normalIndex.z-1].normal[2];
				
			texcoords[k + 4] = model.points[f_uvIndex.z-1].uvCoord[0];
			texcoords[k + 5] = model.points[f_uvIndex.z-1].uvCoord[1];

			vertex[i + 6] = model.points[f_vertexIndex.z-1].vertex[0];
			vertex[i + 7] = model.points[f_vertexIndex.z-1].vertex[1];
			vertex[i + 8] = model.points[f_vertexIndex.z-1].vertex[2];

			//find joints weight for vertex from weight map
			//max 4 joint influences per vertex
			jointCounter = 0;
			j = 0;
			for(; j < theSkeleton->allJoints.size(); j++) 
			{
				//we have found all of the joints that we need
				if(jointCounter >= 4)
				{
					break;
				}

				imageSize = theSkeleton->allJoints[j]->weightMap->texMap.getSize();
				pixelCoord.x = int(model.points[f_uvIndex.z-1].uvCoord[0] * (imageSize.x - 1));
				pixelCoord.y = int(model.points[f_uvIndex.z-1].uvCoord[1] * (imageSize.y - 1)); //image pixels goes from 0 to size - 1
				pixelCoord.y = (imageSize.y - 1) - pixelCoord.y;  //do this since y-axis goes in opposite way
				weight = (theSkeleton->allJoints[j]->weightMap->texMap.getPixel(pixelCoord.x, pixelCoord.y)).r / 255.0f; //divide by 255 to clamp value from 0 to 1

				if(weight > 0.0f)
				{
					jointWeights[jointIndex] = weight;
					jointIndices[jointIndex] = float(j); 
					//cout << jointWeights[jointIndex] << endl;
					jointIndex++;
					jointCounter++;
				}
			}

			//fill in the remaining data
			if(j >= theSkeleton->allJoints.size())
			{
				for(int fill = jointCounter; fill < 4; fill++)
				{
					jointWeights[jointIndex] = 0.001f;
					jointIndices[jointIndex] = 0.0f; 
					//cout << jointWeights[jointIndex] << endl;
					jointIndex++;
				}
			}

			////normalze weights results so when adding the values together results in one
			//sum = jointWeights[jointIndex] + jointWeights[jointIndex - 1] + jointWeights[jointIndex - 2] + jointWeights[jointIndex - 3];
			//jointWeights[jointIndex] = jointWeights[jointIndex] / sum; 
			//jointWeights[jointIndex - 1] = jointWeights[jointIndex - 1] / sum; 
			//jointWeights[jointIndex - 2] = jointWeights[jointIndex - 2] / sum; 
			//jointWeights[jointIndex - 3] = jointWeights[jointIndex - 3] / sum; 
		}

		//load vertex weights from weight map

		
		vbo->Initialize(numTriangles * 3, true, true, true, false);
		vbo->AddVertices(vertex);
		vbo->AddNormals(normals);
		vbo->AddTexcoords(texcoords);
		vbo->AddJointData(jointWeights, jointIndices);

		fclose(objFile);
	}

		//////////////////////////////////////////////////////////////////////////////////////////////////

	void LoadOBJForMorphTargeting(char *filename, int maxTriangles)
	{	
		objFile = fopen(filename, "r");
		//When the file cannot be opened (e.g., we don't have permission or it doesn't exist when opening for reading), fopen() will return NULL.
		if (objFile == NULL)
		{
			std::cout << "ERROR, could not open OBJ file" << std::endl;
			//fclose(objFile);
			return;
		}

		model.triangle = new TRIANGLE[maxTriangles + 5];	//plus 5 to prevent stack overflow
		model.points = new DATA[maxTriangles * 3]; 
		model.maxTriangles = maxTriangles;

		//dynamically intialize arrays, saves memory
		vertex = new float[(maxTriangles * 3) * 3]; 
		normals = new float[(maxTriangles * 3) * 3];
		texcoords = new float[(maxTriangles * 3) * 2];

		vertexIndex = 0;
		normalIndex = 0;
		uvIndex = 0;
		_textUV[2] = 0.0f;

		
		while(1)	//while true
		{
			int res = fscanf(objFile, "%s", line);
			//checks for end of file (EOF)
			if(res == EOF)
			{
				break;
			}

			//vertices
			else if(strcmp(line, "v") == 0)
			{
				fscanf(objFile, "%f %f %f\n", &XYZ[0], &XYZ[1], &XYZ[2]);
				model.points[vertexIndex].vertex = XYZ;
				vertexIndex++;
			}
			//texture coordinates
			else if(strcmp(line, "vt") == 0)
			{
				fscanf(objFile, "%f %f\n", &_textUV[0], &_textUV[1]);
				model.points[uvIndex].uvCoord = _textUV;
				uvIndex++;
			}

			//normals
			else if(strcmp(line, "vn") == 0)
			{
				fscanf(objFile, "%f %f %f\n", &_normal[0], &_normal[1], &_normal[2]);
				model.points[normalIndex].normal = _normal; 
				normalIndex++;
			}

			//faces
			else if(strcmp(line, "f") == 0)
			{
				int triangluated = fscanf(objFile, "%i/%i/%i %i/%i/%i %i/%i/%i\n", &f_vertexIndex.x, &f_uvIndex.x, &f_normalIndex.x, &f_vertexIndex.y, &f_uvIndex.y, &f_normalIndex.y, &f_vertexIndex.z, &f_uvIndex.z, &f_normalIndex.z);
				//checks to see if the model is triangulated
				if(triangluated%3 != 0)
				{
					cout << "ERROR, file is not triangulated" << endl;
					return;
				}

				model.triangle[numTriangles].t_vertexIndex = f_vertexIndex;
				model.triangle[numTriangles].t_uvIndex = f_uvIndex;
				model.triangle[numTriangles].t_normalIndex = f_normalIndex;

				numTriangles++;
			}
			
		}

		//sort into arrays to be rendered
		int i = 0;
		int k = 0;
		int t = 0;
		for(; t < numTriangles; t++, i+=9, k+=6)
		{
			f_vertexIndex = model.triangle[t].t_vertexIndex;
			f_uvIndex = model.triangle[t].t_uvIndex;
			f_normalIndex = model.triangle[t].t_normalIndex;

			//first vertex
			normals[i] = model.points[f_normalIndex.x-1].normal[0];	
			normals[i + 1] = model.points[f_normalIndex.x-1].normal[1];
			normals[i + 2] = model.points[f_normalIndex.x-1].normal[2];
				
			texcoords[k] = model.points[f_uvIndex.x-1].uvCoord[0];
			texcoords[k + 1] = model.points[f_uvIndex.x-1].uvCoord[1];

			vertex[i] = model.points[f_vertexIndex.x-1].vertex[0];
			vertex[i + 1] = model.points[f_vertexIndex.x-1].vertex[1];
			vertex[i + 2] = model.points[f_vertexIndex.x-1].vertex[2];
				
			//second vertex
			normals[i + 3] = model.points[f_normalIndex.y-1].normal[0];	
			normals[i + 4] = model.points[f_normalIndex.y-1].normal[1];
			normals[i + 5] = model.points[f_normalIndex.y-1].normal[2];
				
			texcoords[k + 2] = model.points[f_uvIndex.y-1].uvCoord[0];
			texcoords[k + 3] = model.points[f_uvIndex.y-1].uvCoord[1];

			vertex[i + 3] = model.points[f_vertexIndex.y-1].vertex[0];
			vertex[i + 4] = model.points[f_vertexIndex.y-1].vertex[1];
			vertex[i + 5] = model.points[f_vertexIndex.y-1].vertex[2];

			//third vertex
			normals[i + 6] = model.points[f_normalIndex.z-1].normal[0];	
			normals[i + 7] = model.points[f_normalIndex.z-1].normal[1];
			normals[i + 8] = model.points[f_normalIndex.z-1].normal[2];
				
			texcoords[k + 4] = model.points[f_uvIndex.z-1].uvCoord[0];
			texcoords[k + 5] = model.points[f_uvIndex.z-1].uvCoord[1];

			vertex[i + 6] = model.points[f_vertexIndex.z-1].vertex[0];
			vertex[i + 7] = model.points[f_vertexIndex.z-1].vertex[1];
			vertex[i + 8] = model.points[f_vertexIndex.z-1].vertex[2];
		}
		
		vbo->Initialize(numTriangles * 3, true, true, false, true);
		vbo->AddVertices(vertex);
		vbo->AddNormals(normals);
		vbo->AddTexcoords(texcoords);

		fclose(objFile);
	}
	//////////////////////////////////////////////////////////////////////////////////////

	void drawModel()
	{
		vbo->ActivateAndRender();
		vbo->Deactivate();
	}

	void drawModelWithMeshSkinning(cbmini::cbfw::GLSLProgram *ShaderProgram)
	{
		// send in the joint outputs to the shader
		glUniformMatrix4fv(glGetUniformLocation(ShaderProgram->GetHandle(), "Joints"), theSkeleton->allJoints.size(), 1, (float*)theSkeleton->skiningOutputList);
	
		//theSkeleton->allJoints[0]->weightMap->drawTex(0);
		vbo->ActivateAndRender();	
		vbo->Deactivate();
	}

	cbmini::cbfw::VertexBuffer *vbo;

	//these arrays represent the final sorted data to be sent to the vbo
	float *vertex; //3 values per vertex
	float *normals;//3 values per vertex
	float *texcoords;//2 values per vertex

	float *jointWeights;	//4 values per vertex
	float *jointIndices;	//4 values per vertex

	int jointIndex;
	int vertexIndex;
	int numTriangles;
	int normalIndex;
	int uvIndex;

	Skeleton *theSkeleton; 

	//for loading data from file
	OBJECT model;
	FILE *objFile;
	Vec3f XYZ;
	Vec3f _normal;
	Vec3f _textUV;
	sf::Vector3i f_vertexIndex;	
	sf::Vector3i f_uvIndex;
	sf::Vector3i f_normalIndex;
	char line[255];
	char info;	//info that is needed to determine where the input will be stored. 
};

