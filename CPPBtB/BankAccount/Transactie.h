#pragma once

#include <string> 

class Transactie
{
	public:
		Transactie(float value, std::string location);

		float getValue() const;

		const std::string& getLocation() const;

	private:
		float value;
		std::string location;
};

