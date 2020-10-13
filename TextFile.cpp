#include "TextFile.h"

string TextFile::getFileName()
{
    return fileName;
}

bool TextFile::isTheFileEmpty()
{
    bool isEmpty = true;
    fstream TextFile;
    TextFile.open(getFileName().c_str(), ios::app);

    if (TextFile.good() == true)
    {
        TextFile.seekg(0, ios::end);
        if (TextFile.tellg() != 0)
            isEmpty = false;
    }
    TextFile.close();
    return isEmpty;
}
