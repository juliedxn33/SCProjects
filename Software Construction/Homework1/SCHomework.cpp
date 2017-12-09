/// Julie Dixon
/// jad0070
/// SCHomework.cpp

///compile command: g++ SCHomework.cpp
///run command: ./a.out



#include <iostream>
#include <string>
using namespace std;

int main() 
	{
		string more_users = "yes";
	
		string output = "";

		cout << "========================================================\n";
		cout << "|	Welcome to the TigerBook Social Network		|\n";
		cout << "========================================================\n\n";
	

		/// while loop that only iterates more than once if the user answers " yes " to adding more users
		do {
	
			string username;
			string groupname;
			string message;
			string alsomessage;
			bool endofmessage;
			
			/// string for username input
			cout << "Enter user name > ";
			getline(cin, username);
			username = username.substr(0, username.find(" "));

			///string for groupname input			
			cout << "Enter group name > ";
			getline(cin, groupname);
			groupname = groupname.substr(0, groupname.find(" "));
			
			/// statement to prompt person to enter message
			cout << "Enter the message > ";
			
			/// gives values to strings that will be used in upcoming while loop
			endofmessage = false;
			alsomessage = "";
			message = "";
		

			/// while loop defines when the message will end
			while (endofmessage == false)
			{
				getline(cin, alsomessage);
				if (alsomessage != "^!") /// concatinates strings for the message as long
				{			/// as the symbol is not ^!	
					message += alsomessage + "\n";
				}
				else
				{
				endofmessage = true;
				}
			}
			
			/// string concatinating the output which changes value each iteration
			output = username + " (" + groupname + ") >" + "\n" + message + "\n\n" + output;
	
			/// checks for more users
			cout << "Any more users? > ";
			getline(cin, more_users);
			more_users = more_users.substr(0, more_users.find(" "));
		}

		while (more_users == "yes"); /// conditional loop, checks if person answered "yes"
	
	
		cout << "The current messages are >>\n\n";
		
		/// print the output string given in the do while loop and ends the line
		cout << output << endl;

		return 0;
	}


