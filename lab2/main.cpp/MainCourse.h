#pragma once
#include "MenuDish.h"
#include <string>
using namespace std;

class MainCourse : public MenuDish 
{ private:
	int weightGrams;
	bool isVegetarian;
public: 
	MainCourse(const string& c, const string& n, double p, int w, bool veg);
	virtual ~MainCourse();
};

