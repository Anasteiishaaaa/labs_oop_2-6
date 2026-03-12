#pragma once
#include <string>
using namespace std;

class MenuDish { 
	private:
		string category;
		string name;
		double price;
public:
	MenuDish(string c, string n, double p);
	MenuDish();
	~MenuDish();
};

