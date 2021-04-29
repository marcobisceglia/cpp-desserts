#ifndef UTILITY_H_
#define UTILITY_H_

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <dirent.h>

using namespace std;

// classe statica
class Utility {
private:
	Utility(); // costruttore privato per rendere  la classe statica
	virtual ~Utility();

public:
	// metodi
	static vector<string> fileToVectorString(string);
	static void addKeyValue(map<string, string>&, string, string);
	static map<string, string> getInfoFromFile(string);
	static map<string, string> getIngredientsFromFile(string);
	static vector<string> getDescriptionFromFile(string);
	static void printMap(map<string, string>);
	static void trim(string&);
	static void printVectorString(vector<string>);
	static vector<string> getFilePaths(const char *);
};

#endif /* UTILITY_H_ */
