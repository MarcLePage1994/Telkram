#pragma once
#include "texture.h"
#include <string>
#include "MathClass.h"
#include "objLoader.h"
#include "Collision.h"
#include "pcNode.h"
#include "MorphTargeting.h"

//the character's animations
struct Animations
{
	//Skeleton test;
	morph StillFrame;
	morph Idle;
	morph Walking;
	morph WalkingBackward;
	morph StrafeLeft;
	morph StrafeRight;
	morph Shooting;
	morph Jumping;
	morph Aiming;
	morph Death;
	morph Scared;
};

class character
{
public:

	character();
	
	character(bool isAlive, int hitpoints, Vec3f Cposition, float angle, int Cspecies, Vec3f CstartingPosition);

	~character();

	//This function fills out the array that defines which species a species is hostile to. 
	//This can be redefined in different levels to have different setups. 
	void setUpHostileSpecies();


	//Default collision type (radius of 0)
	//virtual void setUpCollisionType();

	//radius collision type
	//virtual void setUpCollisionType(float radius);

	//2D binding box collision type
	//virtual void setUpCollisionType(float length, float width);

	//3D binding box collision type
	//virtual void setUpCollisionType(float length, float width, float height);


	virtual void checkCollision();

	virtual void checkForHostiles();

	virtual void updateCharacter();

	//void loadCharacter(const std::string &textureFileName, char* modelFileName, int polyCount);

	void loadCharacter(tex* importedTex, char* modelFileName, int polyCount);

	virtual void drawCharacter();

	//calculates the current axis of the character. only needs to be calculated when there is an orientation change
	void calcAxis();

	//for animations
	virtual void loadAnimations();
	virtual void updateAnimations(float dt);


	//Variable Declarations
	bool alive;	//whether we apply any functions to the npc or not. Deactivated means it isnt affected by anything.

	float tValue; //interpolating value (used for lerps and slerps and curves)
	float deltaTime; 

	int species;		//what type of species the character is
	int isHostileTowards[10];	//species/people types the character will attack

	int sightRadius;

	int health;			//amount of health an enemy has

	bool isHostile;		//if the character is in attack mode or not. by default they aren't in attack mode until an enemy is detected
	bool isAttackable;	//if the character is vulnerable to attacks or not. By default this is on. 


	Vec3f position;		//the current position. this is the global position
	Vec3f startingPosition;	//the starting position of the character
	Vec3f movementVec; //The vector that the character moves along
	Vec3f ZaxisPos;		//facing forwards
	Vec3f ZaxisNeg;		//facing backwards
	Vec3f XaxisPos;		//facing right
	Vec3f XaxisNeg;		//facing left
	float theta;		//starting angle of the character

	float speed;

	bool flipNegXAxis;
	bool flipPosXAxis;
	bool flipPosZAxis;
	bool flipNegZAxis;

	float accumulatedTime;
	float waitTime;

	float recentlyAttacked; //amount of time its been since an npc attacked
	float relaxingPeriod; //amount of time a character takes to relax after its last shot

	tex *theTexture1;
	objLoader *theModel;

	//parent child node
	pcNode node;

	//COLLISION
	collisionObject cObject;
	//Checks collision of other NPC's, collision of the scene, collision of objects in the scene (later), and the player
	bool checkCollision(std::list<collisionObject*>& collisionList);
	void collisionSet(float radius);

	//character Animations
	Animations animations; 
};