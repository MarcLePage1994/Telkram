#pragma once
#include <windows.h>
#include <stdio.h>
#include "Fmod\fmod.hpp"
#include "Fmod\fmod_errors.h"
#include "MathClass.h"

const float DISTANCEFACTOR = 39.3701f;		// Units per meter.  I.e feet would = 3.28.  centimeters would = 100.	inches would = 39.3701

//checks if there is a error
//if there is a error it will print it to the console
inline void ERRCHECK(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//The sound manager
class SoundManager
{
private:
	int key, numdrivers;
	unsigned int version;
	FMOD_SPEAKERMODE speakermode;
    FMOD_CAPS caps;
	FMOD_RESULT result;
	char name[256];
public:
	SoundManager();
	~SoundManager();
	void set3DListener(Vec3f position, Vec3f velocity, Vec3f forward, Vec3f up);
	void cleanUp();
	FMOD::System *system;
	//FMOD::Channel *channel1, *channel2, *channel3; //where a sound can play itself, allows to play multiple sounds at once, (one sound per channel)
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace sound
{

//represents a single sound in game
class GameSound
{
public:
	GameSound();
	GameSound(SoundManager *soundManager); 
	~GameSound();

	int load3DSound(const char *fileName, Vec3f position, Vec3f velocity, float minDistance, float maxDistance, bool loop);
	void load2DSound(const char *fileName, bool loop);

	void playSound();
	void stopSound();

	void updateSound(Vec3f newPos);

	void changeRollOff(bool linearRollOff);

	void cleanUp();

	bool is3D;	//if it is a 3D sound true, if not false
	bool isLoop;
	bool isPlaying;	//if the sound is currently playing

private:
	SoundManager *manager; 
	FMOD::Sound *sound; 
	FMOD::Channel *channel; //where a sound can play itself, allows to play multiple sounds at once, (one sound per channel)
	FMOD_RESULT result;
	FMOD_VECTOR pos;	//position of 3D sound
	FMOD_VECTOR vel;	//verlocity of 3D sound
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//this lets use have only one sound manager for all sounds
static SoundManager *soundManager; 

//must be called to initialize sound
inline void initSound()
{
	soundManager = new SoundManager();
}
}