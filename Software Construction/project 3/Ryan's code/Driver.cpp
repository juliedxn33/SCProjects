
#include<fstream>
using namespace std;

#include <iostream> 
using namespace std;

#include <vector>
using namespace std;

#include <string>
using namespace std;

#include "System.cpp"
using namespace std;

int main()  
{
	System sys;
	sys.buildMap();
	sys.addUsers(sys.numUsers());
	sys.game();
	sys.getWinner();
	return 0;
};