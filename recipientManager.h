#ifndef RECIPIENTMANAGER_H
#define RECIPIENTMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "recipient.h"
#include "RecipientFile.h"

using namespace std;

class RecipientManager
{
    const int LOGGED_USER_ID;
    vector <Recipient> recipients;
    RecipientFile recipientFile;

    Recipient enterDataForNewRecipient();
    void showRecipientData(Recipient recipient);
    int enterIdForSelectedRecipient();
    int returnLineWithSelectedRecipient(int RecipientId);
    int getRecipientIdFromDataSeparatedVerticalLines(string SingleRecipientDataSeparatedVerticalLines);
    char chooseOptionFromEditMenu();

public:
    RecipientManager(string RecipientFileName, int loggedUserId)
    : recipientFile(RecipientFileName), LOGGED_USER_ID(loggedUserId)
    {
        recipients=recipientFile.loadLoggedUserRecipientsFromFile(LOGGED_USER_ID);
    };
    void addRecipient();
    void showAllRecipients();
    int removeRecipient();
    void editRecipient();
    void showNumberOfSearchingRecipients(int numbOfRecipients);
    void searchRecipientsByName();
    void searchRecipientsBySurname();
};

#endif
