#include "OnlineOrder.h"
#include <iostream>
using namespace std;

OnlineOrder::OnlineOrder(int id, double b, bool p, const Customer& cust, const string& address, double fee)
	:Order(id, b, p, cust), deliveryAddress(address), deliveryFee(fee) {
	cout << "Online constructor called for ID: " << orderID << endl;
}

OnlineOrder::~OnlineOrder() {
	cout << "OnlineOrder destructor called for ID: " << orderID << endl;
}

OnlineOrder::OnlineOrder(const OnlineOrder& other)
	:Order(other), deliveryAddress(other.deliveryAddress), deliveryFee(other.deliveryFee) {
	cout << "OnlineOrder copy constructor called. " << orderID << endl;
}

OnlineOrder::OnlineOrder(OnlineOrder&& other) noexcept
	:Order(move(other)), deliveryAddress(move(other.deliveryAddress)), deliveryFee(other.deliveryFee) {
	other.deliveryFee = 0;
	cout << "OnlineOrder move constructor called. " << orderID << endl;
}

OnlineOrder& OnlineOrder::operator=(const OnlineOrder& rhs) {
	if (this != &rhs) {
		Order::operator=(rhs);
		deliveryAddress = rhs.deliveryAddress;
		deliveryFee = rhs.deliveryFee;
	}
	cout << "OnlineOrder copy assignment operator called. " << orderID << endl;
	return *this;
}

void OnlineOrder::display() const {
	Order::display();
	cout << "Delivery details: " << endl;
	cout << "Address: " << deliveryAddress << ", Delivery fee: " << deliveryFee << " UAH" << endl;
}

void OnlineOrder::processOrder() const {
	cout << "Processing online order ID: " << orderID << endl;
	cout << "Preparing for delivery to: " << deliveryAddress << endl;
}