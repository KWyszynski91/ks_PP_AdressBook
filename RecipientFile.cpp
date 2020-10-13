#include "RecipientFile.h"

bool RecipientFile::addRecipientToFile(Recipient recipient)
{
    string recipientDataLine = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::out | ios::app);

    if (textFile.good() == true)
    {
        recipientDataLine = replaceRecipientDataToLineSeparatedVerticalDashes(recipient);

        if (TextFile::isTheFileEmpty() == true)
        {
            textFile << recipientDataLine;
        }
        else
        {
            textFile << endl << recipientDataLine ;
        }
        lastRecipientID++;
        textFile.close();
        return true;
    }
    return false;
}

string RecipientFile::replaceRecipientDataToLineSeparatedVerticalDashes(Recipient recipient)
{
    string recipientDataLine = "";

    recipientDataLine += AuxiliaryMethods::intToStringConversion(recipient.getId()) + '|';
    recipientDataLine += AuxiliaryMethods::intToStringConversion(recipient.getUserId()) + '|';
    recipientDataLine += recipient.getName() + '|';
    recipientDataLine += recipient.getSurname() + '|';
    recipientDataLine += recipient.getPhoneNumber() + '|';
    recipientDataLine += recipient.getEmailAdres() + '|';
    recipientDataLine += recipient.getPostalAdres() + '|';

    return recipientDataLine;
}

string RecipientFile::getNumber(string text, int signPosition)
{
    string number = "";
    while(isdigit(text[signPosition]) == true)
    {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}

int RecipientFile::getUserIdFromDataSeparatedVerticalLines(string singleRecipientDataSeparatedVerticalDashes)
{
    int startPositionUserID = singleRecipientDataSeparatedVerticalDashes.find_first_of('|') + 1;
    int userID = AuxiliaryMethods::stringToIntConversion(getNumber(singleRecipientDataSeparatedVerticalDashes, startPositionUserID));

    return userID;
}

vector <Recipient> RecipientFile::loadLoggedUserRecipientsFromFile(int loggedUserID)
{
    vector <Recipient> recipients;
    Recipient recipient;
    string singleRecipientDataSeparatedVerticalDashes = "";
    string lastRecipientFileData = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, singleRecipientDataSeparatedVerticalDashes))
        {
            if(loggedUserID == getUserIdFromDataSeparatedVerticalLines(singleRecipientDataSeparatedVerticalDashes))
            {
                recipient = getRecipientData(singleRecipientDataSeparatedVerticalDashes);
                recipients.push_back(recipient);
            }
        }
        lastRecipientFileData = singleRecipientDataSeparatedVerticalDashes;
        textFile.close();
    }
    if(lastRecipientFileData !="")
    {
        lastRecipientID=getRecipientIdFromDataSeparatedVerticalLines(lastRecipientFileData);
    }
        return recipients;
}

Recipient RecipientFile::getRecipientData(string recipientDataSeparatedVerticalDashes)
{
    Recipient recipient;
    string singleRecipientData = "";
    int numberOfSingleRecipientData = 1;

    for (int signPosition = 0; signPosition < recipientDataSeparatedVerticalDashes.length(); signPosition++)
    {
        if (recipientDataSeparatedVerticalDashes[signPosition] != '|')
        {
            singleRecipientData += recipientDataSeparatedVerticalDashes[signPosition];
        }
        else
        {
            switch(numberOfSingleRecipientData)
            {
            case 1:
                recipient.setId(atoi(singleRecipientData.c_str()));
                break;
            case 2:
                recipient.setUserId(atoi(singleRecipientData.c_str()));
                break;
            case 3:
                recipient.setName(singleRecipientData);
                break;
            case 4:
                recipient.setSurname(singleRecipientData);
                break;
            case 5:
                recipient.setPhoneNumber(singleRecipientData);
                break;
            case 6:
                recipient.setEmailAdres(singleRecipientData);
                break;
            case 7:
                recipient.setPostalAdres(singleRecipientData);
                break;
            }
            singleRecipientData = "";
            numberOfSingleRecipientData++;
        }
    }
    return recipient;
}

int RecipientFile::getRecipientIdFromDataSeparatedVerticalLines(string singleRecipientDataSeparatedVerticalDashes)
{
    int startPositionRecipientID = 0;
    int recipientID = AuxiliaryMethods::stringToIntConversion(getNumber(singleRecipientDataSeparatedVerticalDashes, startPositionRecipientID));
    return recipientID;
}

int RecipientFile::getLastRecipientID()
{
    return lastRecipientID;
}

int RecipientFile::getLastRecipientIDFromFile()
{
    int lastRecipientID = 0;
    string singleRecipientDataSeparatedVerticalDashes = "";
    string lastRecipientDataInFile = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, singleRecipientDataSeparatedVerticalDashes)) {}
            lastRecipientDataInFile = singleRecipientDataSeparatedVerticalDashes;
            textFile.close();
    }
    else
        cout << "Nie uda\210o si\251 otworzy\206 pliku i wczyta\206 danych." << endl;

    if (lastRecipientDataInFile != "")
    {
        lastRecipientID = getRecipientIdFromDataSeparatedVerticalLines(lastRecipientDataInFile);
    }
    return lastRecipientID;
}

int RecipientFile::getLastRecipientIDAfterRemovedChosenRecipient(int removedRecipientID)
{
    if (removedRecipientID == lastRecipientID)
        return getLastRecipientIDFromFile();
    else
        return lastRecipientID;
}

int RecipientFile::getLineNumberOfSearchingRecipient(int removedRecipientID)
{
    bool thisAddressExist = false;
    int lineNumberInTextFile = 1;
    string singleRecipientDataSeparatedVerticalDashes = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true && removedRecipientID != 0)
    {
        while(getline(textFile, singleRecipientDataSeparatedVerticalDashes))
        {
            if(removedRecipientID == getRecipientIdFromDataSeparatedVerticalLines(singleRecipientDataSeparatedVerticalDashes))
            {
                thisAddressExist = true;
                textFile.close();
                return lineNumberInTextFile;
            }
            else
                lineNumberInTextFile++;
        }
        if (thisAddressExist = false)
        {
            textFile.close();
            return 0;
        }
    }
    return 0;
}

void RecipientFile::removeFile(string fileNameWithExtension)
{
    if (remove(fileNameWithExtension.c_str()) == 0) {}
    else
        cout << "Failed to delete file." << fileNameWithExtension << endl;
}

void RecipientFile::changeFileName(string formerName, string newName)
{
    if (rename(formerName.c_str(), newName.c_str()) == 0) {}
    else
        cout << "Failed to delete file." << formerName << endl;
}

void RecipientFile::removeLineInFile(int removedLineNumber)
{
    fstream loadedTextFile, temporaryTextFile;
    string loadedLine = "";
    int loadLineNumber=1;

    loadedTextFile.open(getFileName().c_str(), ios::in);
    temporaryTextFile.open(TEMPORARY_RECIPIENT_FILE_NAME.c_str(), ios::out | ios::app);

    if (loadedTextFile.good() == true && removedLineNumber != 0)
    {
        while (getline(loadedTextFile, loadedLine))
        {
            // Tych przypadkow jest tyle, gdyz chcemy osiagnac taki efekt,
            // aby na koncu pliku nie bylo pustej linii
            if (loadLineNumber == removedLineNumber) {}
            else if (loadLineNumber == 1 && loadLineNumber != removedLineNumber)
                temporaryTextFile << loadedLine;
            else if (loadLineNumber == 2 && removedLineNumber == 1)
                temporaryTextFile << loadedLine;
            else if (loadLineNumber > 2 && removedLineNumber == 1)
                temporaryTextFile << endl << loadedLine;
            else if (loadLineNumber > 1 && removedLineNumber != 1)
                temporaryTextFile << endl << loadedLine;
            loadLineNumber++;
        }
        loadedTextFile.close();
        temporaryTextFile.close();

        removeFile(getFileName());
        changeFileName(TEMPORARY_RECIPIENT_FILE_NAME, getFileName());
    }
}

int RecipientFile::removedChosenRecipientFromFile(int removedRecipientID)
{
    int removedRecipientLineNumber;
    removedRecipientLineNumber=getLineNumberOfSearchingRecipient(removedRecipientID);
    removeLineInFile(removedRecipientLineNumber);
    lastRecipientID=getLastRecipientIDAfterRemovedChosenRecipient(removedRecipientID);
}

void RecipientFile::editLineInFile(int editLineNumber, string lineWithRecipientDataSeparatedVerticalDashes)
{
    fstream loadedTextFile, temporaryTextFile;
    string loadedLine = "";
    int loadLineNumber = 1;

    loadedTextFile.open(getFileName().c_str(), ios::in);
    temporaryTextFile.open(TEMPORARY_RECIPIENT_FILE_NAME.c_str(), ios::out | ios::app);

    if (loadedTextFile.good() == true)
    {
        while (getline(loadedTextFile, loadedLine))
        {
            if (loadLineNumber == editLineNumber)
            {
                if (loadLineNumber == 1)
                    temporaryTextFile << lineWithRecipientDataSeparatedVerticalDashes;
                else if (loadLineNumber > 1)
                    temporaryTextFile << endl << lineWithRecipientDataSeparatedVerticalDashes;
            }
            else
            {
                if (loadLineNumber == 1)
                    temporaryTextFile << loadedLine;
                else if (loadLineNumber > 1)
                    temporaryTextFile << endl << loadedLine;
            }
            loadLineNumber++;
        }
        loadedTextFile.close();
        temporaryTextFile.close();

        removeFile(getFileName());
        changeFileName(TEMPORARY_RECIPIENT_FILE_NAME, getFileName());
    }
}

void RecipientFile::updateChosenRecipientData(Recipient recipient, int editRecipientID)
{
    vector <Recipient> recipients;
    int editLineNumber = 0;
    string recipientDataLine = "";

    editLineNumber = getLineNumberOfSearchingRecipient(editRecipientID);
    recipientDataLine = replaceRecipientDataToLineSeparatedVerticalDashes(recipient);
    editLineInFile(editLineNumber, recipientDataLine);

    cout << endl << "Recipient data has been updated." << endl << endl;
}
