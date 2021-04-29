#include "utility.h"

Utility::Utility() {}

Utility::~Utility() {}

vector<string> Utility::fileToVectorString(string path){
	ifstream file(path);
	string line;
	vector<string> lines;

	if(file.is_open()){
		while(getline(file, line)){
			lines.push_back(line);
		}
	}else cout << "Unable to open the file!";

	file.close();
	return lines;
}

void Utility::addKeyValue(map<string, string> &map, string s, string delimiter){
	string key;
	string value;
	int posOfDel = s.find(delimiter);
	int posOfEndl = s.find("\n");

	key = s.substr(0, posOfDel);

	if (posOfDel != -1){
		// se non c'� delimitatore non c'� value
		value = s.substr(posOfDel + delimiter.length(), posOfEndl);
	}
	map.insert({key, value});
}

map<string, string> Utility::getInfoFromFile(string path){
	// get file lines
	vector<string> lines = fileToVectorString(path);
	// creo mappa per salvare info
	map<string, string> info;

	string delimiter = ":";
	int i = 0;
	while(lines.at(i).compare("---ingredients---") != 0){
		addKeyValue(info, lines.at(i), delimiter);
		i++;
	}

	return info;
}

map<string, string> Utility::getIngredientsFromFile(string path){
	// get file lines
	vector<string> lines = fileToVectorString(path);
	string delimiter = ":";

	// remove info and description
	auto i = find(lines.begin(), lines.end(), "---ingredients---") + 1;
	auto j = find(lines.begin(), lines.end(), "---description---");
	lines = std::vector<string>(i,j); // slice

	// creo mappa per salvare ingredienti
	map<string, string> ingredients;
	for (string line:lines){
		addKeyValue(ingredients, line, delimiter);
	}

	return ingredients;
}

vector<string> Utility::getDescriptionFromFile(string path){
	// get file lines
	vector<string> lines = fileToVectorString(path);

	// remove info and ingredients
	auto i = find(lines.begin(), lines.end(), "---description---") + 1;
	lines = std::vector<string>(i, lines.end()-1); // slice
	return lines;
}

void Utility::printMap(map<string, string> map){
	for (auto itr = map.begin(); itr != map.end(); ++itr) {
		string key = itr->first;
		string value = itr->second;
		Utility::trim(key);
		Utility::trim(value);
		if (value.compare("") == 0){
			cout << key << endl;
		}else{
			cout << key << ": " << value << endl;
		}
	}
}

void Utility::trim(string &s){
	int len = s.length();

	// sx
	int i=0;
	while(i<len && isspace(s[i])){
		i++;
	}

	// dx
	while(len>i && isspace(s[len-1])) {
		len--;
	}

	if(i==len){
		s = "";
	} else{
		s = s.substr(i,len-i);
	}
}

void Utility::printVectorString(vector<string> v){
	for (string line: v){
		cout << "- " << line << endl;
	}
	cout << endl;
}

vector<string> Utility::getFilePaths(const char *dirname){
	vector<string> filePaths;
	DIR *d;
	struct dirent *dir;
	d = opendir(dirname);
	if (d){
		while ((dir = readdir(d)) != NULL) {
			string fileName = dir->d_name;
			if (fileName.length() > 4){
				string ext = fileName.substr(fileName.length()-4, fileName.length());
				if (ext.compare(".txt") == 0){
					filePaths.push_back(dirname + fileName);
				}
			}
		}
		closedir(d);
	}

	return filePaths;
}
