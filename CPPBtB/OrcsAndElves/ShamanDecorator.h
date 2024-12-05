#pragma once

#include "Decorator.h"

class ShamanDecorator : public Decorator
{
public:
	ShamanDecorator(NPC* npc);
	virtual ~ShamanDecorator();

	void render();
};

