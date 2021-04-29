#include "special_dessert.h"

SpecialDessert::SpecialDessert(string name, int people, int time, LevelEnum level, map<string, string> ingredients): Dessert(name, people, time, level){
	this->ingredients = ingredients;
}

SpecialDessert::SpecialDessert(string name, int people, int time, LevelEnum level): Dessert(name, people, time, level){}

SpecialDessert::~SpecialDessert() {}

void SpecialDessert::printInfo(){
	// call super
	Dessert::printInfo(); 
}

void SpecialDessert::getType(){
	cout << "Special dessert" << endl;
}

void SpecialDessert::printAll(){
	// call super
	Dessert::printInfo();
	cout << endl << "INGREDIENTI: non resi visibili" << endl << endl << "DESCRIZIONE: non resa visibile" << endl;
}