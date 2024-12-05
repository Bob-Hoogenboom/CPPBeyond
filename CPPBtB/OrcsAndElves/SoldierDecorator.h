#pragma once

#include "Decorator.h"

class SoldierDecorator : public Decorator
{
public:
	SoldierDecorator(NPC* npc);
	virtual ~SoldierDecorator();

	void render();
};

