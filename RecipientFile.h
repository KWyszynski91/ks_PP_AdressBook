#ifndef RECIPIENTFILE_H
#define RECIPIENTFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "AuxiliaryMethods.h"
#include "Recipient.h"
#include "TextFile.h"

using namespace std;

class RecipientFile: public TextFile
{
    const string fileName;
    const string TEMPORARY_RECIPIENT_FILE_NAME = "Recipient_temporaryfile.txt";
    int lastRecipientID;
    int removedRecipientID;
    int editRecipientID;

    string replaceRecipientDataToLineSeparatedVerticalDashes(Recipient recipient);
    string getNumber(string text, int signPosition);
    Recipient getRecipientData(string recipientDataSeparatedVerticalDashes);
    int getRecipientIdFromDataSeparatedVerticalLines(string singleRecipientDataSeparatedVerticalDashes);
    int getUserIdFromDataSeparatedVerticalLines(string singleRecipientDataSeparatedVerticalDashes);

    int getLineNumberOfSearchingRecipient(int removedRecipientID);
    void removeLineInFile(int removedLineNumber);
    void removeFile(string fileNameWithExtension);
    void changeFileName(string formerName, string newName);
    void editLineInFile(int editLineNumber, string lineWithRecipientDataSeparatedVerticalDashes);
    int getLastRecipientIDFromFile();

public:
    RecipientFile(string fileName) : TextFile(fileName) {
    lastRecipientID=0;
    };

    bool addRecipientToFile(Recipient recipient);
    vector <Recipient> loadLoggedUserRecipientsFromFile(int loggedUserID);
    int getLastRecipientID();
    int getLastRecipientIDAfterRemovedChosenRecipient(int removedRecipientID);
    int removedChosenRecipientFromFile(int removedRecipientID);
    void updateChosenRecipientData(Recipient recipient, int editRecipientID);
};

#endif
