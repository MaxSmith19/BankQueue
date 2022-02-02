#include "userLog.h"
#include "fileHandling.h"
#include "user.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
UserLog::UserLog() {} //Userlog constructor
UserLog::~UserLog() {}
int UserLog::UI() {
	int choice;
	cout << "------BANK---LOGIN------\n";
	cout << "1.Create an account \n";
	cout << "2.Log into an account \n";
	cout << "3.Exit\n";
	cin >> choice;
	//The input is taken within this function instead of in main for added security.
	return choice;
}

bool UserLog::setSpecial() {
	bool special;
	string temp;
	cout << "Is this a business account?(yes/no)\n";
	cin >> temp;
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower); //to lower on the entire string, so that if the user
	//---puts "YES" or "Yes" or "Y", they are still able to give the right account type
	if (temp == "yes" or temp == "y") {
		special = true;
	}
	else {
		special = false;
	}
	return special;
}
bool UserLog::getSpecial() { return special; }

string UserLog::setUsername() {

	string username, key, data;
	bool flag = false;
	string readFileName = "secureFile.txt"; 
	ifstream readFile(readFileName);//File is opened 

	cout << "What is your username\n";
	cin >> username;
	if (username.length() >= 8) { // if their username is more than or equal to the length of 8
		vector<string>values = splitValues(readFileName, ','); //split the values of the read file
		if (values.size() != 0) { //if there are items in the file, then check each name to make sure they dont conflict
			for (int i = 0; i < values.size() - 2; i = i + 2) { //for the length of the file - 2 (as the last two items cause conflict)
				if (values[i] == username) { //-- As they're definitely not going to be usernames
					cout << "this username has already been taken, try another username\n";
					cin >> username;
				}

			}
		}
		else {
			return username;
		}
		return username;
	}
	else {
		cout << "This username must be at least 8 characters!";
		setUsername();
	}
	
}
string UserLog::setFirstN() {
	string name;
	cout << "What is your first name: \n";
	cin >> name;
	return name;
	
}
string UserLog::setSecondN() {
	string name;
	cout << "What is your second name: \n";
	cin >> name;
	return name;

}
string UserLog::getUsername() {return username;}

string UserLog::setPassword() {
	string key, temp;
	cout << "What is your key\n";
	cin >> key;
	if (key.length() >= 8) {//make sure their password is a at least 8 characters
		cout << "Please type your key again\n";
		cin >> temp;

		if (key == temp) {
			password = key; //Additional validation to make sure that the user typed the right password
			return key;
		}
	}
	else {
		cout << "Your password should be at least 8 characters!\n";
		setPassword();
	}
}
string UserLog::getPassword() { return password; }

string UserLog::loginUser() {

	
	string data, username, key;
	int attempts = 2;
	do { //do while loop used so that the while loop does not need to carry on if the user logs in correctly
		string readFileName="secureFile.txt"; //this needs to be kept within the while loop so that it resets the pointer value to the beginning of the file.
		ifstream readFile(readFileName);
		string data;
		int i = 0;
		cout << "Enter your username: \n";
		cin >> username;
		cout << "Enter your key: \n";
		cin >> key;
		vector<string>values = splitValues(readFileName, ',');//split the values to compare the values
		while (i < values.size()) { //for the length of the vector
			if (values[i] == username) { //if the first item is equal to username
				if (values[i + 1] == key) { //and the second is equal to password or [i+1](as its the next value in the vector)
					cout << "Youre logged in!" << endl;
					return username;
				}
			}
			i++;
		}
		cout << "You have " << attempts << "attempts remaining"<< endl;
		attempts--;

	} while (attempts >= 0);
}

