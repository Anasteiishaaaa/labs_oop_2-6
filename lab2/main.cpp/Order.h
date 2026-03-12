#pragma once
class Order {
private:
	int orderID;
	int tableNumber;
	double totallBill;
	bool isPaid;
	static int totalOrders;
public:
	Order(int id, int t, double b, bool p);
	Order();
	~Order();
	void payOrder();
	void display() const;
	static int getTotalOtders();
};