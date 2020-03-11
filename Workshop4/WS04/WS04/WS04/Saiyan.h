// CLASS:	OOP244NGG
// NAME:	Minh Triet Nhan
// Std#:	112512199
// ID:		mtnhan@myseneca.ca
#ifndef SDDS_SAIYAN_H__
#define SDDS_SAIYAN_H__

namespace sdds {
	class Saiyan
	{
		char m_name[31];
		int m_dob;
		int m_power;
		bool m_super;
	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, bool super = false);
		bool hasLost(const Saiyan& other) const;
	};
}

#endif

