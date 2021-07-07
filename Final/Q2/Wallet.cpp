#include <iostream>
#include "Wallet.h"
#include "DebitCard.h"
#include "CreditCard.h"

Wallet::Wallet()
{
    ncards = 0;
    for (int i = 0; i < MAX_NCARDS; i++)
        cards[i] = nullptr;
}

Wallet::Wallet(const Wallet &objToCopy)
{
    ncards = objToCopy.ncards;
    for (int i = 0; i < MAX_NCARDS; i++)
    {
        if (objToCopy.cards[i] != nullptr)
        {
            if (objToCopy.cards[i]->gettype() == 0)
                cards[i] = new DebitCard((DebitCard &)*objToCopy.cards[i]);
            else
                cards[i] = new CreditCard((CreditCard &)*objToCopy.cards[i]);
        }
        else
            cards[i] = nullptr;
    }
}

Wallet &Wallet::operator=(const Wallet &objToCopy)
{
    if (this != &objToCopy)
    {
        ncards = objToCopy.ncards;
        for (int i = 0; i < MAX_NCARDS; i++)
        {
            if (objToCopy.cards[i] != nullptr)
            {
                if (objToCopy.cards[i]->gettype() == 0)
                {
                    cards[i] = new DebitCard((DebitCard &)*objToCopy.cards[i]);
                }
                else
                {
                    cards[i] = new CreditCard((CreditCard &)*objToCopy.cards[i]);
                }
            }
            else
                cards[i] = nullptr;
        }
    }
    return *this;
}

Wallet::~Wallet()
{
    for (int i = 0; i < ncards; i++)
        if (cards[i]!= nullptr)
	{
		delete cards[i];
    		cards[i] = nullptr;
	}
}

// Write the implementation of the addCard member function here.
void Wallet::addCard(const GenericCard &card)
{
	if (ncards < MAX_NCARDS)
	{
		if (card.gettype() == 0)
			cards[ncards] = new DebitCard((DebitCard &)(card));
		if (card.gettype() == 1)
			cards[ncards] = new CreditCard((CreditCard &)(card));
		ncards = ncards + 1;
	}
}

// Write the implementation of the print member function here
void Wallet::print() const
{
	for(int i = 0; i < ncards; i++)
	{
		cards[i]->print();
	}
}

// Write the implementation of the summary member function here
void Wallet::summary() const
{
	int Dnum=0, Cnum=0;
	for(int i = 0; i < ncards; i++)
	{
		if (cards[i]->gettype() == 0)
			Dnum = Dnum + 1;
		if (cards[i]->gettype() == 1)
			Cnum = Cnum + 1;
	}
	std::cout << "Number of debit cards: " << Dnum << std::endl;
	std::cout << "Number of credit cards: " << Cnum << std::endl;
}
