#include "BVH_FileLoader.h"

//////////////////////////////////////////////////////////////////////////////////////////////
//Class Joint
Joint::Joint()
{
	Parent = NULL;
	TLocal = ObjectSpace = Mat4f();
	ObjectSpacePos = Vec4f();
	weightMap = new tex();
}

Joint::~Joint()
{
}

void Joint::loadWeightMap(string fileDirectory)
{
	string temp = fileDirectory;
	temp.append(name);
	temp.append(".jpg");

	weightMap->loadTex(temp);

	//load all of the childern's weight maps too
	for(unsigned int i = 0; i < this->Children.size(); i++)
	{
		Children[i]->loadWeightMap(fileDirectory);
	}
}

void Joint::updateTransform(Animation *animation, int frameCounter, int &channelCounter)
{
	if(numChannels == 6)
	{
		Mat4f temp = Translate(animation->Frames[frameCounter].Tranformations[channelCounter], animation->Frames[frameCounter].Tranformations[channelCounter + 1], animation->Frames[frameCounter].Tranformations[channelCounter + 2]);
		TLocal = temp; 

		////so animations stay in one spot
		//Mat4f temp = Translate(0.0f, animation->Frames[frameCounter].Tranformations[channelCounter + 1], 0.0f);
		//TLocal = temp; 	

		Mat4f rZ = RotateZ(animation->Frames[frameCounter].Tranformations[channelCounter + 3]);	//z
		Mat4f rX = RotateX(animation->Frames[frameCounter].Tranformations[channelCounter + 4]);	//y
		Mat4f rY = RotateY(animation->Frames[frameCounter].Tranformations[channelCounter + 5]);	//x
		RLocal = rZ * rX * rY; //rZ * rY * rX

		channelCounter += 6;
	}
	else if(numChannels == 3)
	{
		Mat4f rZ = RotateZ(animation->Frames[frameCounter].Tranformations[channelCounter]);
		Mat4f rX = RotateX(animation->Frames[frameCounter].Tranformations[channelCounter + 1]);
		Mat4f rY = RotateY(animation->Frames[frameCounter].Tranformations[channelCounter + 2]);
		RLocal = rZ * rX * rY; 

		channelCounter += 3;
	}

	//update all of the childern
	for(unsigned int i = 0; i < this->Children.size(); i++)
	{
		Children[i]->updateTransform(animation, frameCounter, channelCounter);	
	}
}

void Joint::updateAdditiveTransform(Animation *animation1, Animation *animation2, int frameCounter, int &channelCounter)
{
	if(numChannels == 6)
	{
		Mat4f temp = Translate(animation1->Frames[frameCounter].Tranformations[channelCounter], animation1->Frames[frameCounter].Tranformations[channelCounter + 1], animation1->Frames[frameCounter].Tranformations[channelCounter + 2]);
		TLocal = temp; 

		Mat4f rZ = RotateZ(animation1->Frames[frameCounter].Tranformations[channelCounter + 3] + animation2->Frames[frameCounter].Tranformations[channelCounter + 3]);
		Mat4f rY = RotateY(animation1->Frames[frameCounter].Tranformations[channelCounter + 4] + animation2->Frames[frameCounter].Tranformations[channelCounter + 4]);
		Mat4f rX = RotateX(animation1->Frames[frameCounter].Tranformations[channelCounter + 5] + animation2->Frames[frameCounter].Tranformations[channelCounter + 5]);
		RLocal = rZ * rY * rX; 

		channelCounter += 6;
	}
	else if(numChannels == 3)
	{
		Mat4f rZ = RotateZ(animation1->Frames[frameCounter].Tranformations[channelCounter] + animation2->Frames[frameCounter].Tranformations[channelCounter]);
		Mat4f rY = RotateY(animation1->Frames[frameCounter].Tranformations[channelCounter + 1] + animation2->Frames[frameCounter].Tranformations[channelCounter + 1]);
		Mat4f rX = RotateX(animation1->Frames[frameCounter].Tranformations[channelCounter + 2] + animation2->Frames[frameCounter].Tranformations[channelCounter + 2]);
		RLocal = rZ * rY * rX; 

		channelCounter += 3;
	}

	//update all of the childern
	for(unsigned int i = 0; i < this->Children.size(); i++)
	{
		Children[i]->updateAdditiveTransform(animation1, animation2, frameCounter, channelCounter);	
	}
}

void Joint::updateObjectSpaceTransform(Mat4f WParent)
{ 
	// FORWARD KINEMATICS!
	ObjectSpace = WParent * TLocal * RLocal;

	// CONCATENATE THE MATRICES IN THE SKINNING EQUATION TO SEND TO SHADER
	SkinningMult =  ObjectSpace * InverseObjectSpaceAtBind; 
	*(skinningOutput) = SkinningMult;
	
	ObjectSpacePos = ObjectSpace * Vec4f(0.0f, 0.0f, 0.0f, 1.0f);

	for(unsigned int i = 0; i < Children.size(); i++)
	{
		Children[i]->updateObjectSpaceTransform(ObjectSpace);
	}
}

void Joint::drawJoint()
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(ObjectSpacePos[0], ObjectSpacePos[1], ObjectSpacePos[2]);
	drawBox(1.0f,1.0f,1.0f);
	glPopMatrix();

	for(unsigned int i = 0; i < Children.size(); i++)
	{
		Children[i]->drawJoint();
	}
}

void Joint::AttachChild(Joint *n)
{
	n->Parent = this; 
	Children.push_back(n);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Class Animation
Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::LoadAnimation(FILE *BVH_File,  int totalNumChannels)
{
	Frame tempFrame;

	while(1)	//while true
	{
		int res = fscanf(BVH_File, "%s", line);
		//checks for end of file (EOF)
		if(res == EOF)
		{
			break;
		}
		else if(strcmp(line, "Frames:")==0)
		{
			int frames;
			fscanf(BVH_File, "%i", &frames);
			numFrames = frames;
		}
		else if(strcmp(line, "Time:")==0)
		{
			float frameTime;
			fscanf(BVH_File, "%f", &frameTime);
			FrameTime = frameTime;
			FramesPerSec = 1.0f/FrameTime;

			//get the animation data
			int counter = 0;
			while(1)
			{
				float num;
				res = fscanf(BVH_File, "%f", &num);
					
				if(counter == totalNumChannels)
				{
					Frames.push_back(tempFrame);
					tempFrame.Tranformations.clear();
					counter = 0;
				}
				else if(res == EOF)
				{
					fclose(BVH_File);
					return;
				}

				tempFrame.Tranformations.push_back(num);
				counter++;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Class Skeleton

Skeleton::Skeleton()
{
	Root = NULL;
	EndSite = false;
	totalNumChannels = 0;
	update = true;
	channelCounter = 0;
	frameCounter = 0;
	time = 0.0f;
	animation = new Animation();
}

Skeleton::~Skeleton()
{
}

//load the entire BVH file
void Skeleton::LoadBVHFile(char *filename)
{
	BVH_File = fopen(filename, "r");
	//When the file cannot be opened (e.g., we don't have permission or it doesn't exist when opening for reading), fopen() will return NULL.
	if(BVH_File == NULL)
	{
		cout << "ERROR, could not open BVH file" << endl;
		return;
	}

	//load the skeleton
	LoadSkeleton();
	//load the animation
	animation->LoadAnimation(BVH_File, totalNumChannels);
	//initliaze joints for mesh skinning
	SetOutputJoints();
}

void Skeleton::LoadSkeleton()
{
	//the current joint being processed
	Joint *current;
	current = new Joint();

	//lets use know which level the joint is on
	int numOfBrakets = 0; 

	while(1)	//while true
	{
		fscanf(BVH_File, "%s", line);

		if(strcmp(line, "ROOT")==0)
		{
			Root = new Joint();
			char jointName [50];
			fscanf(BVH_File, "%s", jointName);
			Root->name = jointName;
			Root->level = numOfBrakets;
			Root->numChannels = 6;
			current = Root;
			totalNumChannels += 6;
			allJoints.push_back(Root);
		}
		else if(strcmp(line, "OFFSET")==0)
		{
			Vec3f offset;
			fscanf(BVH_File, "%f %f %f\n", &offset[0], &offset[1], &offset[2]);
			//current->TLocal = Translate(offset);
			current->TLocal = Identity(); //so animations stay in one spot
			if(current->Parent != NULL)
			{
				current->ObjectSpaceAtBind = current->Parent->ObjectSpaceAtBind * current->TLocal;
				current->InverseObjectSpaceAtBind = transformInverseNoScale(current->ObjectSpaceAtBind);
				//skiningOutputList[allJoints.size()-1] = current->ObjectSpaceAtBind * current->InverseObjectSpaceAtBind; 
			}
			else
			{
				current->ObjectSpaceAtBind = Identity(); /* current->TLocal;*/
				current->InverseObjectSpaceAtBind = transformInverseNoScale(current->ObjectSpaceAtBind);
				//skiningOutputList[allJoints.size()-1] = current->ObjectSpaceAtBind * current->InverseObjectSpaceAtBind; 
			}
		}
		else if(strcmp(line, "{")==0)
		{
			numOfBrakets ++;
		}
		else if(strcmp(line, "}")==0)
		{
			numOfBrakets --;
		}
		else if(strcmp(line, "JOINT") == 0)
		{
			Joint *temp;
			temp = new Joint();
			char jointName [50];
			fscanf(BVH_File, "%s", jointName);
			temp->name = jointName;
			temp->level = numOfBrakets;
			temp->numChannels = 3;
			totalNumChannels += 3;

			//find the right parent
			if(current->level >= temp->level)
			{
				while(current->level >= temp->level)
				{
					current = current->Parent; 
				}	
			}

			current->AttachChild(temp);
			current = temp;
			allJoints.push_back(temp);
			parseFile(numOfBrakets, current);
		}

		//this indicates that it is time to move onto to the animation portion of the BVH file
		if(strcmp(line, "MOTION") == 0)
		{
			return;
		}
	}
}

void Skeleton::parseFile(int &numOfBrakets, Joint *current)
{
	while(1)
	{
		fscanf(BVH_File, "%s", line);
		
		//general cases
		if(strcmp(line, "}")==0)
		{
			numOfBrakets--;
		}
		else if(strcmp(line, "End")==0)
		{
			EndSite = true;
		}
		else if(EndSite && strcmp(line, "OFFSET")==0)
		{
			EndSite = false;
		}
		else if(strcmp(line, "{")==0)
		{
			numOfBrakets ++;
		}
		else if(strcmp(line, "OFFSET")==0)
		{
			Vec3f offset;
			fscanf(BVH_File, "%f %f %f\n", &offset[0], &offset[1], &offset[2]);
			current->TLocal = Translate(offset);
			if(current->Parent != NULL)
			{
				current->ObjectSpaceAtBind = current->Parent->ObjectSpaceAtBind * current->TLocal;
				current->InverseObjectSpaceAtBind = transformInverseNoScale(current->ObjectSpaceAtBind);
				//skiningOutputList[allJoints.size()-1] = current->ObjectSpaceAtBind * current->InverseObjectSpaceAtBind; 
			}
			else
			{
				current->ObjectSpaceAtBind = Identity(); /* current->TLocal;*/
				current->InverseObjectSpaceAtBind = transformInverseNoScale(current->ObjectSpaceAtBind);
				//skiningOutputList[allJoints.size()-1] = current->ObjectSpaceAtBind * current->InverseObjectSpaceAtBind; 
			}
		}
		else if(strcmp(line, "JOINT") == 0)
		{
			Joint *temp;
			temp = new Joint();
			char jointName [50];
			fscanf(BVH_File, "%s", jointName);
			temp->name = jointName;
			temp->level = numOfBrakets;
			temp->numChannels = 3;
			totalNumChannels += 3;

			//find the right parent
			if(current->level >= temp->level)
			{
				while(current->level >= temp->level)
				{
					current = current->Parent; 
				}	
			}

			current->AttachChild(temp);
			current = temp;
			allJoints.push_back(temp);
			parseFile(numOfBrakets, current);
		}

		//base cases
		if(strcmp(line, "MOTION") == 0)
		{
			return;
		}
	}
}

void Skeleton::updateSkeleton(Vec3f pos, float theta, float dt)
{
	time += dt /* (animation->FrameTime)*/;

	//update the animation
	if(time >= animation->FrameTime)
	{
		update = true;
		time = 0.0f;
		channelCounter = 0; 
 		frameCounter++;

		//repeat the animation
		if(frameCounter >= animation->numFrames)
		{
			frameCounter = 0;
		}
	}

	//if it is time to update the frame of the animation
	if(update)
	{
		update = false;
		Root->updateTransform(animation, frameCounter, channelCounter);
	}

	Mat4f temp = Translate(0.0f, 0.0f, 0.0f);//Translate(pos) * RotateY(theta) * Scale(0.65f, 0.65f, 0.65f);
	Root->updateObjectSpaceTransform(temp);
}

void Skeleton::updateAdditiveSkeleton(Skeleton *otherSkeleton, Vec3f pos,  float theta, float dt)
{
	time += dt /* (animation->FrameTime)*/;

	//update the animation
	if(time >= animation->FrameTime)
	{
		update = true;
		time = 0.0f;
		channelCounter = 0; 
 		frameCounter++;

		//repeat the animation
		if(frameCounter >= animation->numFrames)
		{
			frameCounter = 0;
		}
	}

	//if it is time to update the frame of the animation
	if(update)
	{
		update = false;
		Root->updateAdditiveTransform(animation, otherSkeleton->animation, frameCounter, channelCounter);
	}

	Mat4f temp = Translate(pos) * RotateY(theta);
	Root->updateObjectSpaceTransform(temp);
}

void Skeleton::drawSkeleton()
{
	glDisable(GL_LIGHTING);
	Root->drawJoint();
	//Root->Children[0]->Children[0]->drawJoint();
	glEnable(GL_LIGHTING);
}

void Skeleton::LoadJointWeightMaps(string fileDirectory)
{
	Root->loadWeightMap(fileDirectory);
}

void Skeleton::SetOutputJoints()
{
	for(unsigned int i = 0; i < allJoints.size(); i++)
	{
		allJoints[i]->skinningOutput = skiningOutputList + i; 
	}
}


