#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string name, string phoneNumber, double bonuses) {
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->bonuses = bonuses;
	cout << "Created a customer: " << this->name << endl;
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

void Customer::printSummary() const {
	cout << "[IPrintable] Customer Name: " << name << endl;
}