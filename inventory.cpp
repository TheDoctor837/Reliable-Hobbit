#include "inventory.h"

/*
	SELL ITEM FUNCTION
	Removes as many items as are being sold from the quantity
	of the item referenced
*/
void inventory::sellItem(string x, int y, bool& check) {
	int temp;
	if (findItemBool(x, temp)) {
		cout << fixed << setprecision(2) << endl;
		for (int i = 1; i <= y; i++) {
			if (quant[temp] > 0) quant[temp]--;
		}
		double c = cent[temp], d = dollar[temp];
		double cost = y * (d + (c / 100));
		double total = cost + (cost * 0.06);
		char answer;
		cout << "Item: " << catalog[temp] << endl
			<< "Quantity: " << quant[temp] << endl
			<< "Price: $" << dollar[temp] << "." << cent[temp] << endl
			<< "Item ID: " << temp << endl;
		cout << "\nTotal price, including state sales tax, is $" << total << endl
			<< "Does the customer have enough money to pay(y/n): ";
		cin >> answer;
		if (answer == 'y') {
			cout << "\nItems successfully sold!\n";
			check = true;
		}
		else {
			cout << "\nItems unsuccessfully sold!\n";
			check = false;
			for (int i = 1; i <= y; i++) {
				quant[temp]++;
			}
		}
	}
	else {
		cout << "\nError: Item not found\n";
		check = false;
	}
}

/*
	RETURN ITEM FUNCTION
	Adds as many items as are being returned to the quantity 
	of the item referenced
*/
void inventory::returnItem(string x, int y) {
	int temp;
	if (findItemBool(x, temp)) {
		for (int i = 1; i <= y; i++) {
			quant[temp]++;
		}
		cout << "\nItems successfully returned!\n";
	}
	else
		cout << "\nError: Item not found\n";
}

/*
	LOAD INVENTORY FUNCTION
	Loads each vector with given arguments
*/
void inventory::loadInventory(string x, int y, int d, int c) {
	catalog.push_back(x);
	quant.push_back(y);
	dollar.push_back(d);
	cent.push_back(c);
}

/*
	LOAD INVENTORY AT FUNCTION 
	Loads each vector with given argument at given position
*/
void inventory::loadInventoryAt(int index, string x, int y, int d, int c) {
	catalog.insert(catalog.begin() + index, x);
	quant.insert(quant.begin() + index, y);
	dollar.insert(dollar.begin() + index, d);
	cent.insert(cent.begin() + index, c);
}

/*
	FIND ITEM BOOL FUNCTION
	Searches for item and returns a bool value based on whether or not the item is found
*/
bool inventory::findItemBool(const string x, int& y) {
	for (unsigned int i = 0; i < catalog.size(); i++) {
		string temp = catalog[i];
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (x == temp || x == catalog[i]) {
			y = i;
			return true; 
		}
	}
	return false;
}

/*
	FIND ITEM FUNCTION
	Performs linear search on catalog and prints item if found
*/
string inventory::findItem(string x) {
	string str;
	cout << endl;
	for (unsigned int i = 0; i < catalog.size(); i++) {
		string temp = catalog[i];
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (x == temp || x == catalog[i]){
			str = "Item: " + catalog[i]
				+ "\nQuantity: " + to_string(quant[i])
				+ "\nPrice: $" + to_string(dollar[i]) + "." + to_string(cent[i])
				+ "\n";
			break;
		}
		else if (i == catalog.size() - 1) {
			str = "Cannot find " + x + "\n";
		}
	}
	return str;
}

/*
	PRINT INVENTORY FUNCTION
	Prints inventory for full catalog
*/
void inventory::printInventory() {
	cout << "FULL STORE CATALOG:" << endl
		<< endl;

	for (unsigned int i = 0; i < catalog.size(); i++)
		cout << "Item: " << catalog[i] << endl
		<< "Quantity: " << quant[i] << endl 
		<< "Price: $" << dollar[i] << "." << cent[i] << endl
		<< "Item ID: " << i << endl
		<< endl;

	cout << "END OF FULL STORE CATALOG" << endl
		<< endl;
}