
#include<fstream>
using namespace std;

#include <iostream> 
using namespace std;

#include <vector>
using namespace std;

#include <string>
using namespace std;

#include "Node.cpp"
using namespace std;

#include "File.cpp"
using namespace std;

#include "User.cpp"
using namespace std;

class System 
{
public:
	
	File file;
	Node maze;
	User winner;
	vector<Node> nodeVector;
	vector<User> userVector;
	string startNode;
	string endNode;
	bool finish;
	int currUser;

	void buildMap()
	{
		finish = false;
		vector<vector<string> > input = file.read("configuration.txt");
		for (int i = 0; i < input.size(); i++)
		{
			vector<string> x = input[i];
			if (i > 2)
			{
				for (int j = 0; j < x.size(); j++)
				{
					bool end = false;
					Node map(x[j]);
					for (int k = 0; k < nodeVector.size(); k++)
					{
						if (nodeVector[k].getNodeName() == map.getNodeName() || map.getNodeName() == "*")
						{
							end = true;
							break;
						}
					}
					if (end == false)
					{
						nodeVector.push_back(map);
					}
				}
			}			
		}
		Node map;
		int index;
		for (int i = 0; i < input.size(); i++)
		{
			vector<string> x = input[i];
			if (i <= 2)
			{
				if (i == 1)
				{
					startNode = x[0];
					maze.setNodeName(x[0]);
				}
				if (i == 2)
				{
					endNode = x[0];
				}
				continue;
			}
			for (int j = 0; j < nodeVector.size(); j++)
			{
				{
					if (nodeVector[j].getNodeName() == x[0])
					{
						map = nodeVector[j];
						index = j;
						break;
					}
				}
			}
			if (x[1] != "*") 
			{
				for (int j = 0; j < nodeVector.size(); j++)
				{
					if (nodeVector[j].getNodeName() == x[1])
					{
						map.attachNewNode(&nodeVector[j], 0);
						break;
					}
				}
			}
			else
			{
				map.attachNewNode(NULL, 0);
			}
			if (x[2] != "*") 
			{
				for (int j = 0; j < nodeVector.size(); j++)
				{
					if (nodeVector[j].getNodeName() == x[2])
					{
						map.attachNewNode(&nodeVector[j], 1);
						break;
					}
				}
			}
			else
			{
				map.attachNewNode(NULL, 1);
			}
			if (x[3] != "*") 
			{
				for (int j = 0; j < nodeVector.size(); j++)
				{
					if (nodeVector[j].getNodeName() == x[3])
					{
						map.attachNewNode(&nodeVector[j], 2);
						break;
					}
				}
			}
			else
			{
				map.attachNewNode(NULL, 2);
			}
			if (x[4] != "*") 
			{
				for (int j = 0; j < nodeVector.size(); j++)
				{
					if (nodeVector[j].getNodeName() == x[4])
					{
						map.attachNewNode(&nodeVector[j], 3);
						break;
					}
				}
			}
			else
			{
				map.attachNewNode(NULL, 3);
			}
			if (x[5] != "*") 
			{
				for (int j = 0; j < nodeVector.size(); j++)
				{
					if (nodeVector[j].getNodeName() == x[5])
					{
						map.attachSnakeLadderNode(&nodeVector[j]);
						break;
					}
				}
			}
			else
			{
				map.attachSnakeLadderNode(NULL);
			}
			nodeVector[index] = map;
		}
	}

	string enterName() 
	{
		string username; 
		cout << "\nEnter name of player: ";
		cin >> username;
		return username;
	}

	string enterChoice(vector<string> choices) 
	{
		bool end = false;
		string choice;
		while (end == false)
		{
			cin >> choice;
			for (int i = 0; i < choices.size(); i++)
			{
				if (choice == choices[i].substr(0,1))
				{
					end = true;
					break;
				}
			}
			if (end == true)
			{
				break;
			}
			cout << "Invalid choice. Enter valid choice: ";
		}		
		return choice;
		
	}

	int numUsers()
	{
		int num;
		cout << "Enter number of players: ";
		cin >> num;
		return num;
	}

	void addUsers(int numUsers)
	{
		while (numUsers > 0)
		{
			User usr;
			usr.setName(enterName());
			usr.setPosition(startNode);
			userVector.push_back(usr);
			numUsers--;
		}
	}

	void playerTurn()
	{
		User usr;
		Node map;
		usr = userVector[currUser];
		vector<string> choices;
		for (int i = 0; i < nodeVector.size(); i++)
		{
			if (nodeVector[i].getNodeName() == userVector[currUser].getPosition())
			{
				map = nodeVector[i];
				break;
			}
		}
		string out = "\n" + usr.getName() + " is currently at node " + usr.getPosition() + ". You can move ";
		if (map.getSnakeLadderNode() != NULL)
		{
			out = "\nSnake or Ladder Node entered";
			cout << out << endl;
			usr.setPosition(map.getSnakeLadderNode()->getNodeName());
			usr.addMove();
		}
		else
		{
			if (map.getAttachedNode(0) != NULL)
			{
				choices.push_back("North");
			}
			if (map.getAttachedNode(1) != NULL)
			{
				choices.push_back("East");
			}
			if (map.getAttachedNode(2) != NULL)
			{
				choices.push_back("South");
			}
			if (map.getAttachedNode(3) != NULL)
			{
				choices.push_back("West");
			}

			for (int i = 0; i < choices.size(); i++)
			{
				out += choices[i];
				if (i != choices.size() - 1)
				{
					out += " or ";
				}
			}

			out += ". What is your choice? ";
			cout << out << endl;
			string choice = enterChoice(choices);
			if (choice == "N")
			{
				usr.setPosition(map.getAttachedNode(0)->getNodeName());
				usr.addMove();
			}
			else if (choice == "E")
			{
				usr.setPosition(map.getAttachedNode(1)->getNodeName());
				usr.addMove();
			}
			else if (choice == "S")
			{
				usr.setPosition(map.getAttachedNode(2)->getNodeName());
				usr.addMove();
			}
			else if (choice == "W")
			{
				usr.setPosition(map.getAttachedNode(3)->getNodeName());
				usr.addMove();
			}
			userVector[currUser] = usr;
		}
		if (usr.getPosition() == endNode)
		{
			winner = usr;
			finish = true;
		}
		
		userVector[currUser] = usr;
	}

	void turnSet()
	{
		while (userVector[currUser].getMoves() > 0 && finish == false)
		{
			playerTurn();
		}
	}

	void game()
	{
		int count = 0;
		bool fin = false;
		while (fin == false)
		{
			currUser = 0;
			while (currUser < userVector.size())
			{
				User usr = userVector[currUser];
				string player = usr.getName();
				cout << "Current Player is " + player << endl;
				usr.rollDice();
				cout << player + " currently has " << usr.getMoves() << " moves left" << endl;
				userVector[currUser] = usr;
				turnSet();
				if (finish == true)
				{
					break;
				}
				if (currUser == userVector.size() - 1)
				{
					currUser = 0;
				}
				else
				{
					currUser++;
				}
			}
			fin = true;
		}
	}

	void getWinner()
	{
		cout << winner.getName() + " is the winner!" << endl;
		cout << winner.getName() + " took " << winner.getTotalMoves() << " steps" << endl;
		string out;
		out = "The nodes visited are";
		vector<string> v = winner.getVisited();
		for (int i = 0; i < v.size(); i++)
		{
			out += " " + v[i];
		}
		cout << out << endl;
	}

};