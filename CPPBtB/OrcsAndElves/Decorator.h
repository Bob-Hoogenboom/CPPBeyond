#pragma once

#include "NPC.h"

class Decorator : public NPC
{
private:
	NPC* theNPC;
public:
	Decorator(NPC* npc);
	virtual ~Decorator();

	virtual void render();
};

