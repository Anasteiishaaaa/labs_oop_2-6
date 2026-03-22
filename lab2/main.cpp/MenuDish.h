#pragma once
#include <string>

using namespace std;

class MenuDish { 
	protected:
		string category;
		string name;
		double price;
public:
	MenuDish(const string& c, const string& n, double p);
	MenuDish();

	MenuDish(const MenuDish& other);
	MenuDish(MenuDish&& other) noexcept;

	virtual ~MenuDish();
	virtual void display() const;

};

