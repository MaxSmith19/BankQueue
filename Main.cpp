#include <iostream>
#include <fstream>
#include "userLog.h"
#include "fileHandling.h"
#include "user.h"
#include "queue.h"

using namespace std;
int main()
{
	Queue q; //Queue class instantiated for easy access, available throughout the whole main scope
	q.initQueue(); //Initiate the queue, so that the queueList is available straight away
	bool userType = false;
	bool flag = false;
	int choice = 0;
	int xChoice = 0;

    UserLog loginMenu; //Create the userlog class.
	
	
	while (choice != 3) { // While the user hasnt chosen to log out
		choice = loginMenu.UI(); //input is done through the userlog instead of in main for added security 
		switch (choice) {
		case 1:
			while (!flag) { 
				User newUser; //New user is created so the program can keep track of all their information for later in the program
				newUser.setSpecial(loginMenu.setSpecial());//it also means that any functions that require it
				newUser.setUsername(loginMenu.setUsername());//can easily access the information with getters and setters
				newUser.setFirstN(loginMenu.setFirstN());
				newUser.setSecondN(loginMenu.setSecondN());
				newUser.appInfo();
				newUser.setPassword(loginMenu.setPassword());
				flag = true;
				newUser.writeToFile(); //None of the files are kept in main so that they arent easy to access
				main(); //it also keeps the users password safe as theyre only kept in secureFile.txt
			}
			break;
		case 2:
		{
			User account;

			account.setUsername(loginMenu.loginUser()); //the user is signed in, and only their username is kept in the account class
			account.setSpecial(account.changeUserType()); //the file is checked to see if the user is a normal or VIPUSer
			if (account.getSpecial() == true) { //True meaning that they are a VIP, false meaning they are a regular user.
				VIPUser VIPAccount;
				VIPAccount.setUsername(account.getUsername()); //a new class is made with the same values as the previous
				//this is because there are some functions that are overwritten for the sake of different 
				xChoice = 0;
				while (xChoice != 5) {
					xChoice = VIPAccount.secondMenu(q);
					switch (xChoice) {
					case 1:
						q.addQueue(VIPAccount.getUsername());
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						q.removeQueue(VIPAccount.getUsername());
						break;
					case 5:
						break;
					}
				}
				choice = 0;
				break;
			}
			else {
				xChoice = 0;
				while (xChoice != 3) {
					xChoice = account.secondMenu(q);
					switch (xChoice) {
					case 1:
					{
						q.addQueue(account.getUsername());
						break;
					}
					case 2:
					{
						q.removeQueue(account.getUsername());
						break;
					}
					}
				}
				break;
			}
			
		}
		case 20:
		{
			Admin newUser;
			if (newUser.logAdmin()) {//the credential information isnt going to be kept in the file but will be constantly the same.
				int aChoice = 0;
				while (aChoice != 4) {
					aChoice = newUser.secondMenu(q);
					switch (aChoice) {
					case 1:
						q.clearQueue();
						break;
					case 2:
						q.advanceQueue();
					case 3:
						q.printQueue();
					}
				}
			}
		}
		case 3:
			EXIT_SUCCESS;
			break;
		}
		
			
		choice = 0;
	}
	choice = 0;
    return 0;
}