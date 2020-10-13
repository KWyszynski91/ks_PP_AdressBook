#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "AuxiliaryMethods.h"
#include "User.h"
#include "TextFile.h"

using namespace std;

class UserFile: public TextFile
{
    const string fileName;
    string replaceUserDataToLineSeparatedVerticalDashes(User user);
    User getUserData(string singleUserDataSeparatedVerticalDashes);
public:
    UserFile(string USER_FILE_NAME):  TextFile(USER_FILE_NAME)  {}; //LISTA INICJALIZACYJNA
    void appendUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveUsersToFile(vector <User> users);
};

#endif
