#include "subInventory.h"

/*
	PRINT INVENTORY - SUBINVENTORY
	Altered so it can account for the different sections of the store
*/
void subInventory::printInventory() {
	cout << "FULL CATALOG OF " << category << ":" << endl
		<< endl;

	for (unsigned int i = 0; i < getCatalogVec().size(); i++)
		cout << "Item: " << getItem(i) << endl
		<< "Quantity: " << getQuant(i) << endl
		<< "Price: $" << getDollar(i) << "." << getCent(i) << endl
		<< "See full catalog for item ID" << endl
		<< endl;

	cout << "END OF CATALOG" << endl
		<< endl;
}

/*
	SELL ITEM FUNCTION
	Removes as many items as are being sold from the quantity
	of the item referenced, overloaded to remove surplus confirmation notice 
	and not print the item twice
*/
void subInventory::sellItem(string x, int y) {
	int temp;
	if (findItemBool(x, temp)) {
		for (int i = 1; i <= y; i++) {
			if (quant[temp] > 0) quant[temp]--;
		}
	}
	else
		cout << "\nError: Item not found\n";
}

/*
	RETURN ITEM FUNCTION
	Adds as many items as are being returned to the quantity
	of the item referenced, overloaded to remove surplus confirmation
	notice
*/
void subInventory::returnItem(string x, int y) {
	int temp;
	if (findItemBool(x, temp)) {
		for (int i = 1; i <= y; i++) {
			quant[temp]++;
		}
	}
	else
		cout << "\nError: Item not found\n";
}

/*
	SUBINVENTORY CONSTRUCTOR
	Sets category to NULL value
*/
subInventory::subInventory()
{
	category = "NULL";
}