#include "Orc.h"

Orc::Orc(std::string n, bool f)
{
	this->name = n;
	this->isFriendly = f;
}

Orc::~Orc()
{

}

void Orc::render()
{
	std::string friendlyText;
	if (this->isFriendly)
	{
		friendlyText = "and I am a Friend!";
	}
	else {
		friendlyText = "and I am a Enemy!";
	}
	std::cout << "Me is Orc '" << this->name << "', " << friendlyText << std::endl;
}
