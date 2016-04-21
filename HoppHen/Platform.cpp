#include "Platform.h"

Platform::Platform(int xPos, int yPos)
{
	platformRect = new QRect(xPos, yPos, PF_WIDTH, PF_HEIGHT);
	platformTexture = new QPixmap("pizzahut.png"); //L�gg till bild h�r
}

void Platform::update(Player* player)
{
#if MOVE_WORLD 1 //se i defines.h
		platformRect->moveBottom(platformRect->bottom() + _yvel);
#endif
		if (!player->getEnemyHit())
		{
			//Om player/platform-kollision
			if (platformRect->contains(player->getRect()->bottomLeft()) || platformRect->contains(player->getRect()->bottomRight()))
			{
				//Om kommer ovanp� med pos yVel (ned�t)
				if ((player->getRect()->bottom() > platformRect->top()) && (player->getyvel() >= 0))
					player->setyvel(-15);
			}
		}
}

void Platform::setPos(const int _newY, const int _newX)
{
	platformRect->moveBottom(_newY);
	platformRect->moveLeft(_newX);
}

void Platform::paint(QPainter& painter) const
{
	painter.drawPixmap(platformRect->x(), platformRect->y(), *platformTexture);
	
}


