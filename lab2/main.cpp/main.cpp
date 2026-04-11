#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>

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
				try {
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

					if (price < 0 || weight <= 0) {
						throw invalid_argument("Price must be non-negative and weight must be positive.");
					}

					cout << "Is the dish vegetarian? (1 for yes, 0 for no): ";
					cin >> isVegetarian;
					restaurantMenu.push_back(make_shared<MainCourse>("Main Course", name, price, weight, isVegetarian));

					ofstream outFile("menu.txt", ios::app);
					if (outFile.is_open()) {
						outFile << "Main Course: " << name << " " << price << " " << weight << " " << (isVegetarian ? "Yes" : "No") << endl;
						outFile.close();
						cout << "Dish saved to menu.txt!" << endl;
					}
				}
				catch (const exception& e) {
					cout << "Error: " << e.what() << endl;
				}

				break;
			}

			case 2: {
				try {
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

					if (price < 0 || volume <= 0) {
						throw invalid_argument("Price must be non-negative and volume must be positive.");
					}

					cout << "Is the drink alcoholic? (1 for yes, 0 for no): ";
					cin >> isAlcoholic;
					restaurantMenu.push_back(make_shared<Drink>("Drink", name, price, volume, isAlcoholic));
					ofstream outFile("menu.txt", ios::app);
					if (outFile.is_open()) {
						outFile << "Drink: " << name << " " << price << " " << volume << " " << isAlcoholic << endl;
						outFile.close();
						cout << "Drink saved to menu.txt!" << endl;
					}
				}
				catch (const exception& e) {
					cout << "Error: " << e.what() << endl;
				}
				break;
			}

			case 3: {
				try{
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

				if (price < 0 || calories <= 0) {
					throw invalid_argument("Price must be non-negative and calories must be positive.");
				}

				cout << "Does the dessert contains nuts? (1 for yes, 0 for no): ";
				cin >> containsNuts;
				restaurantMenu.push_back(make_shared<Dessert>("Dessert", name, price, calories, containsNuts));

				ofstream outFile("menu.txt", ios::app);
				if (outFile.is_open()) {
					outFile << "Dessert: " << name << " " << price << " " << calories << " " << containsNuts << endl;
					outFile.close();
				}
					cout << "Dessert saved to menu.txt!" << endl;
				}
				catch (const exception& e) {
					cout << "Error: " << e.what() << endl;
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
			if (customers.empty()) {
				cout << "No customers registered! Please sign up first." << endl;
				break;
			}

			if (restaurantMenu.empty()) {
				cout << "Menu is empty! Please wait for admin to add dishes." << endl;
				break;
			}

			cout << "Select yout profile:" << endl;
			for (size_t i = 0; i < customers.size(); i++) {
				cout << i + 1 << ". ";
				customers[i]->display();
			}

			int customerChoice;
			cout << "Your choice: ";
			cin >> customerChoice;
			if (customerChoice < 1 || customerChoice > customers.size()) {
				cout << "Invalid choice. Returning to user menu." << endl;
				break;
			}

			vector<shared_ptr<MenuDish>> cart;
			int dishChoice = -1;
			cout << "\nAdd dishes to yout cart" << endl;
			while (dishChoice != 0) {
				for (size_t i = 0; i < restaurantMenu.size(); ++i) {
					cout << i + 1 << ". ";
					restaurantMenu[i]->display();
				}
				cout << "0. Finish adding to cart" << endl;
				cout << "Select dish to add: ";
				cin >> dishChoice;

				if (dishChoice > 0 && dishChoice <= restaurantMenu.size()) {
					cart.push_back(restaurantMenu[dishChoice - 1]);
					cout << "[+] Dish added to cart!\n" << endl;
				}
				else if (dishChoice != 0) {
					cout << "[-] Invalid choice!\n" << endl;
				}
			}

			if (cart.empty()) {
				cout << "Your cart is empty. Order cancelled." << endl;
				break;
			}

			double totalPrice;
			cout << "\nYour cart has " << cart.size() << " items." << endl;
			cout << "Enter total price to pay (UAH): ";
			cin >> totalPrice;

			int orderType;
			cout << "Select order type:\n1. Dine-in\n2. Online delivery\nYour choice: ";
			cin >> orderType;
			string typeName;


			if (orderType == 1) {
				int table;
				double tip;
				cout << "Enter table number: "; cin >> table;
				cout << "Enter tip amount: "; cin >> tip;

				Order* newOrder = new DineInOrder(1, totalPrice, false, *customers[customerChoice - 1], table, tip);
				cout << "\n[System] Processing Dine-in order..." << endl;
				newOrder->processOrder();
				newOrder->display();
				delete newOrder;
				typeName = "Dine-in";
			}
			else if (orderType == 2) {
				string address;
				double fee;
				cout << "Enter delivery address (no_spaces): "; cin >> address;
				cout << "Enter delivery fee: "; cin >> fee;

				Order* newOrder = new OnlineOrder(2, totalPrice, false, *customers[customerChoice - 1], address, fee);
				cout << "\n[System] Processing Online order..." << endl;
				newOrder->processOrder();
				newOrder->display();
				delete newOrder;
				typeName = "Online";
			}
			else {
				cout << "[Error] Invalid order type." << endl;
			}

			if (orderType == 1 || orderType == 2) {
				ofstream historyFile("orders.txt", ios::app);
				if (historyFile.is_open()) {
					historyFile << "ORDER | Customer Profile ID: " << customerChoice
						<< " | Items count: " << cart.size()
						<< " | Total: " << totalPrice << " UAH | Delivery: " << typeName << "\n";
					historyFile.close();
					cout << "[System] Receipt successfully saved to history.txt!" << endl;
				}
				else {
					cout << "[Error] Could not save history file." << endl;
				}
			}
			break;
		}

		case 4: {
			cout << "--- All information ---" << endl;
			cout << "~~~ REGISTERED CUSTOMERS (" << customers.size() << ") ~~~" << endl;
			if (customers.empty()) cout << "No customers yet." << endl;
			for (size_t i = 0; i < customers.size(); i++) {
				customers[i]->display();
			}

			cout << "\n~~~ RESTAURANT MENU (" << restaurantMenu.size() << ") ~~~" << endl;
			if (restaurantMenu.empty()) cout << "Menu is empty." << endl;
			for (size_t i = 0; i < restaurantMenu.size(); i++) {
				restaurantMenu[i]->display();
			}
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