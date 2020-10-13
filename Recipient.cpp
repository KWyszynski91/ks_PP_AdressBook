#include "Recipient.h"

void Recipient::setId(int newId)
{
    id=newId;
}

void Recipient::setUserId(int newUserId)
{
    userId=newUserId;
}

void Recipient::setName(string newName)
{
    name=newName;
}

void Recipient::setSurname(string NewSurname)
{
    surname=NewSurname;
}

void Recipient::setPhoneNumber(string NewPhoneNumber)
{
    phoneNumber=NewPhoneNumber;
}

void Recipient::setEmailAdres(string NewEmailAdres)
{
    emailAdres=NewEmailAdres;
}

void Recipient::setPostalAdres(string NewPostalAdres)
{
    postalAdres=NewPostalAdres;
}

int Recipient::getId()
{
    return id;
}

int Recipient::getUserId()
{
    return userId;
}

string Recipient::getName()
{
    return name;
}

string Recipient::getSurname()
{
    return surname;
}

string Recipient::getPhoneNumber()
{
    return phoneNumber;
}

string Recipient::getEmailAdres()
{
    return emailAdres;
}

string Recipient::getPostalAdres()
{
    return postalAdres;
}
