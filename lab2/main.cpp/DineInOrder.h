#pragma once
#include "Order.h"
class DineInOrder : public Order
{
private:
	int tableNumber;
	double tips;
public:
	DineInOrder(int id, double b, bool p, const Customer& cust, int tableNum, double t);
    ~DineInOrder() override;
	void display() const override;
};

