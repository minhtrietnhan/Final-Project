// Name:		Minh Triet Nhan
// Student ID:	112512199
// Workshop 5

#ifndef _SDDS_SHIP_H
#define _SDDS_SHIP_H
#include "Engine.h"

namespace sdds {
#define MAX_ENGINE 10
#define MAX_SHIP_TYPE 7

	class Ship
	{
		Engine* engines;
		char* type;
		int noOfEngine;
		double distance;
	public:
		Ship();
		Ship(const char* type, Engine engines[], int noOfEngine);
		~Ship();
		void setEmpty();
		bool empty() const;
		float calculatePower() const;
		void display() const;
		Ship& operator+=(Engine e);
		friend bool operator==(const Ship& first, const Ship& second);
	};

	bool operator<(const Ship& ship, double power);
}

#endif

