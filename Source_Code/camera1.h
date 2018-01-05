#pragma once
#include "MathClass.h" 
#include "player.h"
//using namespace std;

#ifndef CAMERA_H
#define CAMERA_H

class camera1
{
public:
	camera1();
	~camera1();

	void setStartingVector (Vec3f levelStartingVector);
	void setCurrentVector (Vec3f currentVec);
	void setPosition (/*Vec3f positionition*/);
	void setSavedOffset(Vec3f currentVec);
	void setLastState(Vec3f parameter);
	void updateCamera(playerStats player); 

	Vec3f getStartingVector ();
	Vec3f getCurrentVector ();
	Vec3f getPosition ();

	Vec3f position;
	Vec3f startingVector;
	Vec3f currentVector;
	Vec3f savedOffset;

	Vec3f ForwardVector;
	Vec3f UpVector;
	Vec3f RightVector;

	Vec3f playerPoint;
	Vec3f playerPointReserved;

	Vec3f lastState;
	
};

#endif