#ifndef _SDDS_GIFT_H_
#define _SDDS_GIFT_H_

namespace sdds {
	#define MAX_DESC 15
	#define MAX_PRICE 999.99

	struct Gift {
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
	};

	void gifting(char*);
	void gifting(double&);
	void gifting(int&);
	void display(const Gift&);
}


#endif
