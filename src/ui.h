#ifndef UI_H_
#define UI_H_

#include "cookbook.h"

// classe statica
class UI {
private:
	UI(); // costruttore privato per rendere  la classe statica
	virtual ~UI();

	static void setMenuChoice();
	static void showMenu();
	static void exitDialog();

public:
	static void start();
};

#endif /* UI_H_ */
