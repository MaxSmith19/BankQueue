#include <iostream>
#include <string>
#include "user.h"
#include <fstream>
#include "fileHandling.h"
#include "Queue.h"
using namespace std;

User::User() {
	username = username;
	firstN = firstN;
	secondN = secondN;
	password = password;
	special = special;
	queuePos = queuePos;
}
User::~User(){}

void User::writeToFile() {
	ofstream writeFile("secureFile.txt", std::ios_base::app);
	writeFile << username << "," << password << "," << special << ",\n"; //this information is used to log the user in
}

void User::appInfo() {
	ofstream writeFile("CustomerList.txt", ios::app);
	writeFile << username << " " << firstN << " " << secondN << endl;//This information will be used when i decide to continue this project
}
bool User::changeUserType() {
	return getVIP("secureFile.txt",username); //This is done through fileHandling instead of in user directly as it is more convenient.
}

int User::secondMenu(Queue queue) {
	int found = queue.returnPos(username);
	if (found!=string::npos) {
		cout << "\nYou're currently number " << found+1 << " in the queue!\n";
	}
	int choice = 0;
	cout << "\n\nWelcome " << username << " To (placeholder) Bank!" << endl;
	cout << "-------------------------------------------------\n";
	cout << "1.Join the Queue" << endl;
	cout << "2.Leave the Queue" << endl;
	cout << "3.Log out" << endl;
	cin >> choice;
	return choice;
}
int VIPUser::secondMenu(Queue queue) {
	int found = queue.returnPos(username);
	if (found != string::npos) {
		cout << "You're currently number " << found+1 << " in the queue!\n";
	}
	int choice = 0;
	cout << "\n\nWelcome " << username << " To (placeholder) Bank!" << endl;
	cout << "---------------BUSINESS ACCOUNT-----------------\n";
	cout << "1.Join the Queue" << endl;
	cout << "2.Set an appointment" << endl;
	cout << "3.Manage appointments" << endl;
	cout << "4.Leave the Queue" << endl;
	cout << "5.Log out" << endl;
	cin >> choice;
	return choice;
}
int Admin::secondMenu(Queue queue) { //Overwriting the secondMenu function=
	cout << "Current Queue:\n";
	queue.printQueue();
	cout << "\n\n";
	int choice = 0;
	cout << "\n\nWelcome " << username << " To (placeholder) Bank!" << endl;
	cout << "---------------ADMIN ACCOUNT-----------------\n";
	cout << "1.Clear the Queue" << endl;
	cout << "2.Advance the queue" << endl;
	cout << "3.View the queue";
	cout << "4.Log out" << endl;
	cin >> choice;
	return choice;
}
bool Admin::logAdmin() {
	string name, pass;
	cout << "What is your username: \n";
	cin >> name;
	cout << "What is your password: \n";
	cin >> pass;
	if (name == username and pass == password) {
		return true;
	}
	else {
		return false;
	}

}