#pragma once
#include "Order.h"
#include <string>
using namespace std;

class OnlineOrder : public Order 
{ 
private:
	string deliveryAddress;	
	double deliveryFee;
public: 
	OnlineOrder(int id, double b, bool p, const Customer& cust, const string& address, double fee);
	~OnlineOrder() override;
	OnlineOrder(const OnlineOrder& other);
	OnlineOrder(OnlineOrder&& other) noexcept;
	OnlineOrder& operator=(const OnlineOrder& rhs);
	void display() const;
	void processOrder() const override;
};

