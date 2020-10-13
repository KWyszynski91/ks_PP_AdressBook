#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFile
{
    const string fileName;
public:
    TextFile(string FILE_NAME) : fileName(FILE_NAME) {
    }
    string getFileName();
    bool isTheFileEmpty();
};

#endif
