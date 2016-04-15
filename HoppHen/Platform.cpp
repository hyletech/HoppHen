#include "Platform.h"

Platform::Platform(int xPos, int yPos)
{
	platformRect = new QRect(xPos, yPos, PF_WIDTH, PF_HEIGHT);
	platformTexture = new QPixmap("pizzahut.png"); //Lägg till bild här
	moving = 0;
}

void Platform::Update(Player* player)
{
	QPoint pointLeft(player->getRect()->bottomLeft());	// Punkt i nedre vänsterkanten på player
	QPoint pointRight(player->getRect()->bottomRight());	// Punkt i nedre högerkanten på player

#if MOVE_WORLD 1 //se i defines.h
	if (pointLeft.y() <= 400 || pointRight.y() <= 400)
		moving = 1;
	if (moving)
	{
		platformRect->moveBottom(platformRect->bottom() + _yvel);
		moving = 0;
	}
#endif

	if (platformRect->contains(pointLeft) || platformRect->contains(pointRight))
	{
		player->getRect()->moveBottom(player->getRect()->bottom() + player->getyvel());
		if (player->getyvel() >= 0)
			player->setyvel(player->getyvel() * 1.05);
		if ((player->getRect()->bottom() > platformRect->top()) && (player->getyvel() >= 0))
		{
			player->getRect()->setBottom(player->getRect()->bottom());
			player->setyvel(-15);
		}
		if (player->getyvel() <= 0)
			player->setyvel(player->getyvel() * 0.95);
		if (player->getyvel() > -0.5 && player->getyvel() < 0)
			player->setyvel(1);
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

//Sätter vänstra-top-hörnet till x & y
void Platform::setPosition(int x, int y)
{
	platformRect->moveLeft(x);
	platformRect->moveTop(y);
}

void Platform::startMoving()
{
	_yvel = 2;
}