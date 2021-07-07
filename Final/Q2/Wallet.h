#ifndef WALLET_H
#define WALLET_H

#include "GenericCard.h"
#include "CreditCard.h"
#include "DebitCard.h"

const int MAX_NCARDS = 10;
class Wallet
{
    private:
        GenericCard *cards[MAX_NCARDS];
        int ncards;
    public:
        Wallet();
        Wallet(const Wallet & objToCopy);
        Wallet & operator = (const Wallet & objToCopy);
        ~Wallet();
        void addCard(const GenericCard & card);
        void print() const;
        void summary() const;
};

#endif
