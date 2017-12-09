/// Julie Dixon
/// jad0070
/// Project 2

#include<fstream>
using namespace std;

#include <iostream>
using namespace std;

#include <vector>
using namespace std;

#include <string>
using namespace std;

#include<algorithm>
using namespace std;

#include<ctime>
using namespace std;

#include<sstream>
using namespace std;



class FileInfo
{
   
    public:
   ifstream inStream;
   ofstream outStream;

   
     //Checks if a file exists
      bool fileExists(string fileInput)
      {
      
         fileInput = fileInput + ".txt";     
         ifstream file(fileInput.c_str());
         if (file.is_open())
         {
            file.close();
            
            return true;
         }
         
         return false;
      }

      
      
       //creates a new file
      void createNewFile(string fileInput)
      
      {
         fileInput = fileInput + ".txt";        
         outStream.open(fileInput.c_str());
         outStream.close();
      }
      
      

      
      //Reads the contents of a file and outputs contents as a string
      string readFile(string fileInput)
      {
         string FileContents;
         vector<string> outputArray;
         fileInput = fileInput + ".txt";  
         ifstream SomeFile(fileInput.c_str());
         
         if (SomeFile.is_open())
         {
            while (!SomeFile.eof())
            {
               getline(SomeFile, FileContents);
               outputArray.push_back(FileContents);
            }
         }
         
         SomeFile.close();
         FileContents = "";
         
         for (int i = 0; i < outputArray.size(); i++)
         {
            FileContents = FileContents + outputArray[i];
         }
         return FileContents;
         
      }
      
      
      
      
      //Writes a message to a file
      void writeMessage(string messageInput, string fileInput)
      {
         string FileContents;
         fileInput = fileInput + ".txt";  
         FileContents = readFile(fileInput);
         FileContents = messageInput + FileContents;
         outStream.open(fileInput.c_str());
         
         outStream << FileContents;
         outStream.close();
      }
      
      

 
 	  
 	  void addUser(string input)
 	  {
 	  outStream.open("Usernames.txt", ios:: app);
 	  outStream << input;
 	  outStream.close();
 	  }
 	  
 	  
 	  void addGroup(string input)
 	  {
 	  outStream.open("Groups.txt", ios:: app);
 	  outStream << input;
 	  outStream.close();
 	  }
 	  
 
 };     
 
 
 
 
 class SystemInfo
{


   
public:

   string username;
   string groupname;
   string message;
   string recipient; ///string to store recipient name 
   string messagebuffer;
   vector <int> indexArray;
   vector <string> Garray;
   vector <string> Uarray;
   vector <string> Harray; //homepage array
   FileInfo userFile;
   FileInfo groupFile;
   FileInfo f;
   string YorN; //yes or no string for homepage and wallpage
   string information; ///some string containing info ..... do i actually use this?
   
   string choice; //what letter the user chooses
   string n; // new user
   string b; //broadcast
   string m; //multicast
   string u; //unicast
   string w; //wallpage
   string h; //homepage
   string g; //create group
   string j; //join group
   string s; //switch user
   string q; //quit
   
      
   ///SYSTEM METHOD?



	  //Prompts for username.
      //Prints banner for username input.                            
      //creates file for user
      
      void createUser() {	
			 
		 
		 
		 	      
      
         cout << "\n\nPlease enter username: ";
         getline(cin, username);
         username = username.substr(0, username.find(" "));
      
         cout << "========================================================\n";
         cout << "|  Welcome to Distributed TigerBook System, " +  username + " |\n";
         cout << "========================================================\n\n";
         
         
        if (userFile.fileExists(username) == false)
         {
            userFile.createNewFile(username);
            userFile.addUser("{" + username + "}");
         }    												
        													   
        
        
      }
	
	
	
	//prompts for groupname.
	//if group already exists, gives error message.
	//if group doesn't exist, creates new file and adds info to it.
	
	 void createGroup()
	 
      {
      	 
      	 //FileInfo groupFile;
      
         cout << "\n\nPlease enter group name: ";
         getline(cin, groupname);
         groupname = groupname.substr(0, username.find(" "));
      
          
        
         
         
         
         if (groupFile.fileExists(groupname) == false)
         
          {
          	groupFile.createNewFile(groupname);
            groupFile.addGroup("{" + groupname + "}" + username);
               
            cout << "========================================================\n";
            cout << "|           " + groupname + " group created            |\n";
            cout << "========================================================\n\n";
          }  
          
          else
          
          {
          	cout << "Group has already been created.";  
          }
         
      
      }
      
      
      //prompts for groupname
      // if group exists, add user to the group
      //if group does not exist, give error message.
      
      void joinGroup()
      
      {
      
         //FileInfo groupFile;      
      
      
      	 cout << "\n\nPlease enter group name: ";
         getline(cin, groupname);
         groupname = groupname.substr(0, username.find(" "));
         
         
         if (groupFile.fileExists(groupname) == true)
         
         {
              
     
         	groupFile.addGroup("{" + groupname + "}" + username);    	
         	
            
         	cout << "========================================================\n";
         	cout << "|     " + username + " is in " + groupname + " group   |\n";
         	cout << "========================================================\n\n";
         
        }	
         
         
		else  
			
	    {     
         	cout <<  "Please pick an existing group.";  
        }	
         
      }
      	
      	
      
      
      
	
	  //Messagebuffer that stores all the messages and returns index
      //for each starting point.
      vector<int> message_buffer(stringstream timestamp, string username, string groupname, string message)
      
      {
         vector<int> ind;
         
         int position;
         
         string mssg;
         
         mssg = messagebuffer;
         
         timestamp << time(0);
         string outputTime =  timestamp.str(); 
         
         messagebuffer = "^" + outputTime + "!" + username + "#" + groupname + "<" + message + ">";
      	 messagebuffer += mssg;
         position = messagebuffer.find("<", 0);
         
      while (position != string::npos)
      {
         ind.push_back(position);
         position = messagebuffer.find("<", position + 1);
      }
      
      return ind;
      }
      
      
      
      //parses the messsage buffer into substrings of messages using index from above method
      vector<string> parseBuffer(vector<int> ind, string message)
      
     {
      vector<string> messageString;
      
      for (int i = 0; i < ind.size(); i++)
      {
         if (i == ind.size() - 1)
         {
            messageString.push_back(message.substr(ind[i]));
         }
         else
         
            messageString.push_back(message.substr(ind[i], ind[i + 1] - ind[i]));
         
      }
      return messageString;

	  }
	
	
	
      string parseTime(string strIn)
      
      {
      
      int found1 = strIn.find("^");
      int found2 = strIn.find("!");
      return strIn.substr(found1 + 1, found2 - found1 - 1); 
      
      }
	
	
	 //Parses name from an array.
      string parseName(string strIn)
      
      {
         int found1 = strIn.find("!");
         int found2 = strIn.find("#");
         return strIn.substr(found1 + 1, found2 - found1 - 1);                     ///alter delimiters
         
      }

      //Parses group from an array.
      string parseGroup(string strIn)
      
      {
         int found1 = strIn.find("#");
         int found2 = strIn.find("<");
         return strIn.substr(found1 + 1, found2 - found1 - 1);						///alter delimiters
         
      }

      
      //Parses message from an array.
      string parseMsg(string strIn)
      
      {
      
         int found1 = strIn.find("<");
         int found2 = strIn.find(">");
         return strIn.substr(found1 + 1, found2 - found1 - 1);						//alter delimiters
         	
      }
      
      
      
      
       void broadcast()
       
      {
      
      cout << "\n\nEnter message: ";
      getline(cin, message);
      message = message.substr(0, message.find("^!"));
      groupname = "#All";
      Garray.push_back("!" + username + "#" + groupname + "<" + message + ">"); 
      
      
      f.writeMessage(message, "_All");						
      cout << "\n" + username + " broadcasted a message" << endl;
      
      }
      
      
      //Prompts user to enter multicast message.
      //Stores user name, groupname, and message into an array. 
      void multicast()
      
      {
   
      cout << "Enter the group name: ";
      getline(cin, groupname);
      
      
      if (groupFile.fileExists(groupname) == true)
         
       {
      
        	cout << "\n\nEnter message: ";
     		getline(cin, message);
      		message = message.substr(0, message.find("^!"));
    		Garray.push_back("!" + username + "#" + groupname + "<" + message + ">");
    		
    		
      	   	
      	
      		f.writeMessage(message, "_" + groupname);
      		cout << "\n" + username + "multicasted the group " + groupname << endl;
      		
       }
      		
      else 
      	
       {
      		cout << "Please choose an existing group.";
       }	
      
     }
      
      
      
      
      //Prompts user to enter unicast message.
      //Stores user name, groupname, and message into an array. 
      void unicast()
      
      {
      
     
      cout << "Enter the recipient's name: ";
      getline(cin, recipient);
      
      
      
      if (userFile.fileExists(recipient) == true)
         
       {
      
        	cout << "\n\nEnter message: ";
     		getline(cin,message);
     		message = message.substr(0, message.find("^!"));
     		Garray.push_back("!" + username + "#" + recipient + "<" + message + ">");
     		 
     		  
     		f.writeMessage(message, recipient);
     		cout << "\n" + username + " unicasted " + recipient << endl;
     		 
     	 }
     		 
     	else 
     	{	 
       		cout << "Please choose an existing user.";
        }
        
      }
     
      
      
	  
	  
	  
	   //Displays user's Wall Page
      void wallPage()
      {
      
      
     string WallInfo;
     WallInfo.clear();
     Uarray.clear();
     string input;
     string extractingInfo;
     
      
     cout << "========================================================\n";
     cout << "|            " + username + "'s Wall Page              |\n";
     cout << "========================================================\n\n";
     
      
      //extractingInfo = readFile("_All");
      //vector<string> all = parseString(parseIndex(extractingInfo),extractingInfo); //wrong place continue later needs to be in a loop do
      																				// all last, do group and user first.
      //wallArray.pushback(all[i] + "(#All)");
      
      
      for(int i = 0; i < Garray.size(); i++)
      {
      if(parseName(Garray[i]) == username)
      {
      Uarray.push_back(Garray[i]);
      }
      }
      for(int i = 0; i < Uarray.size(); i++)
      {
      
      
      if (i < 2) {
      
      WallInfo = Uarray[i];
      string Wgroup = parseGroup(WallInfo);
      string Wname = parseName(WallInfo); 
      string Wmessage = parseMsg(WallInfo);
      
      string output = Wname + " (" + Wgroup + ") >\n" + Wmessage;
      cout << output << endl;
      }
      
      else 
      {
      
      cout << "More messages? (yes/no) ";
      getline(cin, input);
      
       		if (input == "yes")
       		{
       	    
       	    WallInfo = Uarray[i];
      		string Wgroup = parseGroup(WallInfo);
      		string Wname = parseName(WallInfo); 
      		string Wmessage = parseMsg(WallInfo);
      
      		string output = Wname + " (" + Wgroup + ") >\n" + Wmessage;
      		cout << output << endl;
     
       		}
			
			else 
			
			{
			
			break;
			
			}      
      
      
      }
      
      
      
	  }
   



      
      
      
      }
      
      //Displays user's Home Page
      void homePage()
      {
      string input;
      string HomeInfo;
      string WallInfo;
      WallInfo.clear();
      HomeInfo.clear();
      Uarray.clear();
      
      
      
       cout << "========================================================\n";
       cout << "|            " + username + "'s Home Page              |\n";
       cout << "========================================================\n\n";
      
      
      for(int i = 0; i < Garray.size(); i++)
      {
      if(parseName(Garray[i]) == username)
      {
      Uarray.push_back(Garray[i]);
      }
      }
      for(int i = 0; i < Uarray.size(); i++)
      {
      
      WallInfo = Uarray[i];
      
      }
      
      for(int i = 0; i < Garray.size(); i++)
      {
      if(parseGroup(Uarray[i]) == parseGroup(Garray[i]))
      {
      Harray.push_back(Garray[i]);
      }
      }
      for(int i = 0; i < Harray.size(); i++)
      {
      
	     if (i < 2) 
	     {
      
    	  HomeInfo = Harray[i];
    	  string Wgroup = parseGroup(HomeInfo);
    	  string Wname = parseName(HomeInfo); 
    	  string Wmessage = parseMsg(HomeInfo);
    	  
    	  string output = Wname + " (" + Wgroup + ") >\n" + Wmessage;
    	  cout << output << endl;
    	  }
    	  
    	  else 
    	  {
    	  
    	  cout << "More messages? (yes/no) ";
    	  getline(cin, input);
    	  
    	   		if (input == "yes")
    	   		{
    	   	    
    	   	    HomeInfo = Harray[i];
    	  		string Wgroup = parseGroup(HomeInfo);
    	  		string Wname = parseName(HomeInfo); 
    	  		string Wmessage = parseMsg(HomeInfo);
    	  
    	  		string output = Wname + " (" + Wgroup + ") >\n" + Wmessage;
    	  		cout << output << endl;
    	 
    	   		}
				
				else 
					
				{
				break;
				}      
    	  
      
     	 }
      
      
      
	  }
   

     
      
      }
      
      

};      
   
     

	
	
	
	
	 // Main class that calls functions from the Information class depending on which
   // letter is chosen.

	int main() {
	
		SystemInfo info;
		string choice;
		
		
		
     
   
      cout << "========================================================\n";
      cout << "|          The Distrubted Tigerbook System               |\n";
      cout << "========================================================\n\n";
      
      
      
      
      
   	 cout << "Please select \"n\" to create a user.\n";
     
   


  
   
      // conditional loop ensuring that user is continually prompted unless q is chosen.
      while (choice != "q")
      {
      
      cout << "\n\nCreate user (n), Broadcast (b), Multicast (m), Unicast (u), Wallpage (w), Homepage (h), Create group (g),\nJoin  group (j), Quit(q)\n\n";
      
      
      // user is prompted to chose an option, each option will call on its respective
      // function in the Information class. 
      cout << "Choose an option: ";
      getline(cin, choice);
      choice = choice.substr(0, choice.find(" "));  ///make sure to alter the delimiter
   
        if (choice == "n") {
        info.createUser();
        
        }
        
        if (choice == "g") {
        
        info.createGroup();
        }
        
        if (choice == "j") {
        info.joinGroup();
        }
        
        if (choice == "b") {
        
        info.broadcast();
        }
       
        if (choice == "m")
        {
        info.multicast();
        }
        
        if (choice == "u")
        {
        info.unicast();
        }
        
        if (choice == "w")
        {
        info.wallPage();
        }
        
        if (choice == "h")
        {
        info.homePage();
        }                      
         
      
      }
   
    /// Banner printed when q is chosen.
      cout << "\n\n========================================================\n";
      cout << "	  Thank you for using Distributed Tigerbook System\n"; 
      cout << "========================================================\n\n";
      
     return 0;
     };
 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		

     
     
     
     
     
     
     
