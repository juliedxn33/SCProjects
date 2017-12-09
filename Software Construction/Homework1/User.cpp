/// Julie Dixon
/// jad0070
/// User Class

#include <iostream>
#include <string>
#include "Optionsclass.cpp"
using namespace std;

class User: public Options
{
   string username;
 
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

   
};
