#pragma once
#include "texture.h"
#include <math.h>
#include "SFML\Graphics.hpp"
#include "SFML\OpenGL.hpp"
#include <string>
#include "MathClass.h"
#include <list>
//using namespace std;

class Circle
{
public:
	Circle();
	void SetRadius(float radius);
	void SetPosition(float x, float y, float z);
	void SetPosition(Vec3f newPos);
	bool CollisionTest(Circle& other, float theSpeed, Vec3f theVector);
	//float x;
	//float z;
	Vec3f Pos;
	float radius;
};


class Box
{
public:
	Box();
	void SetScale(float scaleX, float scaleY);
	void SetPosition(float x, float z);
	bool CollisionTest(Box& other, float theSpeed, Vec3f theVector);
	bool CollisionTest(Circle& other, float theSpeed, Vec3f theVector); //this wont work yet

	float x;
	float z;
	float scaleX;
	float scaleZ;
};

class Mask
{
public:
	Mask();
	Mask(string fileName, Vec3f startingPosition, float xScale, float zScale, Vec3f AutoScale);
	Mask(string fileName);
	~Mask();
	
	void draw();
	bool collisionCheck(Vec3f theVector, float theSpeed, Vec3f thePosition, Mask& theMask);
	bool squareCheck(Vec3f thePosition, Mask &theMask);

	sf::Image trackMask;
	tex maskTex;
	GLuint _textureID;

	float maskSizeX;
	float maskSizeY;

	Vec3f startingOffset;
	float scaleX;
	float scaleY;
	float scaleZ;
	Vec3f autoScale;
};

////////////////////////////////////////////////////////////////////////////////////////////////
//Cone vision for NPCs, for sneaking
class Cone
{
public:
	Cone();
	Cone(Vec3f negX, Vec3f posX, Vec3f posZ, Vec3f Size, Vec3f CenterPos);
	~Cone();
	
	class Point
	{
	public:
		Point()
		{
		}
		~Point()
		{
		}
		Vec3f position;
		float rank;
	};

	Vec3f size;			//the size of the cone 

	Point *centerPos;	//position of object
	Point *rightPos;		//right bound position
	Point *leftPos;		//left bound position

	Vec3f coneCenter;	//the center position of the triangle
	float tRadius;		//the radius of the traingle from the cone center

	void update(Vec3f negX, Vec3f posX, Vec3f posZ, Vec3f CenterPos);
	bool collisionTest(Vec3f position, float radius);

};
///////////////////////////////////////////////////////////////////////////////////////////////////////


class collisionObject
{
public:
	collisionObject(); //does nothing
	collisionObject(float radius, Vec3f startingPosition, float startingSpeed, bool posUpdate); //makes a circle
	collisionObject(float x, float y, Vec3f startingPosition, float startingSpeed, bool posUpdate); //makes a box
	collisionObject(string fileName,Vec3f startingOffset, float startingSpeed, float xScale, float zScale, Vec3f AutoScale); //creates a collision mask
	collisionObject(Vec3f negX, Vec3f posX, Vec3f posZ, Vec3f Size, Vec3f CenterPos); //creates a cone collision
	~collisionObject();

	//Collision test needs to grab: 
	//the list of all collision objects in the game. game will change to level once the level class is in. 
	bool collisionTest(std::list<collisionObject*>& collisionList);

	bool collisionTest(collisionObject *i);

	void updateCollisionObject(Vec3f newVec, float newSpeed, Vec3f newPosition);
	void updateCollisionObject(Vec3f newVec, Vec3f xNeg, Vec3f xPos, float newSpeed, Vec3f newPosition);
	
	//used for sneaking, determines if the player is behind a object. If this is true than the npcs can't see the player
	bool rayCastTest(collisionObject *i, collisionObject *map);
	bool rayCastTestLight(Vec3f lightPos, Vec3f characterPos, collisionObject *map);

	//1 = circle
	//2 = bounding box
	//3 = collision mask
	//4 = cone vision
	int collisionType; //this determines what type of collision object each thing will compare to. 

	Vec3f dirVec; //the direction vector of the object.
	float speed; //the speed of an object
	Vec3f position;

	Circle theCircle;
	Box theBox;
	Mask theMask;
	Cone theCone;

	bool updatePos; //if the position needs to be updated (true) or if it is a static collision (false)


};
