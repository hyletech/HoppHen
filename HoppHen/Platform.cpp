#include "Platform.h"

Platform::Platform(int xPos, int yPos)
{
	platformRect = new QRect(xPos, yPos, PF_WIDTH, PF_HEIGHT);
	platformTexture = new QPixmap("pizzahut.png"); //Lägg till bild här
	moving = 0;
}

void Platform::Update(PlayerManager* playerManager)
{
	QPoint pointLeft(playerManager->getRect()->bottomLeft());	// Punkt i nedre vänsterkanten på player
	QPoint pointRight(playerManager->getRect()->bottomRight());	// Punkt i nedre högerkanten på player

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
		playerManager->getRect()->moveBottom(playerManager->getRect()->bottom() + playerManager->getyvel());
		if (playerManager->getyvel() >= 0)
			playerManager->setyvel(playerManager->getyvel() * 1.05);
		if ((playerManager->getRect()->bottom() > platformRect->top()) && (playerManager->getyvel() >= 0))
		{
			playerManager->getRect()->setBottom(playerManager->getRect()->bottom());
			playerManager->setyvel(-15);
		}
		if (playerManager->getyvel() <= 0)
			playerManager->setyvel(playerManager->getyvel() * 0.95);
		if (playerManager->getyvel() > -0.5 && playerManager->getyvel() < 0)
			playerManager->setyvel(1);
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