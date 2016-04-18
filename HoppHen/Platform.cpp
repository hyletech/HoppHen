#include "Platform.h"

Platform::Platform(int xPos, int yPos)
{
	platformRect = new QRect(xPos, yPos, PF_WIDTH, PF_HEIGHT);
	platformTexture = new QPixmap("pizzahut.png"); //Lägg till bild här
}

void Platform::update(Player* player)
{
#if MOVE_WORLD 1 //se i defines.h
		platformRect->moveBottom(platformRect->bottom() + _yvel);
#endif

	//Om player/platform-kollision
	if (platformRect->contains(player->getRect()->bottomLeft()) || platformRect->contains(player->getRect()->bottomRight()))
	{
		//Onödig rad?
		//player->getRect()->moveBottom(_player->getRect()->bottom() + _player->getyvel()); 

		//också onödig rad?
		//Om kommer från undersidan
		//if (player->getyvel() >= 0)
		//	player->setyvel(_player->getyvel() * 1.05);

		//Om kommer ovanpå med pos yVel (nedåt)
		if ((player->getRect()->bottom() > platformRect->top()) && (player->getyvel() >= 0))
			player->setyvel(-15);

		//vad gör denna?
		//if (player->getyvel() > -0.5 && _player->getyvel() < 0) 
		//	player->setyvel(1);
	}
}

void Platform::paint(QPainter& painter) const
{
	painter.drawPixmap(platformRect->x(), platformRect->y(), *platformTexture);
	//QBrush br;
	//br.setColor(Qt::blue);
	//painter.setBrush(br);
	//painter.drawRect(platformRect->x(), platformRect->y(), PF_WIDTH, PF_HEIGHT);
}


