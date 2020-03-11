#pragma once
#ifndef SDDS_SAIYAN_H__
#define SDDS_SAIYAN_H__

namespace sdds {
#define MAX_NAME 30
	class Saiyan
	{
		char* m_name;
		int m_dob;
		int m_power;
		bool m_super;
		int m_level;
	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		~Saiyan();
		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool hasLost(Saiyan& other);
		void powerup();
	};
}

#endif

