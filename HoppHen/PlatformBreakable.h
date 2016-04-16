#pragma once
#include <qpainter.h>
#include "defines.h"
#include "Platform.h"

class PlatformBreakable : public Platform
{
	public:
	
		PlatformBreakable(int xPos, int Ypos, Platform *platform);
		~PlatformBreakable(){}

		void paint(QPainter & painter);
		void disappearEffect();

private:
		Platform* _platform;
};