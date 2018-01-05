#include "GameSound.h"
using namespace sound; 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////The sound manager

SoundManager::SoundManager()
{
	/*channel1 = 0; 
	channel2 = 0; 
	channel3 = 0;*/

	//Create a system object and initialize it
	result = FMOD::System_Create(&system);
	ERRCHECK(result);

	result = system->getVersion(&version);
	ERRCHECK(result);

	if (version < FMOD_VERSION)
    {
        printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
    }

	result = system->getNumDrivers(&numdrivers);
	ERRCHECK(result);

    if (numdrivers == 0)
    {
        result = system->setOutput(FMOD_OUTPUTTYPE_NOSOUND);
        ERRCHECK(result);
    }
	else
	{
		result = system->getDriverCaps(0, &caps, 0, &speakermode);
        ERRCHECK(result);

		result = system->setSpeakerMode(speakermode);       //Set the user selected speaker mode.
        ERRCHECK(result);

		if (caps & FMOD_CAPS_HARDWARE_EMULATED)             // The user has the 'Acceleration' slider set to off!  This is really bad for latency!. 
        {                                                   // You might want to warn the user about this. 
            result = system->setDSPBufferSize(1024, 10);
            ERRCHECK(result);
        }

		result = system->getDriverInfo(0, name, 256, 0);
        ERRCHECK(result);

		if (strstr(name, "SigmaTel"))   //Sigmatel sound devices crackle for some reason if the format is PCM 16bit.  PCM floating point output seems to solve it. 
        {
            result = system->setSoftwareFormat(48000, FMOD_SOUND_FORMAT_PCMFLOAT, 0,0, FMOD_DSP_RESAMPLER_LINEAR);
            ERRCHECK(result);
        }
	}

	result = system->init(100, FMOD_INIT_NORMAL | FMOD_INIT_HRTF_LOWPASS | FMOD_INIT_3D_RIGHTHANDED, 0);
	if(result == FMOD_ERR_OUTPUT_CREATEBUFFER)	// Ok, the speaker mode selected isn't supported by this soundcard.  Switch it back to stereo...
	{
		result = system->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
		ERRCHECK(result);

		result = system->init(100, FMOD_INIT_NORMAL, 0); //... and re-init. 
        ERRCHECK(result);
	}
	
	
    //Set the distance units. (meters/feet etc).
    result = system->set3DSettings(0.5, DISTANCEFACTOR, 0.3f);
    ERRCHECK(result);
}

SoundManager::~SoundManager()
{
}

void SoundManager::set3DListener(Vec3f position, Vec3f velocity, Vec3f forwardVec, Vec3f upVec)
{
	FMOD_VECTOR pos = {position[0], position[1], position[2]};
	FMOD_VECTOR vel = {velocity[0], velocity[1], velocity[2]};
	FMOD_VECTOR forward = {forwardVec[0], forwardVec[1], forwardVec[2]};
	FMOD_VECTOR up = {upVec[0], upVec[1], upVec[2]};

	result = system->set3DListenerAttributes(0, &pos, &vel, &forward, &up);
    ERRCHECK(result);

	system->update();
}

//Shut down
void SoundManager::cleanUp()
{
	result = system->close();
    ERRCHECK(result);
    result = system->release();
    ERRCHECK(result);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////A single sound
GameSound::GameSound()
{
	channel = NULL; 
	manager = NULL;
	isPlaying = false;
}

GameSound::GameSound(SoundManager *soundManager)
{
	channel = NULL; 
	manager = soundManager; 
	isPlaying = false;
}

GameSound::~GameSound()
{
}

void GameSound::load2DSound(const char *fileName, bool loop)
{
	is3D = false;
	isLoop = loop;

	//create the 2D sound
	result = manager->system->createSound(fileName, FMOD_SOFTWARE | FMOD_2D, 0, &sound);
    ERRCHECK(result);

	//if the 2D sound is suppose to loop 
	if(loop)
	{
		result = sound->setMode(FMOD_LOOP_NORMAL);
		ERRCHECK(result);
	}
}

int GameSound::load3DSound(const char *fileName, Vec3f position, Vec3f velocity, float minDistance, float maxDistance, bool loop)
{
	is3D = true;
	isLoop = loop;

	FMOD_VECTOR temp1 = {position[0], position[1], position[2]};
	FMOD_VECTOR temp2 = {velocity[0], velocity[1], velocity[2]};

	pos = temp1;
	vel = temp2;

	//create the 3D sound
	result = manager->system->createSound(fileName, FMOD_3D, 0, &sound);
	ERRCHECK(result);
	result = sound->set3DMinMaxDistance(minDistance * DISTANCEFACTOR, maxDistance * DISTANCEFACTOR);
	ERRCHECK(result);

	//if the 3D sound is suppose to loop then just play it
	if(loop)
	{
		result = sound->setMode(FMOD_LOOP_NORMAL);
		ERRCHECK(result);
	}

	if(result != FMOD_OK)
	{
		return 0;
	}

	return 1;
}

//DO NOT USE THIS FUNCTION IF SOUND LOOPS, it will play automatically
void GameSound::playSound()
{
	if(!isPlaying)
	{
		//if 3D sound, always have 3D sound on channel 1
		if(is3D)
		{
			result = manager->system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
			ERRCHECK(result);
			result = channel->set3DAttributes(&pos, &vel);
			ERRCHECK(result);
		}
		//else 2D sound, always have 3D sound on channel 3
		else
		{
			result = manager->system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
			ERRCHECK(result);
		}
	}
	
	isPlaying = true;
}

void GameSound::stopSound()
{
	isPlaying = false;

	//make sure we don't stop a sound that is not being played
	bool channelPlay = false;
	channel->isPlaying(&channelPlay);

	if(is3D)
	{
		if(channelPlay)
		{
			result = channel->setPaused(true);
			ERRCHECK(result);
		}
	}
	else
	{
		if(channelPlay)
		{
			result = channel->setPaused(true);
			ERRCHECK(result);
		}
	}
}

void GameSound::updateSound(Vec3f newPos)
{
	FMOD_VECTOR temp1 = {newPos[0], newPos[1], newPos[2]};
	pos = temp1; 

	//make sure we don't update a sound that is not being played
	bool channelPlay = false;
	channel->isPlaying(&channelPlay);
	if(channelPlay)
	{
		result = channel->set3DAttributes(&pos, &vel);
	}
	ERRCHECK(result);
}

void GameSound::changeRollOff(bool linearRollOff)
{
	if(linearRollOff)
	{
		result = sound->setMode(FMOD_3D_LINEARROLLOFF);
		ERRCHECK(result);
	}
	else
	{
		result = sound->setMode(FMOD_3D_INVERSEROLLOFF); //FMOD_3D_LOGROLLOFF
		ERRCHECK(result);
	}
}

//Shut down
void GameSound::cleanUp()
{
	result = sound->release();
	ERRCHECK(result);
}