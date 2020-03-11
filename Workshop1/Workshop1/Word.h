#ifndef _SDDS_WORD_H_
#define _SDDS_WORD_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cctype>
#include <cstring>
#include "Tools.h"

const int MAX_WORD_LEN = 21;
const int MAX_NO_OF_WORDS = 500;

namespace sdds {
    struct Word {
        char letters[MAX_WORD_LEN];
        int count;
    };
    int searchWords(const Word words[], int num, const char word[]);
    void addWord(Word words[], int* index, const char newWord[]);
    void swap(Word* p1, Word* p2);
    void sort(Word words[], int cnt);
    void print(const Word* w, bool gotoNextLine);
    void report(const Word words[], int noOfWords, int longestWord);
}

#endif
