#include <iostream>
#include <vector>
#include "dessert.h"

using namespace std;

Dessert::Dessert(string nome, int porzioni = 1, int tempo = 60, LevelEnum level = Easy) {
	this->name = nome;
	this->people = porzioni;
	this->time = tempo;
	this->level = level;
}

Dessert::Dessert(string nome, int porzioni = 1, int tempo = 60, int level = 1) {
	this->name = nome;
	this->people = porzioni;
	this->time = tempo;
	this->level = static_cast<LevelEnum>(level);
}

Dessert::~Dessert(){}

void Dessert::printInfo(){
	cout << endl;
	// convert string to upper case
	transform(this->name.begin(), this->name.end(), this->name.begin(), ::toupper);
	cout << this->name;
	
	cout << endl;
	cout << "Livello: " << this-> level << "/" << Hard << endl;
	cout << "Tempo: " << this-> time << " minuti" << endl;
	cout << "Persone: " << this-> people << endl;
}

void Dessert::printIngredients(){
	cout << endl << "INGREDIENTI:" << endl;
	Utility::printMap(this->ingredients);
}

void Dessert::printDescription(){
	cout << endl << "DESCRIZIONE:" << endl;
	Utility::printVectorString(this->description);
}

void Dessert::printAll(){
	this->printInfo();
	this->printIngredients();
	this->printDescription();
}

void Dessert::setIngredients(map<string, string> ingredients){
	this->ingredients = ingredients;
}

void Dessert::setDescription(vector<string> description){
	this->description = description;
}

map<string, string> Dessert::getIngredients(){
	return this->ingredients;
}

vector<string> Dessert::getDescription(){
	return this->description;
}

void Dessert::getType(){
	cout << "Dessert" << endl;
}
