#include "Order.h"
#include <iostream>
using namespace std;

int Order::totalOrders = 0;

Order::Order(int id, double b, bool p, const Customer& cust)
	:orderID(id), totallBill(b), isPaid(p), customer(cust) {
	totalOrders++;
	cout << "Created base order constructor called for ID: " << orderID << endl;
}

Order::Order()
	:Order(0, 0.0, false, Customer("Default", "000", 0.0)) {
}

Order::~Order() {
	cout << "Destroyed base order destructor called for ID: " << orderID << endl;
}

void Order::payOrder() {
	isPaid = true;
	cout << "Order " << orderID << " has been paid." << endl;
}

void Order::display() const {
	cout << "Order ID: " << orderID << endl;
	cout << "Total Bill: " << totallBill << " UAH, Paid: " << (isPaid ? "Yes" : "No") << endl;
	cout << "Customer info: ";
	customer.display();
}

int Order::getTotalOrders() {
	return totalOrders;
}