#include "AddressBook.h"

void AddressBook::userRegistration()
{
    userManager.userRegistration();
}

void AddressBook::showAllUsers()
{
    userManager.showAllUsers();
}

void AddressBook::loginUser()
{
    userManager.loginUser();
    if(userManager.isTheUserLogedIn())
    {
        recipientManager=new RecipientManager(RECIPIENT_FILE_NAME, userManager.getLogedUserID());
    }
}

void AddressBook::changingPasswordOfTheLoggedUser()
{
    userManager.changingPasswordOfTheLoggedUser();
}

bool AddressBook::isTheUserLogedIn()
{
    return userManager.isTheUserLogedIn();
}

int AddressBook::getLogedUserID()
{
    userManager.getLogedUserID();
}

void AddressBook::logoutUser()
{
    userManager.logoutUser();
    delete recipientManager;
    recipientManager=NULL;
}

void AddressBook::addRecipient()
{
    if(userManager.isTheUserLogedIn())
    {
        recipientManager->addRecipient();
    }
    else
    {
        cout<<"If you want to add a recipient, you must log in"<<endl;
        system("pause");
    }
}

void AddressBook::removeRecipient()
{
    if(userManager.isTheUserLogedIn())
    {
        recipientManager->removeRecipient();
    }
    else
    {
        cout<<"If you want to remove a recipient, you must log in"<<endl;
        system("pause");
    }
}

void AddressBook::editRecipient()
{
   if(userManager.isTheUserLogedIn())
    {
        recipientManager->editRecipient();
    }
    else
    {
        cout<<"If you want to edit a recipient, you must log in"<<endl;
        system("pause");
    }
}

void AddressBook::searchRecipientsByName()
{
   if(userManager.isTheUserLogedIn())
    {
        recipientManager->searchRecipientsByName();
    }
    else
    {
        cout<<"If you want to view contacts you have to login"<<endl;
        system("pause");
    }
}

void AddressBook::searchRecipientsBySurname()
{
   if(userManager.isTheUserLogedIn())
    {
        recipientManager->searchRecipientsBySurname();
    }
    else
    {
        cout<<"If you want to view contacts you have to login"<<endl;
        system("pause");
    }
}

void AddressBook::showAllRecipients()
{
       if(userManager.isTheUserLogedIn())
    {
        recipientManager->showAllRecipients();
    }
    else
    {
        cout<<"If you want to view contacts you have to login"<<endl;
        system("pause");
    }
}

char AddressBook::selectOptionsFromTheMainMenu()
{
    char choice;
    system("cls");
    cout<<"+=======================+"<<endl;
    cout<<"|=====ADDRESS BOOK======|" << endl;
    cout<<"|_______main menu_______|" << endl;
    cout<<"| 1. Registration       |"<<endl;
    cout<<"| 2. Login              |"<<endl;
    cout<<"| 9. Quit               |"<<endl;
    cout<<"+=======================+" << endl;
    cin>>choice;
    return choice;
}

char AddressBook::selectOptionsFromTheUserMenu()
{
    char choice;
    system("cls");
    cout<<"+==================================+"<<endl;
    cout<<"|===========ADDRESS BOOK===========|" << endl;
    cout<<"|_____________user menu____________|" << endl;
    cout<<"| 1. Add recipient                 |"<<endl;
    cout<<"| 2. Search by name                |"<<endl;
    cout<<"| 3. Search by surname             |"<<endl;
    cout<<"| 4. Show all recipients           |"<<endl;
    cout<<"| 5. Remove recipient              |"<<endl;
    cout<<"| 6. Edit recipient                |"<<endl;
    cout<<"+==================================+"<<endl;
    cout<<"| 7. Change password               |"<<endl;
    cout<<"| 9. Logout                        |"<<endl;
    cout<<"+==================================+"<<endl;
    cout<<"Your choice: ";
    cin>>choice;
    cout<<"+==================================+"<<endl;
    return choice;
}
