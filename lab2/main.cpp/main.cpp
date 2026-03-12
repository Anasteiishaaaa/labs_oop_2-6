#include <iostream>
#include "MenuDish.h"
#include "Customer.h"
#include "Order.h"
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

	Order order1(1, 7, 539.99, true);
	Order order2;
	order1.display();
	order1.payOrder();
	order2.display();

	cout << endl;

	cout << "Copy and move constructors" << endl;

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

    return 0;
}
