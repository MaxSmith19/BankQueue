#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Queue.h"
#include "fileHandling.h"
#include <algorithm>
using namespace std;

Queue::Queue() {};

vector<string> Queue::initQueue() {
	string data;
	fstream queueFile(fileName);
	vector<size_t> values;
	int size = getListSize(); //get the size of the current queue
	while (getline(queueFile, data)) {
		queueList.push_back(data);//add every value from the queueInfo file into the queueList
	}
	return queueList;
}
void Queue::addQueue(string user) {
	int i;
	string data;
	ofstream queueWriteFile(fileName, ios::app); //append the file instead of write.
	ifstream queueReadFile(fileName);//both an input and output file required to check the user doesnt already exist. 
	//I was going to use fstream (with both methods of writing and reading), however it caused huge issues.
	int size = getListSize();
	if (size != 0) {
		while (getline(queueReadFile, data)) {
			size_t found = data.find(user);
			if (data.find(user) != string::npos) {//if the user is found within the file
				cout << "User is already in the queue!" << endl; // then they wont be added to the queue
				return;
			}
			else {
				queueList.push_back(user); //otherwise they'll be added to the queueList
				queueWriteFile << user << endl; //and written to the file
				break;
			}
		}
	}
	else {
		queueList.push_back(user); //otherwise they'll be added to the queueList
		queueWriteFile << user << endl; //and written to the file
	}

}
void Queue::alertPosition() {
	cout << "It is " << queueList[0]<<"'s turn in the queue!";
}
void Queue::removeQueue(string user) {
	string data;	
	int size = getListSize()-1;
	ifstream queueFile(fileName);
	size_t found = 0;
	while (getline(queueFile, data)) {
		size_t found = data.find(user);
	}
	
	if (found != string::npos) { //if the user is in the queue.
		ofstream truncFile(fileName, ofstream::out | fstream::trunc); //all information is deleted from the file
		truncFile.close();
		fstream queueFile(fileName, ios::app);
		for (int i = 0; i < size; i++) {
			if (queueList[i] == user) {
				queueList.erase(queueList.begin() + i); //they are removed from the queue
				cout << "User has been removed from the queue!\n";
				
			}

			queueFile << queueList[i] << "\n";
		}
	}
	else {
		cout << "You are not a part of the queue..." << endl;
	}
	queueFile.close();
}
int Queue::returnPos(string user) {
	int i=0;
	string data;
	ifstream queueFile(fileName);
	while (getline(queueFile, data)) {
		if (data.find(user) != string::npos) {
			return i;
		}
		i++;
	}
	return string::npos;
}
void Queue::advanceQueue() {
	removeQueue(queueList[0]); //using removeQueue(), remove the first item in the list.
}
void Queue::clearQueue() {
	//admin function, the entire queue can be deleted
	queueList.clear();
	ofstream truncFile(fileName, ofstream::out | fstream::trunc);
	truncFile.close();
}
void Queue::printQueue() {
	//print the contents of the queue file.
	for (int i = 0; i < getListSize(); i++) {
		cout << queueList[i] << "|";
	}
}