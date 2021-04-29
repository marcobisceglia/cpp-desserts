#ifndef CAKE_H_
#define CAKE_H_

#include "dessert.h"

// eredita virtual
class Cake: virtual public Dessert{
protected:
	int diameter; // campo aggiuntivo

public:
	// costruttore
	Cake(string, int, int, LevelEnum, int);

	// distruttore
	~Cake();

	// override di un metodo virtual (posso ottenere binding dinamico)
	void printInfo();

	// override di un metodo non virtual (mi aspetto dessert nel caso di polimorfismo)
	void getType();
};

#endif /* CAKE_H_ */
