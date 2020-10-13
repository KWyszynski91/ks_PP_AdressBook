#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string intToStringConversion(int number);
    static string loadLine();
    static string changeFirstLetterToLargeAndRestToSmall(string text);
    static int stringToIntConversion(string number);
    static char loadSign();
    static int loadInteger();
    static string getNumber(string text, int signPosition);
};

#endif
