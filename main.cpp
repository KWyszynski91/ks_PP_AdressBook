#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressbook("Users.txt", "Recipients.txt");

    //PlikZAdresatami plikZAdresatami("Adresaci.txt");
    //plikZAdresatami.dopisz("tekst do dopisania");
    //PlikZUzytkownikami plikZUzytkownikami("Uzytkownicy.txt");

    char choise;

    while (true)
    {
        if (addressbook.isTheUserLogedIn()==false)
        {
            choise=addressbook.selectOptionsFromTheMainMenu();
            switch(choise)
                {
                case '1':
                    addressbook.userRegistration(); break;
                case '2':
                    addressbook.loginUser(); break;
                case '9':
                    exit(0); break;
                default:
                    cout<<endl<<"No option in menu." <<endl<<endl;
                system("pause");
                break;
                }
        }
        else
        {
            choise=addressbook.selectOptionsFromTheUserMenu();
            switch(choise)
            {
            case '1':
                addressbook.addRecipient(); break;
            case '2':
                addressbook.searchRecipientsByName(); break;
            case '3':
                addressbook.searchRecipientsBySurname(); break;
            case '4':
                addressbook.showAllRecipients(); break;
            case '5':
                addressbook.removeRecipient(); break;
            case '6':
                addressbook.editRecipient(); break;
            case '7':
                addressbook.changingPasswordOfTheLoggedUser(); break;
            case '9':
                addressbook.logoutUser(); break;
            }
        }
    }
    return 0;
}
