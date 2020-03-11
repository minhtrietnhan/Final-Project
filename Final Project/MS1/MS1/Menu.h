/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: MenuItem.h
Version 1.0
Author John Doe
Revision History
-----------------------------------------------------------
Date Reason
2020/?/? Preliminary release
2020/?/? Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

/*------------------------+
|  Name: Minh Triet Nhan  |
|  Student ID: 112512199  |
|-------------------------+
*/

#ifndef _SDDS_MENU_H
#define _SDDS_MENU_H

#include "MenuItem.h"
#include <iostream>
#include <string>
#define MAX_NO_OF_ITEMS 10
namespace sdds {
	class Menu
	{
		char* title;
		MenuItem* menuItems;
		int noOfItems;

	public:
		Menu() : title(nullptr), menuItems(nullptr), noOfItems(0) {}
		Menu(const char* title, int indent = 0);
		Menu(const Menu& menu);
		~Menu() {
			delete[] this->title;
			delete[] this->menuItems;
			this->title = nullptr;
			this->menuItems = nullptr;
		}

		bool isEmpty() const;
		void add(const char* str);
		int run();
		std::ostream& display(std::ostream& os);
		Menu& operator=(const Menu& menu);
		operator bool();
		operator int();
		std::string& operator=(const char* str);
		Menu& operator<<(const char* item);
	};
}
#endif

