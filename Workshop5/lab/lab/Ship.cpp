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
		if (type != nullptr && strlen(type) <= 6 && engines != nullptr && noOfEngine > 0 && noOfEngine <= 10) {
			strcpy(this->type, type);
			for (int i = 0; i < noOfEngine; i++)
				this->engines[i] = engines[i];
			this->noOfEngine = noOfEngine;
			this->distance = 0;
		}
		else
			this->setEmpty();
	}

	void Ship::setEmpty()
	{
		this->type[0] = '\0';
		this->noOfEngine = 0;
		this->distance = 0;
		for (int i = 0; i < MAX_ENGINE; i++)	// set each engine to empty
			engines[i].setEmpty();
	}

	bool Ship::empty() const
	{
		return (this->type[0] == '\0' && this->noOfEngine == 0 && !this->engines[0].isValid() && this->distance == 0);
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
				engines[i].display();
		}
		else
			cout << "No available data" << endl;
	}

	Ship& Ship::operator+=(Engine e)
	{
		// TODO: insert return statement here
		if (!this->empty()) {
			if (this->noOfEngine < 10) {
				this->noOfEngine += 1;
				this->engines[this->noOfEngine - 1] = e;
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