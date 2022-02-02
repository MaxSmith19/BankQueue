#include "fileHandling.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<size_t> itemCount(string data, string item) {
	vector<size_t> index;
	size_t pos = data.find(item, 0); //find all instances of the parameter (mostly "," in this case)
	index.push_back(0); //add the number zero to help looping later on
	while (pos != string::npos)
	{
		index.push_back(pos);// add the instance of comma
		pos = data.find(item, pos + 1); //then after that position, find the next comma.
	}
	//credit to Benjamin Lindley - Stack Overflow - https://stackoverflow.com/questions/4034750/find-all-a-substrings-occurrences-and-locations
	return index;
}
vector<string> splitValues(string readFileName, char seperator) {
	ifstream readFile(readFileName); 
	string data;
	vector<string> values;

	while (getline(readFile, data, ',')) { //read the data file for each comma.
		data.erase(std::remove(data.begin(), data.end(), '\n'), data.end());
		//removes the 0,1 and trailing \n so that its easier to read the file.
		values.push_back(data);
		//add the item into the vector for comparison

	}
	return values;
}
bool getVIP(string readFileName,string username) {
	ifstream readFile(readFileName);
	string data;
	bool VIP = false;
	vector<string> values;

	while (getline(readFile, data, ',')) { //whilst the data isnt equal to "\n" and the data is being read
		data.erase(std::remove(data.begin(), data.end(), '\n'),data.end());
		//add the item without the \n being used so its easier to convert from string to bool
		values.push_back(data);

	}
	for (int i = 0; i < values.size(); i++) { //for every item in the vector
		if (values[i] == username) { //if it is their username
			if (values[i + 2].find("1")!=-1) { //and their userType is 1
				return VIP = true;//they are therefore a VIP
			}if (values[i + 2].find("0")!=-1) {
				return VIP = false;//otherwise they are not.
			}
		}
	}

}