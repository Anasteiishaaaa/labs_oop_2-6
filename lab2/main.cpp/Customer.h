#pragma once
#include <string>
#include "IPrintable.h"
using namespace std;

class Customer : public IPrintable {
private:
	string name;
	string phoneNumber;
	double bonuses;
public:
	Customer(string n, string p, double b);
	Customer(string n);
	Customer();
	~Customer();
	void display() const;
	void addPoints(double b);

	void printSummary() const override;
};


