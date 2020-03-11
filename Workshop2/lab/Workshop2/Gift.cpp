//Gift.cpp
#include "Gift.h"
#include <iostream>
using namespace std;

namespace sdds {
	// Get gift's description from input
	void gifting(char* description)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> description;
	}

	// Get gift's price from input
	void gifting(double& price)
	{
		bool valid = false;
		do {
			cout << "Enter gift price: ";
			cin >> price;
			if (price >= 0 && price <= MAX_PRICE)
				valid = true;
			else
				cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
		} while (valid == false);
	}

	// Get gift's unit from input
	void gifting(int& unit)
	{
		bool valid = false;
		do {
			cout << "Enter gift units: ";
			cin >> unit;
			if (unit >= 1)
				valid = true;
			else
				cout << "Gift units must be at least 1" << endl;
		} while (valid == false);
	}

	// Display gift's information
	void display(const Gift& gift)
	{
		cout << "Gift Details:" << endl;
		cout << "Description: " << gift.g_description << endl;
		cout << "Price: " << gift.g_price << endl;
		cout << "Units: " << gift.g_units << endl;
	}
}