/*
 * David Dixon
 * This class sets the board for use by creating the nodes. 
 */
 
 #include <iostream>
 //#include "Node.cpp"
 
 using namespace std;
 
 class Board
 {
	 public:
		Board();
		bool findNode(string nodeName, Node nodeArray[], int nodeCount);
		int findNodeLocation(string nodeName, Node nodeArray[], int nodeCout);
 };
 
 Board::Board()
 {
	 
 };
 
 bool Board::findNode(string nodeName, Node nodeArray[], int nodeCount)
 {
	 for (int i = 0; i < nodeCount; i++)
	 {
		if (nodeName == nodeArray[i].getNodeName())
		{
			return true;
		}
	 }
	 return false;
 };
 //returns location of node if node is found
 //returns -1 if node not found
 int Board::findNodeLocation(string nodeName, Node nodeArray[], int nodeCount)
 {
	 for (int i = 0; i < nodeCount; i++)
	 {
		if (nodeName == nodeArray[i].getNodeName())
		{
			return i;
		}
	 }
	 
	 return -1;
 };
 
 
