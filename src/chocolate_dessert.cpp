#include "chocolate_dessert.h"

ChocolateDessert::ChocolateDessert(string name, int people, int time, LevelEnum level, string chocolate): Dessert(name, people, time, level){
	this->chocolate = chocolate;
}

ChocolateDessert::~ChocolateDessert(){}

void ChocolateDessert::printInfo(){
	Dessert::printInfo(); // call super
	cout << "Cioccolato: " << this-> chocolate << endl;
}

void ChocolateDessert::getType(){
	cout << "Chocolate dessert" << endl;
}
