#pragma once
#include <string>
using namespace std;
class UserLog {
public:
	UserLog();
	~UserLog();

	int UI();

	string setUsername();
	string getUsername();

	string setFirstN();
	string setSecondN();

	string setPassword();
	string getPassword();

	bool setSpecial();
	bool getSpecial();

	void writeToFile();
	string loginUser();
private:
	string username;
	string firstN;
	string secondN;
	string password;
	bool special;

	
	
};