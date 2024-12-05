#include "Elf.h"

Elf::Elf(std::string n, bool f)
{
	this->name = n;
	this->isFriendly = f;
}

Elf::~Elf()
{
}

void Elf::render()
{
	std::string friendlyText;
	if (this->isFriendly)
	{
		friendlyText = "and I am a Friend!";
	}
	else {
		friendlyText = "and I am a Enemy!";
	}

	std::cout << "I am Elf '" << this->name << "', " << friendlyText << std::endl;
}
