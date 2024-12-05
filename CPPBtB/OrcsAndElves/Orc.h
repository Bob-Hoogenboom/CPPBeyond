#pragma once

#include <iostream>
#include "NPC.h"

class Orc : public NPC
{
public: 
	Orc(std::string n, bool f);
	virtual ~Orc();

	void render();
};

