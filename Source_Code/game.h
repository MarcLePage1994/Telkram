#pragma once
#include "Include\CBMini\CBMiniFW.h"
#include "ShaderInit.h" 
#include "Include\GL\glew.h"
#include "texture.h"
#include "player.h"
#include "drawPrimitives.h"
#include "objLoader.h"
#include "camera1.h"
#include "projectile.h"
#include <math.h>
#include <vector>
#include <list>
#include "particleEngine.h"
#include "Level.h"
#include "character.h"
#include "RegularNPC.h"
#include "MorphTargeting.h"
#include "UIClass.h"
#include "GameSound.h"
#include "SkyBox.h"
#include "MissionBuilder.h"
#include "menuClass.h"
#include <Xinput.h>

#define G -9.8f	   //gravity

//handles information on the mouse
//used for camera movement
//in screen coordinates
struct mouseInput
{
	sf::Vector2i current;	//current mouse position
};

//handles information on the current state of the game
struct GameState
{
	unsigned int windowWidth, windowHeight; 
	//keeps track if the current section being rendered is a interior or district
	bool interior;	//if inside
	bool district;	//if outside
	int interiorID;	//the ID of the current interior
	int districtID;	//the ID of the current district
	int levelID;	//the ID of the current level

	float currentTime; //current time in seconds

	Interior *currentInterior; //reference the current interior
};

//games current state e.g. paused, menu, running
enum states
{
	menu,
	running,
	paused
};

enum menuStates
{
	mainMenu,
	options,
	menuToOptions,
	optionsToMenu,
	controls,
	menuToControls,
	controlToMenu,
	credits,
	menuToCredits,
	creditsToMenu
};

//////////////////////////////////////////////////////////////////////////////////////////////////////

class game
{
public:
	game();	//constructor
	~game(); //destructor
	void handleInput(); //handles input for both keyboard and controller
	void handleKeyFunc();	//handles the user's input (when button is pushed down) from keyboard
	void handleJoyStickFunc(); //handles the user's input (when button is pushed down) from joyStick/controller
	void initRenderFunc();	//renders the 3D scene
	void initWindowFunc(GLfloat ratio);	//handles the window
	void drawFunc(sf::RenderWindow *window);		//draws the 3D scene
	void cleanUp();			//cleans up once the user presses the esc key or quites
	void updateFunc();	//updates the scene
	void mouseMotion(sf::Vector2i current, sf::RenderWindow *window);
	void keyboardUp(unsigned char key, int x, int y);		//when a button is realeased
	void runGame();
	void updateCamera();
	void updateMenu();
	void drawMenu();
	void menuKeyFunc();
	void pausedKeyFunc();
	void RenderHDRScene(sf::RenderWindow *window);
	void PlayercheckHostile(std::list<regularNPC*>& theNPC, float dt);
	void joyStickMoveMouse();

	Shader *shader; 

	sf::RenderWindow *window;

	//jumping
	void playerJumping();
	float testTimer;

	//for useing the mouse to look around the scene
	void mouseDirectionCheckX(float x, float y);	//for x axis
	void mouseDirectionCheckY(float x, float y);	//for y axis
	Vec3f prevX;	//stores the previous mouse direction for x axis
	Vec3f prevY;	//stores the previous mouse direction for y axis

	sf::Vector2i dirVec(sf::Vector2i v, sf::Vector2i other);
	sf::Vector2f norm(sf::Vector2i temp);

	sf::Joystick joyStick;
	playerStats player;	//gain access the playerStats data members.
	mouseInput mouse; 
	GameState gameState;

	int runningState;
	int menuState;

	camera1 theCamera;

	//so we can draw simple shapes
	drawPrimitives *drawShapes;
//**********MENU STUFF********************//
	objLoader *menuCube;
	sf::Clock menuClock;
	tex *menuCubeTexture;
	bool firstPress;
	Mask menuMask;
	sf::Image menuMask1[10];
	float transitionTime;
	bool end;

	UI ui;
	UI gameScreen;
	UI cursor;
	UI deathUI;
	UI pressEToEnter;
	UI pressAToEnter; 
	gameMenu inGameMenu;

//**********LEVELS************************//
	Level *levels[2];	//an array of levels, 2 is the number of levels

//***********PARTICLES*********************//
	ParticleManager *rain; 
	ParticleManager *splash; 

	list<ParticleManager*> particleSystems;

//***************CAMERA DELTA TIME********************//
	sf::Clock cameraClock;

//********************JUMPIING*********************//
	sf::Clock jumpClock;
	
// clock for time tracking and constant updates
	sf::Clock theClock;
	sf::Time frameTime;
	sf::Clock bulletClock;
	sf::Clock deathClock;
	bool deathBool;

	int numIterations;
	int frameRate;
	float deltaTime;
	float lerpTime;
	float rippleTime;
//////////////////////////////////////////////////////////////////////
	sf::View myGUIView;

	//Sky Box
	SkyBox *skyBox;

	//Player sounds
	sound::GameSound *rainSound; 
	sound::GameSound *test2Dsound;
	sound::GameSound *atmospheric;
	sound::GameSound *clubMusic;
	sound::GameSound *barMusic;
	sound::GameSound *lowBass;
	sound::GameSound *laserBlast;
	sound::GameSound *death;
	sound::GameSound *stealth[3];
	//sound::GameSound *door;

	//AI sounds
	sound::GameSound *AISounds[15];

	bool playMainMenuMusic; 

//////////////////////////////////////////////////////////////////////
	//HDR Rending
	cbmini::cbfw::FrameBuffer *FBO;
	cbmini::cbfw::FrameBuffer *FBO_BP;	//Bright Pass Filter
	cbmini::cbfw::FrameBuffer *FBO_BOX_BLUR; //Box Blurring
	cbmini::cbfw::FrameBuffer *FBO_G_BLUR_X; //Gaussian Bluring X
	cbmini::cbfw::FrameBuffer *FBO_G_BLUR_Y; //Gaussian Bluring Y
	cbmini::cbfw::FrameBuffer *FBO_FINAL; //Final with HDR rendering applied
	float shrinkFactor; 

	//HUD
	cbmini::cbfw::FrameBuffer *HUD;
	bool displayCursor;

///////////////////////////////////////////////////////////////
	//Missions
	GameMissions missions; 

////////////////////////
	float ETimer;
	bool drawE;

///////////////////////
	//for xbox controller
	XINPUT_STATE controllerState;
	XINPUT_VIBRATION vibration; 
	float firstPersonTimer;
	float vibrationTimer;

};
