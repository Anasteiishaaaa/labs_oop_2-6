#include "Order.h"
#include <iostream>
using namespace std;

int Order::totalOrders = 0;

Order::Order(int id, int t, double b, bool p)
	:orderID(id), tableNumber(t), totallBill(b), isPaid(p) {
	totalOrders++;
	cout << "Created an order: " << orderID << endl;
}

Order::Order()
	:Order(0, 0, 0.0, false) {
}

Order::~Order() {
	cout << "Destroyed an order: " << orderID << endl;
}

void Order::payOrder() {
	isPaid = true;
	cout << "Order " << orderID << " has been paid." << endl;
}

void Order::display() const {
	cout << "Order ID: " << orderID << ", Table: " << tableNumber << ", Total Bill: " << totallBill << " UAH, Paid: " << (isPaid ? "Yes" : "No") << endl;
}

int Order::getTotalOtders() {
	return totalOrders;
}