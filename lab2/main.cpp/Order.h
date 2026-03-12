#pragma once
class Order {
private:
	int orderID;
	int tableNumber;
	double totallBill;
	bool isPaid;
public:
	Order(int id, int t, double b, bool p);
	Order();
	~Order();
};