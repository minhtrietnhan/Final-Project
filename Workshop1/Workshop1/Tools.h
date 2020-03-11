#ifndef _SDDS_TOOLS_H_
#define _SDDS_TOOLS_H_

#include <iostream>
#include <cctype>
#include <cstring>

namespace sdds {
	void toLowerCaseAndAlphabeticCopy(char des[], const char source[]);
	void title();
	void endList();
	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
	void wordStats(bool logOn);
	void programTitle();
}



#endif
