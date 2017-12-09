/**
* David Dixon
* 26.07.2017
*/
#include <iostream>

using namespace std;

class Node {
	public:
		Node(string newname);
		Node();
		void setNodeName(string newname);
		string getNodeName();
		void setNorthNode(Node *northNode);
		void setEastNode(Node *eastNode);
		void setSouthNode(Node *southNode);
		void setWestNode(Node *westNode);
		Node *getNorthNode();
		Node *getEastNode();
		Node *getSouthNode();
		Node *getWestNode();
		void setLadderChuteNode(Node *newNode);
		Node *getLadderChuteNode();
		string checkDirection();
		string directionOutput();
		bool checkLadderChute();
		bool hasLadderChuteNode();
	
	private:
		string name;
		Node *northN;
		Node *eastN;
		Node *southN;
		Node *westN;
		Node *ladderorChuteNode;
};

Node::Node(string newname)
{
	name = newname;
	northN = NULL;
	eastN = NULL;
	southN = NULL;
	westN = NULL;
	ladderorChuteNode = NULL;
};

Node::Node()
{
	name = "";
};

void Node::setNodeName(string newname)
{
	name = newname;
};

string Node::getNodeName()
{
	return name;
};

void Node::setNorthNode(Node *northNodeIn)
{
	northN = northNodeIn;
};

void Node::setEastNode(Node *eastNodeIn)
{
	eastN = eastNodeIn;
};

void Node::setSouthNode(Node *southNodeIn)
{
	southN = southNodeIn;
};

void Node::setWestNode(Node *westNodeIn)
{
	westN = westNodeIn;
};

Node* Node::getNorthNode()
{
	return northN;
};

Node* Node::getEastNode()
{
	return eastN;
};

Node* Node::getSouthNode()
{
	return southN;
};

Node* Node::getWestNode()
{
	return westN;
};

void Node::setLadderChuteNode(Node *newNode)
{
	ladderorChuteNode = newNode;
};

Node* Node::getLadderChuteNode()
{
	return ladderorChuteNode;
};

string Node::checkDirection()
{
	string directions = "";
	if (northN != NULL)
	{
		directions += "n";
	}
	
	if (eastN != NULL)
	{
		directions += "e";
	}
	
	if (southN != NULL)
	{
		directions += "s";
	}
	
	if (westN != NULL)
	{
		directions += "w";
	}
	
	return directions;
};

string Node::directionOutput()
{
	string directions = "";
	int count = 0;
	if (northN != NULL)
	{
		directions += "north";
		count++;
	}
	
	if (eastN != NULL )
	{
		
		if (count > 0)
		{
			directions += " ";
		}
		directions += "east";
		count++;
	}
	
	if (southN != NULL)
	{
		if (count > 0)
		{
			directions += " ";
		}
		directions += "south";
		count++;
	}
	
	if (westN != NULL)
	{
		if (count > 0)
		{
			directions += " ";
		}
		directions += "west";
		count++;
	}
	
	
	
	return directions;
};

bool Node::checkLadderChute()
{
	if (ladderorChuteNode != NULL)
	{
		return true;
	}
	return false;
};

bool Node::hasLadderChuteNode()
{
	if (ladderorChuteNode != NULL)
	{
		return true;
	}
	return false;
};












