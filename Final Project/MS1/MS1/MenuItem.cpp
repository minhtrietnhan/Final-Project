/* Citation and Sources...
Final Project Milestone 1
Module: MenuItem
Filename: MenuItem.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "MenuItem.h"
#include <iostream>
#include <cstring>
namespace sdds {
	MenuItem::MenuItem(const char* content)
	{
		if (content == nullptr || strlen(content) == 0)
			*this = MenuItem();
		else {
			this->content = new char[strlen(content) + 1];
			
		}
	}
}