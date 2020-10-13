#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = setNewUserData();

    users.push_back(user);
    userFile.appendUserToFile(user);

    cout << endl << "New account has been created." << endl << endl;
    system("pause");
}

User UserManager::setNewUserData()
{
    User user;
    user.setId(setNewUserID());
    string login;
    do
    {
        cout<< "Enter login: ";
        cin>>login;
        user.setLogin(login);
    } while (isLoginExist(user.getLogin()) == true);

    string password;
    cout << "Enter the password: ";
    cin>>password;
    user.setPassword(password);
    return user;
}

int UserManager::setNewUserID()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExist(string login)
{
    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin()==login)
        {
            cout<<endl<<"There is a user with this login!"<<endl;
            return true;
        }
    }
    return false;
}

void UserManager::showAllUsers()
{
       for (int i=0; i<users.size(); i++)
    {
        {
            cout<<users[i].getId()<<endl;
            cout<<users[i].getLogin()<<endl;
            cout<<users[i].getPassword()<<endl;
        }
    }
}

void UserManager::loginUser()
{
    User user;
    string login="", password = "";

    cout << endl << "Enter login: ";
    login=AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin()==login)
        {
            for (int numberOfTests = 3; numberOfTests > 0; numberOfTests--)
            {
                cout << "Enter the password. You have: " << numberOfTests << " tries: ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword()==password)
                {
                    logedUserID=itr -> getId();
                    cout << endl << "You have logged in." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Incorrect password entered 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with this login." << endl << endl;
    system("pause");
    return;
}

void UserManager::changingPasswordOfTheLoggedUser()
{
    string newPassword = "";
    cout << "Podaj nowe password: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == logedUserID)
        {
            itr -> setPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    userFile.saveUsersToFile(users);
}

void UserManager::logoutUser()
{
    logedUserID=0;
}

bool UserManager::isTheUserLogedIn()
{
    if(logedUserID>0)
        return true;
    else
        return false;
}

int UserManager::getLogedUserID()
{
    return logedUserID;
}
