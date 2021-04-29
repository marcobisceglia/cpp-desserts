#ifndef CHOCOLATE_CAKE_H_
#define CHOCOLATE_CAKE_H_

#include "cake.h"
#include "chocolate_dessert.h"

// eredita da entrambe le classi
class ChocolateCake: public Cake, public ChocolateDessert{

public:
	// costruttore
	ChocolateCake(string, int, int, LevelEnum, int, string);

	// distruttore
	~ChocolateCake();

	// override di un metodo virtual (posso ottenere binding dinamico)
	void printInfo();

	// override di un metodo non virtual (mi aspetto dessert nel caso di polimorfismo)
	void getType();
};

#endif /* CHOCOLATE_CAKE_H_ */
