#pragma once

#include <string>

class NPC
{
protected:
	std::string name;
	bool isFriendly;

public:
	NPC();
	virtual ~NPC();

	virtual void render() = 0;
};

