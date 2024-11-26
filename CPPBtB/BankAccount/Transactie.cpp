#include "Transactie.h"

Transactie::Transactie(float value, std::string location)
{
	this->value = value;
	this->location = location;
}

float Transactie::getValue() const
{
	return value;
}

const std::string& Transactie::getLocation() const
{
	return location;
}
