#pragma once
#include "Customer.h"
#include <iostream>

class Order {
protected:
	int orderID;
	double totallBill;
	bool isPaid;
	Customer customer; 
	static int totalOrders;

public:
	Order(int id, double b, bool p, const Customer& cust);
	Order();
	~Order();
	void payOrder();
	void display() const;
	static int getTotalOrders();
};