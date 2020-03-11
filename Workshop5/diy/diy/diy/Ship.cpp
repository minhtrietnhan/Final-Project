// Name:		Minh Triet Nhan
// Student ID:	112512199
// Workshop 5

#define _CRT_SECURE_NO_WARNINGS
#include "Ship.h"
#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

namespace sdds {
	Ship::Ship()
	{
		this->setEmpty();
	}

	Ship::Ship(const char* type, Engine engines[], int noOfEngine)
	{
		if (type != nullptr && strlen(type) <= 6 && engines != nullptr && noOfEngine > 0) {
			if (this->type != nullptr)
				delete[] this->type;
			this->type = new char[strlen(type) + 1];
			strcpy(this->type, type);

			if (this->engines != nullptr)
				delete[] this->engines;
			this->engines = new Engine[noOfEngine];
			for (int i = 0; i < noOfEngine; i++)
				this->engines[i] = engines[i];

			this->noOfEngine = noOfEngine;
			this->distance = 0;
		}
		else
			this->setEmpty();
	}

	Ship::~Ship()
	{
		if (!this->empty()) {
			delete[] this->type;
			this->type = nullptr;

			delete[] this->engines;
			this->engines = nullptr;
		}
	}

	void Ship::setEmpty()
	{
		if (this->type != nullptr)
			delete[] this->type;
		this->type = nullptr;
		this->noOfEngine = 0;
		this->distance = 0;
		if (this->engines != nullptr)
			delete[] this->engines;
		this->engines = nullptr;
	}

	bool Ship::empty() const
	{
		return (this->type == nullptr && this->noOfEngine == 0 && this->engines == nullptr && this->distance == 0);
	}

	float Ship::calculatePower() const
	{
		if (!this->empty()) {
			float totalPower = 0.0;
			for (int i = 0; i < this->noOfEngine; i++) {
				totalPower += (float)(this->engines[i].get() * 5);	// get each power of engine (size * 5)
			}
			return totalPower;
		}
		else {
			cout << "Error: Empty Ship!" << endl;
			return 0.0;
		}
	}

	void Ship::display() const
	{
		if (!this->empty()) {
			cout << this->type << "-";
			cout << fixed;
			cout << setprecision(2);
			cout << setw(6);
			cout << this->calculatePower() << endl;
			for (int i = 0; i < this->noOfEngine; i++)
				this->engines[i].display();
		}
		else
			cout << "No available data" << endl;
	}

	Ship& Ship::operator+=(Engine e)
	{
		// TODO: insert return statement here
		if (!this->empty()) {
			if (this->noOfEngine < 10) {
				Engine* newEngine = new Engine[this->noOfEngine + 1];
				for (int i = 0; i < this->noOfEngine; i++)
					newEngine[i] = this->engines[i];
				this->noOfEngine++;		// increase the size of array by 1
				newEngine[this->noOfEngine - 1] = e;		// assign the added engine to the new array of engines

				delete[] this->engines;		// deallocate old array of engines
				this->engines = newEngine;
				return *this;
			}
			else {
				cout << "Error: Maximum number of Engines allowed!" << endl;
				return *this;
			}
		}
		else {
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
			return *this;
		}
	}



	bool operator==(const Ship& first, const Ship& second)
	{
		if (!first.empty() && !second.empty())
			return (first.calculatePower() == second.calculatePower());
		else
			return false;
	}

	bool operator<(const Ship& ship, double power)
	{
		if (!ship.empty())
			return ship.calculatePower() < power;
		else
			return false;
	}

}