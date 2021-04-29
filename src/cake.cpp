#include "cake.h"

Cake::Cake(string name, int people, int time, LevelEnum level, int diameter): Dessert(name, people, time, level){
	this->diameter = diameter;
}

Cake::~Cake(){}

void Cake::printInfo(){
	Dessert::printInfo(); // call super
	cout << "Diametro: " << this-> diameter << " cm" << endl;
}

void Cake::getType(){
	cout << "Cake" << endl;
}
