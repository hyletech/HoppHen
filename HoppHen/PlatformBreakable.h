#pragma once
#include <qpainter.h>
#include "defines.h"
#include "Platform.h"

class PlatformBreakable : public Platform
{
	public:
	
		PlatformBreakable(int xPos, int Ypos);
		void update(Player* player);
		~PlatformBreakable(){}
};