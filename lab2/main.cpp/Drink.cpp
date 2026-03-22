#include "Drink.h"
#include <iostream>
using namespace std;

Drink ::Drink(const string& c, const string& n, double p, int v, bool alc)
	:MenuDish(c, n, p), volumeMl(v), isAlcoholic(alc) {
	cout << "Drink constructor called for: " << name << endl;
}

Drink ::~Drink() {
	cout << "Drink destructor called for: " << name << endl;
}

void Drink::display() const {
	MenuDish::display();
	cout << "Volume: " << volumeMl << "ml, Type: " << (isAlcoholic ? "Yes" : "No") << endl;
}