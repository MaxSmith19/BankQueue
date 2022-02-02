#pragma once
#include <string>
#include <vector>
using namespace std;

//vector<string> seperateItems(string data, char seperator=',');
bool seperate(string data, string items, char seperator=',');
vector<string> splitValues(string data, char seperator = ',');
bool getVIP(string readFileName, string username);
vector<size_t> itemCount(string data, string item);