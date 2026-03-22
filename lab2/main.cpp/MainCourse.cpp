#include "MainCourse.h"
#include <iostream>

MainCourse::MainCourse(const string& c, const string& n, double p, int w, bool veg)
	:MenuDish(c, n, p), weightGrams(w), isVegetarian(veg) {
	cout << "MainCourse constructor called for: " << name << endl;
}

MainCourse::~MainCourse() {
	cout << "MainCourse destructor called for: " << name << endl;
}

void MainCourse::display() const {
	MenuDish::display();
	cout << "Weight: " << weightGrams << "g, Veg: " << (isVegetarian ? "Yes" : "No") << endl;
}