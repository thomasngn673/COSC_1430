#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "GenericCard.h"
#include <string>

class CreditCard : public GenericCard// Implement inheritance (from GenericCard) and use the virtual qualifier when needed.
{
    private:
        double creditLimit;
        double balance;
    public:
        CreditCard(const std::string & _bankName, unsigned long int _number, const std::string & _expDate, const std::string & _nameOnCard);
        void setcreditLimit(double value);
        void setbalance(double value);
        int gettype() const;
        void print() const;
};

#endif
