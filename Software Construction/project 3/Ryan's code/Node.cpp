#include<string>
using namespace std;

class Node {
public:
	Node(string newname)
	{
		name = newname;
	}
	Node()
	{
		name = "default";
	}
	void setNodeName(string newname)
	{
		name = newname;
	}
	string getNodeName()
	{
			return name;
	}
	void attachNewNode(Node *newNode, int direction)
	{
		attachedNodes[direction] = newNode;
	} 
	Node *getAttachedNode(int direction)
	{
		return attachedNodes[direction];
	}
	void attachSnakeLadderNode(Node *newNode)
	{
		snakeOrLadderNodes = newNode;
	}
	Node *getSnakeLadderNode()
	{
		return snakeOrLadderNodes;
	}

private:
	string name;
	Node *attachedNodes[4];
	Node *snakeOrLadderNodes;
};


