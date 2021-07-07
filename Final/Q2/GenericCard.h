#ifndef GENERICCARD_H
#define GENERICCARD_H

#include <string>

class GenericCard   // Use the virtual qualifier when needed
{
    private:
        std::string bankName;
        unsigned long int number;
        std::string nameOnCard;
        std::string expDate;
        int type;       // 0 Debit, 1 Credit
    public:
        GenericCard(const std::string & _bankName, unsigned long int _number, const std::string & _expDate, const std::string & _nameOnCard);
        virtual int gettype() const = 0;
        virtual void print() const;
        ~GenericCard(){};
};

#endif
