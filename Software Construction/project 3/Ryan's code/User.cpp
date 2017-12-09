
#include<fstream>
using namespace std;

#include <iostream> 
using namespace std;

#include <vector>
using namespace std;

#include <string>
using namespace std;

#include <cstdlib>
using namespace std;

#include <ctime>
using namespace std;

class User
{
private:
	string name;
	string position;
	int moves;
	int totalMoves;
	vector<string> visited;

public:

	string getPosition()
	{
		return position;
	}

	void setPosition(string posIn)
	{
		position = posIn;
		visit(position);
		//addMove();
	}

	int getMoves()
	{
		return moves;
	}

	void setName(string nameIn)
	{
		name = nameIn;
		moves = 0;
		totalMoves = 0;
	}

	string getName()
	{
		return name;
	}

	void rollDice()
	{
		srand(time(0));
    	int roll = rand() % 6 + 1;		
		moves = roll;
		//cout << "moves " << moves << endl;
	}

	void visit(string node)
	{
		visited.push_back(node);
	}

	vector<string> getVisited()
	{
		return visited;
	}

	void addMove()
	{
		totalMoves++;
		moves--;
	}


	int getTotalMoves()
	{
		return totalMoves;
	}

};