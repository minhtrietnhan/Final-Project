// Name:		Minh Triet Nhan
// Student ID:	112512199
// Workshop 5

#define _CRT_SECURE_NO_WARNINGS
#include "Engine.h"
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
namespace sdds {
	Engine::Engine()
	{
		this->setEmpty();
	}
	Engine::Engine(const char* type, double size)
	{
		if (size > 0 && type != nullptr && strlen(type) != 0) {
			this->size = size;
			strcpy(this->type, type);
		}
		else
			this->setEmpty();
	}
	void Engine::setEmpty()
	{
		this->size = 0;
		this->type[0] = '\0';
	}
	double Engine::get() const
	{
		return size;
	}
	void Engine::display() const
	{
		if (this->isValid()) {
			cout << fixed;
			cout << setprecision(2);
			cout << this->size << " liters - " << this->type << endl;
		}
		else
			cout << "No available data." << endl;
	}
	bool Engine::isValid() const
	{
		return (this->size > 0 && this->type[0] != '\0');
	}
}
