#pragma once
#include <list>
#include "MathClass.h"
#include "Collision.h"

class node
{
public:
	node();
	~node();

	node *parent;		//the parent of the node, esstianal for pathfinding
	node *neighbor[4];	//the node's neighbors, can have a max of 4
	Vec3f pos;		//the position of the node in world coordinates
	Vec3f squarePoints[4];	//the four vertices that makes up the square
	float rank;		//the rank of this node
	float weight;	//the weight to move to this current node, this is more for 3D graphs, so remain 1 for now
	//float cost;		//the cost from the starting point to the current node
};

//created the graph of the level for pathfinding
//needs to be computed for each level and district. 
//this is used by all AI
class levelGraph
{
public:
	levelGraph();
	~levelGraph();

	//used to create the graph
	void generateGraph(Vec3f point0, Vec3f point1, Vec3f point2, Vec3f point3, int numRows, int numColliums);		//the parameters are the four points of the bottom left square of the graph 
																													//points are starting from the bottom left of the square and going counter clockwise
																													//the last two parameters are the number of rows and colliums the graph will have
																													
	void loadLevelGraph(collisionObject *collisionMask);		//load the level graph by loading in the collision map and proccessing it

	//node *theGraph[100][100];	//the graph of the level [row#][element # in row]
	//node (*theGraph)[100];
	node *theGraph[500][500];

	int numGraphRows;
	int numGraphCol;

	Mask *levelMask; 
};

//used to created the path for each AI
//needs to be assigned to each AI induvidually
class AStar
{
public:
	AStar();
	~AStar();

	void createPath(Vec3f startPos, Vec3f endPos, levelGraph *level);	//where A* is used, creates the path 

	void getPath (Vec3f startPos, Vec3f endPos, Mask *levelMask);	//gets the path by returning the postion of the goal, traverse the parents until the start pos is reached
	
	bool inOpen (node *point);		//checks to see if the node is in the open list
	bool inClosed(node *point);		//checks to see if the node is in the closed list
	
	float g(node *point);		//finds the exact cost of the path from the starting point to any vertex n.
	float h(node *point);		//finds the heuristic estimated cost from vertex n to the goal

	float movementCost(node *pointToTravelTo);	//the cost to move from one node to another

	void removeFromOpen(node *point);
	void removeFromClosed(node *point);

	node *findNodeInGraph(Vec3f pos, levelGraph *level);	//finds the node in the graph

	list<node*> open;	//contains those nodes that are candidates for examining. Initially the open set contains just one element: the starting position 
	list<node*> closed;	//contains those nodes that have already been examined. Initially, the closed set is empty
	list<Vec3f> path;	//the final path;

	node *start;	//the starting node
	node *goal;		//the goal node
	node *current;		//the current node being processed

	bool firstTime;	//if it is the first time running the AStar pathfinding code for a particular npc

	//levelGraph *gameLevel;	//the graph of the level
};