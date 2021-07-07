#include "GenericCard.h"
#include <iostream>

GenericCard::GenericCard(const std::string & _bankName, unsigned long int _number, const std::string & _expDate, const std::string & _nameOnCard)
{
    bankName = _bankName;
    number = _number;
    nameOnCard = _nameOnCard;
    expDate = _expDate;
}

void GenericCard::print() const
{
    std::cout << "Bank: " << bankName << ", Card number: " << number
    << ", Name on Card: " << nameOnCard << ", Exp Date: " << expDate << std::endl;
}