#pragma once

#include <iostream>
#include "NPC.h"

class Elf : public NPC 
{
public:
	Elf(std::string n, bool f);
	virtual ~Elf();

	void render();
};

