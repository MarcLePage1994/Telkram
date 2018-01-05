#include "camera1.h"

camera1::camera1()
{
	//initializations
		position = Vec3f(0,0,0);
		startingVector = Vec3f(0,0,0);
		currentVector = Vec3f(0,0,0);

		ForwardVector = Vec3f(0,0,0) ;
		UpVector = Vec3f(0,0,0);
		RightVector = Vec3f(0,0,0);
		//savedOffset = Vec3f(0.0f, 10.0f, -40.0f);
}
camera1::~camera1()
{

}

void camera1::setStartingVector (Vec3f levelStartingVector)
{
	startingVector = levelStartingVector;
}

void camera1::setCurrentVector (Vec3f currentVec)
{
	currentVector = currentVec;
}

void camera1::setSavedOffset (Vec3f currentVec)
{
	savedOffset = currentVec;
}
void camera1::setLastState(Vec3f parameter)
{
	lastState = parameter;
}
void camera1::setPosition (/*Vec3f positionition*/)
{
	//position = positionition + currentVector;
	position = playerPointReserved + currentVector; 

}

void camera1::updateCamera(playerStats player)
{
	if(player.state.fp)
	{
		//find frent frame of camera
		ForwardVector = player.ZaxisPos;
		RightVector = ((ForwardVector).cross(Vec3f(0.0f, 1.0f, 0.0f))).normalize();
		UpVector = RightVector.cross(ForwardVector);
	}
	else
	{
		//find frent frame of camera
		ForwardVector = (player.position - position).normalize();
		RightVector = ((ForwardVector).cross(Vec3f(0.0f, 1.0f, 0.0f))).normalize();
		UpVector = RightVector.cross(ForwardVector);
	}

}

Vec3f camera1::getStartingVector ()
{
	return startingVector;
}

Vec3f camera1::getCurrentVector ()
{
	return currentVector;
}
	
Vec3f camera1::getPosition ()
{
	return position;
}