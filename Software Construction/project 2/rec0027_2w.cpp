// Lab 12 Distributed TigerBook Social Network
// Name: Ryan Crumpler
// Class: COMP 2710
// Date: 10/91617
// Email: rec0027
// File rec0027_2.cpp

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
         ifstream file(fileIn + ".txt");
         if (file.is_open())
         {
            file.close();
            //cout << "exist " + fileIn << endl;
            return true;
         }
         //qcout << "not exist  " + fileIn << endl;
         return false;
      }

      //Function writeMessage
      //Inputs: string of he message and string of file to write to
      //Writes a message to a file
      void writeMessage(string messageIn, string fileIn)
      {
         string contents;
         string temp;
         
         contents = readMesage(fileIn);
         contents = messageIn + contents;
         outStream.open(fileIn + ".txt");
         outStream << contents;
         outStream.close();
      }

      //Function readMEssage
      //Inputs: name of file to read from
      //Outputs: contents of a file
      //Reads the contents of a file and outputs contents as a string
      string readMesage(string fileIn)
      {
         string contents;
         vector<string> output;
         ifstream file ( fileIn + ".txt");
         if (file.is_open())
         {
            while (!file.eof())
            {
               getline(file, contents);
               output.push_back(contents);
            }
         }
         file.close();
         contents = "";
         for (int i = 0; i < output.size(); i++)
         {
            contents = contents + output[i];
         }
         return contents;
      }

      //Function createFile
      //Inputs: fine name
      //Outputs: none
      //creates a new file
      void createFile(string fileIn)
      {
         outStream.open(fileIn + ".txt");
         outStream.close();
      }

      //Function groupCOntains
      //Inputs: string containing the group info
      //Outputs a bool if a group contains a member
      //Checks of a group contains a certain user
      bool groupContains(string input)
      {
         string g;
         ifstream file ("allGroups.txt");
         if (file.is_open())
         {
            while (!file.eof())
            {
               getline(file,g);
            }
         }
         file.close();
         if (g.find(input) != string::npos)
         {
            return true;
         }
         return false;
      }

      //Function addUserGroup
      //Inputs: string of user or group and a boolean that specifies if adding a user to a group or a new user
      //Either adds a user to a group or saves the name of a new user to a file
      void addUserGroup(string input, bool user)
      {
         if (user == false)
         {
            outStream.open("allGroups.txt", ios::app);
         }
         else 
         {
            outStream.open("allUsers.txt", ios::app);
         }
         outStream << input;
         outStream.close();
      }
};

class System
{

private:
   string name;
public:
   System(string nameIn)
   {
      name = nameIn;
      File f;
      if (f.fileExists("allGroups") == false)
      {
         f.createFile("allGroups");
      }
      if (f.fileExists("_All") == false)
      {
         f.createFile("_All");
      }
      if (f.fileExists("allUsers") == false)
      {
         f.createFile("allUsers");
      }
      
   }

   //Function setName
   //Inputs: string of the user name
   //Outputs: None
   // Changes the user name in the constructor of the System object
   void setName(string nameIn)
   {
      name = nameIn;
   }

   //Function enter_name
   //Inputs: bool that define whether user is entering a group or a user
   //Outputs: a string that is either the inputted user name or group name
   //Takes in the user input for either a group name or a user name and returns it
   string enter_name(bool group) 
   {
      string username;
      if (group == true)
      {
         cout << "\nEnter group name > ";
      }
      else 
      {
         cout << "\nEnter user name >  ";
      }
      getline(cin, username);
      username = username.substr(0, username.find(" "));
      return username;
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

   //Function build message
   //InputsL string of the message
   //Outputs: String that contains timestamp, sender and the message
   //Adds timestamp and sender to a message
   string buildMessage(string messageIn)
   {
      stringstream s;
      s << time(0);
      string out = "{!" + s.str() + "!}<!" + name + "!>" + messageIn;
      return out;
   }

   //Function parseSender
   //Inputs: string containing a complete message
   //Outputs: the user that a sent the message
   //Parses the sender out of a message 
   string parseSender(string in)
   {
      int found1 = in.find("<");
      int found2 = in.find(">");
      return in.substr(found1 + 2, found2 - found1 - 3);
   }

   //Function parseMEssage
   //Inputs: string containing a complete message
   //Outputs: the message
   //Parses the message out of the message buffer 
   string parseMessage(string in)
   {
      int found1 = in.find(">");
      int found2 = in.find("(");
      return in.substr(found1 + 1, found2 - found1 - 1);
   }

   //Function parseGroup
   //Inputs: string containing a complete message
   //Outputs: the group that a message was sent to
   //Parses the group out of a message if a group exists
   string parseGroup(string in)
   {
      int found1 = in.find("(");
      int found2 = in.find(")");
      if (found2 - found1 > 1)
      {
         return in.substr(found1 + 1, found2 - found1 - 1);
      }
      return "";
   } 

   //Function newUser
   //Inputs: bool that defines whether it is making new user or group
   //Outputs: none
   //Allows creation of new user or a new group, checks if user or group already exists and creates it if it does not
   void newUser(bool group)
   {
      File f;
      string user;
      while (true)
      {
         user = enter_name(group);
         if (user == "e")
         {
            break;
         }
         else if (group == false)
         {
            if (f.fileExists(user) == false)
            {
               f.createFile(user);
               setName(user);
               f.addUserGroup("{" + user + "}", true);
               cout << "\nWelcome to TigerBook, " + name + "!" << endl;
               break;
            }
            else 
            {
               cout << "User already exists, enter valid user or (e) to exit:";
            }
         }
         else if (group == true)
         {
            if (f.fileExists("_" + user) == false)
            {
               f.createFile("_" + user);
               cout << user + " Group created" << endl;
               f.addUserGroup("{" + user + "}<" + name + ">", false);
               break;
            }
            else 
            {
               cout << "Group already exists, enter valid group or (e) to exit:";
            }
         }  
      }
   }

   //Function broadcast
   //Inputs: none
   //Outputs: none
   //User enters message and it is stored in the all group
   void broadcast()
   {
      File f;
      string message = enter_message();
      message = buildMessage(message);
      f.writeMessage(message, "_All");
      cout << "\n" + name + " broadcasted a message" << endl;
   }

   //Function multicast
   //Inputs: none
   //Outputs: none
   //User enters a group and a message and the message is stored in the group file, checks if group exists and user is part of group
   void multicast()
   {
      bool valid = false;
      string group;
      string message;
      File f;
      while (true)
      {
         group = enter_name(true);
         if (group == "e")
         {
            break;
         }
         else if (f.fileExists("_" + group) == true)
         {
            break;
         }
         else 
         {
            cout << "Group does not exist. Enter valid group or (e) to exit" << endl;
         }
      }
      if (group != "e")
      {
         message = buildMessage(enter_message());
         f.writeMessage(message, "_" + group);
         cout << "\n" + name + "municasted the group " + group << endl;
      }
   }

   //Function unicast
   //Inputs: none
   //Outputs: none
   //User enters message and recipitent and message is stored in recipient file. Checks if recipitent exists
   void unicast()
   {
      string recieve;
      string message;
      File f;
      while (true)
      {
         recieve = enter_name(false);
         if (recieve == "e")
         {
            break;
         }
         else if (f.fileExists(recieve) == true)
         {
            break;
         }
         else 
         {
            cout << "User does not exist. Enter valid user or (e) to exit" << endl;
         }
      }
      if (recieve != "e") 
      {
         message = buildMessage(enter_message());
         f.writeMessage(message, recieve);
         cout << "\n" + name + " municasted " + recieve << endl;
      }
   }

   //Function switchUser
   //Inputs: none
   //Outputs: none
   //Checks if user exists then switches to user
   void switchUser()
   {
      string user;
      File f;
      while (true)
      {
         user = enter_name(false);
         if (user == "e")
         {
            break;
         }
         else if (f.fileExists(user) == false)
         {
            cout << "User does not exist. Enter valid user or (e) to exit" << endl;
         }
         else 
         {
            break;   
         }
      }
      setName(user);
      cout << "\nWelcome back to TigerBook, " + name + "!" << endl;
   }

   //Function joinGroup
   //Inputs: none
   //Outputs: none
   //Checks if group exists then adds user to group   
   void joinGroup()
   {
      string group;
      File f;
      while (true)
      {
         group = enter_name(true);
         if (group == "e")
         {
            break;
         }
         else if (f.fileExists("_" + group) == true)
         {
            if (f.groupContains( "{" + group + "}<" + name + ">") == false)
            {
               f.addUserGroup("{" + group + "}<" + name + ">", false);
               cout << "\nWelcome to the " + group + " group " + name + "!" << endl;
               break;
            }
            else 
            {
               cout << "User is already a member of this group. Enter new group or (e) to exit: ";
            }
         }
         else
         {
            cout << "Invalid group name. Enter valid group or (e) to exit: ";
         }
      }
   }

   //Function parseIndex
   //Inputs: string of a complete message buffer
   //Outputs: int vector that contains the indicies of where each message starts
   //Finds the index of where each message starts in a message buffer and adds each index to a vector
   vector<int> parseIndexes(string message_buffer)
   {
      vector<int> output;
      int pos;
      File f;
      pos = message_buffer.find("{", 0);
      while (pos != string::npos)
      {
         output.push_back(pos);
         pos = message_buffer.find("{", pos + 1);
      }
      return output;
   }

   //Function parseString
   //Inputs: int vector of all message start indexes and the message to be parsed
   //Outputs: a string vector of each message
   //Will use the indexes of each message to parse a message buffer and add each individual message to a vector
   vector<string> parseString(vector<int> pos, string m)
   {
      vector<string> output;
      for (int i = 0; i < pos.size(); i++)
      {
         if (i == pos.size() - 1)
         {
            output.push_back(m.substr(pos[i]));
         }
         else
         {
            output.push_back(m.substr(pos[i], pos[i + 1] - pos[i]));
         }
      }
      return output;
   }

   //Functio groupUser
   //Inputs: string of user or group and bool that indicates if it is a user or group
   //Outputs: a string vector that contains all the users or all the groups that currently exist
   vector<string> groupUsers(string memberIn, bool user)
   {
      File f;
      string group;
      if (user == false) 
      {
         group = f.readMesage("allGroups");
      }
      else 
      {
         group = f.readMesage("allUsers");
      }
      vector<int> positions = parseIndexes(group);
      vector<string> output;
      for (int i = 0; i < positions.size(); i ++)
      {
         if (i == positions.size() - 1)
         {
            output.push_back(group.substr(positions[i]));
         }
         else 
         {
            output.push_back(group.substr(positions[i], positions[i + 1] - positions[i]));
         }
      }
      if (user == false)
      {
         for (int i = 0; i < output.size(); i ++)
         {
            string x = output[i].substr(1, output[i].find("}") - 1);
            if (find(output.begin(), output.end(), x) != output.end())
            {
               output.erase(output.begin() + i);
            }
            else
            {
               output[i] = x;
            }
         }
      }
      else
      {
         for (int i = 0; i < output.size(); i++)
         {
            string x = output[i].substr(1, output[i].size() - 2);
            output[i] = x;
         }
      }
      return output;
   }

   //Function getHomeVector
   //Inputs: None
   //Outputs: string vector of all messages the user recieved
   //Finds al the messages a user recieved and adds all the messages to a vector and sorts the messages by time
   vector<string> getHomeVector()
   {
      File f;
      string x;
      vector<string> groups = groupUsers(name, false);
      x = f.readMesage("_All");
      vector<string> all = parseString(parseIndexes(x), x);
      x = f.readMesage(name);
      vector<string> user = parseString(parseIndexes(x), x);
      vector<string> output;
      for (int i = 0; i < groups.size(); i++)
      {
         x = f.readMesage("_" + groups[i]);
         vector<string> g = parseString(parseIndexes(x), x);
         for (int j = 0; j < g.size(); j++)
         {
            output.push_back(g[j] + "(" + groups[i] + ")");
         }
      }
      for (int i = 0; i < all.size(); i++)
      {
         output.push_back(all[i] + "(#All)");   
      }
      for (int i = 0; i < user.size(); i++)
      {
         output.push_back(user[i] + "()");
      }
      sort(output.begin(), output.end());
      return output;
   }

   //Function getWallVector
   //Inputs: None
   //Outputs: string vector of all messages the user sent
   //Finds al the messages a user sent and adds all the messages to a vector and sorts the messages by time
   vector<string> getWallVector()
   {
      File f;
      string x;
      vector<string> groups = groupUsers(name, false);
      vector<string> users = groupUsers(name, true);
      x = f.readMessage("_All");
      vector<string> all = parseString(parseIndexes(x), x);
      vector<string> output;
      for (int i = 0; i < groups.size(); i++)
      {
         x = f.readMesage("_" + groups[i]);
         vector<string> g = parseString(parseIndexes(x), x);
         for (int j = 0; j < g.size(); j++)
         {
            if (parseSender(g[j]) == name)
            {
               output.push_back(g[j] + "(" + groups[i] + ")");
               cout << "group added" << endl;
            }
         }
      }
      for (int i = 0; i < users.size(); i++)
      {
         x = f.readMesage(users[i]);
         vector<string> u = parseString(parseIndexes(x), x);
         for (int j = 0; j < u.size(); j++)
         {
            if (parseSender(u[j]) == name)
            {
               output.push_back(u[j] + "(" + users[i] + ")");
            }
         }
      }
      for (int i = 0; i < all.size(); i++)
      {
         if (parseSender(all[i]) == name)
         {
            output.push_back(all[i] + "(#All)");
         }        
      }
      sort(output.begin(), output.end());
      return output;
   }  

   //Function getWall
   //Inputs: none
   //Outputs: none
   //Prints out all messages a user sent, stops at first 2 and asks user if they want to se more
   void getWall()
   {
      File f;
      vector<string> x = getWallVector();
      cout << "\n" + name + "'s Wall Page\n" << endl;
      string out;
      string in;
      string group;
      for (int i = x.size() - 1; i >= 0; i--)
      {
            if (i == x.size() - 3)
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
         group = parseGroup(x[i]);
         out = parseSender(x[i]) + " (" + group + ") >\n" + parseMessage(x[i]) + "\n";
         cout << out << endl;

      }
      cout << "End of " + name + "'s Wall Page" << endl;
   }

   //Function getHome
   //Inputs: none
   //Outputs: none
   //Prints out all messages a user recieved, stops at first 2 and asks user if they want to se more
   void getHome()
   {
      File f;
      vector<string> x = getHomeVector();
      cout << "\n" + name + "'s Home Page\n" << endl;
      string out;
      string in;
      string group;
      for (int i = x.size() -1; i >= 0; i--)
      {
            if (i == x.size() - 3)
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
         group = parseGroup(x[i]);
         if (group.size() > 0)
         {
            out = parseSender(x[i]) + " (" + group + ") >\n" + parseMessage(x[i]) + "\n";
         }
         else 
         {
            out = parseSender(x[i]) +  " >\n" + parseMessage(x[i]) + "\n";
         }
         cout << out << endl;
      }
      cout << "End of " + name + "'s Home Page" << endl;
   }
   
   //Function: printMenu
      //Inputs: name
      //Outputs: menu
      //Description: returns menu options
      string printMenu()
   {
      string menu = "\nCreate new user (n), Broadcast (b), Multicast (m), Unicast (u),  Wall page (w), Home page (h), Create new group (g),\nJoin a group (j), Switch user (s), Quit (q)\n\n";     
      return  menu;
   }
};

//Description: main program for printing menu
int main()  
{
   string input;
   System sys("Default");
   bool start_new = true;
   bool cont = false;
   cout << "The TigerBook Social Network!" << endl;
   
   while (input != "q")
   {
      cout << sys.printMenu();
      cout << "Choose an option: ";
      getline(cin, input);
      if (input == "q")
      {
         break;
      }
      if (input == "n")
      {
         sys.newUser(false);
         start_new = false;
      }  
      else if (input == "s")
      {
         sys.switchUser();
         start_new = false;
      }
      while ((input != "s" || input != "n") && start_new == true)
      {
         cout << "Must create new user or log in as esisting user first .select (n) or (s) ";
         getline(cin, input);
         if (input == "n" || input == "s")
         {
            start_new = false;
            cont = true;
            break;
         }
      }
      if (cont == true)
      {
         cont = false;
         continue;
      }
      if (input == "b")
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
         sys.newUser(true);
      }
      else if (input == "j")
      {
         sys.joinGroup();
      }
      else 
      {
         cout << "Invalid Option. Choose an option: ";
      }     
   }
   cout << "Thank you for using Tigerbook Social Network" << endl;
   return 0;
};

