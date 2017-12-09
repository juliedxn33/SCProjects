/// Julie Dixon
/// jad0070
/// Options Class

#include <iostream>
using namespace std;

#include <string>
using namespace std;

#include <vector>
using namespace std;

#include <algorithm>
using namespace std;


 
 ///// FINISH RECIPIENT ERROR SHOWS UP ON BOTH ONLY SHOULD SHOW UP ON ONE PAGE
 //// BUILD MESSAGEBUFFER FOR MESSAGES ONLY                              ///attempted

 
 
 
 class Information 
 {
 public:
 
 
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
   string choice; //what letter the user chooses
   string username; //user name
   string groupname; //group name
   vector<string> Garray; ///array for all info
   vector<string> Uarray;  //array for just userinfo
   vector <string> Harray; //homepage array
   vector<int> index; //number of messages
   string YorN; //yes or no string
   string information; ///some string containing info
   string message; ///string for messages
   string recipient; ///string to store recipient name 
   string messagebuffer;
   
   
   
      //Prompts for username.
      //Prints banner for username input.
      void newUser() {
      
         cout << "\n\nPlease enter username: ";
         getline(cin, username);
         username = username.substr(0, username.find(" "));
      
         cout << "========================================================\n";
         cout << "|      Welcome to the TigerBook Social Network, " +  username + " |\n";
         cout << "========================================================\n\n";
         
        
      }
   
   
      //Prompts for user name to swtich to.
      //Prints banner for user name input.
      void switchUser() {
      
         cout << "\n\nEnter user's name: ";
         getline(cin, username);
         username = username.substr(0, username.find(" "));
      
         cout << "========================================================\n";
         cout << "|      Welcome back to the TigerBook Social Network, " +  username + " |\n";
         cout << "========================================================\n\n";
      }
   
    
 
      //Prompts for group name.
      //Prints banner for group name input.
      void newGroup()
      {
      
         cout << "\n\nPlease enter group name: ";
         getline(cin, groupname);
         groupname = groupname.substr(0, username.find(" "));
      
      
          
         
         
         cout << "========================================================\n";
         cout << "|           " + groupname + " group created            |\n";
         cout << "========================================================\n\n";
         
         
      }
      
      
   
      //Prompts for group name for user to join.
      //Prints banner for group name input.   
      void joinGroup()
      {
      
         cout << "\n\nPlease enter group name: ";
         getline(cin, groupname);
         groupname = groupname.substr(0, username.find(" "));
      
          
        
      
            
         cout << "========================================================\n";
         cout << "|     " + username + " is in " + groupname + " group   |\n";
         cout << "========================================================\n\n";
         
         
      
      }
       
      
      
      
      
      //Messagebuffer that stores all the messages and returns index
      //for each starting point.
      vector<int> message_buffer(string username, string groupname, string message)
      {
         vector<int> ind;
         int pos;
         string mssg;
         mssg = messagebuffer;
         messagebuffer = "!" + username + "#" + groupname + "<" + message + ">";
      messagebuffer += mssg;
      pos = messagebuffer.find("<", 0);
      while (pos != string::npos)
      {
         ind.push_back(pos);
         pos = messagebuffer.find("<", pos + 1);
      }
      return ind;
      }

      
    
      
      
      //Prompts user to enter broadcast message.
      //Stores user name, groupname, and message into an array. 
      void broadcast()
      {
      
      cout << "\n\nEnter message: ";
      getline(cin, message);
      message = message.substr(0, message.find("^!"));
      groupname = "#All";
      Garray.push_back("!" + username + "#" + groupname + "<" + message + ">");
      
     
       
      
      
      }
      
      
      
      //Prompts user to enter multicast message.
      //Stores user name, groupname, and message into an array. 
      void multicast()
      {
      
      cout << "Enter the group name: ";
      getline(cin,groupname);
      cout << "\n\nEnter message: ";
      getline(cin, message);
      message = message.substr(0, message.find("^!"));
      Garray.push_back("!" + username + "#" + groupname + "<" + message + ">");
      
      
      
      
      }
      
      
      
      
      //Prompts user to enter unicast message.
      //Stores user name, groupname, and message into an array. 
      void unicast()
      {
      
      cout << "Enter the recipient's name: ";
      getline(cin, recipient);
      cout << "\n\nEnter message: ";
      getline(cin,message);
      message = message.substr(0, message.find("^!"));
      Garray.push_back("!" + username + "#" + recipient + "<" + message + ">");
      
      
      
      
      }
      
      
      
      
      //Parses name from an array.
      string parseName(string strIn)
      {
         int found1 = strIn.find("!");
         int found2 = strIn.find("#");
         return strIn.substr(found1 + 1, found2 - found1 - 1);
         
      }

      //Parses group from an array.
      string parseGroup(string strIn)
      {
         int found1 = strIn.find("#");
         int found2 = strIn.find("<");
         return strIn.substr(found1 + 1, found2 - found1 - 1);
         
      }

      
      //Parses message from an array.
      string parseMsg(string strIn)
      {
         int found1 = strIn.find("<");
         int found2 = strIn.find(">");
         return strIn.substr(found1 + 1, found2 - found1 - 1);
         
      }
      
      
      
      
      
      //Displays user's Wall Page
      void wallPage()
      {
      
      
     string WallInfo;
     WallInfo.clear();
     Uarray.clear();
     string input;
     
      
     cout << "========================================================\n";
     cout << "|            " + username + "'s Wall Page              |\n";
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
	
		Information info;
		 string choice;
		
		
		
     
   
      cout << "========================================================\n";
      cout << "|          The TigerBook Social Network!               |\n";
      cout << "========================================================\n\n";
      
      
      
      
   
   
   


  
   
      // conditiaonal loop ensuring that user is continually prompted unless q is chosen.
      while (choice != "q")
      {
      
      cout << "\n\nCreate new user (n), Broadcast (b), Multicast (m), Unicast (u), Wallpage (w), Home page (h), Create a group (g),\nJoin a group (j), Switch user (s), Quit(q)\n\n";
      
      
      // user is prompted to chose an option, each option will call on its respective
      // function in the Information class. 
      cout << "Choose an option: ";
      getline(cin, choice);
      choice = choice.substr(0, choice.find(" "));  ///make sure to alter the delimiter
   
        if (choice == "n") {
        info.newUser();
        
        }
        
        if (choice == "s") {
        info.switchUser();
        }
        
        if (choice == "g") {
        
        info.newGroup();
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
      cout << "	  Thank you for using Tigerbook!\n"; 
      cout << "========================================================\n\n";
      
     return 0;
     };
 
 


	
