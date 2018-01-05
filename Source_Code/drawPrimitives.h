#pragma once
#include "Include/SFML/Graphics.hpp"
#include "Include/SFML/OpenGL.hpp"

class drawPrimitives
{
public:
	drawPrimitives()
	{
	}

	~drawPrimitives()
	{
	}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
	void drawPyramid(float side,float height)
	{
		glBegin(GL_QUADS);
			//furthermost left point
			glVertex3f(-side/2,0,-side/2);
			glVertex3f(side/2,0,-side/2);
			glVertex3f(side/2,0,side/2);
			glVertex3f(-side/2,0,side/2);
		glEnd();

		glBegin(GL_TRIANGLES);
			//front face
			glVertex3f(0,height, 0);
			glVertex3f(-side/2,0,-side/2);
			glVertex3f(side/2,0,-side/2);

			//left face
			glVertex3f(0,height, 0);
			glVertex3f(-side/2,0,side/2);
			glVertex3f(-side/2,0,-side/2);
		
			//right face
			glVertex3f(0,height, 0);
			glVertex3f(side/2,0,-side/2);
			glVertex3f(side/2,0,side/2);
		
			//back face
			glVertex3f(0,height, 0);
			glVertex3f(side/2,0,side/2);
			glVertex3f(-side/2,0,side/2);
		
		glEnd();
	}

	void drawBox(float width,float height,float depth)
	{
		glBegin(GL_QUADS);

		//front
		glVertex3f(-width/2,-height/2,depth/2);
		glVertex3f(width/2,-height/2,depth/2);
		glVertex3f(width/2,height/2,depth/2);
		glVertex3f(-width/2,height/2,depth/2);

		//back 
		glVertex3f(-width/2,height/2,-depth/2);
		glVertex3f(width/2,height/2,-depth/2);
		glVertex3f(width/2,-height/2,-depth/2);
		glVertex3f(-width/2,-height/2,-depth/2);
	
		//left side
		glVertex3f(-width/2,height/2,depth/2);
		glVertex3f(-width/2,height/2,-depth/2);
		glVertex3f(-width/2,-height/2,-depth/2);
		glVertex3f(-width/2,-height/2,depth/2);
	

		//right side
		glVertex3f(width/2,-height/2,depth/2);
		glVertex3f(width/2,-height/2,-depth/2);
		glVertex3f(width/2,height/2,-depth/2);
		glVertex3f(width/2,height/2,depth/2);

		//top side
		glVertex3f(-width/2,height/2,depth/2);
		glVertex3f(width/2,height/2,depth/2);
		glVertex3f(width/2,height/2,-depth/2);
		glVertex3f(-width/2,height/2,-depth/2);
	
	
		//bottom side
		glVertex3f(-width/2,-height/2,-depth/2);
		glVertex3f(width/2,-height/2,-depth/2);
		glVertex3f(width/2,-height/2,-depth/2);
		glVertex3f(-width/2,-height/2,depth/2);

		glEnd();
	}

};

//////////////////////////////////////////////////////////////////////////////////////////////

inline void drawPyramid(float side,float height)
{
	glBegin(GL_QUADS);
		//furthermost left point
		glVertex3f(-side/2,0,-side/2);
		glVertex3f(side/2,0,-side/2);
		glVertex3f(side/2,0,side/2);
		glVertex3f(-side/2,0,side/2);
	glEnd();

	glBegin(GL_TRIANGLES);
		//front face
		glVertex3f(0,height, 0);
		glVertex3f(-side/2,0,-side/2);
		glVertex3f(side/2,0,-side/2);

		//left face
		glVertex3f(0,height, 0);
		glVertex3f(-side/2,0,side/2);
		glVertex3f(-side/2,0,-side/2);
		
		//right face
		glVertex3f(0,height, 0);
		glVertex3f(side/2,0,-side/2);
		glVertex3f(side/2,0,side/2);
		
		//back face
		glVertex3f(0,height, 0);
		glVertex3f(side/2,0,side/2);
		glVertex3f(-side/2,0,side/2);
		
	glEnd();
}

inline void drawBox(float width,float height,float depth)
{
	glBegin(GL_QUADS);

	//front
	glVertex3f(-width/2,-height/2,depth/2);
	glVertex3f(width/2,-height/2,depth/2);
	glVertex3f(width/2,height/2,depth/2);
	glVertex3f(-width/2,height/2,depth/2);

	//back 
	glVertex3f(-width/2,height/2,-depth/2);
	glVertex3f(width/2,height/2,-depth/2);
	glVertex3f(width/2,-height/2,-depth/2);
	glVertex3f(-width/2,-height/2,-depth/2);
	
	//left side
	glVertex3f(-width/2,height/2,depth/2);
	glVertex3f(-width/2,height/2,-depth/2);
	glVertex3f(-width/2,-height/2,-depth/2);
	glVertex3f(-width/2,-height/2,depth/2);
	

	//right side
	glVertex3f(width/2,-height/2,depth/2);
	glVertex3f(width/2,-height/2,-depth/2);
	glVertex3f(width/2,height/2,-depth/2);
	glVertex3f(width/2,height/2,depth/2);

	//top side
	glVertex3f(-width/2,height/2,depth/2);
	glVertex3f(width/2,height/2,depth/2);
	glVertex3f(width/2,height/2,-depth/2);
	glVertex3f(-width/2,height/2,-depth/2);
	
	
	//bottom side
	glVertex3f(-width/2,-height/2,-depth/2);
	glVertex3f(width/2,-height/2,-depth/2);
	glVertex3f(width/2,-height/2,-depth/2);
	glVertex3f(-width/2,-height/2,depth/2);

	glEnd();
}