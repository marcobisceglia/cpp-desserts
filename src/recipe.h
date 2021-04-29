#ifndef RECIPE_H_
#define RECIPE_H_

#include <string>
#include <map>
#include <vector>

using namespace std;

/* Recipe: classe astratta.
 * Una ricetta deve avere un nome, degli ingedienti e
 * e una descrizione dei passaggi per realizzarla.
 */
class Recipe{
public:
	virtual void printInfo() = 0;
	virtual void printIngredients() = 0;
	virtual void printDescription() = 0;
	virtual void printAll() = 0;
};

#endif /* RECIPE_H_ */
