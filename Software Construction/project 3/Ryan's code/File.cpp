#include<fstream>
using namespace std;

#include <iostream> 
using namespace std;

#include <vector>
using namespace std;

#include <string>
using namespace std;

//#include<algorithm>
//using namespace std;

class File
{
public:
	ifstream inStream;
	ofstream outStream;

    //Function: fileExists
    //Inputs: string of file name
    //Outputs: bol if file exists or not
    //Checks if a file exists
	bool fileExists(string fileIn)
	{
		ifstream file(fileIn.c_str());
		if (file.is_open())
		{
			file.close();
			return true;
		}
		return false;
	}

    //Function readFile
    //Inputs: name of file to read from
    //Outputs: contents of a file
    //Reads the contents of a file and outputs contents as a string
    vector<vector<string> > read(string fileIn)
    {
    	string contents;
    	vector<vector<string> > output;
    	vector<string> line;
    	ifstream file (fileIn.c_str());
    	if (file.is_open())
    	{
    		while (!file.eof())
    		{
    			getline(file, contents);
    			string l;
    			for (int i = 0; i < contents.length() - 1; i++) 
    			{
    				l = contents.at(i);
    				if (l == " ") 
    				{
    					l = "";
    					continue;
    				}
    				else if (l == "*") 
    				{
    					line.push_back(l);
    					l = "";
    					continue;
    				}
    				else 
    				{	
    					i++;
    					l += contents.at(i);
    					line.push_back(l);
    					l = "";
    				}
    				if (i == contents.length() - 2)
    				{
    					break;
    				}
    			}
    			output.push_back(line);
    			line.clear();
    		}
    	}
    	file.close();
    	return output;
    }

    //Function createFile
    //Inputs: fine name
    //Outputs: none
    //creates a new file
    void createFile(string fileIn)
    {
    	outStream.open(fileIn.c_str());
    	outStream.close();
    }
};
