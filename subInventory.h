#pragma once
#include "inventory.h"
#include <vector>
using namespace std;

/*-----------------------------------------------------
	SUBINVENTORY CLASS

	Specialized class that handles the inventory of the 
	separate sections of the store
-----------------------------------------------------*/
class subInventory :
	public inventory
{
private:
	string category;
public:
	void sellItem(string x, int y);
	void returnItem(string x, int y);
	void printInventory(); // Overloaded to add the catalog being printed
	void setCategory(string x) { category = x; } // Sets category value to passed argument

	subInventory();
};