#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"
#include "RecipientManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
    RecipientManager *recipientManager;
    const string RECIPIENT_FILE_NAME;

public:
    AddressBook(string userFileName, string recipientFileName)
    : userManager(userFileName), RECIPIENT_FILE_NAME(recipientFileName)
    {
        recipientManager=NULL;
    };
    ~AddressBook() //DESTRUKTOR
    {
        delete recipientManager;
        recipientManager=NULL;
    }
    void userRegistration();
    void showAllUsers();
    void loginUser();
    void changingPasswordOfTheLoggedUser();
    int getLogedUserID();
    void logoutUser();
    void addRecipient();
    void removeRecipient();
    void editRecipient();
    void searchRecipientsByName();
    void searchRecipientsBySurname();
    void showAllRecipients();
    char selectOptionsFromTheMainMenu();
    char selectOptionsFromTheUserMenu();
    bool isTheUserLogedIn();
};

#endif
