#include "MenuDish.h"
#include <iostream>
using namespace std;

MenuDish::MenuDish(string c, string n, double p)
	:category(c), name(n), price(p) {
	cout << "Created a dish: " << name << " (" << category << ")" << endl;
}

MenuDish::MenuDish()
	:MenuDish("General", "Default", 0.0) {
}

MenuDish::~MenuDish() {
	cout << "Destroyed a dish: " << name << " (" << category << ")" << endl;
}

void MenuDish::display() const {
		cout << "Dish: " << name << " (" << category << ")" << ", Price: " << price << " UAH" << endl;
}
