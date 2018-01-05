#pragma once
#include <list>
#include "ShaderInit.h"
#include "Include/SFML/Graphics.hpp"
#include "Include/SFML/OpenGL.hpp"
#include "texture.h"
#include "MathClass.h"
#include "pcNode.h"
#include "Collision.h"
#include "particleEngine.h"

////////////////////////////////////////////////////////////////
//load bullet texture only once
static tex *bulletTex;

inline void loadBulletTex()
{
	bulletTex = new tex();
	bulletTex->loadTex("Images/Particles/fireParticle1.png");
}
////////////////////////////////////////////////////////////////

class projectile
{
public:

	projectile()
	{
	}

	void setProjectile(Vec3f DirVec, Vec3f Pos, float speed, float size, float yOffset, pcNode* theParent, tex *texture)
	{
		projectilePos[0] = Pos[0];
		projectilePos[1] = Pos[1] + yOffset;
		projectilePos[2] = Pos[2];
		this->size = size / 2.0f;
		this->speed = speed;
		this->directionVector = DirVec;
		theObject = collisionObject(1.0f, projectilePos, speed, true);
		node = pcNode(theParent);
		//theTex = texture;
		theTex = bulletTex; 
		theta = 0.0f;
		collide = false;
		end = false;
		initialize = true;

		time = 0.0f;
		particleLife = 0.5f;

		bulletParticles = new ParticleManager();
		bulletParticles->setVerlocityRand(Vec3f(-10, -10, -10), Vec3f(10, 10, 10));
		bulletParticles->setLifeTrans(true);
		bulletParticles->loadTex(bulletTex);
	}

	Vec3f directionVector;
	Vec3f projectilePos;
	float speed;
	float size;
	bool end, collide;	//collide is when bullet collides with object, this lets us know when we need to starts drawing and updating particle system;
						//end is when the particle system is done playing
	bool initialize; //initialize the particle elements
	collisionObject theObject;

	//parent child relationships
	pcNode node;

	tex *theTex;
	float theta;

	//particle upon collision for bullets
	ParticleManager *bulletParticles;
	float particleLife;
	float time; 
};

//draws the projectile in the draw function
static void drawProjectile(std::list<projectile> toDraw, Shader *shader)
{
	glPushMatrix();
	shader->Particle_Shader->Activate();
	glEnable(GL_BLEND);	//particles must have the background as transparent and must be in png format
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	//first parameter is the pixel you are currently drawing and second parameter is the old pixel

	for(std::list<projectile>::iterator i = toDraw.begin(); i != toDraw.end();)
	{
		//do not draw projectile if collision has occured, its now time to draw the particle system
		if(!i->collide)
		{
			glUniform1f(glGetUniformLocation(shader->Particle_Shader->GetHandle(), "size"), i->size);
			glUniform1f(glGetUniformLocation(shader->Particle_Shader->GetHandle(), "alpha"), 1.0f);

			i->theTex->drawTex(0); 
			glBegin(GL_POINTS);
				glVertex3f(i->projectilePos[0], i->projectilePos[1], i->projectilePos[2]);
			glEnd();
		}
		else
		{
			i->bulletParticles->drawParticles(shader->Particle_Shader);
		}
		i++;
	}	
	glDisable(GL_BLEND);
	shader->Particle_Shader->Deactivate();
	glPopMatrix();
}

//updates the projectile in the update function
static void updateProjectile(std::list<projectile>& toUpdate, collisionObject* theMask, float playerTheta, float dt, Vec3f cameraPos)
{
	for(std::list<projectile>::iterator i = toUpdate.begin(); i != toUpdate.end();)
	{
		//do not update projectile if collision has occured, its now time to update the particle system
		if(!i->collide)
		{
			i->theta = playerTheta - 180.0f;

			i->projectilePos[0] += i->speed * i->directionVector[0];
			i->projectilePos[1] += i->speed * i->directionVector[1]; 
			i->projectilePos[2] += i->speed * i->directionVector[2]; 

			i->theObject.updateCollisionObject(i->directionVector,i->speed,i->projectilePos);
		}
		else
		{
			//must inlialize particle with updated position
			if(i->initialize)
			{
				i->bulletParticles->setAtrributes(Vec3f(5.0f, 5.0f, 5.0f), Vec3f(1,1,1),i->projectilePos, Vec3f(0,-9.8f,0), 1.0, 1.0f, i->particleLife, 1, 8, true);
				i->initialize = false;
			}

			//update particle system upon collision
			if(dt < 1.0f)
			{
				i->bulletParticles->updateParticles(dt, playerTheta, cameraPos);

				i->time += dt;
			}
			//if the time is greater than the particle system life, it is time to fully delete the projectile from the list
			if(i->time > i->particleLife)
			{
				i->end = true;
			}
		}

		//Check collision so that if it hits a wall, it clears that bullet from the list
		if(i->collide)
		{
			if(i->end)
			{
				i = toUpdate.erase(i);
			}
			else
			{
				i++;
			}
		}
		else if(i->theObject.collisionTest(theMask))
		{
			//i = toUpdate.erase(i);
			i->collide = true;
			i++;
		}
		else
		{
			i++;
		}

		
	}		
}