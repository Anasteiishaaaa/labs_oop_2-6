#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string n, string p, double b)
	:name(n), phoneNumber(p), bonuses(b) {
	cout << "Created a customer: " << name << endl;
}

Customer::Customer(string n)
	:Customer(n, "Default phone number", 0.0) {
}

Customer::Customer()
	:Customer("Unknown") {
}

Customer::~Customer() {
	cout << "Destroyed a customer: " << name << endl;
}

void Customer::display() const {
	cout << "Customer: " << name << ", Phone: " << phoneNumber << ", Loyalty bonuses: " << bonuses << endl;
}

void Customer::addPoints(double b) {
	bonuses += b;
}
