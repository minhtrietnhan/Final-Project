/* Citation and Sources...
Final Project Milestone 1
Module: MenuItem
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

#ifndef _SDDS_MENU_ITEM_H
#define _SDDS_MENU_ITEM_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Menu.h"

namespace sdds {
	class MenuItem
	{
		char* content;

		MenuItem() : content(nullptr) {}
		MenuItem(const char* content);
		MenuItem(const MenuItem& mi);
		~MenuItem() {
			delete this->content;
			this->content = nullptr;
		}

		std::ostream& display(std::ostream& os);
		MenuItem& operator=(const MenuItem& mi);
		friend class Menu;
	};
}

#endif

