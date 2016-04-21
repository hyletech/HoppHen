#include "PlatformBreakable.h"


PlatformBreakable::PlatformBreakable(int xPos, int yPos): Platform(xPos, yPos)
{
	platformTexture = new QPixmap("pizzahutBreak.png");
}

void PlatformBreakable::update(Player* player)
{
	if (!player->getEnemyHit())
	{
		//Om player/platform-kollision
		if (platformRect->contains(player->getRect()->bottomLeft()) || platformRect->contains(player->getRect()->bottomRight()))
		{
			//Om kommer ovanp� med pos yVel (ned�t)
			if ((player->getRect()->bottom() > platformRect->top()) && (player->getyvel() >= 0))
			{
				player->setyvel(-15);
				platformRect->moveLeft(1500);
			}
		}
	}
}


