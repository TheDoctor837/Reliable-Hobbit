#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

/*-----------------------------------------------------------
	INVENTORY CLASS
	
	Handles all matters relating to the inventory of the store
------------------------------------------------------------*/
class inventory
{
private:
	vector<string> catalog; // This vector holds the catalog, given that I changed the inventory constantly, it cannot have a set size
	vector<int> dollar, cent; // This vector holds the quantity of each item
public:
	vector<int> quant;

	void sellItem(string, int, bool&);
	void returnItem(string, int);
	void loadInventory(string, int, int, int); // Loads values to inv and quant
	void loadInventoryAt(int, string, int, int, int); // Loads values to specific area of full catalog
	void printInventory(); // Prints catalog
	string findItem(string); // Finds item according to name
	bool findItemBool(string, int&); // Returns bool value corresponding to the items existence
	string getItem(int x) { return catalog[x]; } // Prints name of item
	int getQuant(int x) { return quant[x]; } // Prints quantity of item
	int getDollar(int x) { return dollar[x]; } // Prints dollar value of item
	int getCent(int x) { return cent[x]; } // Prints cent value of item
	vector<int> getQuantVec() { return quant; } // Returns quantity vector
	vector<int> getDollarVec() { return dollar; } // Returns dollar value vector
	vector<int> getCentVec() { return cent; } // Returns cent value vector
	vector<string> getCatalogVec() { return catalog; } // Returns name vector
};