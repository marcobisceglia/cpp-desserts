#include "cookbook.h"
#include "cake.h"
#include "chocolate_dessert.h"
#include "chocolate_cake.h"

bool Cookbook::started = false;
Cookbook *Cookbook::cookbook = nullptr;

Cookbook::Cookbook() {
	// inizializzo il singleton caricando i file nel campo desserts e special dessert
	cout << "Caricamento ricettario..." << endl;
	loadDesserts();
	loadSpecialDesserts();
}

Cookbook* Cookbook::getInstance() {
  // se il ricettario è già stato creato non viene stampato nulla a differenza di prima
	if (!started) {
		cookbook = new Cookbook();
		started = true;
  }

	return cookbook;
}

Cookbook::~Cookbook() {
	this->started = false;
	for(auto el: this->desserts){
		delete(el);
	}
	// delete non necessaria per this->special_desserts grazie a shared_ptr
	delete(cookbook);
}

Dessert* Cookbook::getDessertFromInfo(map<string, string> map){
	bool isCake = false;
	bool isChocolate = false;
	Dessert *dessert;
	string name;
	LevelEnum level;
	int minutes;
	int people;
	int diameter;
	string chocolate;

	for (auto itr = map.begin(); itr != map.end(); ++itr) {
		string key = itr->first;
		string value = itr->second;

		Utility::trim(key);
		Utility::trim(value);

		// stabilisco se � dessert, cake, chocolate o chocolate dessert
		if (key.compare("diametro") == 0){
			isCake = true;
			diameter = stoi(value);
		}else if(key.compare("cioccolato") == 0){
			isChocolate = true;
			chocolate = value;
		}else if(key.compare("nome") == 0){
			name = value;
		}else if(key.compare("minuti") == 0){
			minutes = stoi(value);
		}else if(key.compare("persone") == 0){
			people = stoi(value);
		}else if(key.compare("livello") == 0){
			level = static_cast<LevelEnum>(stoi(value));
		}

		// sfrutto polimorfismo
		if (isCake && !isChocolate){
			dessert = new Cake(name, people, minutes, level, diameter);
		}else if(!isCake && isChocolate){
			dessert = new ChocolateDessert(name, people, minutes, level, chocolate);
		}else if(isCake && isChocolate){
			dessert = new ChocolateCake(name, people, minutes, level, diameter, chocolate);
		}else{
			dessert = new Dessert(name, people, minutes, level);
		}
	}
	return dessert;
}

SpecialDessert* Cookbook::getSpecialDessertFromInfo(map<string, string> map){
	string name;
	LevelEnum level;
	int minutes;
	int people;

	for (auto itr = map.begin(); itr != map.end(); ++itr) {
		string key = itr->first;
		string value = itr->second;

		Utility::trim(key);
		Utility::trim(value);

		if(key.compare("nome") == 0){
			name = value;
		}else if(key.compare("minuti") == 0){
			minutes = stoi(value);
		}else if(key.compare("persone") == 0){
			people = stoi(value);
		}else if(key.compare("livello") == 0){
			level = static_cast<LevelEnum>(stoi(value));
		}
	}

	return new SpecialDessert(name, people, minutes, level);
}

void Cookbook::loadDesserts(){
	auto filePaths = Utility::getFilePaths("./recipes/desserts/");
	for (auto filePath: filePaths){
		map<string, string> info = Utility::getInfoFromFile(filePath);

		auto ingredients = Utility::getIngredientsFromFile(filePath);

		auto description = Utility::getDescriptionFromFile(filePath);

		Dessert *d = getDessertFromInfo(info);
		d->setIngredients(ingredients);
		d->setDescription(description);

		// aggiungo la ricetta al vettore
		this->desserts.push_back(d);
	}
}

void Cookbook::loadSpecialDesserts(){
	auto filePaths = Utility::getFilePaths("./recipes/special_desserts/");
	for (auto filePath: filePaths){
		map<string, string> info = Utility::getInfoFromFile(filePath);

		auto ingredients = Utility::getIngredientsFromFile(filePath);

		auto description = Utility::getDescriptionFromFile(filePath);

		SpecialDessert *d = getSpecialDessertFromInfo(info);
		this->special_desserts.push_back(shared_ptr<SpecialDessert>(d));
	}
}

void Cookbook::printDesserts(){
	cout << "****************************************************" << endl;
	cout << "RICETTARIO DI DOLCI" << endl;
	cout << "****************************************************" << endl;
	for (auto dessert: cookbook->desserts){
		// dessert->getType(); // no binding dinamico, perch� non � virtual
		dessert->printAll();
		cout << "****************************************************" << endl;
	}

	for (auto special: cookbook->special_desserts){
		special->printAll(); // non contiene ingredients e description, perché sono metodi privati
		cout << "****************************************************" << endl;
	}
}

void Cookbook::printDessertsInfo(){
	cout << "****************************************************" << endl;
	cout << "RICETTARIO DI DOLCI (solo info)" << endl;
	cout << "****************************************************";
	for (auto dessert: cookbook->desserts){
		dessert->printInfo();
		cout << "****************************************************";
	}

	for (auto special: cookbook->special_desserts){
		special->printInfo();
		cout << "****************************************************" << endl;
	}
}

void Cookbook::printDessertsTypes(){
	cout << "****************************************************" << endl;
	cout << "RICETTARIO DI DOLCI (solo tipi)" << endl;
	cout << "****************************************************" << endl;
	for (auto dessert: cookbook->desserts){
		dessert->getType();
	}

	for (auto special: cookbook->special_desserts){
		special->getType();
	}
}


