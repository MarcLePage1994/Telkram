#pragma once
#include "texture.h"
#include "Include/SFML/Graphics.hpp"
#include "Include/SFML/OpenGL.hpp"
#include "Collision.h"
#include "RegularNPC.h"
#include "player.h"
#include <vector>
#include "objLoader.h"

//loads the icons for the objectives
static tex *killIcon;
static tex *stealIcon;
static tex *goToIcon;
static tex *talkingIcon;

static void loadObjectiveIcons()
{
	killIcon = new tex();
	stealIcon = new tex();
	goToIcon = new tex();
	talkingIcon = new tex();

	killIcon->loadTex("Images/ObjectiveIcon/crosshair.png");
	stealIcon->loadTex("Images/ObjectiveIcon/hand.png");
	goToIcon->loadTex("Images/ObjectiveIcon/compass.png");
	talkingIcon->loadTex("Images/ObjectiveIcon/talking.png");
}

/*
for stealing and smuggling objects
-the ability to not render certain objects once hitting a collision zone
-the ability to re-render certain objects once hitting a collision zone
*/
class Object
{
public:
	Object();
	Object(const std::string &textureFilename, char *modelFilename, int maxTriangles, bool draw, Vec3f position, Vec3f Scale, float angle, int level, int subLevel, bool outSide);
	~Object();

	collisionObject *collisionZone; 
	tex *theTexture;
	objLoader *theModel;
	Vec3f pos;		//the position of the object
	Vec3f scale;	//the scale of the object
	float theta;	//the orientation of the object
	bool render;	//if the object should be rendered or not

	//used to determine if the current object needs to be rendered
	int Level;			//the current level the player is on
	int SubLevel;		//the current district or interior the player is one
	bool OutSide;		//if the player is in a district(true) or in a interior(false)
};

/*
for having NPC dialogue with player
-can be used to give player background info
-explain mission or objective
-etc
*/
class Dialogue 
{
public:
	Dialogue();
	~Dialogue();

	bool dialogueDone; 
	int index;
	bool render;
	float time;

	void update( float dt);
	void draw(sf::RenderWindow *window);

	//font and text
	sf::Text text;
	sf::Font font;
	vector<float> timeRender; 
	vector<sf::String> theString; //the description of the objective
	bool updateRes;
	sf::Vector2f prevRes;	//helps change the position of the text upon window resize
	sf::Vector2f offsetRes; //helps change the position of the text upon window resize
};

//a objective is a single goal
class Objective
{
public:
	Objective();
	Objective(bool Choice, int level, int subLevel, bool outSide, sf::String popup, tex *textureForIcon);
	~Objective();
	collisionObject *goalArea;	//a area collisions. Could be anything from where to meet someone, and even where the npc is to talk to
	regularNPC *NPCToKill; 
	Object *theObject;

	//for dialogue (our cutscenes)
	Dialogue *dialogue; 

	//Objective *parent;		//the objective for this one
	vector<Objective*> parents;
	vector<Objective*> children;	//the objective(s) that come after this one

	bool objectiveComplete;

	bool display; //for the cout commands to the console screen

	bool choice; //is used to determine a difference between choice objectives (so do objective A or B but not both to progress the mission state) 
				//and objectives that need to be done all at once (so do both objective A and B to progress the mission state). 

	//used to determine if the current objective needs to be updated
	int Level;			//the current level the player is on
	int SubLevel;		//the current district or interior the player is one
	bool OutSide;		//if the player is in a district(true) or in a interior(false)

	void attachChild(Objective *child);		
	void updateObjective(playerStats *player,  float dt);	//update the goal areas if they need to be updated
	void drawObjective(sf::RenderWindow *window, float dt, bool textDone, int difference);		//draws the objective to the HUD
	void drawIcons(cbmini::cbfw::GLSLProgram *ShaderProgram);

	int errorCounter; //prevents errors

	float timeDifference;
	bool TextDone;
	int Difference;

	//font and text
	sf::Text text;
	sf::Font font;
	sf::String theString; //the description of the objective
	Vec3f textStartingPos;
	Vec3f textEndingPos;
	Vec3f textCurrentPos;
	float time;
	bool wait; 
	int waitCounter;
	bool updateRes;
	sf::Vector2f prevRes;	//helps change the position of the text upon window resize
	sf::Vector2f offsetRes; //helps change the position of the text upon window resize

	bool space;
	bool waitLonger;

	//for the icon that displays where the current objective is
	float iconTheta;
	Vec3f iconPos; 
	float iconSize;
	tex *iconTexture;

	bool renderObjective; 
};

//a mission is made up of many objectives
class Mission
{
public:
	Mission();
	Mission(int startLevel, int startSubLevel, bool startOutSide, sf::String missionName);
	~Mission();

	collisionObject *startArea; //this is the area where the player first comes across the mission

	//for dialogue (our cutscenes)
	Dialogue *dialogue; 

	//used to determine if the current mission's start area needs to be updated
	int Level;			//the current level the player is on
	int SubLevel;		//the current district or interior the player is one
	bool OutSide;		//if the player is in a district(true) or in a interior(false)

	//Mission *parent;
	vector<Mission*> parents;
	vector<Mission*> children;

	Objective *firstObjective;
	vector<Objective*> currentObjectives; 

	bool completed;	//if mission has been completed 

	void attachChild(Mission *child);

	void updateMission(playerStats *player, int level, int subLevel, bool outside,  float dt);	//update the state of the mission (i.e. all of the objectives of the mission)
	void drawMission(sf::RenderWindow *window, float dt);		//draws the mission to the HUD	 
	void drawIcons(cbmini::cbfw::GLSLProgram *ShaderProgram, int level, int subLevel, bool outside);

	float timeDifference;

	//font and text
	sf::Text text;
	sf::Font font;
	sf::String theString; //the name of the mission
	float time;
	bool wait; 
	bool textDone;	//when the text is done displaying
	int waitCounter;
	bool updateTex;
	bool updateRes;
	sf::Vector2f prevRes;	//helps change the position of the text upon window resize
	sf::Vector2f offsetRes; //helps change the position of the text upon window resize
	sf::Vector2f currentTextPos; 
};

//a game is made up of many missions
class GameMissions
{
public:
	GameMissions();
	~GameMissions();

	Mission *active;
	vector<Mission*> notActive;
	vector<Mission*> completed;
	vector<Mission*> notFound;
	vector<Mission*> cannotDo;
	vector<Mission*> all; //this include all of the active and not active missions

	//stores pointers to all of the objects used in objectives so that they can be rendered
	vector<Object*> allObjects; 

	/*
	one way to load npcs is to declare them in level.cpp and then use the missions object to store the pointer to the npc object in a vector in the 
	GameMissions class in missionBuilder.h, and then just manually accessing them from the vector in the loadGamMissions function. 
	*/
	vector<regularNPC*> NPCsToKill;

	void loadGameMissions();
	void updateGameMissions(playerStats *player, int level, int subLevel, bool outside, float dt);
	void drawGameMissions(sf::RenderWindow *window, float dt);
	void drawIcons(cbmini::cbfw::GLSLProgram *ShaderProgram, int level, int subLevel, bool outside);

	void drawMissionObjects(int level, int subLevel, bool outside);
};
