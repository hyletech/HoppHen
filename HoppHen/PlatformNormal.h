#pragma once
#include "Platform.h"

class PlatformNormal : public Platform
{
public:
	PlatformNormal(int xPos, int Ypos);
	void update(Player* player);
	~PlatformNormal(){};
};

