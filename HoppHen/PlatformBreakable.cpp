#include "PlatformBreakable.h"


PlatformBreakable::PlatformBreakable(int xPos, int yPos, Platform *platform): Platform(xPos, yPos)
{
	_platform = platform;
}

void PlatformBreakable::paint(QPainter& painter)
{
	

}







void PlatformBreakable::disappearEffect()
{
	//l�gga till n�got i stil med: if( brytbar platform = hit)
	//                                 delete just  den platformen vid n�sta uppdate
}

