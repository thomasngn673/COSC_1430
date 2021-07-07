#include "CreditCard.h"
#include <iostream>
#include <iomanip>

CreditCard::CreditCard(const std::string & _bankName, unsigned long int _number, const std::string & _expDate, const std::string & _nameOnCard) : GenericCard (_bankName,_number,_expDate,_nameOnCard)
{
    balance = 0;
    creditLimit = 0;
}

void CreditCard::setcreditLimit(double value)
{
    creditLimit = value;
}
void CreditCard::setbalance(double value)
{
    if (creditLimit >= value)
        balance = value;
}
int CreditCard::gettype() const
{
    return 1;
}
void CreditCard::print() const
{
    this->GenericCard::print();
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Balance: " << balance << ", Credit Limit: " << creditLimit << ", Utilization: " << balance * 100 / creditLimit <<std::endl;
}
