/*
* David Dixon
* This is the program for a ladder chute game.
*/

#include "Node.cpp"
#include "Board.cpp"
#include <fstream>


using namespace std;

int main()
{
	cout << "Welcome to this game...\n";
	
	string mazeStr, mazeStr1;
	ifstream inStream;
	Node primeNode;
	Node branchNode("A1");
	Node blockNode;
	Node bufferNode;
	string str = "*";
	blockNode = Node(str);
	Node *pointerNode;
	Node *primeNodePointer;
	Board board;
	string nodeName;
	Node nodeArray[48];
	int nodeCount = 0;
	int nodeLocation = -1;
	int primeNodeLocation = -1;
	string file;
	
	cout << "Please enter file name: ";
	cin >> file;
	cout << "\n";
	
	inStream.open(file.c_str());
	
	if (inStream.fail())
	{
		cerr << "There was an error opening this file.";
		return 0;
	}
	
	
	for (int i = 0; i < 48; i++)
	{
		//get prime node name
		inStream >> mazeStr;
		primeNode = Node(mazeStr);
		
		//if primenode isn't in node array, add it.
		if (!board.findNode(primeNode.getNodeName(), nodeArray, nodeCount))
		{
			nodeArray[nodeCount] = Node(primeNode.getNodeName());
			nodeCount++;
		}
		//find node location on board
		primeNodeLocation = board.findNodeLocation(mazeStr, nodeArray, nodeCount);
		//point to the prime node in the nodeArray;
		primeNodePointer = &nodeArray[primeNodeLocation];
		//dereference node for editting
		//primeNode = *primeNodePointer;
		//get north node
		inStream >> mazeStr;
		//if north node is "*", set north node pointer to blocknode
		if (mazeStr == "*")
		{
			
			pointerNode = NULL;
			primeNode.setNorthNode(NULL);
		}
		//if north node isn't "*", see if node is already in array
		//if it isn't, create it, add it, and point primenode.north to it
		//
		else
		{
			
			if (!board.findNode(mazeStr, nodeArray, nodeCount))
			{
				branchNode = Node(mazeStr);
				nodeArray[nodeCount] = branchNode;
				nodeCount++;
			}
			nodeLocation = board.findNodeLocation(mazeStr, nodeArray, nodeCount);
			pointerNode = &nodeArray[nodeLocation];
			nodeArray[primeNodeLocation].setNorthNode(pointerNode);
				
		}
		
		
		//get east node
		
		inStream >> mazeStr;
		
		//if east node is "*", set east node pointer to blocknode
		if (mazeStr == "*")
		{
			
			pointerNode = NULL;
			primeNode.setEastNode(pointerNode);
		}
		//if east node isn't "*", see if node is already in array
		//if it isn't, create it, add it, and point primenode.east to it
		//
		else
		{
			
			
			if (!board.findNode(mazeStr, nodeArray, nodeCount))
			{
				
				branchNode = Node(mazeStr);
				nodeArray[nodeCount] = branchNode;
				nodeCount++;
			}
			nodeLocation = board.findNodeLocation(mazeStr, nodeArray, nodeCount);
			pointerNode = &nodeArray[nodeLocation];
			nodeArray[primeNodeLocation].setEastNode(pointerNode);
		}
		
		//get south node
		inStream >> mazeStr;
		//if south node is "*", set north node pointer to blocknode
		if (mazeStr == "*")
		{
			
			pointerNode = NULL;
			primeNode.setNorthNode(pointerNode);
		}
		//if south node isn't "*", see if node is already in array
		//if it isn't, create it, add it, and point primenode.south to it
		//
		else
		{
			if (!board.findNode(mazeStr, nodeArray, nodeCount))
			{
				branchNode = Node(mazeStr);
				nodeArray[nodeCount] = branchNode;
				nodeCount++;
			}
			nodeLocation = board.findNodeLocation(mazeStr, nodeArray, nodeCount);
			pointerNode = &nodeArray[nodeLocation];
			nodeArray[primeNodeLocation].setSouthNode(pointerNode);
		}
		//get west node
		inStream >> mazeStr;
		//if west node is "*", set west node pointer to blocknode
		if (mazeStr == "*")
		{
			pointerNode = NULL;
			primeNode.setWestNode(pointerNode);
		}
		//if west node isn't "*", see if node is already in array
		//if it isn't, create it, add it, and point primenode.west to it
		//
		else
		{
			if (!board.findNode(mazeStr, nodeArray, nodeCount))
			{
				branchNode = Node(mazeStr);
				nodeArray[nodeCount] = branchNode;
				nodeCount++;
			}
			nodeLocation = board.findNodeLocation(mazeStr, nodeArray, nodeCount);
			pointerNode = &nodeArray[nodeLocation];
			nodeArray[primeNodeLocation].setWestNode(pointerNode);
		}
		//get ladderchute node
		inStream >> mazeStr;
		//if ladderchute node is "*", set ladderchute node pointer to blocknode
		if (mazeStr == "*")
		{
			pointerNode = NULL;
			primeNode.setLadderChuteNode(pointerNode);
		}
		//if west node isn't "*", see if node is already in array
		//if it isn't, create it, add it, and point primenode.ladderchute to it
		//
		else
		{
			if (!board.findNode(mazeStr, nodeArray, nodeCount))
			{
				branchNode = Node(mazeStr);
				nodeArray[nodeCount] = branchNode;
				nodeCount++;
			}
			nodeLocation = board.findNodeLocation(mazeStr, nodeArray, nodeCount);
			pointerNode = &nodeArray[nodeLocation];
			nodeArray[primeNodeLocation].setLadderChuteNode(pointerNode);
		}
		
	}
	inStream.close();
	
	char direction;
	Node currentNode;
	string output;
	pointerNode = &nodeArray[0];
	currentNode = *pointerNode;
	bool finished = false;
	string nodeNames[100];
	string nameList;
	int nodesVisited = 0;
	int jumpCount = 0;
	
	while (currentNode.getNodeName() != "H6" && direction != 'q')
	{
		currentNode = *pointerNode;
		nodeNames[nodesVisited] = currentNode.getNodeName();
		nodesVisited++;
		if (currentNode.getNodeName() == "H6")
		{
			cout << "Congratualtions! You've completed the maze!" << endl;
			jumpCount = nodesVisited - 2;
			cout << "You took " << jumpCount << " steps." << endl;
			cout << "The nodes you visited are: ";
			for (int i = 0; i < nodesVisited; i++)
			{
				cout << nodeNames[i] << " ";
			}
			finished = true;
			cout << "\n";
			return 0;
		}
		if (currentNode.hasLadderChuteNode())
		{
			pointerNode = currentNode.getLadderChuteNode();
			currentNode = *pointerNode;
			cout << "You've hit a ladder node or a chute node!\n";
		}
		
		output = "You are currently at node ";
		output += currentNode.getNodeName();
		output += "\n";
		output += "You can move in the following directions: ";
		output += currentNode.directionOutput();
		cout << output << endl;
		cout << "Which direction would you like to move? ";
		cin >> direction;
		cout << "\n";
		
		switch(direction)
		{
			case 'n':
				if (currentNode.getNorthNode() == NULL)
				{
					cout << "Invalid direction\n";
				}
				else
				{
					pointerNode = currentNode.getNorthNode();
				}
				
				break;
			case 'e':
				if (currentNode.getEastNode() == NULL)
				{
					cout << "Invalid direction\n";
				}
				else
				{
					pointerNode = currentNode.getEastNode();
				}
				
				break;
			case 's':
				if (currentNode.getSouthNode() == NULL)
				{
					cout << "Invalid direction\n";
				}
				else
				{
					pointerNode = currentNode.getSouthNode();
				}
				break;
			case 'w':
				if (currentNode.getWestNode() == NULL)
				{
					cout << "Invalid direction\n";
				}
				else
				{
					pointerNode = currentNode.getWestNode();
				}
				break;
			case 'q':
				cout << "Good bye!";
				break;
			default:
				cout << "Invalid Input\n";
				break;
		}
	}
	
	return 0;
}
