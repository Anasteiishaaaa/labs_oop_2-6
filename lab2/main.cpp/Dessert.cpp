#include "Dessert.h"
#include <iostream>	
using namespace std;	

Dessert::Dessert(const string& c, const string& n, double p, int cal, bool nuts)
	:MenuDish(c, n, p), calories(cal), containsNuts(nuts) {
	cout << "Dessert constructor called for: " << name << endl;
}

Dessert::~Dessert() {
	cout << "Dessert destructor called for: " << name << endl;
}

void Dessert::display() const {
	MenuDish::display();
	cout << "Calories: " << calories << " kcal, Nuts: " << (containsNuts ? "Yes" : "No") << endl;
}