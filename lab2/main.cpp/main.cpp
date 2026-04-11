#include <iostream>
#include <string>
#include <vector>
#include "MenuDish.h"
#include "Customer.h"
#include "Order.h"
#include "OnlineOrder.h"
#include "DineInOrder.h"
#include "MainCourse.h"
#include "Drink.h"
#include "Dessert.h"
#include "IPrintable.h"

using namespace std;

void printDishDetails(const MenuDish &dish) {
	cout << "Printing via Reference" << endl;
	dish.display();
}

int main()
{
	int choice;
	bool isRunning = true;

	Customer customer1("Nastya", "0970000000", 20);
	Customer customer2("Alice");

	while (isRunning) {
		cout << "------- MAIN RESTAURANT MENU -------" << endl;
		cout << "1. View Menu" << endl;
		cout << "2. Add new customer" << endl;
		cout << "3. Create order" << endl;
		cout << "4. Print all information" << endl;
		cout << "0. Exit the program" << endl;
		cout << "------------------------------------" << endl;
		cout << "Your choice: " << endl;

		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "--- Our menu ---" << endl;
			MenuDish* menuItem1 = new MainCourse("Main courses", "Grilled Steak", 299.99, 300, false);
			MenuDish* menuItem2 = new Drink("Drinks", "Mojito", 149.99, 250, true);
			MenuDish* menuItem3 = new Dessert("Desserts", "Chocolate Cake", 119.99, 450, true);

			MenuDish* menuItems[] = { menuItem1, menuItem2, menuItem3 };
			for (int i = 0; i < 3; i++) {
				menuItems[i]->display();
				cout << endl;
			}

			delete menuItem1;
			delete menuItem2;
			delete menuItem3;
			break;
		}

		case 2: {
			cout << "--- Client registration ---" << endl;
			string name;
			cout << "Enter customer name: ";
			cin >> name;

			Customer newCustomer(name);
			cout << "Customer " << name << " seccesfully created!" << endl;
			newCustomer.display();
			break;
		}

		case 3: {
			cout << "--- Create new order ---" << endl;
			Order* newOrder1 = new DineInOrder(1, 539.99, true, customer1, 5, 50);
			Order* newOrder2 = new OnlineOrder(2, 199.99, false, customer2, "123 Main St", 20);

			cout << "Dine-in order processing:" << endl;
			newOrder1->processOrder();
			newOrder1->display();

			cout << "Online order processing:" << endl;
			newOrder2->processOrder();
			newOrder2->display();

			delete newOrder1;
			delete newOrder2;

			break;
		}

		case 4: {
			cout << "--- All information ---" << endl;

			Drink myDrink("Drink", "Mojito", 149.99, 250, true);
			Customer vipCustomer("Admin", "0980000000", 1000);

			IPrintable* printableItems[2];
			printableItems[0] = &myDrink;
			printableItems[1] = &vipCustomer;

			for (int i = 0; i < 2; i++) {
				printableItems[i]->printSummary();
			}
			break;
		}

		case 0: {
			cout << "Exiting the program. Goodbye!" << endl;
			break;
		}

		default: {
			cout << "Invalid choice. Please try again." << endl;
		}
		}
	}
	cout << endl;

    return 0;
}
