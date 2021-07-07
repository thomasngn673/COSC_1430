#include "DebitCard.h"
#include <iostream>
#include <iomanip>

DebitCard::DebitCard(const std::string & _bankName, unsigned long int _number, const std::string & _expDate, const std::string & _nameOnCard) : GenericCard (_bankName,_number,_expDate,_nameOnCard)
{
    accountType = "";
    remainingBalance = 0;
}

void DebitCard::setaccountType(const std::string & _accountType)
{
    accountType = _accountType;
}
void DebitCard::setremainingBalance(double value)
{
        remainingBalance = value;
}
int DebitCard::gettype() const
{
    return 0;
}
void DebitCard::print() const
{
    this->GenericCard::print();
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Account type: " << accountType << ", Remaining Balance: " << remainingBalance <<std::endl;
}