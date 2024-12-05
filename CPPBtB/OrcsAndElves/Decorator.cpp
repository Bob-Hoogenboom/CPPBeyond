#include "Decorator.h"

Decorator::Decorator(NPC* npc) 
{
	theNPC = npc;
}

Decorator::~Decorator()
{
	if (theNPC) delete theNPC;
}

void Decorator::render()
{
	theNPC->render();
}