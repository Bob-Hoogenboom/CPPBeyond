#include <iostream>
#include "ShamanDecorator.h"

ShamanDecorator::ShamanDecorator(NPC* npc) : Decorator(npc) {}

ShamanDecorator::~ShamanDecorator()
{
}

void ShamanDecorator::render() 
{
	Decorator::render();
	std::cout << ">>Shaman Role Assigned<<" << std::endl;
}