#include <iostream>
#include "SoldierDecorator.h"

SoldierDecorator::SoldierDecorator(NPC* npc) : Decorator(npc) {}

SoldierDecorator::~SoldierDecorator()
{
}

void SoldierDecorator::render() 
{
	Decorator::render();
	std::cout << ">>Soldier Role Assigned<<" << std::endl;
}