#pragma once
#include "MenuDish.h"
#include <string>

class Dessert : public MenuDish
{ protected: 
	int calories;
	bool containsNuts;
public: 
	Dessert(const string& c, const string& n, double p, int cal, bool nuts);
	~Dessert();
	void display() const;
};

