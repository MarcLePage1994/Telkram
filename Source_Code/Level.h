#pragma once
#include "Include\CBMini\CBMiniFW.h"
#include "ShaderInit.h"
#include "Include\GL\glew.h"
#include "texture.h"
#include <iostream>
#include <list>
#include "objLoader.h"
#include "AStarPathFinding.h"
#include "player.h"
#include "Collision.h"
#include "RegularNPC.h"
#include "MissionBuilder.h"
#include "drawPrimitives.h"
#include "camera1.h"
#include "UIClass.h"
#include "GameSound.h"
#include "MorphTargeting.h"


//Light data
class Light
{
public:
	Light()
	{
		drawPoint = false;
		spotLight = false;

		spotCutoff = 180.0f;
	}
	Light(Vec4f lightColor, Vec4f lightPosition, bool DrawPoint, bool SpotLight)
	{																			 
		LightColor[0] = lightColor[0];
		LightColor[1] =	lightColor[1];
		LightColor[2] =	lightColor[2];
		LightColor[3] =	lightColor[3];

		LightPosition[0] = lightPosition[0];
		LightPosition[1] = lightPosition[1];
		LightPosition[2] = lightPosition[2];
		LightPosition[3] = lightPosition[3];

		drawPoint = DrawPoint;
		spotLight = SpotLight; 

		spotCutoff = 180.0f; 

		linearConstant = 0.0001f;
		quadraticConstant = 0.0002f; 
	}
	Light(Vec4f lightColor, Vec4f lightPosition, bool DrawPoint, bool SpotLight, float linearAtt, float quadraticAtt)
	{																			 
		LightColor[0] = lightColor[0];
		LightColor[1] =	lightColor[1];
		LightColor[2] =	lightColor[2];
		LightColor[3] =	lightColor[3];

		LightPosition[0] = lightPosition[0];
		LightPosition[1] = lightPosition[1];
		LightPosition[2] = lightPosition[2];
		LightPosition[3] = lightPosition[3];

		drawPoint = DrawPoint;
		spotLight = SpotLight; 

		spotCutoff = 180.0f; 

		linearConstant = linearAtt;
		quadraticConstant = quadraticAtt; 
	}
	Light(Vec4f lightColor, Vec4f lightPosition, bool DrawPoint, bool SpotLight, float spotCutoffAngle,  float linearAtt, float quadraticAtt)
	{
		LightColor[0] = lightColor[0];
		LightColor[1] =	lightColor[1];
		LightColor[2] =	lightColor[2];
		LightColor[3] =	lightColor[3];

		LightPosition[0] = lightPosition[0];
		LightPosition[1] = lightPosition[1];
		LightPosition[2] = lightPosition[2];
		LightPosition[3] = lightPosition[3];

		drawPoint = DrawPoint;
		spotLight = SpotLight; 

		spotCutoff = spotCutoffAngle; 

		linearConstant = linearAtt;
		quadraticConstant = quadraticAtt; 
	}
	~Light()
	{
	}
	GLfloat LightColor[4];
	GLfloat LightPosition[4];
	float spotCutoff; 
	float rank;
	bool drawPoint;	//if true, draws a point at the light's position to visual show where the light is positioned
	bool spotLight; //if the light is a spotlight
	float linearConstant;
	float quadraticConstant; 
};

//the doors that leed to the next area (interiors and districts)
class toNextArea
{
public:
	toNextArea()
	{
	}

	toNextArea(collisionObject *CollisionZone, Vec3f playerNewPos, bool ifDistrict, int IDNumber)
	{
		collisionZone = CollisionZone;
		district = ifDistrict;
		ID = IDNumber; 
		playerPos = playerNewPos;
	}

	~toNextArea()
	{
	}

	collisionObject *collisionZone;		//if the player collides with "door area" and presses "e", they will be able to go to next area
	bool district;	//true if next area is a district and false if next area is an interior
	int ID;		//the ID number of the next district or interior
	Vec3f playerPos;	//the players starting pos in the next area after going through the door
};

//a district is made up of models, textures, fog
struct District
{
	std::list <tex*> sectionTexs;		//a list of all of the textures for the particular district
	std::list <tex*> sectionNormalMaps;  //a list of all of the normal maps for the particular district
	std::list <objLoader*> sectionModels;	//a list of all of the models for the particular district; 

	//a list of all of the areas the the player can goto 
	vector<toNextArea*> Areas; 

	//loads the collision map
	levelGraph *levelCollisionMap;

	//A list of all of the collision objects in the district;
	std::list<collisionObject*> collisionList;
	//the collision mask of the district
	collisionObject collisionMask;

	//List of all the NPCs in the particular district
	std::list<regularNPC*> NPCList;

	//************PROJECTILES*******************//
	//bullets
	std::list<projectile> Bullets;
	projectile Bullet;

	////////////////////////////////////////////////////////

	GLfloat fogColor[4];	//what is the color for the fog?
	GLfloat fogStart;	
	GLfloat fogEnd; 

	//lights
	GLfloat ambientLightColor[4];
	GLfloat directedLightColor[4];
	GLfloat directedLightPosition[4];
	vector<Light> lights;	//a list that stores all of the point lights for the particular district
	vector<Light> normalLights; //a list that stores all of the white point lights that bring out the normals of the level
};

//a interior is made up of models and textures
struct Interior
{
	std::list <tex*> sectionTexs;		//a list of all of the textures for the particular interiors
	std::list <tex*> sectionNormalMaps;  //a list of all of the normal maps for the particular interiors
	std::list <objLoader*> sectionModels;	//a list of all of the models for the particular interiors

	//a list of all of the areas the the player can goto 
	vector<toNextArea*> Areas; 

	//loads the collision map
	levelGraph *levelCollisionMap;

	//A list of all of the collision objects in the district;
	std::list<collisionObject*> collisionList;
	//the collision mask of the district
	collisionObject collisionMask;

	//List of all the NPCs in the particular interior
	std::list<regularNPC*> NPCList;

	//************PROJECTILES*******************//
	//bullets
	std::list<projectile> Bullets;
	projectile Bullet;

	//lights
	GLfloat ambientLightColor[4];
	/*GLfloat directedLightColor[4];
	GLfloat directedLightPosition[4];*/
	vector<Light> lights;		//a list that stores all of the point lights for the particular interior
}; 

//a level is made up of districts and interiors
struct GameLevel
{
	District district[100];		//a array of all of the districts for the level, a array of lists
	Interior interior[100];		//a array of all of the interiors for the level, a array of lists
};

//***********************SHOULD NOT TOUCH ANYTHING FROM THIS CLASS*********************************//
//***To create a new level create a new level class and have it inherite publicly from this class***
//abstract base class (polymorphism)
class Level
{
public:
	virtual void loadLevel(GameMissions *missions) = 0;		//loads all the distrcts and interiors of the level

	/*void loadMissions();
	void updateMissions(playerStats player, float dt);
	void drawMissions();*/

	void drawDistrict(int n, Shader *shader);	//int n is the district number
	void drawInterior(int n, Shader *shader);
	
	void updateDistrict(playerStats *thePlayer, camera1 *theCamera, bool &interor, bool &district, int &districtID, int &interiorID, bool &drawE, float dt, sound::GameSound *AISounds[]);
	void updateInterior(playerStats *thplayer, camera1 *theCamera, bool &interor, bool &district, int &districtID, int &interiorID, bool &drawE, float dt, sound::GameSound *AISounds[]);
	
	void deleteLevel();		//deletes all districts and interiors of the level from memory

	GameLevel gameLevel;
	//GameMissions missions; 
	sf::Clock timeSinceDiscovered;

	int numInteriors, numDistricts;		//keeps track of how many interiors and districts there are in the level
};

//inherites publicly from calss level
class Level1 : public Level
{
public:
	void loadLevel(GameMissions *missions);
};