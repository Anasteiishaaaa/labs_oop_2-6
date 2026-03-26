#pragma once
#include <string>
#include "IPrintable.h"

using namespace std;

class MenuDish : public IPrintable { 
	protected:
		string category;
		string name;
		double price;
public:
	MenuDish(const string& c, const string& n, double p);
	MenuDish();

	MenuDish(const MenuDish& other);
	MenuDish(MenuDish&& other) noexcept;

	MenuDish& operator=(const MenuDish& other);
	MenuDish& operator=(MenuDish&& other) noexcept;

	void staticBinding() const;
	
	virtual ~MenuDish();
	virtual void display() const;
	virtual void getDescription() const;

	void printSummary() const override;
};

