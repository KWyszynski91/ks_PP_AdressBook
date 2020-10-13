#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager
{
    int logedUserID;
    vector <User> users;

    User setNewUserData();
    int setNewUserID();
    bool isLoginExist(string login);
    UserFile userFile;
public:
    UserManager(string userFileName): userFile(userFileName)
    {logedUserID=0;
    users=userFile.loadUsersFromFile();
    }; //LISTA INICJALIZACYJNA
    void userRegistration();
    void showAllUsers();
    void loadUsersFromFile();
    void loginUser();
    void changingPasswordOfTheLoggedUser();
    void logoutUser();
    int getLogedUserID();
    bool isTheUserLogedIn();
};

#endif
