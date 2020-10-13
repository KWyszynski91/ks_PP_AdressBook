#include "UserFile.h"

//METODY

void UserFile::appendUserToFile(User user)
{
    fstream textFile;
    string userDataLine = "";
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true)
    {
        userDataLine = replaceUserDataToLineSeparatedVerticalDashes(user);

        if (TextFile::isTheFileEmpty()==true)
        {
            textFile<<userDataLine;
        }
        else
        {
            textFile<<endl<<userDataLine;
        }
        textFile.close();
    }
    else
        cout << "Failed to open file: " << getFileName() << " and entered data was not saved." << endl;
}

string UserFile::replaceUserDataToLineSeparatedVerticalDashes(User user)
{
    string userDataLine = "";
    userDataLine += AuxiliaryMethods::intToStringConversion(user.getId())+ '|';
    userDataLine += user.getLogin() + '|';
    userDataLine += user.getPassword() + '|';
    return userDataLine;
}

vector <User> UserFile::loadUsersFromFile()
{
    User user;
    vector <User> users;
    string singleUserDataSeparatedVerticalDashes = "";
    fstream textFile;

    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, singleUserDataSeparatedVerticalDashes))
        {
            user = getUserData(singleUserDataSeparatedVerticalDashes);
            users.push_back(user);
        }
        textFile.close();
    }
    return users;
}

User UserFile::getUserData(string singleUserDataSeparatedVerticalDashes)
{
    User user;
    string userSingleData = "";
    int numberOfUserSingleData = 1;

    for (int signPosition = 0; signPosition < singleUserDataSeparatedVerticalDashes.length(); signPosition++)
    {
        if (singleUserDataSeparatedVerticalDashes[signPosition] != '|')
        {
            userSingleData += singleUserDataSeparatedVerticalDashes[signPosition];
        }
        else
        {
            switch(numberOfUserSingleData)
            {
            case 1:
                user.setId(atoi(userSingleData.c_str()));
                break;
            case 2:
                user.setLogin(userSingleData);
                break;
            case 3:
                user.setPassword(userSingleData);
                break;
            }
            userSingleData = "";
            numberOfUserSingleData++;
        }
    }
    return user;
}

void UserFile::saveUsersToFile(vector <User> users)
{
    fstream textFile;
    string userDataLine = "";
    vector <User>::iterator itrEnd = --users.end();
    textFile.open(TextFile::getFileName().c_str(), ios::out);

    if (textFile.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            userDataLine = replaceUserDataToLineSeparatedVerticalDashes(*itr);

            if (itr == itrEnd)
            {
               textFile << userDataLine;
            }
            else
            {
                textFile << userDataLine << endl;
            }
            userDataLine = "";
        }
    }
    else
    {
        cout << "Cannot open the file." << fileName << endl;
    }
    textFile.close();
}
