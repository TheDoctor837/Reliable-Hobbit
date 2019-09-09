// Ian McNulty	CSC 2110 Project	3/26/2019
//---------------------------------------------------------------------------------------------------------------
// SUMMARY
// Barebones POS(point of sale) system for supermarket - NO GUI
//---------------------------------------------------------------------------------------------------------------
// DESCRIPTION
// System can load inventory from backup text file, upload the new inventory to that file add new items 
// dynamically to the inventory, sell items, return items, print the entire inventory and sections' various 
// smaller inventories, and search the entire inventory of the store by item name.
//---------------------------------------------------------------------------------------------------------------
// PROGRAM NOTES
// Uses 2 classes, 1 base class and the other it's derivative, to handle the matters of the inventory
// duch as loading the inventory, printing the inventory, selling an item, etc. See the classes' definition and
// implementation files for specific info. Primary file brings it all together and handles the menus of the POS 
// primarily using its own functions. This file also handles the reading of the inventory.txt file and updating
// of that same file.
#include <iostream>
#include <vector>
#include <fstream>
#include "inventory.h"
#include "subInventory.h"
using namespace std;

void mainMenu(int& x); // Main menu
void menu(int& x); // Shortened menu
int two(); // Menu for option 2
string three(); // Menu for option 3
void fourFive(inventory inv, string& cat, string& item, int& quant); // Menu for options 4 and 5
void six(inventory inv, string& cat, string& item, int& quant, int& dollar, int& cent); // Menu for option 6

int main()
{
	int input, b, counter = -1, quant, doll, cent, index, sellQuant, retQuant;
	string c, item, category, sellCat, retCat, sellItem, retItem;
	bool check;
	const string INV = "inventory.txt"; // This file holds the inventory
	ifstream invRead;
	ofstream invPrint;
	inventory cat;
	subInventory dairy, fruit, vegetables, bakery, beverages;

	/*
	THIS WHILE LOOP IS WHAT LOADS UP THE INVENTORY FROM inventory.txt DO NOT TOUCH
	*/
	invRead.open(INV);
	while (invRead.good()) { 
		string temp;
		int temp2, temp3, temp4;

		invRead >> temp >> temp2 >> temp3 >> temp4;
		if (temp2 != 999) cat.loadInventory(temp, temp2, temp3, temp4);

		switch (counter) {
		case 0: // Loads dairy catalog
			if (temp2 != 999)
				dairy.loadInventory(temp, temp2, temp3, temp4);
			break;
		case 1: // Loads fruit catalog
			if (temp2 != 999) 
				fruit.loadInventory(temp, temp2, temp3, temp4);
			break;
		case 2: // Loads veggie catalog
			if (temp2 != 999) 
				vegetables.loadInventory(temp, temp2, temp3, temp4);
			break;
		case 3: // Loads bakery catalog
			if (temp2 != 999)
				bakery.loadInventory(temp, temp2, temp3, temp4);
			break;
		case 4: // Loads beverage catalog
			if (temp2 != 999) 
				beverages.loadInventory(temp, temp2, temp3, temp4);
			break;
		}

		if (temp2 == 999) {
			counter++;
			switch (counter) {
			case 0: // Loads dairy catalog
				dairy.setCategory(temp);
				break;
			case 1: // Loads fruit catalog
				fruit.setCategory(temp);
				break;
			case 2: // Loads veggie catalog
				vegetables.setCategory(temp);
				break;
			case 3: // Loads bakery catalog
				bakery.setCategory(temp);
				break;
			case 4: // Loads beverage catalog
				beverages.setCategory(temp);
				break;
			}
		}
	}
	invRead.close();

	mainMenu(input);
	while (input != 8) { // Basic menu system allows for reccurence of a simplified menu until program is exited with input of 8
		switch (input) {
		case 1: // Print full catalog
			cat.printInventory();
			break;
		case 2: // Print section catalog
			b = two();
			if (b == 1) dairy.printInventory();
			else if (b == 2) fruit.printInventory();
			else if (b == 3) vegetables.printInventory();
			else if (b == 4) bakery.printInventory();
			else beverages.printInventory();
			break;
		case 3: // Search Item
			c = three();
			cout << cat.findItem(c); // Searches for item in main catalog
			break;
		case 4: // Sell Item
			fourFive(cat, sellCat, sellItem, sellQuant);
			if (sellCat == "dairy") {
				cat.sellItem(sellItem, sellQuant, check);
				if (check) dairy.sellItem(sellItem, sellQuant);
			}
			else if (sellCat == "fruit") {
				cat.sellItem(sellItem, sellQuant, check);
				if (check) fruit.sellItem(sellItem, sellQuant);
			}
			else if (sellCat == "vegetables") {
				cat.sellItem(sellItem, sellQuant, check);
				if (check) vegetables.sellItem(sellItem, sellQuant);
			}
			else if (sellCat == "bakery") {
				cat.sellItem(sellItem, sellQuant, check);
				if (check) bakery.sellItem(sellItem, sellQuant);
			}
			else {
				cat.sellItem(sellItem, sellQuant, check);
				if (check) beverages.sellItem(sellItem, sellQuant);
			}
			break;
		case 5: // Return Item
			fourFive(cat, retCat, retItem, retQuant);
			if (retCat == "dairy") {
				cat.returnItem(retItem, retQuant);
				dairy.returnItem(retItem, retQuant);
			}
			else if (retCat == "fruit") {
				cat.returnItem(retItem, retQuant);
				fruit.returnItem(retItem, retQuant);
			}
			else if (retCat == "vegetables") {
				cat.returnItem(retItem, retQuant);
				vegetables.returnItem(retItem, retQuant);
			}
			else if (retCat == "bakery") {
				cat.returnItem(retItem, retQuant);
				bakery.returnItem(retItem, retQuant);
			}
			else {
				cat.returnItem(retItem, retQuant);
				beverages.returnItem(retItem, retQuant);
			}
			break;
		case 6: // Add Item
			six(cat, category, item, quant, doll, cent);
			if (category == "dairy") {
				index = dairy.getCatalogVec().size();
				cat.loadInventoryAt(index, item, quant, doll, cent);
				dairy.loadInventory(item, quant, doll, cent);
			}
			else if (category == "fruit") {
				index = dairy.getCatalogVec().size() + fruit.getCatalogVec().size();
				cat.loadInventoryAt(index, item, quant, doll, cent);
				fruit.loadInventory(item, quant, doll, cent);
			}
			else if (category == "vegetables") {
				index = dairy.getCatalogVec().size() + fruit.getCatalogVec().size() + vegetables.getCatalogVec().size();
				cat.loadInventoryAt(index, item, quant, doll, cent);
				vegetables.loadInventory(item, quant, doll, cent);
			}
			else if (category == "bakery") {
				index = dairy.getCatalogVec().size() + fruit.getCatalogVec().size() + vegetables.getCatalogVec().size() + bakery.getCatalogVec().size();
				cat.loadInventoryAt(index, item, quant, doll, cent);
				bakery.loadInventory(item, quant, doll, cent);
			}
			else {
				cat.loadInventory(item, quant, doll, cent);
				beverages.loadInventory(item, quant, doll, cent);
			}
			break;
		case 7: // Update inventory
			/*
				THIS BLOCK READS THE INVENTORY TO THE inventory.txt FILE, CREATING
				A DYNAMIC INVENTORY THAT CHANGES AS ITEMS ARE ADDED
			*/
			invPrint.open(INV);
			for (int i = 0; i < 5; i++) {
				if (i == 0) {
					for (unsigned int j = 0; j < dairy.getCatalogVec().size(); j++) {
						if (j == 0) invPrint << "DAIRY 999 999 999" << endl;
						invPrint << dairy.getItem(j) << " " << dairy.getQuant(j) << " "
							<< dairy.getDollar(j) << " " << dairy.getCent(j) << endl;
					}
				}
				else if (i == 1) {
					for (unsigned int j = 0; j < fruit.getCatalogVec().size(); j++)
					{
						if (j == 0) invPrint << "FRUIT 999 999 999" << endl;
						invPrint << fruit.getItem(j) << " " << fruit.getQuant(j) << " "
							<< fruit.getDollar(j) << " " << fruit.getCent(j) << endl;
					}
				}
				else if (i == 2) {
					for (unsigned int j = 0; j < vegetables.getCatalogVec().size(); j++)
					{
						if (j == 0) invPrint << "VEGETABLES 999 999 999" << endl;
						invPrint << vegetables.getItem(j) << " " << vegetables.getQuant(j) << " "
							<< vegetables.getDollar(j) << " " << vegetables.getCent(j) << endl;
					}
				}
				else if (i == 3) {
					for (unsigned int j = 0; j < bakery.getCatalogVec().size(); j++)
					{
						if (j == 0) invPrint << "BAKERY 999 999 999" << endl;
						invPrint << bakery.getItem(j) << " " << bakery.getQuant(j) << " "
							<< bakery.getDollar(j) << " " << bakery.getCent(j) << endl;
					}
				}
				else {
					for (unsigned int j = 0; j < beverages.getCatalogVec().size(); j++)
					{
						if (j == 0) invPrint << "BEVERAGES 999 999 999" << endl;
						invPrint << beverages.getItem(j) << " " << beverages.getQuant(j) << " "
							<< beverages.getDollar(j) << " " << beverages.getCent(j) << endl;
					}
					invPrint << "END 999 999 999" << endl;
				}
			}
			invPrint.close();
			cout << "\nInventory backup successfully updated\n";
			break;
		case 8: // Exit
			break;
		}

		menu(input);
	}

	cout << "\nThanks for working at IAN'S GROCERIES\n";

	return 0;
}

/*
	MAIN MENU FUNCTION
	Prints main menu options and gathers user's option
*/
void mainMenu(int& x) {
	cout << "*********************************************************\n"
		<< "**********           IAN'S GROCERIES           **********\n"
		<< "********** Remember to smile and be courteous! **********\n"
		<< "*********************************************************\n\n";

	cout << "Print Catalog ----------------------------------------- 1\n"
		<< "Print Section Catalog --------------------------------- 2\n"
		<< "Search Inventory -------------------------------------- 3\n"
		<< "Sell items -------------------------------------------- 4\n"
		<< "Return items ------------------------------------------ 5\n"
		<< "Add new items ----------------------------------------- 6\n"
		<< "Update items ------------------------------------------ 7\n"
		<< "Exit -------------------------------------------------- 8\n";
	cin >> x;
	if (x < 1 || x > 8) {
		cout << "Error: Enter a value between 1 and 8: ";
		cin >> x;
	}
}

/*
	MENU FUNCTION
	Prints shortened form of main menu and takes option
*/
void menu(int& x) {
	cout << "\nPrint Catalog ----------------------------------------- 1\n"
		<< "Print Section Catalog --------------------------------- 2\n"
		<< "Search Inventory -------------------------------------- 3\n"
		<< "Sell items -------------------------------------------- 4\n"
		<< "Return items ------------------------------------------ 5\n"
		<< "Add new items ----------------------------------------- 6\n"
		<< "Update items ------------------------------------------ 7\n"
		<< "Exit -------------------------------------------------- 8\n";
	cin >> x;
	if (x < 1 || x > 8) {
		cout << "Error: Enter a value between 1 and 8: ";
		cin >> x;
	}
}

/*
	TWO MENU FUNCTION
	Menu for option 2, gathers user input
*/
int two() {
	int temp;
	cout << "\nWhich section would you like to see?\n"
		<< "Dairy -------- 1\n"
		<< "Fruit -------- 2\n"
		<< "Vegetables --- 3\n"
		<< "Bakery ------- 4\n"
		<< "Beverages ---- 5\n";
	cin >> temp;
	return temp;
}

/*
	THREE MENU FUNCTION
	Menu for option 3, gathers user input
*/
string three() {
	string temp;
	cout << "What item would you like to search for(use a hyphen between words, i.e. Dozen-Eggs): ";
	cin >> temp;
	return temp;
}

/*
	FOURFIVE MENU FUNCTION
	Acts as menu for options four and five given their similarity
*/
void fourFive(inventory inv, string& cat, string& item, int& quant) {
	cout << "\nCategory of Item: ";
	cin >> cat;
	if (cat != "dairy" && cat != "vegetables" && cat != "fruit" && cat != "bakery" && cat != "beverages") {
		cout << "Error: Please input your response in lowercase letters: ";
		cin >> cat;
	}

	int temp;
	cout << "Item Name(format-like-so): ";
	cin >> item;
	if (!(inv.findItemBool(item, temp))) {
		cout << "Error: item is not present: ";
		cin >> item;
	}

	cout << "Quantity: ";
	cin >> quant;
	if (quant <= 0) {
		cout << "Error: Quantity must be greater than zero: ";
		cin >> quant;
	}
}

/*
	SIX MENU FUNCTION
	Menu for option 6, gathers user inputs
*/
void six(inventory inv, string& cat, string& item, int& quant, int& dollar, int& cent) {
	cout << "\nCategory of Item: ";
	cin >> cat;
	if (cat != "dairy" && cat != "vegetables" && cat != "fruit" && cat != "bakery" && cat != "beverages") {
		cout << "Error: Only the manager may add new categories, otherwise please input your response in lowercase letters: ";
		cin >> cat;
	}

	int temp;
	cout << "Item Name(format-like-so): ";
	cin >> item;
	if (inv.findItemBool(item, temp)) {
		cout << "Error: item is already present: ";
		cin >> item;
	}

	cout << "Quantity: ";
	cin >> quant;
	if (quant < 0) {
		cout << "Error: Quantity must be greater than or equal to zero: ";
		cin >> quant;
	}

	cout << "Price(dollar cent): ";
	cin >> dollar >> cent;
	if (dollar < 0 || cent < 0) {
		cout << "Error: Price values must be greater than zero: ";
		cin >> dollar >> cent;
	}
}