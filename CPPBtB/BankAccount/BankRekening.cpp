#include <iostream>
#include "BankRekening.h"

BankRekening::BankRekening(std::string name, float amount, int numberOfTransactions)
{
	std::cout << "Giro: " << name << std::endl;
	this->name = name;
	this->amount = amount;
	this->numberOfTransactions = numberOfTransactions;
}

BankRekening::~BankRekening()
{
	std::cout << "dtor: " << std::endl;
}

//Getters
const std::string& BankRekening::getName() const
{
	return name;
}

const float BankRekening::getAmount() const
{
	return amount;
}

const int BankRekening::getNumberOfTransaction() const
{
	return numberOfTransactions;
}

//operators
BankRekening BankRekening::operator+(const Transactie& transactie) const
{
	return BankRekening(name, amount + transactie.getValue(), numberOfTransactions + 1);
}

BankRekening BankRekening::operator-(const Transactie& transactie) const
{
	return BankRekening(name, amount - transactie.getValue(), numberOfTransactions - 1);
}

BankRekening& BankRekening::operator+=(const Transactie& transactie)
{
	amount += transactie.getValue();
	numberOfTransactions++;
	return *this;
}

BankRekening& BankRekening::operator=(const BankRekening& transactie)
{
	if (this != &transactie)
	{
		std::cout << "Account:" << std::endl;
		this->name = transactie.name;
		this->amount = transactie.amount;
		this->numberOfTransactions = transactie.numberOfTransactions;
	}
	return *this;
}
