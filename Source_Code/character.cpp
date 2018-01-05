#include "character.h"

character::character()
{

		species = 0;
		setUpHostileSpecies();

		health = 0;

		alive = true;

		theta = 0.0f;
		position = Vec3f(0.0f, 0.0f, 0.0f);
		startingPosition = Vec3f(0.0f,0.0f,0.0f);
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

		flipNegXAxis = false;
		flipPosXAxis = false;
		flipPosZAxis = false;
		flipNegZAxis = false;

		accumulatedTime = 0.f;
		waitTime = 0.f;
}



character::character(bool isAlive, int hitpoints, Vec3f Cposition, float angle, int Cspecies, Vec3f CstartingPosition)
{

	species = Cspecies;
	setUpHostileSpecies();

	health = hitpoints;

	alive = isAlive;

	theta = 0.0f;
	position = Vec3f();
	startingPosition = Vec3f();
	tValue = 0.f;
	deltaTime = 0.f;

	ZaxisPos = Vec3f(0.0f, 0.0f, 1.0f);		//front of the character
	ZaxisPos.applyYRotation(theta);
	ZaxisNeg = Vec3f(0.0f, 0.0f, -1.0f);		//back of the character
	ZaxisNeg.applyYRotation(theta);

	XaxisNeg = Vec3f(-1.0f, 0.0f, 0.0f);			//left of the character
	XaxisNeg.applyYRotation(theta);
	XaxisPos = Vec3f(1.0f, 0.0f, 0.0f);			//right of the character
	XaxisPos.applyYRotation(theta);

	flipNegXAxis = false;
	flipPosXAxis = false;
	flipPosZAxis = false;
	flipNegZAxis = false;

	accumulatedTime = 0.f;
	waitTime = 0.f;
}

character::~character()
{
	//destructor
	//delete theTexture1;
	//delete theModel;
}

//void character::loadCharacter(const std::string &textureFileName, char* modelFileName, int polyCount)
//{
//	theModel = new objLoader();
//	theTexture1 = new tex();
//
//	theTexture1->loadTex(textureFileName);
//	theModel->LoadOBJ(modelFileName,polyCount);
//}

void character::loadCharacter(tex *importedTex, char* modelFileName, int polyCount)
{
	theModel = new objLoader();
	//theTexture1 = new tex();

	theTexture1 = importedTex; 
	theModel->LoadOBJForMorphTargeting(modelFileName, polyCount);
}

void character::drawCharacter()
{
	glPushMatrix();
	glTranslatef(position[0], position[1] - 8.0f, position[2]);
	
	//handle floating point errors
	if(theta > 360.0f)
	{
		theta -= 360.0f;
	}
	else if(theta < 0.0f)
	{
		theta += 360.0f;
	}

	glRotatef(theta, 0, 1, 0);
	glScalef(0.6f, 0.6f, 0.6f);
	
	glColor3f(1.0f, 1.0f, 1.0f);
	theTexture1->drawTex(0);
	theModel->drawModel();
	glPopMatrix();
}

void character::checkCollision()
{
	//Collision specifics will be defined in the inherited classes
}

void character::checkForHostiles()
{
	//hostile check specifics will be defined in the inherited classes
} // If this function returns true, this character becomes hostile. 

void character::updateCharacter()
{
	//update is handled in inherited classes
}

void character::setUpHostileSpecies()
{
	//10 player
	//1 gang 1
	//2 gang 2
	//3 gang 3
	//4 gang 4
	//5 civilian
	//6 gwark


	for (int i = 0; i < 10; i++)
	{
		if (species == 10)
		{
			//everything
			isHostileTowards[0] = 10;
			isHostileTowards[1] = 1;
			isHostileTowards[2] = 2;
			isHostileTowards[3] = 3;
			isHostileTowards[4] = 4;
			isHostileTowards[5] = 5;
			isHostileTowards[6] = 6;

		}
		else if (species == 1)
		{
			//everything but the gang
			isHostileTowards[0] = 10;
			isHostileTowards[1] = 0;
			isHostileTowards[2] = 2;
			isHostileTowards[3] = 3;
			isHostileTowards[4] = 4;
			isHostileTowards[5] = 5;
			isHostileTowards[6] = 6;
		}
		else if (species == 2)
		{
			//everything but the gang
			isHostileTowards[0] = 10;
			isHostileTowards[1] = 1;
			isHostileTowards[2] = 0;
			isHostileTowards[3] = 3;
			isHostileTowards[4] = 4;
			isHostileTowards[5] = 5;
			isHostileTowards[6] = 6;

		}
		else if (species == 3)
		{
			//everything but the gang
			isHostileTowards[0] = 10;
			isHostileTowards[1] = 1;
			isHostileTowards[2] = 2;
			isHostileTowards[3] = 0;
			isHostileTowards[4] = 4;
			isHostileTowards[5] = 5;
			isHostileTowards[6] = 6;

		}
		else if (species == 4) 
		{
			//everything but the gang
			isHostileTowards[0] = 10;
			isHostileTowards[1] = 1;
			isHostileTowards[2] = 2;
			isHostileTowards[3] = 3;
			isHostileTowards[4] = 0;
			isHostileTowards[5] = 5;
			isHostileTowards[6] = 6;

		}
		else if (species == 5)
		{
			//everything is a potential enemy but other civilians
			isHostileTowards[0] = 10;
			isHostileTowards[1] = 1;
			isHostileTowards[2] = 2;
			isHostileTowards[3] = 3;
			isHostileTowards[4] = 4;
			isHostileTowards[5] = 0;
			isHostileTowards[6] = 6;
		}
		else if (species == 6)
		{
			//everything is a potential enemy
			isHostileTowards[0] = 10;
			isHostileTowards[1] = 1;
			isHostileTowards[2] = 2;
			isHostileTowards[3] = 3;
			isHostileTowards[4] = 4;
			isHostileTowards[5] = 5;
			isHostileTowards[6] = 6;
		}

	}

}

void character::calcAxis()
{
	//rotation for x axis
	//using quaternions
	//using QvQ^c formula
	//first we must figure out the rotation quaternion and its conjucate
	Quat rotateQuat = rotationQuat(theta, Vec3f(0, 1, 0));
	Quat conjugate = rotateQuat.conjugate();

	//next we find the new direction vector by rotation it
	Quat newQuatPosX = rotateQuat * Quat(0, 1, 0, 0) * conjugate;
	Quat newQuatNegX = rotateQuat * Quat(0, -1, 0, 0) * conjugate; 
	Quat newQuatPosZ = rotateQuat * Quat(0, 0, 0, 1) * conjugate;
	Quat newQuatNegZ = rotateQuat * Quat(0, 0, 0, -1) * conjugate;

	//transfer our direction vector from pure quaternion to vector form
	Vec3f newVecPosX = newQuatPosX.toVector();
	Vec3f newVecNegX = newQuatNegX.toVector();
	Vec3f newVecPosZ = newQuatPosZ.toVector();
	Vec3f newVecNegZ = newQuatNegZ.toVector();

	//finally normalize the vectors to make sure they are direction vectors
	/*XaxisPos = (newVecPosX.normalize());
	XaxisNeg = (newVecNegX.normalize());
	ZaxisPos = (newVecPosZ.normalize());
	ZaxisNeg = (newVecNegZ.normalize());*/

	XaxisPos = newVecPosX;
	XaxisNeg = newVecNegX;
	ZaxisPos = newVecPosZ;
	ZaxisNeg = newVecNegZ;
}

void character::collisionSet(float radius)
{
	cObject = collisionObject(radius,this->startingPosition,this->speed, true);
}

bool character::checkCollision(std::list<collisionObject*>& collisionList)
{
	return cObject.collisionTest(collisionList);
}

void character::loadAnimations()
{
}

void character::updateAnimations(float dt)
{
}