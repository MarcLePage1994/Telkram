#pragma once
#include "texture.h"
#include <list>
#include "MathClass.h"
#include "Include/SFML/Graphics.hpp"
#include "Include/SFML/OpenGL.hpp"


//holds the data for each individual particle
struct Particle
{
	bool m_isAlive;		
	float m_lifeTime;		//if lifeTime is less than or equal to -1, then lifeTime is infinite
	float m_transparency;	//percentage from 0 to 1, with 0 being empty and 1 being completly full
	Vec3f m_size;
	Vec3f m_pos;
	Vec3f m_vel;
	Vec3f m_force;		//force being applied to the particle
	Vec3f m_acceleration; // acceleration = force / mass
	float m_mass;		//must be greater than 0;
	int m_numLives;	//if numLives is less than or equal to 0, then numLives is infinite
	float dist; //particle distance to player
};

//for sorting the particles
inline bool CompareParticles(Particle p1, Particle p2)
{
	if(p1.dist > p2.dist)
	{
		return true;
	}

	return false;
}

//handles all of the particles
//applies forces, calls particle update at each iteration
class ParticleManager
{
public:
	ParticleManager()
	{
		m_theta = 0;
		updatedIntialPos = Vec3f(0,0,0);
		verRandFrom = Vec3f(1,1,1);
		verRandTo = Vec3f(1,1,1);
		posRandFrom = Vec3f(1,1,1); 
		posRandTo = Vec3f(1,1,1);
		lifeTrans = true;
		particleTex = new tex();
		updateSize = false;
		spawnAtPos = false;
		Vec3f spawnColl = Vec3f(0.0f, 0.0f, 0.0f); 
		sort = false;
	}

	//sets the particle system's elements
	void setAtrributes(Vec3f verlocity, Vec3f size, Vec3f position, Vec3f force, float transparency, float mass, float lifeTime, int numLives, int numParticles, bool sortParticles)
	{
		sort = sortParticles;

		Particle currentParticle;
		Particle intialParticle;
		
		for(int i = 0; i < numParticles; i++)
		{
			intialParticle.m_isAlive = currentParticle.m_isAlive = true;		
			intialParticle.m_lifeTime = currentParticle.m_lifeTime = lifeTime; //+ (rand()%5 / (1+rand()%3));		
			intialParticle.m_transparency = currentParticle.m_transparency = transparency;
			intialParticle.m_size = currentParticle.m_size = Vec3f(size[0]/2.0f, size[1]/2.0f, size[2]/2.0f);
			intialParticle.m_force = currentParticle.m_force = force;
			intialParticle.m_mass = currentParticle.m_mass = mass;		
			intialParticle.m_numLives = currentParticle.m_numLives = numLives;	
			intialParticle.m_acceleration[0] = currentParticle.m_acceleration[0] = force[0] / mass;
			intialParticle.m_acceleration[1] = currentParticle.m_acceleration[1] = force[1] / mass;
			intialParticle.m_acceleration[2] = currentParticle.m_acceleration[2] = force[2] / mass;

			//if the particles postion is not suppose to be randomized
			if(posRandFrom == Vec3f(1,1,1) && posRandTo == Vec3f(1,1,1))
			{
				intialParticle.m_pos = currentParticle.m_pos = position; 
			}
			//if the particles postion is suppose to be randomized
			else
			{
				intialParticle.m_pos = currentParticle.m_pos = position + Vec3f(posRandFrom[0] + rand() % (int)posRandTo[0], posRandFrom[1] + rand() % (int)posRandTo[1], posRandFrom[2] + rand() % (int)posRandTo[2]);
			}
			//if the particles verlocity is not suppose to be randomized
			if(verRandFrom == Vec3f(1,1,1) && verRandTo == Vec3f(1,1,1))
			{
				intialParticle.m_vel = currentParticle.m_vel = verlocity; 
			}
			//if the particles verlocity is suppose to be randomized
			else
			{
				intialParticle.m_vel = currentParticle.m_vel = verlocity + Vec3f(verRandFrom[0] + rand() % (int)verRandTo[0], verRandFrom[1] + rand() % (int)verRandTo[1], verRandFrom[2] + rand() % (int)verRandTo[2]);
			}
			
			particleSystem.push_back(currentParticle);
			intialParticles.push_back(intialParticle);
		}
	}

	//draws/renders the particles to the screen
	void drawParticles(cbmini::cbfw::GLSLProgram *ShaderProgram)
	{
		glPushMatrix();
		particleTex->drawTex(0);

		for(std::list<Particle>::iterator i = particleSystem.begin(); i != particleSystem.end();)
		{
			glUniform1f(glGetUniformLocation(ShaderProgram->GetHandle(), "size"), i->m_size[0]);
			glUniform1f(glGetUniformLocation(ShaderProgram->GetHandle(), "alpha"), i->m_transparency);
			
			glBegin(GL_POINTS);
				glVertex3f(i->m_pos[0], i->m_pos[1], i->m_pos[2]);
			glEnd();
			i++;
		}
		glPopMatrix();
	}

	//updates the particles
	void updateParticles(float dt, float cameraTheta, Vec3f cameraPos)
	{ 
		if(dt < 1.0f)
		{
			m_theta = cameraTheta - 180.0f;

			std::list<Particle>::iterator k = intialParticles.begin();
			for(std::list<Particle>::iterator i = particleSystem.begin(); i != particleSystem.end();)
			{
				i->m_lifeTime -= dt;
				i->dist = (cameraPos - i->m_pos).magnitude();

				//no more lives
				if(spawnAtPos)
				{
					if(i->m_pos[1] <= spawnColl[1])
					{
						if(i->m_numLives <= 1 && i->m_numLives > 0)
						{
							i->m_isAlive = false;
							i = particleSystem.erase(i);	
							k = intialParticles.erase(k);
						}
				
						//respawn the particle
						else
						{
							i->m_numLives--;
							i->m_lifeTime			=		k->m_lifeTime;		
							i->m_transparency		=		k->m_transparency;
							i->m_size				=		k->m_size;
							//i->m_pos				=		k->m_pos;
							i->m_vel				=		k->m_vel;
							i->m_force				=		k->m_force;
							i->m_mass				=		k->m_mass;		
							i->m_acceleration[0]	=		k->m_acceleration[0];
							i->m_acceleration[1]	=		k->m_acceleration[1];
							i->m_acceleration[2]	=		k->m_acceleration[2];

							if(posRandFrom == Vec3f(1,1,1) && posRandTo == Vec3f(1,1,1))
							{
								i->m_pos	=		k->m_pos;
							}
							//if the particles postion is suppose to be randomized
							else
							{
								i->m_pos = k->m_pos + Vec3f(posRandFrom[0] + rand() % (int)posRandTo[0], posRandFrom[1] + rand() % (int)posRandTo[1], posRandFrom[2] + rand() % (int)posRandTo[2]);
							}
						}
					}
				}
				//this is when the particle has died
				else if(i->m_lifeTime < 0 /*&& i->m_lifeTime > -1*/)
				{
				
					if(i->m_numLives <= 1 && i->m_numLives > 0)
					{
						i->m_isAlive = false;
						i = particleSystem.erase(i);	
						k = intialParticles.erase(k);
					}

					//respawn the particle
					else
					{
						i->m_numLives--;
						i->m_lifeTime			=		k->m_lifeTime;		
						i->m_transparency		=		k->m_transparency;
						i->m_size				=		k->m_size;
						//i->m_pos				=		k->m_pos;
						i->m_vel				=		k->m_vel;
						i->m_force				=		k->m_force;
						i->m_mass				=		k->m_mass;		
						i->m_acceleration[0]	=		k->m_acceleration[0];
						i->m_acceleration[1]	=		k->m_acceleration[1];
						i->m_acceleration[2]	=		k->m_acceleration[2];

						if(posRandFrom == Vec3f(1,1,1) && posRandTo == Vec3f(1,1,1))
						{
							i->m_pos	=		k->m_pos;
						}
						//if the particles postion is suppose to be randomized
						else
						{
							i->m_pos = k->m_pos + Vec3f(posRandFrom[0] + rand() % (int)posRandTo[0], posRandFrom[1] + rand() % (int)posRandTo[1], posRandFrom[2] + rand() % (int)posRandTo[2]);
						}

					}
				
				}

				//update the particle
				if(i->m_isAlive)
				{
					i->m_pos += (i->m_vel *dt) + (((i->m_acceleration * 0.5f) * (dt *dt)));
					i->m_vel += i->m_acceleration * dt;	
				
					if(updatedIntialPos[0] != 0 && /*updatedIntialPos[1] != 0 &&*/ updatedIntialPos[2] != 0)
					{
						k->m_pos = updatedIntialPos; 
					}	
				
					//i->m_lifeTime -= dt;

					//cout << i->m_lifeTime << endl; //###########################################################

					//if true
					if(lifeTrans)
					{
						i->m_transparency -= (dt / k->m_lifeTime);
					}

					if(updateSize)
					{
						if(i->m_size[0] > 0.0f && i->m_size[1] > 0.0f && i->m_size[2] > 0.0f)
						{
							i->m_size[0] -= (dt / k->m_lifeTime);
							i->m_size[1] -= (dt / k->m_lifeTime);
							i->m_size[2] -= (dt / k->m_lifeTime);
						}
					}
				
					k++;
					i++;
				}	
			}

			//sort the particles so they render better
			if(sort)
			{
				particleSystem.sort(CompareParticles);
			}
		}
	}

	//updates the starting point where the particles spawn
	void updateIntialPos(Vec3f pos)
	{
		updatedIntialPos = pos;
	}

	void updateParticleSize(bool update)
	{
		updateSize = update;
	}

	//set the random postion values
	void setPositionRand(Vec3f from, Vec3f to)
	{
		posRandFrom = from;
		posRandTo = to;
	}

	//sets the random verlocity values
	void setVerlocityRand(Vec3f from, Vec3f to)
	{
		verRandFrom = from;
		verRandTo = to;
	}

	void setLifeTrans(bool lifeOpac)
	{
		lifeTrans = lifeOpac;
	}

	void setCollisionPos(Vec3f Pos)
	{
		spawnAtPos = true;
		spawnColl = Pos;
	}

	void loadTex(const std::string &filename)
	{
		particleTex->loadTex(filename);
	}

	void loadTex(tex *texture)
	{
		particleTex = texture;
	}

	

private:
	bool spawnAtPos;
	Vec3f spawnColl; 
	bool updateSize;
	list<Particle> particleSystem;
	list<Particle> intialParticles;
	int m_numParticles;
	float m_theta;	//the theta/orientation of the particles in relation to the player/camera. 
	Vec3f updatedIntialPos;	//the updated intial postion of the particle
	Vec3f verRandFrom;
	Vec3f verRandTo;
	Vec3f posRandFrom;
	Vec3f posRandTo;
	bool lifeTrans; //sets whether or not the particle gets transparent while it gets closer to death
	tex *particleTex;
	bool sort; 
};

