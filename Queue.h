#pragma once
#include <string>
#include <vector>
using namespace std;

class Queue {
public:
	Queue();
	string getfileName() { return fileName; }

	vector<string> getList() { return queueList; }
	int getListSize() { return queueList.size(); }
	void alertPosition();
	vector<string> initQueue();
	void addQueue(string user);
	void removeQueue(string user);
	void clearQueue();
	void advanceQueue();
	int returnPos(string user);
	void printQueue();
private:
	string fileName = "queueInfo.txt";
	vector<string> queueList = {};
};