#ifndef DEBITCARD_H
#define DEBITCARD_H

#include "GenericCard.h"
#include <string>

class DebitCard : public GenericCard // Implement inheritance (from GenericCard) and use the virtual qualifier when needed.
{
    private:
        std::string accountType;
        double remainingBalance;
    public:
        DebitCard(const std::string & _bankName, unsigned long int _number, const std::string & _expDate, const std::string & _nameOnCard);
        void setaccountType(const std::string & _accountType);
        void setremainingBalance(double value);
        int gettype() const;
        void print() const;
};

#endif
