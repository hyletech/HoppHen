#include "Platform.h"

Platform::Platform(int xPos, int yPos)
{
	platformRect = new QRect(xPos, yPos, PF_WIDTH, PF_HEIGHT);
	//platformTexture = new QPixmap() //Lägg till bild här
}

void Platform::Update()
{
}

void Platform::paint(QPainter& painter) const
{
	painter.drawPixmap(platformRect->x(), platformRect->y(), P_WIDTH, P_HEIGHT, *platformTexture);
}

//Sätter vänstra-top-hörnet till x & y
void Platform::setPosition(int x, int y)
{
	platformRect->moveLeft(x);
	platformRect->moveTop(y);
}
