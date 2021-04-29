#include "ui.h"

UI::UI() {}

UI::~UI() {}

void UI::showMenu(){
	cout << "Scegli opzione: " << endl;
	cout << "1. Stampa le ricette complete" << endl;
	cout << "2. Stampa solo le informazioni" << endl;
	cout << "3. Stampa solo i tipi di ricette" << endl;
	cout << "4. Esci" << endl << endl;
}

void UI::setMenuChoice() {
	cout << "Inserisci opzione: ";
	string choice;
	cin >> choice;
	cout << endl;

	if (choice.length()==1 && isdigit(choice[0])){
		int num = stoi(choice);

		switch (num){
			case 1:
				Cookbook::getInstance();
				Cookbook::printDesserts();
				UI::exitDialog();
				break;
			case 2:
				Cookbook::getInstance();
				Cookbook::printDessertsInfo();
				UI::exitDialog();
				break;
			case 3:
				Cookbook::getInstance();
				Cookbook::printDessertsTypes();
				UI::exitDialog();
				break;
			case 4:
				cout << "Ciao" << endl;
				break;
			default:
				cout << "Opzione non valida" << endl << endl;
				cin.clear();
				UI::setMenuChoice();
				break;
		}
	} else{
		cout << "Input deve essere un numero!" << endl << endl;
		UI::setMenuChoice();
	}
}

void UI::exitDialog(){
	cout << endl << "Vuoi continuare? (y/n) ";
	string s = "";
	cin >> s;
	cout << endl;

	if (s=="y" || s=="Y"){
		UI::start();
	} else if (s=="n" || s=="N"){
		cout << "Ciao" << endl;
	} else{
		cout << "Input non valido" << endl;
		UI::exitDialog();
	}
}

void UI::start(){
	UI::showMenu();
	UI::setMenuChoice();
}
