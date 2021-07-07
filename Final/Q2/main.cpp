#include <iostream>
#include "GenericCard.h"
#include "DebitCard.h"
#include "CreditCard.h"
#include "Wallet.h"

int main() {
	DebitCard DC1("BoA", 1234, "1/1/2022", "Carlos Rincon");
	DC1.setaccountType("Checking");
	DC1.setremainingBalance(8500);
	DebitCard DC2("Wells Fargo", 1235, "1/1/2022", "Carlos Rincon");
	DC2.setaccountType("Savings");
	DC2.setremainingBalance(5000);
	CreditCard CC1("BoA", 1236, "1/1/2022", "Carlos Rincon");
	CC1.setcreditLimit(10000);
	CC1.setbalance(1500);
	CreditCard CC2("Chase", 1237, "1/1/2022", "Carlos Rincon");
	CC2.setcreditLimit(7500);
	CC2.setbalance(3500);
	Wallet myWallet;
	myWallet.addCard(CC1);
	myWallet.addCard(DC1);
	myWallet.addCard(CC2);
	myWallet.print();
	myWallet.summary();
}
