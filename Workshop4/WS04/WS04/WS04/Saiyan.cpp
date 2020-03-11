// CLASS:	OOP244NGG
// NAME:	Minh Triet Nhan
// Std#:	112512199
// ID:		mtnhan@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include "Saiyan.h"
#include <cstring>
#include <iostream>

using namespace std;
namespace sdds {
	Saiyan::Saiyan()
	{
		/*this->m_name[0] = '\0';
		this->m_dob = 0;
		this->m_power = 0;
		this->m_super = false;*/

		this->setEmpty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power)
	{
		if (name == nullptr || dob >= 2020 || power <= 0)
			this->setEmpty();
		else {
			strcpy(this->m_name, name);
			this->m_dob = dob;
			this->m_power = power;
			this->m_super = false;
		}
	}

	bool Saiyan::isSuper() const
	{
		return this->m_super;
	}

	bool Saiyan::isValid() const
	{
		return (this->m_name[0] != '\0' && this->m_dob > 0 && this->m_power > 0);
	}

	void Saiyan::setEmpty()
	{
		this->m_name[0] = '\0';
		this->m_dob = 0;
		this->m_power = 0;
		this->m_super = false;
	}

	void Saiyan::display() const
	{
		if (this->isValid()) {
			cout << this->m_name << endl;
			cout << "DOB: " << this->m_dob << " Power: " << this->m_power << endl;
			cout << "Super Saiyan Ability: " << (this->isSuper() ? "Super Saiyan." : "Not super Saiyan.") << endl << endl;
		}
		else {
			cout << "Invalid Saiyan!" << endl;
		}
	}

	void Saiyan::set(const char* name, int dob, int power, bool super)
	{
		if (name == nullptr || dob >= 2020 || power <= 0)
			this->setEmpty();
		else {
			strcpy(this->m_name, name);
			this->m_dob = dob;
			this->m_power = power;
			this->m_super = super;
		}
	}

	bool Saiyan::hasLost(const Saiyan& other) const
	{
		if (!this->isValid() || !other.isValid())
			return false;
		else if (this->m_power < other.m_power)
			return true;
		else
			return false;
	}
}
