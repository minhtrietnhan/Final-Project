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
		if (name == nullptr || strlen(name) == 0 || dob < 1 || dob >= 2020 || power <= 0)
			this->setEmpty();
		else {
			this->m_name = new char[MAX_NAME + 1];
			strcpy(this->m_name, name);
			this->m_dob = dob;
			this->m_power = power;
			this->m_super = false;
			this->m_level = 0;
		}
	}

	Saiyan::~Saiyan()
	{
		/*if (this->m_name == nullptr)
			cout << "NULL but deleted!\n";
		else
			cout << this->m_name << endl;*/
		delete[] this->m_name;
		this->m_name = nullptr;
	}

	bool Saiyan::isSuper() const
	{
		return this->m_super;
	}

	bool Saiyan::isValid() const
	{
		return (this->m_name != nullptr && this->m_dob > 0 && this->m_dob < 2020  && this->m_power > 0);
	}

	void Saiyan::setEmpty()
	{
		this->m_name = nullptr;
		this->m_dob = 0;
		this->m_power = 0;
		this->m_super = false;
		this->m_level = 0;
	}

	void Saiyan::display() const
	{
		if (this->isValid()) {
			cout << this->m_name << endl;
			cout << "DOB: " << this->m_dob << " Power: " << this->m_power << endl;
			cout << "Super Saiyan Ability: " << (this->isSuper() ? "Super Saiyan." : "Not super Saiyan.") << endl;
			if (this->m_level > 0)
				cout << "Super Saiyan level is: " << this->m_level << endl;
			else
				cout << endl;
		}
		else {
			cout << "Invalid Saiyan!" << endl;
		}
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super)
	{
		if (name == nullptr || strlen(name) == 0 || dob < 1 || dob >= 2020 || power <= 0)
			this->setEmpty();
		else {
			if (this->m_name != nullptr)
				delete[] this->m_name;
			this->m_name = new char[MAX_NAME + 1];
			strcpy(this->m_name, name);
			this->m_dob = dob;
			this->m_power = power;
			this->m_super = super;
			if (this->isSuper())
				this->m_level = level;
			else
				this->m_level = 0;
		}
	}

	bool Saiyan::hasLost(Saiyan& other)
	{
		if (this->isValid() == false || other.isValid() == false)
			return false;
		else {
			this->powerup();
			other.powerup();
			if (this->m_power < other.m_power)
				return true;
			else
				return false;
		}
	}

	void Saiyan::powerup()
	{
		if (this->isValid()) {
			this->m_power *= (this->m_level + 1);
		}
	}
}
