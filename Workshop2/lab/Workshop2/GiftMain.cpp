/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory & Function Overloading
// File GiftMain.cpp
// Version 1.0
// Date	2020/01/05
// Author Michael Huang
// Description
// Tests Gift module and provides a set of TODOs to complete
// which the main focuses are dynamic memory allocation
//
// Revision History
// -----------------------------------------------------------
// Name: Minh Triet Nhan            Date: 2020-01-21            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
//GiftMain.cpp

#include <iostream>
#include "Gift.h"
#include "Gift.h" // Intentional
using namespace std;
using namespace sdds;

int main() {
    int numberOfGifts = 0; // Initial number of Gifts

    struct Gift* gift = nullptr;

    cout << "Enter number of Gifts to allocate: ";
    cin >> numberOfGifts;

    if (numberOfGifts < 1) return 1;

    gift = new Gift[numberOfGifts];

    for (int i = 0; i < numberOfGifts; ++i) {
        cout << "Gift #" << i + 1 << ": " << endl;
        gifting(gift[i].g_description);
        cin.ignore(2000, '\n'); // clear input buffer
        gifting(gift[i].g_price);
        cin.ignore(2000, '\n'); // clear input buffer
        gifting(gift[i].g_units);
        cin.ignore(2000, '\n');
        cout << endl;
    }

    for (int i = 0; i < numberOfGifts; ++i) {
        cout << "Gift #" << i + 1 << ":" << endl;
        display(gift[i]);
        cout << endl;
    }

    delete[] gift;
    gift = nullptr;

    return 0;
}