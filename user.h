#pragma once
#include <string>
#include "Queue.h"
using namespace std;

class User {
public:

	User();
	~User();

	void setUsername(string name) { username = name; }
	string getUsername() { return username; };

	void setFirstN(string name) { firstN = name; }
	string getFirstN() { return firstN; }

	void setSecondN(string name) { secondN = name; }
	string getSecondN() { return secondN; }

	void setPassword(string key) { password = key; }
	string getPassword() { return password; }

	
	void setSpecial(bool vip) { special=vip; }
	bool getSpecial() { return special; }

	void appInfo();
	bool changeUserType();
	void writeToFile();
	int secondMenu(Queue queue);

protected:
	string username;
	string firstN;
	string secondN;
	string password;
	bool special = false;
	int queuePos;
};
class VIPUser : public User{
public:
	int secondMenu(Queue queue);
protected:
	bool special = true;
};
class Admin : public User {
public:
	int secondMenu(Queue queue);
	bool logAdmin();
private:
	string username = "Admin";
	string password = "Admin";
};