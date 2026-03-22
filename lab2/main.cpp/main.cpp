#include <iostream>
#include "MenuDish.h"
#include "Customer.h"
#include "Order.h"
#include "OnlineOrder.h"
#include "DineInOrder.h"
#include "MainCourse.h"
#include "Drink.h"
#include "Dessert.h"

using namespace std;

int main()
{
	MenuDish dish1("Soups", "Borscht", 159.99);
	MenuDish dish2("Main courses", "Chicken Kiev", 129.99);
	MenuDish dish3;
	dish1.display();
	dish2.display();
	dish3.display();

	cout << endl;

	Customer customer1("Nastya", "0970000000", 20);
	Customer customer2("Alice");
	Customer customer3;
	customer1.display();
	customer2.display();
	customer3.display();

	cout << endl;

	Order order1(1, 539.99, true, customer1);
	Order order2;
	order1.display();
	order1.payOrder();
	order2.display();

	cout << endl;

	cout << "Copy and move constructors" << endl;
	cout << endl;

	MenuDish originalDish("Dessert", "Tiramisu", 99.99);
	MenuDish copiedDish = originalDish; 
	cout << "Original dish: ";
	originalDish.display();
	cout << "Copied dish: ";
	copiedDish.display();
	cout << endl;

	MenuDish movedDish = move(copiedDish);
	cout << "Moved dish: ";
	movedDish.display();
	cout << "Copied dish after move: ";
	copiedDish.display();
	cout << endl;

	cout << endl;
	cout << "Const and static" << endl;
	cout << endl;

	const Customer vipCustomer("Admin", "0980000000", 1000);
	vipCustomer.display();
	cout << endl;

	cout << "Total orders created: " << Order::getTotalOrders() << endl;
	cout << endl;

	cout << "----------------------------------------" << endl;
	cout << "Inheritance" << endl;
	cout << endl;

	cout << "MENU" << endl;

	MainCourse steak("Main courses", "Grilled Steak", 299.99, 300, false);
	steak.display();
	cout << endl;
	
	Drink cocktail("Drinks", "Mojito", 149.99, 250, true);
	cocktail.display();

	Dessert cake("Desserts", "Chocolate Cake", 119.99, 450, true);
	cake.display();
	cout << endl;

	cout << "ORDERS" << endl;

	DineInOrder dineInOrder(2, 299.99, false, customer2, 5, 50);
	dineInOrder.display();
	cout << endl;

	OnlineOrder onlineOrder(3, 199.99, false, customer3, "123 Main St", 20);
	onlineOrder.display();
	cout << endl;

	cout << "Total orders after lab4: " << Order::getTotalOrders() << endl;
	cout << endl;

    return 0;
}
