#pragma once
#include "texture.h"
#include "MathClass.h"
#include "player.h"

class SkyBox
{
public:
	SkyBox()
	{
		pos = Vec3f();
		scale = 1.0f;
	}
	SkyBox(Vec3f Pos)
	{
		pos = Pos;
		scale = 1000.0f;

	}
	~SkyBox(){}

	void initSkyBox()
	{
		SkyTex[0] = new tex();
		SkyTex[0]->loadTex("Images/SkyBox/FullMoonBack.jpg");
		SkyTex[1] = new tex();
		SkyTex[1]->loadTex("Images/SkyBox/FullMoonFront.jpg");
		SkyTex[2] = new tex();
		SkyTex[2]->loadTex("Images/SkyBox/FullMoonRight.jpg");
		SkyTex[3] = new tex();
		SkyTex[3]->loadTex("Images/SkyBox/FullMoonLeft.jpg");
		//SkyTex[4] = new tex();
		//SkyTex[4]->loadTex("Images/SkyBox/FullMoonUp.png");
	}

	void drawSkyBox()
	{
		//glDisable(GL_FOG);
		glDisable(GL_LIGHTING);
		glDepthMask(false);

		glPushMatrix();
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTranslatef(pos[0], pos[1], pos[2]);

		//back
		SkyTex[0]->drawTex(0);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(scale,-scale,-scale);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(scale,scale,-scale);	
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-scale,scale,-scale);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-scale,-scale,-scale);
		glEnd();
		

		//front 
		SkyTex[1]->drawTex(0);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-scale,-scale,scale);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-scale,scale,scale);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(scale,scale,scale);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(scale,-scale,scale);
		glEnd();
	
		//left side
		SkyTex[2]->drawTex(0);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(scale,scale,scale);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(scale,scale,-scale);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(scale,-scale,-scale);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(scale,-scale,scale);
		glEnd();
	

		//right side
		SkyTex[3]->drawTex(0);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-scale,scale,-scale);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-scale,scale,scale);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-scale,-scale,scale);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-scale,-scale,-scale);
		glEnd();

		////top side
		//SkyTex[4]->drawTex(0);
		//glNormal3f(0.0f, -1.0f, 0.0f);
		//glVertex3f(-scale/2,scale/2,scale/2);
		//glVertex3f(scale/2,scale/2,scale/2);
		//glVertex3f(scale/2,scale/2,-scale/2);
		//glVertex3f(-scale/2,scale/2,-scale/2);
	
	
		////bottom side
		//glVertex3f(-scale/2,-scale/2,-scale/2);
		//glVertex3f(scale/2,-scale/2,-scale/2);
		//glVertex3f(scale/2,-scale/2,-scale/2);
		//glVertex3f(-scale/2,-scale/2,scale/2);


		glPopMatrix();
		//glEnable(GL_FOG);
		glEnable(GL_LIGHTING);
		glDepthMask(true);
	}

	void updateSkyBox(Vec3f playerPos)
	{
		pos = playerPos; 
	}

	Vec3f pos;
	float scale;

	tex *SkyTex[4]; 
};

