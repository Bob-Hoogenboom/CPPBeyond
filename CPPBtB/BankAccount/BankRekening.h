#pragma once

#include <string>
#include "Transactie.h"

class BankRekening
{
public:
	BankRekening(std::string name, float amount = 0, int numberOfTransactions = 0);
	virtual ~BankRekening();


	const std::string& getName() const;
	const int getNumberOfTransaction() const;
	const float getAmount() const;

	BankRekening operator+ (const Transactie& transactie) const;
	BankRekening operator- (const Transactie& transactie) const;
	BankRekening& operator+= (const Transactie& transactie);

	BankRekening& operator=(const BankRekening&);

private:
	std::string name;
	float amount;
	int numberOfTransactions;
};

