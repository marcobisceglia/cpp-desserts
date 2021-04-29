#ifndef CHOCOLATE_DESSERT_H_
#define CHOCOLATE_DESSERT_H_

#include "dessert.h"

class ChocolateDessert: virtual public Dessert{
protected:
	string chocolate; // campo aggiuntivo

public:
	// costruttore
	ChocolateDessert(string, int, int, LevelEnum, string);

	// distruttore
	~ChocolateDessert();

	// override di un metodo virtual (posso ottenere binding dinamico)
	void printInfo();

	// override di un metodo non virtual (mi aspetto dessert nel caso di polimorfismo)
	void getType();
};

#endif /* CHOCOLATE_DESSERT_H_ */
