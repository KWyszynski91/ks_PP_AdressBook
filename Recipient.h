#ifndef RECIPIENT_H
#define RECIPIENT_H

#include <iostream>

using namespace std;

class Recipient
{
    int id;
    int userId;
    string name = "";
    string surname = "";
    string phoneNumber = "";
    string emailAdres = "";
    string postalAdres = "";

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setName(string newName);
    void setSurname(string NewSurname);
    void setPhoneNumber(string NewPhoneNumber);
    void setEmailAdres(string NewEmailAdres);
    void setPostalAdres(string NewPostalAdres);

    int getId();
    int getUserId();
    string getName();
    string getSurname();
    string getPhoneNumber();
    string getEmailAdres();
    string getPostalAdres();
};

#endif
