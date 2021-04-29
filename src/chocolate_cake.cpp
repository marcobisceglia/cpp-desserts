#include "chocolate_cake.h"

ChocolateCake::ChocolateCake(string name, int people, int time, LevelEnum level, int diameter, string chocolate):Dessert(name, people, time, level), Cake(name, people, time, level,diameter), ChocolateDessert(name, people, time, level, chocolate){
	this->diameter = diameter;
}

ChocolateCake::~ChocolateCake(){}

void ChocolateCake::printInfo(){
	// call super
	Dessert::printInfo();
	cout << "Diametro: " << this-> diameter << endl;
	cout << "Cioccolato: " << this-> chocolate << endl;
}

void ChocolateCake::getType(){
	cout << "Chocolate cake" << endl;
}
