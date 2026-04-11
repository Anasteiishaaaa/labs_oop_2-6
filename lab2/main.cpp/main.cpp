#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

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

vector<shared_ptr<MenuDish>> restaurantMenu;
vector<shared_ptr<Customer>> customers;

void adminMenu(bool& isAppRunning) {
	int choice;
	bool isAdminRunning = true;

	while (isAdminRunning && isAppRunning) {
		cout << "------- ADMIN MENU -------" << endl;
		cout << "1. Add new dish to menu" << endl;
		cout << "2. Add new drink to menu" << endl;
		cout << "3. Add new dessert to menu" << endl;
		cout << "4. View all menu" << endl;
		cout << "5. View customers" << endl;
		cout << "6. Log out of account" << endl;
		cout << "0. Turn off the system" << endl;
		cout << "--------------------------" << endl;
		cout << "Your choice : " << endl;
		cin >> choice;

		switch (choice) {
			case 1: {
				string category, name;
				double price;
				int weight;
				bool isVegetarian;
				cout << "Enter dish name: ";
				cin >> name;
				cout << "Enter dish price: ";
				cin >> price;
				cout << "Enter dish weight (grams): ";
				cin >> weight;
				cout << "Is the dish vegetarian? (1 for yes, 0 for no): ";
				cin >> isVegetarian;
				restaurantMenu.push_back(make_shared<MainCourse>("Main Course", name, price, weight, isVegetarian));

				ofstream outFile("menu.txt", ios::app);
				if (outFile.is_open()) {
					outFile << "Main Course: " << name << ", Price: " << price << ", Weight: " << weight << "g, Vegetarian: " << (isVegetarian ? "Yes" : "No") << endl;
					outFile.close();
					cout << "Dish saved to menu.txt!" << endl;
				}
				break;
			}

			case 2: {
				string name;
				double price;
				int volume;
				bool isAlcoholic;
				cout << "Enter drink name: ";
				cin >> name;
				cout << "Enter drink price: ";
				cin >> price;
				cout << "Enter drink volume (ml): ";
				cin >> volume;
				cout << "Is the drink alcoholic? (1 for yes, 0 for no): ";
				cin >> isAlcoholic;
				restaurantMenu.push_back(make_shared<Drink>("Drink", name, price, volume, isAlcoholic));
				ofstream outFile("menu.txt", ios::app);
				if (outFile.is_open()) {
					outFile << "Drink: " << name << ", Price: " << price << ", Volume: " << volume << "ml, Alcoholic: " << isAlcoholic << endl;
					outFile.close();
					cout << "Drink saved to menu.txt!" << endl;
				}
				break;
			}

			case 3: {
				string name;
				double price;
				int calories;
				bool containsNuts;
				cout << "Enter dessert name: ";
				cin >> name;
				cout << "Enter dessert price: ";
				cin >> price;
				cout << "Enter dessert calories: ";
				cin >> calories;
				cout << "Is the dessert contains nuts? (1 for yes, 0 for no): ";
				cin >> containsNuts;
				restaurantMenu.push_back(make_shared<Dessert>("Dessert", name, price, calories, containsNuts));

				ofstream outFile("menu.txt", ios::app);
				if (outFile.is_open()) {
					outFile << "Dessert: " << name << ", Price: " << price << ", Calories: " << calories << "kcal, Contains nuts?: " << containsNuts << endl;
					outFile.close();
					cout << "Dessert saved to menu.txt!" << endl;
				}
				break;
			}

			case 4: {
				cout << "--- Our menu ---" << endl;
				if (restaurantMenu.empty()) cout << "Menu is empty!" << endl;
				for (size_t i = 0; i < restaurantMenu.size(); i++) {
						cout << i+1 << ". ";
						restaurantMenu[i]->display();
					}
				break;
				}

			case 5: {
				cout << "--- Customers ---" << endl;
				if (customers.empty()) cout << "No customers registered!" << endl;
				for (size_t i = 0; i < customers.size(); i++) {
						customers[i]->display();
					}
				break;
				}

			case 6: {
				cout << "Returning to main menu..." << endl;
				isAdminRunning = false;
			}
				break;


			case 0: {
				cout << "Turning off the system. Goodbye!" << endl;
				isAppRunning = false;
				isAdminRunning = false;
				break;
			}
		
		default:
			break;
		}
	}
}

void userMenu(bool& isAppRunning) {
	int choice;
	bool isUserRunning = true;

	while (isUserRunning && isAppRunning) {
		cout << "------- USER MENU -------" << endl;
		cout << "1. View Menu" << endl;
		cout << "2. Sign up in system" << endl;
		cout << "3. Create order" << endl;
		cout << "4. Print all information" << endl;
		cout << "5. Log out of account" << endl;
		cout << "0. Exit the program" << endl;
		cout << "------------------------- " << endl;
		cout << "Your choice: " << endl;
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "--- Our menu ---" << endl;
			if (restaurantMenu.empty()) cout << "Menu is empty!" << endl;
			for (size_t i = 0; i < restaurantMenu.size(); i++) {
				cout << i + 1 << ". ";
				restaurantMenu[i]->display();
			}
			break;
		}
		case 2: {
			string name;
			cout << "Enter customer name: ";
			cin >> name;
			auto newCustomer = make_shared<Customer>(name);
			customers.push_back(newCustomer);
			cout << "Customer " << name << " successfully created!" << endl;
			newCustomer->display();
			break;
		}
		case 3: {
			cout << "--- Create new order ---" << endl;
			break;
		}
		case 4: {
			cout << "--- All information ---" << endl;
			break;
		}
		case 5: {
			cout << "Returning to main menu..." << endl;
			isUserRunning = false;
			break;
		}
		case 0: {
			cout << "Exiting the program. Goodbye!" << endl;
			isAppRunning = false;
			isUserRunning = false;
			break;
		}
		default: {
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
		}
	}
}

void loadMenuFromFile() {
	ifstream inFile("menu.txt");
	if (!inFile.is_open()) return; 

	string type, name;
	double price;
	int calories;
	bool containsNuts;

	while (inFile >> type >> name >> price) {
		if (type == "MainCourse") {
			int weight;
			bool isVegetarian;
			inFile >> weight >> isVegetarian;
			restaurantMenu.push_back(make_shared<MainCourse>("Main Course", name, price, weight, isVegetarian));
		}
		else if (type == "Drink") {
			int volume;
			bool isAlcoholic;
			inFile >> volume >> isAlcoholic;
			restaurantMenu.push_back(make_shared<Drink>("Drink", name, price, volume, isAlcoholic));
		}
		else if (type == "Dessert") {
			int calories;
			bool containsNuts;
			inFile >> calories >> containsNuts;
			restaurantMenu.push_back(make_shared<Dessert>("Dessert", name, price, calories, containsNuts));
		}
	}
	inFile.close();
}

	int main() {
		loadMenuFromFile();
		bool isAppRunning = true;
		int roleChoice;
		const string adminPassword = "admin123";

		restaurantMenu.push_back(make_shared<MainCourse>("Main Course", "Grilled Steak", 299.99, 300, false));
		
		while (isAppRunning) {
			cout << "------- WELCOME TO THE RESTAURANT -------" << endl;
			cout << "Select your role:" << endl;
			cout << "1. Admin" << endl;
			cout << "2. User" << endl;
			cout << "0. Exit" << endl;
			cout << "-----------------------------------------" << endl;
			cout << "Your choice: " << endl;
			cin >> roleChoice;

			if (roleChoice == 1) {
				string password;
				cout << "Enter admin password: ";
				cin >> password;
				if (password == adminPassword) {
					adminMenu(isAppRunning);
				}
				else {
					cout << "Incorrect password. Access denied." << endl;
				}
				}

				else if (roleChoice == 2) {
					userMenu(isAppRunning);
				}
				else if (roleChoice == 0) {
					cout << "Exiting the program. Goodbye!" << endl;
					isAppRunning = false;
				}
				else {
					cout << "Invalid choice. Please try again." << endl;
				}
		}
			return 0;
	}