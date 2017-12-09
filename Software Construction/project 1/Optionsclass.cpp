/// Julie Dixon
/// jad0070
/// Options Class

#include <iostream>
#include <string>
using namespace std;

   int main() {
      
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
      string Garray[i]; //array for just groupinfo (one specific)
      string GJarray[k]; ///array for creating and joining a group
      string Uarray[l]; //array for userinfo
      int numCasts[n]; //number of messages
      string YorN; //yes or no string
   
      
      choice = tolower(choice);
     
      while (choice != "b" || choice != "m"|| choice != "s" || choice != "u" || choice != "n" || choice != "w" 
   || choice != "h" || choice != "j" || choice != "g" || choice != "q")
   {
      cout<< "\n\nPlease choose a valid letter";
      
      
      cout << "Choose an option: ";
      getline(cin, choice);
      choice = choice.substr(0, choice.find(" "));///make sure to alter the delimiter
      //choice = tolower(choice);
      
      
   }
   
   while (choice != "q") {
      cout << "========================================================\n";
      cout << "|          The TigerBook Social Network!               |\n";
      cout << "========================================================\n\n";
      
      
      
      cout << "Create new user (n), Broadcast (b), Multicast (m), Unicast (u), Wallpage (w), Home page (h), Create a group (g),\nJoin a group (j), Switch user (s), Quit(q)\n\n";
      
      
      cout << "Choose an option: ";
      getline(cin, choice);
      choice = choice.substr(0, choice.find(" "));///make sure to alter the delimiter
      
      
      

   
   
   public string getUserInfo()
   {
  
   while (choice == "n") {
   
      cout << "\n\n" + "Please enter username: ";
      getline(cin, username);
      username = username.substr(0, username.find(" "));///make sure to alter the delimiter
   
      cout << "========================================================\n";
      cout << "|      Welcome to the TigerBook Social Network, " +  username + " |\n";
      cout << "========================================================\n\n";
   }
   
   while (choice == "s") {
   
      cout << "\n\n" + "Enter user's name: "
         getline(cin, username);
      username = username.substr(0, username.find(" "));///make sure to alter the delimiter
   
      cout << "========================================================\n";
      cout << "|      Welcome back to the TigerBook Social Network, " +  username + " |\n";
      cout << "========================================================\n\n";
   }


   }
    
    
   public string getGroupInfo()
   {
  
   while (choice == "g")
   {
    
      cout << "\n\n" + "Please enter group name: ";
      getline(cin, groupname);
      groupname = groupname.substr(0, username.find(" "));///make sure to alter the delimiter
      
      /// if index doesn't work try array.add()
      Garray[i] = {username + "#" + groupname + ">"};
      i++;
   
      cout << "========================================================\n";
      cout << "|           " + groupname + " group created            |\n";
      cout << "========================================================\n\n";
      
   }
   
   while (choice == "j")
   {
    
      cout << "\n\n" + "Please enter group name: ";
      getline(cin, groupname);
      groupname = groupname.substr(0, username.find(" "));///make sure to alter the delimiter
      
      Garray[i] = {username + "#" + groupname + ">"};
      i++;

            
      cout << "========================================================\n";
      cout << "|     " + username + " is in " + groupname + " group   |\n";
      cout << "========================================================\n\n";
      
   }
   
   while(Garray[i].contains(groupname)) {
   
    GJarray[k] = Garray[i];
    i++;
    k++;
    n++;
   }
   
   while (Garray[i].contains(username)) {
   
   Uarray[l] = Garray[i];
   i++;
   k++;
   n++;
   }
   
   }
   
   
   
   public string getPages() 
   {
   
       while (choice == "h") 
       {
    
    cout << "========================================================\n";
    cout << "|            " + username + "'s Home Page              |\n";
    cout << "========================================================\n\n";
    
    
     while(mcast.contains(groupRecip) == Garray[i].contains(groupname))
     {
   
  
   
     }
   ///this probably wont work, rethink strategy 
   while(ucast.contains(recipient) == Uarray[l].contains(username));
   
   {
   
   ///think about this (draw it out)!!!
   
   }
   
    
    cout << /*user in group */ + "(" + /* array thing */ + ") > \n\n";
    cout << // message from user in group to group
    
      while (numCasts > 2)
         {
         
         cout <<  "\n\n" + "                More messages? (yes/no): " 
         getline(cin, YorN);
         YorN = YorN.subtr(0, YorN.find(" "));///change delimiter if needed
         
    
         while (YorN == "yes") 
            {
            cout << //rest of messages
            cout <<  "\n\n" + "                More messages? (yes/no): " 
            getline(cin, YorN);
            YorN = YorN.subtr(0, YorN.find(" "));///change delimiter if needed
            }
            
            ////may need to alter numcasts, check again later
            while (numCasts =< 2) {
            
            
            cout << "========================================================\n";
            cout << "|            " + username + "'s Home Page              |\n";
            cout << "========================================================\n\n";

    
            cout << /*user in group */ + "(" + /*groupname*/ + ") > \n\n";
            cout << // message from user in group to group

            
            }
         }
         
         
      }                
   
   //STOPPING POINT ALTER VARIABLES STILL TO ACCOMADATE WALL PAGE
   while (choice == "w")
   {
   cout << "========================================================\n";
   cout << "|            " + username + "'s Wall Page              |\n";
   cout << "========================================================\n\n";
   
   cout << /*user in group */ + "(" + /*groupname*/ + ") > \n\n";
   cout << // message from user in group to group
    
      while (casts > /*2*/)
         {
         cout <<  "\n\n" + "                More messages? (yes/no): " 
         getline(cin, YorN);
         YorN = YorN.subtr(0, YorN.find(" "));///change delimiter if needed
         //in errors class write code if user replies
         //other than yes or no
         
          ///NOT FINISHED: write code to assure only 2 messages are displayed at first.
         
    
         while (YorN == "yes") 
            {
            cout << //rest of messages
            cout <<  "\n\n" + "                More messages? (yes/no): " 
            getline(cin, YorN);
            YorN = YorN.subtr(0, YorN.find(" "));///change delimiter if needed
            }
         }

   
   
   }

   
   
   
   }
   
   } 
}
}

