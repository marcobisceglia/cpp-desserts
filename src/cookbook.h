#ifndef COOKBOOK_H_
#define COOKBOOK_H_

#include "dessert.h"
#include "special_dessert.h"
#include <memory>
#include "vector"
using namespace std;

class Cookbook {
private:
	static bool started;
	static Cookbook* cookbook;
	vector<Dessert*> desserts;
	vector<shared_ptr<SpecialDessert>> special_desserts;

	Cookbook();
	Dessert* getDessertFromInfo(map<string, string>); // utility
	SpecialDessert* getSpecialDessertFromInfo(map<string, string>); // utility
	void loadDesserts();
	void loadSpecialDesserts();

public:
	virtual ~Cookbook();
	static Cookbook* getInstance();
	static void printDesserts();
	static void printDessertsInfo();
	static void printDessertsTypes();
};

#endif /* COOKBOOK_H_ */
