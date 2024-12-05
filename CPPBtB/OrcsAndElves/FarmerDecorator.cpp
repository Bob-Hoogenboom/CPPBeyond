#include <iostream>
#include "FarmerDecorator.h"

FarmerDecorator::FarmerDecorator(NPC* npc) : Decorator(npc) {}

FarmerDecorator::~FarmerDecorator() 
{
}

void FarmerDecorator::render() 
{
	Decorator::render();
	std::cout << ">>Farmer Role Assigned<<" << std::endl;
}