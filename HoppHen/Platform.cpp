#include "Platform.h"

Platform::Platform(int xPos, int yPos)
{
	platformRect = new QRect(xPos, yPos, PF_WIDTH, PF_HEIGHT);
	//platformTexture = new QPixmap() //L�gg till bild h�r
}

void Platform::Update(PlayerManager* playerManager)
{
	QPoint* pointLeft = new QPoint(playerManager->getRect()->x(), playerManager->getRect()->y() + PF_HEIGHT);                 // Punkt i nedre v�nsterkanten p� player
	QPoint* pointRight = new QPoint(playerManager->getRect()->x() + PF_WIDTH, playerManager->getRect()->y() + PF_HEIGHT);     // Punkt i nedre h�gerkanten p� player
	if (platformRect->contains(*pointLeft) || platformRect->contains(*pointRight))
	{
		playerManager->getRect()->moveBottom(playerManager->getRect()->bottom() + playerManager->getyvel());
		if (playerManager->getyvel() >= 0)
			playerManager->setyvel(playerManager->getyvel() * 1.05);
		if ((playerManager->getRect()->bottom() > platformRect->top()) && (playerManager->getyvel() >= 0))
			playerManager->setyvel(-15);
		if (playerManager->getyvel() <= 0)
			playerManager->setyvel(playerManager->getyvel() * 0.95);
		if (playerManager->getyvel() > -0.5 && playerManager->getyvel() < 0)
			playerManager->setyvel(1);
	}
}

void Platform::paint(QPainter& painter) const
{
	//painter.drawPixmap(platformRect->x(), platformRect->y(), P_WIDTH, P_HEIGHT, *platformTexture);
	QBrush br;
	br.setColor(Qt::blue);
	painter.setBrush(br);
	painter.drawRect(platformRect->x(), platformRect->y(), PF_WIDTH, PF_HEIGHT);
}

//S�tter v�nstra-top-h�rnet till x & y
void Platform::setPosition(int x, int y)
{
	platformRect->moveLeft(x);
	platformRect->moveTop(y);
}
