// Lab 1: TigerBook Social Network
// Name: Ryan Crumpler
// Class: COMP 2710
// Date: 10/9/17
// Email: rec0027
// File rec0027_1w.cpp

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

// Description: Defines User class and its funcfions
class User
{
   private:
      string name;
      vector<string> groups;
   public:
      
      User(string nameIn)
      {
         name = nameIn;
         groups.push_back("#All");
      }
      
      //FunctionL getName
      //Inputs: none
      //Outputs: name of user
      //Description: returns name of user object
      string getName()
      {
         return name;
      }
   
      //FunctionL addGroup
      //Inputs: group name
      //Outputs: none
      //Description: adds a group to the user object
      void addGroup(string g)
      {
         groups.push_back(g);
      }
      
      //FunctionL getGroups
      //Inputs: none
      //Outputs: groups vector 
      //Description: returns groups vector of user object
      vector<string> getGroups()
      {
         return groups;
      }
};


// Description: Defines Message class and its functions
class Message
{
   private:
      string message;
      
   public:
      Message(string msg) 
      {
         message = msg;
      }
      
      
      //FunctionL getWallVector
      //Inputs: user and vector of indexes
      //Outputs: vector containing wall messages for user
      //Description: Scans message for all valid wall strings and returns them in a vector
      vector<string> getWallVector(string user, vector<int> index)
      {
         vector<string> output;
         string sub_buffer;
         for (int i = 0; i < index.size(); i++)
         {
            sub_buffer = message.substr(index[i] + 2, user.size());
            if (sub_buffer == user)
            {
               if (i < index.size() - 1)
               {
                  output.push_back(message.substr(index[i], index[i + 1] - index[i]));
               }
               else
               {
                  output.push_back(message.substr(index[i]));
               }
            }
         }
         return output;
      }
      
      //FunctionL getHomeVector
      //Inputs: user and vector of indexes
      //Outputs: vector containing homw messages for user
      //Description: Scans message for all valid home strings and returns them in a vector
      vector<string> getHomeVector(User u, vector<int> index)
      {
         vector<string> output;
         vector<string> groups = u.getGroups();
         string sub_buffer;
         for (int i = 0; i < index.size(); i++)
         {     
            if (i < index.size() - 1)
            {
               sub_buffer = message.substr(index[i], index[i + 1] - index[i]);
            }
            else 
            {
               sub_buffer = message.substr(index[i]);
            }
            for (int j = 0; j < groups.size(); j++) 
            {
               string s = sub_buffer.substr(sub_buffer.find(":") + 1, groups[j].size());
               if (s == groups[j] || s == u.getName())
               {
                  output.push_back(sub_buffer);
               }
            }
            
         }
         return output;
      }
      
      //FunctionL parseName
      //Inputs: string of message
      //Outputs: name in message
      //Description: Scans a message and returns name of sender
      string parseName(string strIn)
      {
         int found1 = strIn.find("!");
         int found2 = strIn.find(":");
         return strIn.substr(found1 + 1, found2 - found1 - 1);
      }
      
      //FunctionL parseGroup
      //Inputs: string of message
      //Outputs: group in message
      //Description: Scans a message and returns group
      string parseGroup(string strIn)
      {
         int found1 = strIn.find(":");
         int found2 = strIn.find("!>");
         return strIn.substr(found1 + 1, found2 - found1 - 1);
      }
      
      //FunctionL parseMsg
      //Inputs: string of message
      //Outputs: message
      //Description: Scans a message and returns just the message text
      string parseMsg(string strIn)
      {
         int found = strIn.find(">");
         return strIn.substr(found + 1);
      }
};



// Description: Defines System class and its functions
class System 
{
      public:  
      string name;
      string group;
   vector<User> uV;
   string message_buffer;
   vector<int> index;
   
   //Function: enter_name
   //Inputs: name
   //Outputs: name of user
   //Description: Prompts user to enter name and returns the name
   string enter_name() 
   {
         string username;
      cout << "\nEnter user name >  ";
      getline(cin, username);
         username = username.substr(0, username.find(" "));
         return username;
   }
      
      //Function: enter_group
      //Inputs: name
      //Outputs: group 
      //Description: Prompts user to enter group and returns the group
      string enter_group()
      {
         string groupname;
         cout << "Enter group name > ";
      getline(cin, groupname);
      groupname = groupname.substr(0, groupname.find(" ")); 
         if (groupname.at(0) != '#') 
      {
         groupname = "#" + groupname; 
      }
         return groupname;
      }
   
      //Function: enter_message
      //Inputs: name
      //Outputs: message
      //Description: Prompts user to enter message and returns the message when delimiter is entered
      string enter_message()
      {
      cout << "Enter the message > ";
      bool endmsg = false;
      string msg = "";
      string message = "";
      while (endmsg == false) 
      {
         getline(cin, msg);
         if (msg != "^!") 
         {
            message += msg + "\n";
         }
         else 
         {
            endmsg = true;
         }
      }
         return message;
      }  
   
      //Function: build_buffer
      //Inputs: name, group and message
      //Outputs: vector stroing indexes of where each message starts
      //Description: prepends the message buffer with the new message and returns a vector that contains index of where each message starts
      vector<int> build_buffer(string name, string group, string message)
      {
         vector<int> ind;
         int pos;
         string msg;
         msg = message_buffer;
         message_buffer = "<!" + name + ":" + group + "!>" + message;
      message_buffer += msg;
      pos = message_buffer.find("<", 0);
      while (pos != string::npos)
      {
         ind.push_back(pos);
         pos = message_buffer.find("<", pos + 1);
      }
      return ind;
      }
   
   //Function: broadcast
   //Inputs: name
   //Outputs: none
   //Description: stores a broadcasted message in message buffer
      void broadcast() 
      {
         string message;
         message = enter_message();
         index = build_buffer(name, "#All", message);
      }
   
      //Function: multicast
      //Inputs: name
      //Outputs: none
      //Description: stores a multicasted message in message buffer
      void multicast() 
      {
         bool valid = false;
         bool exit = false;
         string prevGroup = group;
         string message;
         while (valid == false) 
         {
            group = enter_group();
            if (group == "#e")
            {
               exit = true;
               valid = true;
               break;
            }
            else
            {
               for (int i = 0; i < uV.size(); i++)
               {
                  for (int j = 0; j < uV[i].getGroups().size(); j++)
                  {
                     vector<string> g;
                     g = uV[i].getGroups();
                     if (group == g[j])
                     {
                        valid = true;
                        break;
                     }
                  }
                  if (valid == true)
                  {
                     break;
                  }
                  
               }     
            }
            if (valid == false)
            {
               cout << "Invalid group. Enter valid group or (e) to exit" << endl;
            }           
         }
       if (exit == true)
         {
            group = prevGroup;
         }
       else
       {
         message = enter_message();
            index = build_buffer(name, group, message);
         }
      }
   
      //Function: unicast
      //Inputs: name
      //Outputs: none
      //Description: stores a unicasted message in message buffer
      void unicast() 
      {
         bool valid = false;
         bool exit = false;
         string message;
         string receive;
         while (valid == false) 
         {
            name = enter_name();
            if (name == "e")
            {
               exit = true;
               valid = true;
               break;
            }
            else
            {
               for (int i = 0; i < uV.size(); i++)
               {
                  if (name == uV[i].getName())
                  {
                     valid = true;
                     break;
                  }
               }  
            }
            if (valid == false)
            {
               cout << "Invalid user name. Enter valid name or (e) to exit" << endl;
            }           
         }
         if (exit == false)
         {
            message = enter_message();
            index = build_buffer(name, receive, message);
            for (int i = 0; i < uV.size(); i++)
            {
               User usr = uV[i];
               if (usr.getName() == receive)
               {
                  usr.addGroup(receive);
                  break;
               }
            }
         }
      }
   
      //Function: new_group
      //Inputs: name
      //Outputs: none
      //Description: creates a new group
      void new_group() 
      {
         bool valid = false;
         bool exit = false;
         bool stop = false;
         string prevGroup = group;
         while (valid == false) 
         {
            stop = false;
            group = enter_group();
            if (group == "#e")
            {
               exit = true;
               valid = true;
               break;
            }
            else
            {
               for (int i = 0; i < uV.size(); i++)
               {
                  for (int j = 0; j < uV[i].getGroups().size(); j++)
                  {
                     vector<string> g;
                     g = uV[i].getGroups();
                     if (group == g[j])
                     {
                        stop = true;
                        cout << "Invalid group. Enter valid group or (e) to exit" << endl;
                        break;
                     }
                  }
                  if (stop == true)
                  {
                     break;
                  }
                  
               }     
            }
            if (stop == false)
            {
               valid = true;
               break;
            }           
         }
         if (exit == true)
         {
            group = prevGroup;
         }
         else 
         {
         for (int i = 0; i < uV.size(); i++) 
            {
               User usr = uV[i];
               if (usr.getName() == name)
               {
                  usr.addGroup(group);
                  uV[i] = usr;
                  break;
               }
            }
         }
         cout << makeHeader(group + " group created") << endl;
      }
      
      //Function: join_group
      //Inputs: name
      //Outputs: none
      //Description: adds user to existing group
      void join_group() 
      {
         bool valid = false;
         bool exit = false;
         string prevGroup = group;
         while (valid == false) 
         {
            group = enter_group();
            if (group == "#e")
            {
               exit = true;
               valid = true;
               break;
            }
            else
            {
               for (int i = 0; i < uV.size(); i++)
               {
                  for (int j = 0; j < uV[i].getGroups().size(); j++)
                  {
                     vector<string> g;
                     g = uV[i].getGroups();
                     if (group == g[j])
                     {
                        valid = true;
                        break;
                     }
                  }
                  if (valid == true)
                  {
                     break;
                  }
                  
               }     
            }
            if (valid == false)
            {
               cout << "Invalid group. Enter valid group or (e) to exit" << endl;
            }           
         }
         if (exit == true)
         {
            group = prevGroup;
         }
         else
         {
            for (int i = 0; i < uV.size(); i++) 
            {
               User usr = uV[i];
               if (usr.getName() == name)
               {
                  usr.addGroup(group);
                  uV[i] = usr;
                  break;
               }
            }
            cout << makeHeader(name + " is in " + group + " group") << endl;
         }
      }
         
      //Function: new_User
      //Inputs: name
      //Outputs: none
      //Description: creates a new user
      void new_User()
      {
         bool valid = false;
         bool exit = false;
         bool stop = false;
         string prevName = name;
         while (valid == false) 
         {
            stop = false;
            name = enter_name();
            if (name == "e")
            {
               exit = true;
               valid = true;
               break;
            }
            else
            {
               for (int i = 0; i < uV.size(); i++)
               {
                  if (name == uV[i].getName())
                  {
                     stop = true;
                     cout << "Invalid user name. Enter valid name or (e) to exit" << endl;
                     break;
                  }
               }     
            }
            if (stop == false)
            {
               valid = true;
               break;
            }           
         }
         if (exit == true) 
         {
            name = prevName;
         }
         else
         {
            User usr(name);
            uV.push_back(usr);
            cout << makeHeader("Welcome to the TigerBook Social Network, " + name + "!") << endl;
         }
      }
      
      //Function: switch_User
      //Inputs: name
      //Outputs: none
      //Description: switches to existing user
      void switch_User()
      {
         bool valid = false;
         bool exit = false;
         string prevName = name;
         while (valid == false) 
         {
            name = enter_name();
            if (name == "e")
            {
               exit = true;
               valid = true;
               break;
            }
            else
            {
               for (int i = 0; i < uV.size(); i++)
               {
                  if (name == uV[i].getName())
                  {
                     valid = true;
                     break;
                  }
               }  
            }
            if (valid == false)
            {
               cout << "Invalid user name. Enter valid name or (e) to exit" << endl;
            }           
         }
         if (exit == true)
         {
            name = prevName;
         }
         else
         {
            cout << makeHeader("Welcome back to TigerBook Social Network, " + name + "!") << endl; 
         }
      }
      
      //Function: getWall
      //Inputs: name
      //Outputs: none
      //Description: returns all messages a user sent
      void getWall()
      {
         Message mess(message_buffer);
         string in;
      vector<string> out;
      out = mess.getWallVector(name, index);
      string n;
      string g;
      string m;
      string output;
      cout << makeHeader(name + "'s Wall Page") << endl;
      for (int i = 0; i < out.size(); i++)
      {
         if (i == 2)
         {
            while (in != "yes" || in != "no")
            {
               in = "";
               cout << "More Message? (yes/no): ";
               getline(cin, in);
               if (in == "yes" || in == "no")
               {
                  break;
               }
            }
            if (in == "no")
            {
               break;
            }  
               
         }
         n = mess.parseName(out[i]);
         g = mess.parseGroup(out[i]);
         m = mess.parseMsg(out[i]);
         output = "(" + g + ") >\n" + m; 
         cout << output << endl;
      }
      }
      
      //Function: getHome
      //Inputs: name
      //Outputs: none
      //Description: returns all messages a user receives
      void getHome()
      {
         Message mess(message_buffer);
         vector<string> out;
         string n;
      string g;
      string m;
      string output;
      string in;
         for (int i = 0; i < uV.size(); i++)
         {
            User usr = uV[i];
            if (usr.getName() == name)
            {
               out = mess.getHomeVector(usr, index);
            break;
            }
         }
         cout << makeHeader(name + "'s Home Page") << endl;
         for (int j = 0; j < out.size(); j++)
         {
            if (j == 2)
         {
            while (in != "yes" || in != "no")
            {
               in = "";
               cout << "More Message? (yes/no): ";
               getline(cin, in);
               if (in == "yes" || in == "no")
               {
                  break;
               }
            }
            if (in == "no")
            {
               break;
            }     
         }
            n = mess.parseName(out[j]);
         g = mess.parseGroup(out[j]);
         m = mess.parseMsg(out[j]);
         output = n + "(" + g + ") >\n" + m; 
         cout << output << endl;
      }

      }
      
      //Function: makeHeader
      //Inputs: string in header
      //Outputs: header string
      //Description: adds a string to the headder
      string makeHeader(string strIn)
      {
         string output = "============================================================\n|         " + strIn + "    |\n============================================================";
         return output;
      }
      
      //Function: printMenu
      //Inputs: name
      //Outputs: menu
      //Description: returns menu options
      string printMenu()
   {
      string menu = "Create new user (n), Broadcast (b), Multicast (m), Unicast (u),  Wall page (w), Home page (h), Create new group (g),\nJoin a group (j), Switch user (s), Quit (q)\n\n";    
      return  menu;
   }
};


//Description: main program for printing menu
int main()  
{
   string input;
   System sys;
   bool start_new = true;
   cout << sys.makeHeader("The TigerBook Social Network!") << endl;
   while (input != "q")
   {
      cout << sys.printMenu();
      cout << "Choose an option: ";
      getline(cin, input);
      if (input == "q")
      {
         break;
      }
      while (input != "n" && start_new == true)
      {
         cout << "Must create new user first select (n) to create new user: ";
         getline(cin, input);
         if (input == "n")
         {
            start_new = false;
            break;
         }
      }
      if (input == "n")
      {
         sys.new_User();
         start_new = false;
      }  
      else if (input == "b")
      {
         sys.broadcast();
      }
      else if (input == "m")
      {
         sys.multicast();
      }
      else if (input == "u")
      {
         sys.unicast();
      }
      else if (input == "w")
      {
         sys.getWall();
      }
      else if (input == "h")
      {
         sys.getHome();
      }
      else if (input == "g")
      {
         sys.new_group();
      }
      else if (input == "j")
      {
         sys.join_group();
      }
      else if (input == "s")
      {
         sys.switch_User();
      }
      
   }
   cout << sys.makeHeader("Thank you for using Tigerbook Social Network") << endl;
   return 0;
};

