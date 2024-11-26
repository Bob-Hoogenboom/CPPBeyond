#include <iostream>
#include "BankRekening.h"

int main() 
{
	BankRekening mijnRabo = BankRekening("Bob Hoogenboom", 250.65f);

	Transactie boodschappen = Transactie(-19.99f, "AlbertHeijn");
	Transactie betaalverzoek = Transactie(-23.99f, "Bowlingbaan De Kegel");

	mijnRabo = mijnRabo + boodschappen;
	std::cout << mijnRabo.getName() << " amount: " << mijnRabo.getAmount() <<
		", transacties: " << mijnRabo.getNumberOfTransaction() << std::endl;

	mijnRabo += boodschappen;
	std::cout << mijnRabo.getName()
		<< " amount: " << mijnRabo.getAmount()
		<< " transacties: " << mijnRabo.getNumberOfTransaction()
		<< std::endl;


	return 0;
}