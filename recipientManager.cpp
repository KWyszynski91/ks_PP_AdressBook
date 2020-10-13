#include "RecipientManager.h"

void RecipientManager::showRecipientData(Recipient recipient)
{
    cout << endl << "Id:         " << recipient.getId() << endl;
    cout << "Name:               " << recipient.getName() << endl;
    cout << "Surname:            " << recipient.getSurname() << endl;
    cout << "Phone Number:       " << recipient.getPhoneNumber() << endl;
    cout << "Email address:      " << recipient.getEmailAdres() << endl;
    cout << "Postal address:     " << recipient.getPostalAdres() << endl;
}

void RecipientManager::addRecipient()
{
    Recipient recipient;
    system("cls");
    cout << " >>> ADDING A NEW RECIPIENT <<<" << endl << endl;
    recipient = enterDataForNewRecipient();

    recipients.push_back(recipient);
    if(recipientFile.addRecipientToFile(recipient))
        cout<<"New recipient has been added"<<endl;
    else
        cout<<"Error. New recipient could not be added."<<endl;
    system("pause");
}

Recipient RecipientManager::enterDataForNewRecipient()
{
    Recipient recipient;
    string name, surname, phoneNumber, emailAdres, postalAdres;

    recipient.setId(recipientFile.getLastRecipientID()+1);
    recipient.setUserId(LOGGED_USER_ID);

    cout << "Enter the name: ";
    name = AuxiliaryMethods::loadLine();
    name = AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(name);

    cout << "Enter the surname: ";
    surname = AuxiliaryMethods::loadLine();
    surname = AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(surname);

    cout << "Enter the phone number: ";
    phoneNumber = AuxiliaryMethods::loadLine();

    cout << "Enter the e-mail address: ";
    emailAdres = AuxiliaryMethods::loadLine();

    cout << "Enter the postal address: ";
    postalAdres = AuxiliaryMethods::loadLine();

    recipient.setName(name);
    recipient.setSurname(surname);
    recipient.setPhoneNumber(phoneNumber);
    recipient.setEmailAdres(emailAdres);
    recipient.setPostalAdres(postalAdres);

    return recipient;
}

void RecipientManager::showAllRecipients()
{
    system("cls");
    if (!recipients.empty())
    {
        cout << "             >>> RECIPIENTS <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Recipient> :: iterator itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            showRecipientData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "The Address book are empty." << endl << endl;
    }
    system("pause");
}

int RecipientManager::enterIdForSelectedRecipient()
{
    int selectedRecipientID = 0;
    cout << "Enter the recipient ID: ";
    selectedRecipientID  = AuxiliaryMethods::loadInteger();
    return selectedRecipientID;
}

int RecipientManager::removeRecipient()
{
    int removedRecipientID = 0;
    int lineNumberRemovedRecipient = 0;

    system("cls");
    cout << ">>> DELETING SELECTED ADDRESS <<<" << endl << endl;
    removedRecipientID = enterIdForSelectedRecipient();
    char sign;
    bool thisAddressExist = false;

    for (vector <Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
    {
        if (itr ->getId()== removedRecipientID)
        {
            thisAddressExist = true;
            cout<<"The recipient has been found: "<<endl;
            showRecipientData(*itr);
            cout<<"---------------------------"<<endl;
            cout << endl << "Are you sure, you want delete this recipient? Press 'y': ";
            sign = AuxiliaryMethods::loadSign();
            if (sign == 'y')
            {
                lineNumberRemovedRecipient = recipientFile.removedChosenRecipientFromFile(removedRecipientID);
                recipients.erase(itr);
                cout << endl << endl << "Recipient has been REMOVED" << endl << endl;
                system("pause");
                return removedRecipientID;
            }
            else
            {
                cout << endl << endl << "Recipient has not been removed"<< endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (thisAddressExist == false)
    {
        cout << endl << "Addressee not found" << endl << endl;
        system("pause");
    }
    return 0;
}

char RecipientManager::chooseOptionFromEditMenu()
{
    char choose;
    cout << endl << "   >>> EDIT MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Which data you want to update: " << endl;
    cout << "1 - Name" << endl;
    cout << "2 - Surname" << endl;
    cout << "3 - Phone number" << endl;
    cout << "4 - Email addressee" << endl;
    cout << "5 - Postal addressee" << endl;
    cout << "6 - RETURN " << endl;
    cout << endl << "Your choose: ";
    choose = AuxiliaryMethods::loadSign();
    return choose;
}

void RecipientManager::editRecipient()
{
    system("cls");
    Recipient adresat;
    int EditRecipientID = 0;
    string name, surname, phoneNumber, emailAdres, postalAdres;

    cout << ">>> EDITING SELECTED ADDRESS <<<" << endl << endl;
    EditRecipientID = enterIdForSelectedRecipient();

    char choose;
    bool thisAddressExist = false;

    for (int i = 0; i < recipients.size(); i++)
    {
        if (recipients[i].getId() == EditRecipientID)
        {
            thisAddressExist = true;
            cout<<"The recipient has been found: "<<endl;
            showRecipientData(recipients[i]);
            cout<<"---------------------------"<<endl;
            choose = chooseOptionFromEditMenu();
            switch (choose)
            {
            case '1':
                cout << "Enter new name: ";
                name = AuxiliaryMethods::loadLine();
                name = AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(name);
                recipients[i].setName(name);
                recipientFile.updateChosenRecipientData(recipients[i], EditRecipientID);
                break;
            case '2':
                cout << "Enter new surname: ";
                surname = AuxiliaryMethods::loadLine();
                surname = AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(surname);
                recipients[i].setSurname(surname);
                recipientFile.updateChosenRecipientData(recipients[i], EditRecipientID);
                break;
            case '3':
                cout << "Enter new phone number: ";
                phoneNumber = AuxiliaryMethods::loadLine();
                phoneNumber = AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(phoneNumber);
                recipients[i].setPhoneNumber(phoneNumber);
                recipientFile.updateChosenRecipientData(recipients[i], EditRecipientID);
                break;
            case '4':
                cout << "Enter new e-mail address: ";
                emailAdres = AuxiliaryMethods::loadLine();
                emailAdres = AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(emailAdres);
                recipients[i].setEmailAdres(emailAdres);
                recipientFile.updateChosenRecipientData(recipients[i], EditRecipientID);
                break;
            case '5':
                cout << "Enter new postal address: ";
                postalAdres = AuxiliaryMethods::loadLine();
                postalAdres = AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(postalAdres);
                recipients[i].setPostalAdres(postalAdres);
                recipientFile.updateChosenRecipientData(recipients[i], EditRecipientID);
                break;
            case '6':
                cout << endl << "Return to main menu" << endl << endl;
                break;
            default:
                cout << endl << "No option in menu! Returned to main menu." << endl << endl;
                break;
            }
        }
    }
    if (thisAddressExist == false)
    {
        cout << endl << "Recipient not exist." << endl << endl;
    }
    system("pause");
}

void RecipientManager::showNumberOfSearchingRecipients(int numbOfRecipients)
{
    if (numbOfRecipients == 0)
        cout << endl << "Specified recipients were not found in the Address Book." << endl;
    else
        cout << endl << "Number of recipients found: " << numbOfRecipients << endl << endl;
}

void RecipientManager::searchRecipientsByName()
{
    string SearchingRecipientName = "";
    int numbOfRecipients = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> SEARCHING RECIPIENTS BY NAME <<<" << endl << endl;

        cout << "Enter the recipient name you are looking for: ";
        SearchingRecipientName = AuxiliaryMethods::loadLine();
        SearchingRecipientName = AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(SearchingRecipientName);

        for (vector <Recipient>::iterator  itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr -> getName()==SearchingRecipientName)
            {
                showRecipientData(*itr);
                numbOfRecipients++;
            }
        }
        showNumberOfSearchingRecipients(numbOfRecipients);
    }
    else
    {
        cout << endl << "The Address Book are empty!" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void RecipientManager::searchRecipientsBySurname()
{
    string SearchingRecipientSurname;
    int numbOfRecipients = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> SEARCHING RECIPIENTS BY SURNAME <<<" << endl << endl;

        cout << "Enter the recipient surname you are looking for: ";
        SearchingRecipientSurname = AuxiliaryMethods::loadLine();
        SearchingRecipientSurname = AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(SearchingRecipientSurname);

        for (vector <Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr -> getSurname() == SearchingRecipientSurname)
            {
                showRecipientData(*itr);
                numbOfRecipients++;
            }
        }
         showNumberOfSearchingRecipients(numbOfRecipients);
    }
    else
    {
        cout << endl << "The Address Book are empty!" << endl << endl;
    }
    cout << endl;
    system("pause");
}
