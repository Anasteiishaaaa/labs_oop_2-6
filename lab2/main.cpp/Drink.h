#pragma once
#include "MenuDish.h"
#include <string>
using namespace std;

class Drink : public MenuDish
{ private: 
	int volumeMl;
	bool isAlcoholic;
public: 
	Drink(const string& c, const string& n, double p, int v, bool alc);
	~Drink() override;
	void display() const override;
	void getDescription() const override final;
	void staticBinding() const;
};