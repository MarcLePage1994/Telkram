#include "Collision.h"
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////    Circles    ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Circle::Circle()
{
	//x = z = 0.0f;
	Pos = Vec3f();
	radius = 10.0f;
}

void Circle::SetRadius(float radius)
{
	this->radius = radius;
}

void Circle::SetPosition(float x, float y, float z)
{
	//this->x = x;
	//this->z = z;
	Pos = Vec3f(x, y, z);
}

void Circle::SetPosition(Vec3f newPos)
{
	Pos = newPos;
}

bool Circle::CollisionTest(Circle& other, float theSpeed, Vec3f theVector)
{
	float magnitude;

	//grab magnitude 
	Vec3f tempVec = theVector * theSpeed;
	magnitude = tempVec.magnitude();
	
	float distance;

	//subtract the two from each other, and take in to account the magnitude of each vector component
	//distance = sqrt(pow(x - other.x + tempVec[0], 2.0f) + pow(z - other.z + tempVec[2], 2.0f));
	distance = sqrt(pow(Pos[0] - other.Pos[0] + tempVec[0], 2.0f) + pow(Pos[1] - other.Pos[1] + tempVec[1], 2.0f) + pow(Pos[2] - other.Pos[2] + tempVec[2], 2.0f));

	if(distance > radius + other.radius + magnitude) {return false;}

	return true;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////    Boxes    //////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

Box::Box()
{
	x = z = 0.0f;
	scaleX = scaleZ = 10.0f;
}

void Box::SetScale(float scaleX, float scaleY)
{
	this->scaleX = scaleX/2.0f;
	this->scaleZ = scaleZ/2.0f;
}

void Box::SetPosition(float x, float y)
{
	this->x = x;
	this->z = z;
}

bool Box::CollisionTest(Box& other, float theSpeed, Vec3f theVector)
{
	int xOffset = (int)theSpeed * (int)theVector[0]; //grab the current movement vector in the x 
	int zOffset = (int)theSpeed * (int)theVector[2]; //grab the current movement vector in the y

	float distance;

	//Are the boxes too far apart on the x axis?
	distance = abs(x - other.x);
	if(distance > scaleX+other.scaleX + xOffset) {return false;}

	//Are the boxes too far apart on the y axis?
	distance = abs(z - other.z);
	if(distance > scaleZ+other.scaleZ + zOffset) {return false;}

	//They overlap on both axis, they must be colliding
	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////    Masks    //////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

//creates empty mask
Mask::Mask()
{
	//create automatic scaling
	/*autoScale = Vec3f(0.6f, 0.0, 0.6f);

	scaleX = scaleX * autoScale[0];
	scaleZ = scaleZ * autoScale[2];
	scaleY = 1.f; 

	startingOffset[0] = startingPosition[0] * scaleX;
	startingOffset[1] = startingPosition[1] * scaleY;
	startingOffset[2] = startingPosition[2] * scaleZ;*/
}
Mask::Mask(string fileName)
{
	trackMask.loadFromFile(fileName);
	maskTex.loadTex(fileName);
}
//Loads the trackMask file
Mask::Mask(string fileName, Vec3f startingPosition, float xScale, float zScale, Vec3f AutoScale)
{
	trackMask.loadFromFile(fileName);
	maskTex.loadTex(fileName);

	maskSizeX = (float)trackMask.getSize().x; //x will suffice since images will be rectangular for now
	maskSizeY = (float)trackMask.getSize().y;

	startingOffset = startingPosition;

	//create automatic scaling
	autoScale = AutoScale; //Vec3f(0.725f, 0.0, 0.725f);

	scaleX = xScale * autoScale[0];
	scaleZ = zScale * autoScale[2];
	scaleY = 1.0f * autoScale[1];
}

//destructor for mask
Mask::~Mask()
{

}

void Mask::draw()
{
	glPushMatrix();

	maskTex.drawTex(0);
	_textureID = maskTex.texture;
	
	glTranslatef(0.f,-8.f,0.f);
	glScalef(scaleX, 0, scaleZ);
	
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);	
	glVertex3f(0, 0.0f, maskSizeY);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(maskSizeX, 0.0f,maskSizeY);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(maskSizeX, 0.0f, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.0f, 0);
	
	glEnd();
	glPopMatrix();

}

//THIS ONLY WORKS IF THE LEVEL SIZE IS THE SAME AS THE MASK SIZE
bool Mask::collisionCheck(Vec3f theVector, float theSpeed, Vec3f thePosition, Mask& theMask) //the y coordinate in this case is actually
{
	float xOffset = theSpeed * theVector[0]; //grab the current movement vector in the x 
	float zOffset = theSpeed * theVector[2]; //grab the current movement vector in the y

	//#########################################################################################################################################################
	//cout << "X: " << (thePosition[0] + xOffset + theMask.startingOffset[0] * theMask.scaleX)/ theMask.scaleX << endl;
	//cout << "Z: " << (thePosition[2]+ zOffset + theMask.startingOffset[2] * theMask.scaleZ)/ theMask.scaleZ << endl << endl;

	//grab the colour that the character would move towards along the x and z axis. 
	//Grabs the players position plus where they are moving towards. then, you take the offset of the level to the image times the scale. and then all of it is divided by image scale to get the pixel location
	if (theMask.trackMask.getPixel(int((thePosition[0]/theMask.scaleX) + xOffset), int((thePosition[2]/theMask.scaleZ)+ zOffset)).r > 128)
	{

		return true;
	}
	else 
	{
		return false;
	}
}

bool Mask::squareCheck(Vec3f thePosition, Mask &theMask)
{
	//checks the pixel at the position only
	//return true if square is white (collision square)
	if (theMask.trackMask.getPixel(int(thePosition[0]/theMask.scaleX), int(thePosition[2]/theMask.scaleZ)).r > 128)
	{
		return true;
	}
	//return false if square is black (non-collision square)
	else 
	{
		return false;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////   CONE VISION  ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
Cone::Cone()
{
	centerPos = new Point();	
	rightPos = new Point();	
	leftPos = new Point();	
}

Cone::Cone(Vec3f negX, Vec3f posX, Vec3f posZ, Vec3f Size, Vec3f CenterPos)
{
	centerPos = new Point();	
	rightPos = new Point();	
	leftPos = new Point();		

	size = Size;
	update(negX, posX, posZ, CenterPos);
}

Cone::~Cone()
{
}

void Cone::update(Vec3f negX, Vec3f posX, Vec3f posZ, Vec3f CenterPos)
{
	centerPos->position =  CenterPos;

	Vec3f dirRight = (posX + posZ).normalize();
	Vec3f dirLeft = (negX + posZ).normalize();

	dirRight *= size;
	dirLeft *= size;

	rightPos->position = dirRight + centerPos->position;
	leftPos->position = dirLeft + centerPos->position; 

	coneCenter = Vec3f((centerPos->position[0] + rightPos->position[0] + leftPos->position[0]) / 3.0f, (centerPos->position[1] + rightPos->position[1] + leftPos->position[1]) / 3.0f, (centerPos->position[2] + rightPos->position[2] + leftPos->position[2]) / 3.0f);
}

bool Cone::collisionTest(Vec3f position, float radius)
{
	vector<Point*> A;

	//we first must calulate which 2 points are the closest
	centerPos->rank = (position - centerPos->position).magnitude();
	rightPos->rank = (position - rightPos->position).magnitude();
	leftPos->rank = (position - leftPos->position).magnitude();

	A.push_back(centerPos);
	A.push_back(rightPos);
	A.push_back(leftPos);

	//sort the list from the smalles rank to the largest (bubblesort)
	//*******************SORT*********************************************//
	//bubble sort
	for(unsigned int counter = 0; counter < A.size(); counter++)
	{
		unsigned int countEnd = A.size() - 1;

		while(countEnd > counter)
		{
			if(A[countEnd]->rank < A[countEnd - 1]->rank)
			{
				Point *temp;
				temp = new Point();

				temp = A[countEnd];

				A[countEnd] = A[countEnd - 1];
				A[countEnd - 1] = temp;

				temp = NULL;
				delete temp;

			}
			countEnd--;
		}

	}

	Vec3f start = A[0]->position;
	Vec3f end = A[1]->position;

	//determine if i need to switch start and end to get the proper start and end line points
	if(start == centerPos->position)
	{
	}
	else if(end == centerPos->position)
	{
		Vec3f temp = start;
		start = end;
		end = temp;
	}

	//do line collision between these two points
	Vec3f lineStartToEnd = end - start;				//the vector from the start to the end point
	if(lineStartToEnd[0] + lineStartToEnd[1] + lineStartToEnd[2] < 0.0f)
	{
		Vec3f temp = start;
		start = end;
		end = temp;

		lineStartToEnd = end - start;	
	}

	Vec3f lineDir = lineStartToEnd.normalize();		//the direction of the line
	Vec3f lineStartToPos = position - start;		//the vector from the start point of the line to the center of the object

	float pointTest = lineStartToPos.dot(lineStartToEnd) / lineStartToEnd.magnitude();
	
	Vec3f closestPoint;
	if(pointTest < 0.0f)
	{
		closestPoint = start;
	}
	else if(pointTest > lineStartToEnd.magnitude())
	{
		closestPoint = end;
	}
	else
	{
		//Vector projection
		closestPoint = start + (lineDir * lineStartToPos.dot(lineDir));	//the the closet point on the line in relation to the the center of the object
	}
	
	tRadius = (closestPoint - coneCenter).magnitude();

	float length = (position - closestPoint).magnitude();	//the distance from the closet point to the center of the object

	if(length < radius + tRadius)	//if the distance is less than or equal to the radius then a collision has occured
	{
		return true;
	}
	
	return false;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////   CollisionObjects   /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//this sets nothing as the collision object
collisionObject::collisionObject()
{
	dirVec = Vec3f();
	speed = 0.f;
	position = Vec3f();
	collisionType = 0; 
}

//this sets a circle as the collision object
collisionObject::collisionObject(float radius, Vec3f startingPosition, float startingSpeed, bool posUpdate)
{
	theCircle.SetRadius(radius);
	theCircle.SetPosition(startingPosition[0], startingPosition[1], startingPosition[2]);
	collisionType = 1;

	dirVec = Vec3f();
	speed = startingSpeed;
	position = startingPosition;

	updatePos = posUpdate; 
}

//This sets a binding box as the collision object
collisionObject::collisionObject(float x, float z, Vec3f startingPosition, float startingSpeed, bool posUpdate)
{
	theBox.SetScale(x, z);
	theBox.SetPosition(startingPosition[0], startingPosition[2]);
	collisionType = 2;

	dirVec = Vec3f();
	speed = startingSpeed;
	position = startingPosition;

	updatePos = posUpdate; 
}

//This sets a collisionMask as the collision object
collisionObject::collisionObject(string fileName, Vec3f startingOffset, float startingSpeed, float xScale, float zScale, Vec3f AutoScale)
{
	theMask = Mask(fileName, startingOffset, xScale, zScale, AutoScale);
	
	dirVec = Vec3f();
	speed = startingSpeed;

	//mask collision objects are always located at 0,0. Instead, we apply an offset to them. 
	position = Vec3f(0.0f,0.0f,0.0f);
	collisionType = 3;

	updatePos = false; 

}

//This sets a collisionMask as the cone vision object
collisionObject::collisionObject(Vec3f negX, Vec3f posX, Vec3f posZ, Vec3f Size, Vec3f CenterPos)
{
	theCone = Cone(negX, posX, posZ, Size, CenterPos);

	collisionType = 4;
	updatePos = true;
}

collisionObject::~collisionObject()
{

}

//none of this code is right as it requires input from the game to work
bool collisionObject::collisionTest(std::list<collisionObject*>& collisionList)
{
	for (std::list<collisionObject*>::iterator i = collisionList.begin(); i != collisionList.end(); i++)
	{
		//check to see if its the same memory location and do nothing if it is
		if (this == (*i))
		{
			//skip over it
			//cout << "memory location hit" << endl;
		}
		else 
		{
			//If both collisions are circles
			if (collisionType == 1 && (*i)->collisionType == 1)
			{
				if(theCircle.CollisionTest((*i)->theCircle,speed,dirVec)) {return true;}
			}
			//if both collisions are boxes
			else if (collisionType == 2 && (*i)->collisionType == 2)
			{
				if(theBox.CollisionTest((*i)->theBox,speed,dirVec)) {return true;}
			}
			//point to a collision Mask
			else if (collisionType == 1 && (*i)->collisionType == 3)
			{
				if(theMask.collisionCheck(dirVec, speed, position, (*i)->theMask)) {return true;}
			}
		}
	}

	//if no collisions found, just return false
	return false;

}

//bullet collision test
bool collisionObject::collisionTest(collisionObject* i)
{
	//check to see if its the same memory location and do nothing if it is
	if (this == i)
	{
		//skip over it
		//cout << "memory location hit" << endl;
	}
	else 
	{
		//If both collisions are circles
		if (collisionType == 1 && (*i).collisionType == 1)
		{
			//can have an empty direction vector since it checks if the bullet is already inside, not where its about to move
			if(theCircle.CollisionTest((*i).theCircle,speed,Vec3f())) {return true;}
		}
		//point to a collision Mask
		else if (collisionType == 1 && (*i).collisionType == 3)
		{
			if(theMask.collisionCheck(dirVec, speed, position, (*i).theMask)) {return true;}
		}
		else if(collisionType == 1 && (*i).collisionType == 4)
		{
			if((*i).theCone.collisionTest(theCircle.Pos, theCircle.radius))
			{
				return true;
			}
		}
	}

	//if no collisions found, just return false
	return false;

}

//for player
void collisionObject::updateCollisionObject(Vec3f newVec, float newSpeed, Vec3f newPosition)
{
	//if the collision object is not static
	if(updatePos)
	{
		dirVec = newVec;
		speed = newSpeed;
		position = newPosition;
 
		if (collisionType == 1) // update circle
		{
			theCircle.SetPosition(position[0], position[1], position[2]);
		}
		else if (collisionType == 2) //update box
		{
			theBox.SetPosition(position[0],position[2]);
		}
		else if (collisionType == 3) //update mask
		{
			//theMask.SetPosition(position[0],position[1]);
		}
	}
}

//for npcs
void collisionObject::updateCollisionObject(Vec3f newVec, Vec3f xNeg, Vec3f xPos, float newSpeed, Vec3f newPosition)
{
	//if the collision object is not static
	if(updatePos)
	{
		dirVec = newVec;
		speed = newSpeed;
		position = newPosition;
 
		if (collisionType == 1) // update circle
		{
			theCircle.SetPosition(position[0], position[1], position[2]);
		}
		else if (collisionType == 2) //update box
		{
			theBox.SetPosition(position[0],position[2]);
		}
		else if (collisionType == 3) //update mask
		{
			//theMask.SetPosition(position[0],position[1]);
		}
		else if (collisionType == 4)
		{
			theCone.update(xNeg, xPos, dirVec, position);
		}
	}
}

bool collisionObject::rayCastTest(collisionObject *i, collisionObject *map)
{
	//check to see if its the same memory location and do nothing if it is
	if (this == i)
	{
		//skip over it
		//cout << "memory location hit" << endl;
	}
	else 
	{
		Vec3f dirVec = (position - i->position).normalize();
		float length = (position - i->position).magnitude();

		Vec3f temp = i->position + (Vec3f(1.0f, 1.0f, 1.0f) * dirVec);

		while((temp - i->position).magnitude() <= length)
		{
			//check to see if there is a collision at every temp point in the collision mask
			if(theMask.collisionCheck(dirVec, i->speed, temp, map->theMask)) 
			{
				return true;
			}

			temp += Vec3f(1.0f, 1.0f, 1.0f) * dirVec;
		}
	}

	//if no collisions found, just return false
	return false;
}

bool collisionObject::rayCastTestLight(Vec3f lightPos, Vec3f characterPos, collisionObject *map)
{
	//check to see if its the same memory location and do nothing if it is
	if (lightPos == characterPos)
	{
		//skip over it
		//cout << "memory location hit" << endl;
	}
	else 
	{
		lightPos = Vec3f(lightPos[0], 0.0f, lightPos[2]);
		Vec3f dirVec = (characterPos - lightPos).normalize();
		float length = (characterPos - lightPos).magnitude();

		Vec3f temp = lightPos + (Vec3f(1.0f, 1.0f, 1.0f) * dirVec);

		while((temp - lightPos).magnitude() <= length)
		{
			//check to see if there is a collision at every temp point in the collision mask
			if(theMask.collisionCheck(dirVec, 1.0f, temp, map->theMask)) 
			{
				return true;
			}

			temp += Vec3f(1.0f, 1.0f, 1.0f) * dirVec;
		}
	}

	//if no collisions found, just return false
	return false;
}