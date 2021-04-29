#ifndef SPECIAL_DESSERT_H_
#define SPECIAL_DESSERT_H_

#include "dessert.h"

// eredita con private, SpecialDessert non � sottotipo di Dessert
class SpecialDessert: private Dessert {
public:
	// costruttore
	SpecialDessert(string, int, int, LevelEnum, map<string, string>);
	
	// overload costruttore
	SpecialDessert(string, int, int, LevelEnum);
	
	// distruttore
	virtual ~SpecialDessert(); 
	
	// override di un metodo virtual (posso ottenere binding dinamico)
	void printInfo();
	
	// override di un metodo non virtual (mi aspetto dessert nel caso di polimorfismo)
	// ricorda però che SpecialDessert non è sottotipo di Dessert, quindi avrò sempre SpecialDessert
	void getType();

	// override di un metodo virtual (posso ottenere binding dinamico)
	// ricorda però che SpecialDessert non è sottotipo di Dessert, quindi avrò sempre printAll di SpecialDessert
	void printAll();
};

#endif /* SPECIAL_DESSERT_H_ */
