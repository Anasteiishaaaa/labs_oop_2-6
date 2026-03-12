#pragma once
#include <string>
using namespace std;

class Customer {
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
};


