#include "Order.h"
#include <iostream>
using namespace std;

Order::Order(int id, int t, double b, bool p)
	:orderID(id), tableNumber(t), totallBill(b), isPaid(p) {
	cout << "Created an order: " << orderID << endl;
}

Order::Order()
	:Order(0, 0, 0.0, false) {
}

Order::~Order() {
	cout << "Destroyed an order: " << orderID << endl;
}