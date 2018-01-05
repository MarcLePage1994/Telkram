#pragma once
#include "ShaderInit.h"
#include "MathClass.h"
#include "character.h"
#include "BVH_FileLoader.h"
#include "projectile.h"


//input by the player to the game
struct playerInput
{
	bool w,a,s,d, Lshift, space, Lmouse, Rmouse, LCtrl, E;
	float Lt, Rt; //right trigger and left trigger, for joystick
};

//the state of the player
struct playerState
{
	bool running, walking, idle, sneaking, jumping, aiming; 
	bool fp, tp;	//first person and third person;
	float theta;	//the theta of the player at a frozen state
	bool prevfp; //if the player was in first person when entering the dialogue 
};

//the players's statistics that the game needs to know
class playerStats : public character
{
public:
	
	playerStats()
	{
		//animations.test = Skeleton();

		species = 10;
		setUpHostileSpecies();

		health = 100;

		alive = true;
		isHostile = false;
		isAttackable = true;
		
		theta = 0.0f;
		//startingPosition = Vec3f(520.f * 0.6  * 3.0, 0.0, 290.f * 0.6 * 3.0);
		//startingPosition = Vec3f(85.f * 0.6  * 3.0, 0.0f, 260.f * 0.6 * 3.0);
		startingPosition = Vec3f(389, 0, 428);

		position = startingPosition;
		tValue = 0.f;
		
		speed = 1.0f;
		
		ZaxisPos = Vec3f(0.0f, 0.0f, 1.0f);		//front of the character
		ZaxisPos.applyYRotation(theta);
		ZaxisNeg = Vec3f(0.0f, 0.0f, -1.0f);		//back of the character
		ZaxisNeg.applyYRotation(theta);

		XaxisNeg = Vec3f(-1.0f, 0.0f, 0.0f);			//left of the character
		XaxisNeg.applyYRotation(theta);
		XaxisPos = Vec3f(1.0f, 0.0f, 0.0f);			//right of the character
		XaxisPos.applyYRotation(theta);
		
		state.jumping = false;
		playerMove = true;
		state.sneaking = false;

		input.LCtrl = false;
		
		mousePos[2] = 0.0f;
		landHeight = position[1];

		updatePlayerStateTheta = false;

		//jumping
		runSpeed = 1.0f;
		jumpForce = 0.0f;
		yAccel = 0.0f;
		yVelocity = 0.0f;
		playerMass = 50.0f;

		//create the parent/child node
		node = pcNode();

		relaxingPeriod = 1.0f; //amount of time a character takes to relax after its last shot
		recentlyAttacked = relaxingPeriod + 1; //amount of time its been since an npc attacked
		

		timeDelay = 0.0f; 

		state.prevfp = false;

		dialogue = false;
		updateDialoguePerspective = false;

		//collisionObject(8,this->position, this->speed, true);

	}

	//************TO DO: TOO MANY VARIABLES, PUT SOME IN STRUCTS*************************

	
	Vec3f mousePos;		//the mouse's position
	Vec3f screenSize;	//the size of the screen in pixels, (stored as a 2D vector)
	Vec3f mouseDirX;	//the direction of the mouse for x-axis
	Vec3f mouseDirY;	//the direction of the mouse for y-axis
	bool playerMove;	//if the player can move, true, if not false
	float landHeight;

	bool dialogue; //if player is in dialogue 
	bool updateDialoguePerspective; 

	float timeDelay; 

	bool updatePlayerStateTheta;

	//jumping
	float jumpForce, yAccel, yVelocity, playerMass, runSpeed;

	////player Animations
	//playerAnimations animations; 

	playerInput input;
	playerState state;

//this is called when the player shoots to see if npc's notice the player or not. 
//takes in a list, and has an if statement at the beginning that compares if the player is hostile or not. if they are, it 
//goes through and sees if any enemies are in range. if they are, maintain hostility. if not, hostile = true
	void checkHostile(std::list<character*>& theNPC)
	{
		if (this->isHostile)
		{

			for (std::list<character*>::iterator i = theNPC.begin(); i != theNPC.end();i++)
			{
				//reset hostile variable
				Vec3f tempVec; //used to grab the magnitude of the two distances

				//grab the distance between the two
				tempVec = position.negate() + (*i)->position;

				//if they are either within the line of sight, or radius of the NPC
				if (tempVec.magnitude() <= (*i)->sightRadius)
				{
					break;
				}
			}

			//if the end of the loop is reached and no enemies are in range (hasnt had break activated)
			this->isHostile = false;
		}
	}


	void loadAnimations()
	{

		theModel = new objLoader();
		theTexture1 = new tex();

		theTexture1->loadTex("Images/Characters/MainCharacterTextureV3.png");
		theModel->LoadOBJForMorphTargeting("Models/Characters/Player/mainCharacter.obj", 11644);
		

		//for the player's animation

		////idle
		animations.Idle.addKeyFrame("Animations/Player/Idle/keyFrame01.obj", 11644);
		animations.Idle.addKeyFrame("Animations/Player/Idle/keyFrame02.obj", 11644);
		animations.Idle.addKeyFrame("Animations/Player/Idle/keyFrame03.obj", 11644);
		animations.Idle.addKeyFrame("Animations/Player/Idle/keyFrame04.obj", 11644);
		animations.Idle.addKeyFrame("Animations/Player/Idle/keyFrame05.obj", 11644);
		animations.Idle.addKeyFrame("Animations/Player/Idle/keyFrame06.obj", 11644);
		animations.Idle.addKeyFrame("Animations/Player/Idle/keyFrame07.obj", 11644);

		//animations.Jumping.addKeyFrame("Animations/Player/jumping/keyFrame01.obj", 12297);
		animations.Jumping.addKeyFrame("Animations/Player/jumping/keyFrame02.obj", 11644);
		animations.Jumping.addKeyFrame("Animations/Player/jumping/keyFrame03.obj", 11644);
		animations.Jumping.addKeyFrame("Animations/Player/jumping/keyFrame04.obj", 11644);
		animations.Jumping.addKeyFrame("Animations/Player/jumping/keyFrame05.obj", 11644);
		animations.Jumping.addKeyFrame("Animations/Player/jumping/keyFrame06.obj", 11644);
		animations.Jumping.addKeyFrame("Animations/Player/jumping/keyFrame07.obj", 11644);

		animations.StrafeLeft.addKeyFrame("Animations/Player/strafeLeft/keyFrame01.obj", 11644);
		animations.StrafeLeft.addKeyFrame("Animations/Player/strafeLeft/keyFrame02.obj", 11644);
		animations.StrafeLeft.addKeyFrame("Animations/Player/strafeLeft/keyFrame03.obj", 11644);
		animations.StrafeLeft.addKeyFrame("Animations/Player/strafeLeft/keyFrame04.obj", 11644);
		animations.StrafeLeft.addKeyFrame("Animations/Player/strafeLeft/keyFrame05.obj", 11644);
		animations.StrafeLeft.addKeyFrame("Animations/Player/strafeLeft/keyFrame06.obj", 11644);

		animations.StrafeRight.addKeyFrame("Animations/Player/strafeRight/keyFrame01.obj", 11644);
		animations.StrafeRight.addKeyFrame("Animations/Player/strafeRight/keyFrame02.obj", 11644);
		animations.StrafeRight.addKeyFrame("Animations/Player/strafeRight/keyFrame03.obj", 11644);
		animations.StrafeRight.addKeyFrame("Animations/Player/strafeRight/keyFrame04.obj", 11644);
		animations.StrafeRight.addKeyFrame("Animations/Player/strafeRight/keyFrame05.obj", 11644);
		animations.StrafeRight.addKeyFrame("Animations/Player/strafeRight/keyFrame06.obj", 11644);

		animations.Walking.addKeyFrame("Animations/Player/forwardWalking/keyFrame01.obj", 11644);
		animations.Walking.addKeyFrame("Animations/Player/forwardWalking/keyFrame02.obj", 11644);
		animations.Walking.addKeyFrame("Animations/Player/forwardWalking/keyFrame03.obj", 11644);
		animations.Walking.addKeyFrame("Animations/Player/forwardWalking/keyFrame04.obj", 11644);
		animations.Walking.addKeyFrame("Animations/Player/forwardWalking/keyFrame05.obj", 11644);
		animations.Walking.addKeyFrame("Animations/Player/forwardWalking/keyFrame06.obj", 11644);
		animations.Walking.addKeyFrame("Animations/Player/forwardWalking/keyFrame07.obj", 11644);
		animations.Walking.addKeyFrame("Animations/Player/forwardWalking/keyFrame08.obj", 11644);

		animations.WalkingBackward.addKeyFrame("Animations/Player/forwardWalking/keyFrame08.obj", 11644);
		animations.WalkingBackward.addKeyFrame("Animations/Player/forwardWalking/keyFrame07.obj", 11644);
		animations.WalkingBackward.addKeyFrame("Animations/Player/forwardWalking/keyFrame06.obj", 11644);
		animations.WalkingBackward.addKeyFrame("Animations/Player/forwardWalking/keyFrame05.obj", 11644);
		animations.WalkingBackward.addKeyFrame("Animations/Player/forwardWalking/keyFrame04.obj", 11644);
		animations.WalkingBackward.addKeyFrame("Animations/Player/forwardWalking/keyFrame03.obj", 11644);
		animations.WalkingBackward.addKeyFrame("Animations/Player/forwardWalking/keyFrame02.obj", 11644);
		animations.WalkingBackward.addKeyFrame("Animations/Player/forwardWalking/keyFrame01.obj", 11644);

	
		animations.Shooting.addKeyFrame("Animations/Player/shooting/v2playershoot1.obj", 11644);
		animations.Shooting.addKeyFrame("Animations/Player/shooting/v2playershoot2.obj", 11644);
		animations.Shooting.addKeyFrame("Animations/Player/shooting/v2playershoot3.obj", 11644);
		animations.Shooting.addKeyFrame("Animations/Player/shooting/v2playershoot4.obj", 11644);

		animations.Death.addKeyFrame("Animations/Player/death/dying1.obj", 11644);
		animations.Death.addKeyFrame("Animations/Player/death/dying2.obj", 11644);
		animations.Death.addKeyFrame("Animations/Player/death/dying3.obj", 11644);
		animations.Death.addKeyFrame("Animations/Player/death/dying4.obj", 11644);
		animations.Death.addKeyFrame("Animations/Player/death/dying5.obj", 11644);
		animations.Death.loop = false;

		/*
		animations.StillFrame.addKeyFrame("Animations/Player/stillFrame/keyFrame01.obj", 2862);

		animations.Aiming.addKeyFrame("Animations/Player/aiming/keyFrame01.obj", 2862);
		animations.Aiming.addKeyFrame("Animations/Player/aiming/keyFrame02.obj", 2862);*/

	}

	void updateAnimations(float dt)
	{

		//////************player animation*******************//
		
		//death
		if(!alive)
		{
			animations.Death.animate(5, theModel, dt);
		}
		//idle
		else if(state.idle || state.fp || dialogue || state.aiming)
		{
			animations.Idle.animate(7, theModel, dt);
		}
		 ///////if jumping////////
		else if(input.space && !state.fp)
		{
			animations.Jumping.animate(6, theModel, dt);
		}
		//  ///////if shooting////////
		else if(input.Lmouse && !state.fp && !dialogue)
		{
			animations.Shooting.animate(4, theModel, dt);
		}
		//  ///////if strafing right////////
		else if(input.d && !state.fp && !dialogue)
		{
			animations.StrafeRight.animate(6, theModel, dt);
		}
		///////if strafing left////////
		else if(input.a && !state.fp && !dialogue)
		{
			animations.StrafeLeft.animate(6, theModel, dt);
		}
		////	 ///////if walking backwards////////
		else if(input.s && !state.fp && !dialogue)
		{
			animations.WalkingBackward.animate(8, theModel, dt);
		}
		//if walking forward
		else if(input.w && !state.fp && !dialogue)
		{
			animations.Walking.animate(8, theModel, dt);
		}

	}

	void drawCharacter(/*cbmini::cbfw::GLSLProgram *ShaderProgram*/ Shader *shader)
	{
		
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		glTranslatef(position[0], position[1] - 7.0f, position[2]);
		glScalef(1.2f, 1.2f, 1.2f); //1.2
		////handles when the player is idle, camera rotates around player
		if(((!state.idle && !dialogue) || ((state.fp || playerMove) && (!state.tp)) || state.aiming) && (alive))
		{
			glRotatef(theta, 0, 1, 0);
			state.theta = theta;
		}
		else
		{
			glRotatef(state.theta, 0, 1, 0);
		}

		//draw the player's character 
		glColor3f(1.0f, 1.0f, 1.0f);
		//textures
		//glUniform1i(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "my_color_texture"), 0);
		theTexture1->drawTex(0);
		theModel->drawModel();

		glPopMatrix();
		glEnable(GL_CULL_FACE);
	}

	void checkForDamages(std::list<projectile>& toUpdate, float dt)
	{
		std::list<projectile>::iterator i = toUpdate.begin();

		for(std::list<projectile>::iterator i = toUpdate.begin(); i != toUpdate.end();)
		{		
			//if the npc and the bullet is colliding and the npc is not the parent
			if (cObject.collisionTest(&i->theObject)  && !(i->node.checkParent(&node)))
			{
				isHostile = true;

				//play doesn't take damage in cut scenes
				if(playerMove)
				{
					health = health - 20;
				}
				//cout << health << endl; //##################################################################

				//erase the object
				i = toUpdate.erase(i);

				//kill the npc
				if (health <= 0)
				{
					//point at which you would respawn
					alive = false;
				}
			}
			else //no collision is detected therefore increment
			{
				i++;
			}
		}

		//Re-generating health
		timeDelay += dt;

		if(timeDelay > 2.5f && health < 100 && alive)
		{
			health += 5; 
			timeDelay = 0.0; 
		}

	}

};