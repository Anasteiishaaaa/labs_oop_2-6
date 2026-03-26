#pragma once
#include "MenuDish.h"
#include <string>

class Dessert final: public MenuDish
{ protected: 
	int calories;
	bool containsNuts;
public: 
	Dessert(const string& c, const string& n, double p, int cal, bool nuts);
	~Dessert() override;
	void display() const;
};

// class Cake : public Dessert {};