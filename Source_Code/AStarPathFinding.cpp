#include"AStarPathFinding.h"
//******************NODE**************************************//
node::node()
{
	parent = NULL;
	neighbor[0] = NULL;	
	neighbor[1] = NULL;
	neighbor[2] = NULL;
	neighbor[3] = NULL;

	//cost = 0;
	rank = 0;

	weight = 1;
}

node::~node()
{
}

//******************LEVEL GRAPH*********************************//
levelGraph::levelGraph()
{
	//theGraph = new node[100][100];
}

levelGraph::~levelGraph()
{
}

//creates a 2D graph on x and z axis
void levelGraph::generateGraph(Vec3f point0, Vec3f point1, Vec3f point2, Vec3f point3, int numRows, int numColliums)
{
	numGraphRows = numRows;
	numGraphCol = numColliums; 

	float offsetX = point1[0] - point0[0];	//offset on x-axis
	float offsetY = point3[2] - point0[2];	//offset on z-axis

	for(int row = 0; row < numRows; row++)
	{
		for(int col = 0; col < numColliums; col++)
		{
			//if bottom left square
			if(row == 0 && col == 0)
			{
				theGraph[0][0] = new node();
				theGraph[0][0]->squarePoints[0] = point0;
				theGraph[0][0]->squarePoints[1] = point1;
				theGraph[0][0]->squarePoints[2] = point2;
				theGraph[0][0]->squarePoints[3] = point3;
				theGraph[0][0]->pos = Vec3f(point1[0]/2, point0[1], point3[2]/2);
			}
			else
			{
				theGraph[row][col] = new node();
				theGraph[row][col]->squarePoints[0] = Vec3f(point0[0] + (offsetX * col), point0[1] , point0[2] + (offsetY * row));
				theGraph[row][col]->squarePoints[1] = Vec3f(point1[0] + (offsetX * col), point1[1] , point1[2] + (offsetY * row));
				theGraph[row][col]->squarePoints[2] = Vec3f(point2[0] + (offsetX * col), point2[1] , point2[2] + (offsetY * row));
				theGraph[row][col]->squarePoints[3] = Vec3f(point3[0] + (offsetX * col), point3[1] , point3[2] + (offsetY * row));
				theGraph[row][col]->pos = Vec3f(point1[0]/2 + (offsetX * col), point0[1], point3[2]/2 + (offsetY * row));
			}
		}
	}
}

void levelGraph::loadLevelGraph(collisionObject *collisionMask)
{
	//process collision map in accordince to the squares 

	levelMask = &collisionMask->theMask; 

	for(int row = 0; row < numGraphRows; row++)
	{
		for(int col = 0; col < numGraphCol; col++)
		{
			
			//cout << "row: " << row << endl;
			//cout << "col: " << col << endl;

			//no need to procees collision nodes
			if(collisionMask->theMask.squareCheck(theGraph[row][col]->pos, collisionMask->theMask))
			{
				//do nothing
			}
			else
			{
				//must check and assign each of the node's neighbors
				//each node can have a max of 4 neighbors
				//so check the bottom, right, top, and left nodes in that order

				//bottom
				if((row-1 > 0) && (!collisionMask->theMask.squareCheck(theGraph[row-1][col]->pos, collisionMask->theMask)))
				{
					theGraph[row][col]->neighbor[0] = theGraph[row-1][col];
				}
				else
				{
					theGraph[row][col]->neighbor[0] = NULL;
				}

				//right
				if((col+1 < numGraphCol) && (!collisionMask->theMask.squareCheck(theGraph[row][col+1]->pos, collisionMask->theMask)))
				{
					theGraph[row][col]->neighbor[1] = theGraph[row][col+1];
				}
				else
				{
					theGraph[row][col]->neighbor[1] = NULL;
				}

				//top
				if((row+1 < numGraphRows) && (!collisionMask->theMask.squareCheck(theGraph[row+1][col]->pos, collisionMask->theMask)))
				{
					theGraph[row][col]->neighbor[2] = theGraph[row+1][col];
				}
				else
				{
					theGraph[row][col]->neighbor[2] = NULL;
				}

				//left
				if((col-1 > 0) && (!collisionMask->theMask.squareCheck(theGraph[row][col-1]->pos, collisionMask->theMask)))
				{
					theGraph[row][col]->neighbor[3] = theGraph[row][col-1];
				}
				else
				{
					theGraph[row][col]->neighbor[3] = NULL;
				}
				
			}
		}
	}
}

//*************************A STAR*******************************//
AStar::AStar()
{
	start = new node();
	goal = new node();
	current = new node();
	firstTime = true;
}

AStar::~AStar()
{
}

node *AStar::findNodeInGraph(Vec3f pos, levelGraph *level)
{
	int foundRow = 0;
	int foundCol = 0;

	for(int row = 0; row < level->numGraphRows; row++)
	{
		//if the pos(Z) is greather than the node's bottom left point(Z) and the pos is less than the node's top left point(Z).....Z stands for z coordinate
		if(pos[2] > level->theGraph[row][0]->squarePoints[0][2] && pos[2] <= level->theGraph[row][0]->squarePoints[3][2])
		{
			for(int col = 0; col < level->numGraphCol; col++)
			{
				//if the pos(X) is greather than the node's bottom left point(X) and the pos is less than the node's bottom right point(X).....X stands for X coordinate
				if(pos[0] > level->theGraph[row][col]->squarePoints[0][0] && pos[0] <= level->theGraph[row][col]->squarePoints[1][0])
				{
					foundCol = col;
					break;
				}
			}
			foundRow = row;
			break;
		}
	}

	return level->theGraph[foundRow][foundCol];
}

bool AStar::inOpen(node *point)
{
	for(list<node*>::iterator i = open.begin(); i != open.end();)
	{
		if((*i)->pos == point->pos)
		{
			return true;
		}
		i++;
	}

	return false;
}

bool AStar::inClosed(node *point)
{
	for(list<node*>::iterator i = closed.begin(); i != closed.end();)
	{
		if((*i)->pos == point->pos)
		{
			return true;
		}
		i++;
	}

	return false;
}

float AStar::g(node *point)
{
	float g;
	node *temp;
	temp = new node();
	
	g = temp->weight;

	while(temp->parent != NULL)
	{
		temp = temp->parent;
		g += temp->weight;
	}

	delete temp;
	return g;
}

float AStar::h(node *point)
{
	//linear algebra
	/*Vec3f pointA = point->pos;
	Vec3f pointB = goal->pos;

	return (pointB - pointA).magnitude();*/

	//manhattan distance
	float dx = abs(point->pos[0] - goal->pos[0]);
	float dz = abs(point->pos[2] - goal->pos[2]);

	return (dx + dz);
}

float AStar::movementCost(node *pointToTravelTo)
{
	return pointToTravelTo->weight; 
}

void AStar::removeFromOpen(node *point)
{
	for(list<node*>::iterator i = open.begin(); i != open.end(); )
	{
		if((*i)->pos == point->pos)
		{
			i = open.erase(i);
		}
		else
		{
			i++;
		}
	}
}

void AStar::removeFromClosed(node *point)
{
	for(list<node*>::iterator i = closed.begin(); i != closed.end(); )
	{
		if((*i)->pos == point->pos)
		{
			i = closed.erase(i);
		}
		else
		{
			i++;
		}
	}
}

void AStar::createPath(Vec3f startPos, Vec3f endPos, levelGraph *level)
{
	//no need to process this situation
	if(startPos == endPos)
	{
		return;
	}

	/*startPos[0] = (startPos[0] - level->levelMask->startingOffset[0]) / level->levelMask->scaleX;
	startPos[1]	= 0.0f;
	startPos[2]	= (startPos[2] - level->levelMask->startingOffset[2]) / level->levelMask->scaleZ; 

	endPos[0] = (endPos[0] - level->levelMask->startingOffset[0]) / level->levelMask->scaleX;
	endPos[1] = 0.0f;
	endPos[2] = (endPos[2] - level->levelMask->startingOffset[2]) / level->levelMask->scaleZ; 
*/
	start = findNodeInGraph(startPos, level);
	goal = findNodeInGraph(endPos, level);

	//if goal is in collision zone, return so game does not freeze
	if(goal->neighbor[0] == NULL &&
		goal->neighbor[1] == NULL &&
		goal->neighbor[2] == NULL &&
		goal->neighbor[3] == NULL)
	{
		//cout << "ERROR, goal is in collision zone" << endl;
		return;
	}

	open.push_back(start);

	//while lowest ranked node's postion in the open list is not equal to the goal's position
	//if it is equal we are done finding our path
	while(open.front()->pos != goal->pos)
	{
		current = open.front();

		//cout<< current->pos << endl; //##############################################################################################################

		removeFromOpen(open.front());
		//open.clear();

		//put node in closed so we dont reprocess a node that we already processed
		closed.push_back(current);

		//process current's neighbors to look for the right path
		for(int i = 0; i < 4; i++)
		{
			if(current->neighbor[i] != NULL)
			{
				//float cost = g(current) + movementCost(current->neighbor[i]);
				
				////if neighbor in open and cost less than g(neighbor)
				//if(inOpen(current->neighbor[i]) && cost < g(current->neighbor[i]))
				////if(inOpen(current->neighbor[i]) && h(current) < h(current->neighbor[i]))
				//{
				//	//remove neighbor from open, because new path is better
				//	removeFromOpen(current->neighbor[i]);

				//	cout << "GGGGG" << endl;
				//}

				////if neighbor in closed and cost less than g(neighbor)
				//else if(inClosed(current->neighbor[i]) && cost < g(current->neighbor[i]))
				////else if(inClosed(current->neighbor[i]) && h(current) < h(current->neighbor[i]))
				//{
				//	removeFromClosed(current->neighbor[i]);

				//	cout << "AAAA" << endl;
				//}

				//if neighbor not in closed and neighbor not in open
				if((!inOpen(current->neighbor[i])) && (!inClosed(current->neighbor[i])))
				{
					open.push_back(current->neighbor[i]);
					current->neighbor[i]->rank = g(current->neighbor[i]) + h(current->neighbor[i]);
					current->neighbor[i]->parent = current;
				}
			}	
		}

//*******************SORT*********************************************//
		//bubble sort
		
		int check = open.size();

		//ERROR check
		if(check > 1)
		{
			//sort open list from lowest rank to highest
			for(unsigned int counter = 0; counter < check; counter++)
			{
				list<node*>::iterator k = open.end();
				k--;

				list<node*>::iterator m = open.end();
				m--;
				m--;
		
				unsigned int countEnd = check - 1;
				while(countEnd > counter)
				{
					if((*k)->rank < ((*m)->rank))
					{
						node *temp;
						temp = new node();

						temp = (*k);

						(*k) = (*m);
						(*m) = temp;

						temp = NULL;
						delete temp;

					}
					if(countEnd-1 != counter)
					{
						k--;
						m--;
					}
					countEnd--;
				}

			}

			//optimizes pathfinding by shinking open list to fewer nodes to sort
			if(open.size() > 20)
			{
				unsigned int openSize = check / 2; 
				list<node*>::iterator k = open.end();
				k--;

				//remove some of the highest ranked nodes to make open list process faster
				for(unsigned int counter = 0; counter < openSize; counter++)
				{
					//put node in closed so we dont reprocess a node that we already processed
					closed.push_back((*k));

					removeFromOpen((*k));

					k = open.end();
					k--;
				}
			}
		}
		else
		{
			//cout << "ERROR, open list in AStarPathFinding.h contains zero elements, NPC start point is in collision zone. " << endl;
			
			//clear the open and closed lists so they are ready for the next iteration
			open.clear();
			closed.clear();

			if(!firstTime)
			{
				//clear the path list from the previous determined path
				path.clear();
			}

			return;
		}
//*************************************************************************************************/

	}

	//reconstruct path from goal to start by following parent pointers
	getPath( startPos,  endPos, level->levelMask);

	//clear the open and closed lists so they are ready for the next iteration
	open.clear();
	closed.clear();
}


void AStar::getPath( Vec3f startPos, Vec3f endPos, Mask *levelMask)
{
	//if first time running the code
	if(firstTime)
	{
		node *temp;
		temp = new node();

		temp = goal;

		path.push_back(temp->pos); //1.6 is the level scale ************SHOULD NOT BE HARD CODED***********************

		while(temp->pos != start->pos)
		{
			temp = temp->parent;

			if(temp->parent == NULL)
			{
				temp->pos[0] = startPos[0]; //1.79878f
				temp->pos[1] = startPos[1];
				temp->pos[2] = startPos[2];
				break;
			}

			path.push_back(temp->pos);
		}

		firstTime = false;
	}
	//if it is not the firts time running
	else
	{
		//clear the path list from the previous determined path
		path.clear();

		node *temp;
		temp = new node();

		temp = goal;

		path.push_back(temp->pos);

		//traves from the goal to its parent all the way to the start to reconstruct path
		while(temp->pos != start->pos)
		{
			temp = temp->parent;

			if(temp->parent == NULL)
			{
				temp->pos[0] = startPos[0];
				temp->pos[1] = startPos[1];
				temp->pos[2] = startPos[2];
				break;
			}

			path.push_back(temp->pos);
		}
	}

	goal->pos = endPos;
	start->pos = startPos;
}