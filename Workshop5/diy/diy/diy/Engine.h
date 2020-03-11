// Name:		Minh Triet Nhan
// Student ID:	112512199
// Workshop 5

#ifndef _SDDS_ENGINE_H
#define _SDDS_ENGINE_H

namespace sdds {
#define MAX_ENGINE_TYPE 30
	class Engine
	{
		double size;
		char type[MAX_ENGINE_TYPE + 1];
	public:
		Engine();
		Engine(const char* type, double size);
		void setEmpty();
		double get() const;
		void display() const;
		bool isValid() const;
	};
}
#endif

