#include "DineInOrder.h"
#include <iostream>	
using namespace std;

DineInOrder::DineInOrder(int id, double b, bool p, const Customer& cust, int tableNum, double t)
	:Order(id, b, p, cust), tableNumber(tableNum), tips(t) {
	cout << "DineInOrder constructor called for ID: " << orderID << endl;
}

DineInOrder::~DineInOrder() {
	cout << "DineInOrder destructor called for ID: " << orderID << endl;
}

void DineInOrder::display() const {
	Order::display();
	cout << "Dine-in details: " << endl;
	cout << "Table number: " << tableNumber << ", Tips: " << tips << " UAH" << endl;
}

void DineInOrder::processOrder() const {
	cout << "Processing dine-in order ID: " << orderID << endl;
	cout << "Serving at table number: " << tableNumber << endl;
}
