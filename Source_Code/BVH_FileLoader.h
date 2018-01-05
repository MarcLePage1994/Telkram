//stores skeleton animations from BVH files

#pragma once
//#include "SFML\Graphics.hpp"
//#include "SFML\OpenGL.hpp"
#include "texture.h"
#include "MathClass.h"
#include <vector>
#include <stdio.h>
#include <string>
#include "drawPrimitives.h"

//a frame is a list of tranformations for the skeleton
struct Frame
{
	vector<float> Tranformations; 
};

//a animation is a list of frames
class Animation
{
public:
	Animation();
	~Animation();

	int numFrames;
	float FrameTime;
	float FramesPerSec;
	vector<Frame> Frames;	
	void LoadAnimation(FILE *BVH_File, int totalNumChannels);

private:
	char line[255];
};

//stores the data of each joint of the skeleton
class Joint
{
public:
	Joint();
	~Joint();

	string name;	//the name of the joint
	Joint *Parent;
	Mat4f TLocal, RLocal, ObjectSpace, SkinningMult;
	Mat4f ObjectSpaceAtBind;	//first frame
	Mat4f InverseObjectSpaceAtBind;
	Vec4f ObjectSpacePos; 
	vector<Joint*> Children;
	vector<float> Channels;
	int numChannels; //can only have 3 or 6 numChannels
	int level;	//the level of the joint in the heiarachy

	Mat4f *skinningOutput;

	tex *weightMap; //the weight map of the joint for the model's vertices

	void loadWeightMap(string fileDirectory);
	void updateTransform(Animation *animation, int frameCounter, int &channelCounter);
	void updateAdditiveTransform(Animation *animation1, Animation *animation2, int frameCounter, int &channelCounter);	//both animation must have the same number of frames
	void updateObjectSpaceTransform(Mat4f WParent);
	void AttachChild(Joint *n);

	void drawJoint();
};

//can only support one skeleton at a time
class Skeleton 
{
public:
	Skeleton();
	~Skeleton();	
	
	Joint *Root;
	int totalNumChannels;	//the total number of numChannels for all of the joints in the skeleton
	float time;
	bool update;
	int channelCounter;
	int frameCounter;

	Mat4f skiningOutputList[100]; //needed for skinning

	vector<Joint*> allJoints; //all of the joints of the skeleton in a nice list

	//load the entire BVH file, this includes the skeleton and animation
	void LoadBVHFile(char *filename);

	//to load joint weight maps, just give the location of the file that they are in, and program will automatically load all of the
	//proper weight maps and store it to the proper joint
	void LoadJointWeightMaps(string fileDirectory);	

	void updateSkeleton(Vec3f pos, float theta, float dt);	//updates the skeleton with the current animation

	void updateAdditiveSkeleton(Skeleton *otherSkeleton, Vec3f pos, float theta, float dt);	//updates the skeleton with the current additive animation

	void SetOutputJoints(); //intializes the data for the joints that are sent to the shader for mesh skinning
	
	void drawSkeleton();
	
	
	//is used to access animation data
	Animation *animation;

private:	
	FILE *BVH_File;
	char line[255];
	bool EndSite;	
	
	//recurrsivly parse the skeleton heiarchy by using a depth first traversal
	void parseFile(int &numOfBrakets,  Joint *current);
	//load the skeleton
	void LoadSkeleton();
};