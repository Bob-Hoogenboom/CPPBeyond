#pragma once

#include "Decorator.h"

class FarmerDecorator : public Decorator
{
public:
	FarmerDecorator(NPC* npc);
	virtual ~FarmerDecorator();

	void render();
};

