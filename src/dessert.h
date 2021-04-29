#ifndef DESSERT_H_
#define DESSERT_H_

#include <string>
#include <vector>
#include <map>
#include "recipe.h"
#include "utility.h"
#include "level.cpp"

using namespace std;

class Dessert: public Recipe{
protected:
	string name;
	map<string, string> ingredients;
	int people;
	int time; // in minuti
	LevelEnum level;
	vector<string> description; // lista di passaggi

public:
	Dessert(string, int, int, LevelEnum); // costruttore
	Dessert(string, int, int, int); // overload costruttore
	virtual ~Dessert(); // distruttore

	// metodi da recipe
	virtual void printInfo();
	virtual void printIngredients();
	virtual void printDescription();
	virtual void printAll(); // print info, ingredients and description

	// metodi di dessert
	void setIngredients(map<string, string>);
	void setDescription(vector<string>);

	map<string, string> getIngredients();
	vector<string> getDescription();
	
	void getType(); // non virtual, no binding dinamico
};

#endif /* DESSERT_H_ */
