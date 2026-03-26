#include "MenuDish.h"
#include <iostream>
using namespace std;

MenuDish::MenuDish(const string& c, const string& n, double p)
	:category(c), name(n), price(p) {
	cout << "Created a dish: " << name << " (" << category << ")" << endl;
}

MenuDish::MenuDish()
	:MenuDish("General", "Default", 0.0) {
}

MenuDish::MenuDish(const MenuDish& other)
	:category(other.category), name(other.name), price(other.price) {
	cout << "Copy constructor: " << name << " (" << category << ")" << endl;
}

MenuDish::MenuDish(MenuDish&& other) noexcept
	:category(move(other.category)), name(move(other.name)), price(other.price) {
	other.price = 0.0;
	cout << "Move constructor: " << name << " (" << category << ")" << endl;
}

MenuDish& MenuDish::operator=(const MenuDish& other) {
	cout << "Copy assignment operator for: " << other.name << " (" << category << ")" << endl;
	if (this != &other) {
		category = other.category;
		name = other.name;
		price = other.price;
	}
	return *this;
}

MenuDish& MenuDish::operator=(MenuDish&& other) noexcept {
	cout << "Move assignment operator for: " << other.name << " (" << category << ")" << endl;
	if (this != &other) {
		category = move(other.category);
		name = move(other.name);
		price = other.price;
		other.price = 0.0;
	}
	return *this;
}

MenuDish::~MenuDish() {
	cout << "Destroyed a dish: " << name << " (" << category << ")" << endl;
}

void MenuDish::display() const {
		cout << "Dish: " << name << " (" << category << ")" << ", Price: " << price << " UAH" << endl;
}

void MenuDish::staticBinding() const {
	cout << "I am a MenuDish" << endl;
}

void MenuDish::getDescription() const {
	cout << "Standart meni item." << endl;
}

void MenuDish::printSummary() const {
	cout << "[IPrintable] Dish: " << name << " (" << price << " UAH)" << endl;
}