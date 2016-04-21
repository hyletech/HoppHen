#include "PlatformNormal.h"

PlatformNormal::PlatformNormal(int xPos, int yPos) : Platform(xPos, yPos)
{

}

void PlatformNormal::update(Player* player)
{
	if (!player->getEnemyHit())
	{
		//Om player/platform-kollision
		if (platformRect->contains(player->getRect()->bottomLeft()) || platformRect->contains(player->getRect()->bottomRight()))
		{
			//Om kommer ovanpå med pos yVel (nedåt)
			if ((player->getRect()->bottom() > platformRect->top()) && (player->getyvel() >= 0))
			{
				player->setyvel(-15);
			}
		}
	}
}
