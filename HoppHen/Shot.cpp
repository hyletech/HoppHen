#include "Shot.h"
 


Shot::Shot(int xPos, int yPos)
{
	shotTexture = new QPixmap("shot.png"); //Lägg till bild på skott
	shotRect = new QRect(xPos, yPos, S_WIDTH, S_HEIGHT);

}

void Shot::paintEvent(QPaintEvent* e)
{

}

void Shot::update()//Player* player, Enemy* enemy)
{
	shotRect->moveBottom(shotRect->y() + _yVel);
}
	

void Shot::paint(QPainter& painter) const
{
	painter.drawPixmap(shotRect->x(), shotRect->y(), 50,100, *shotTexture);

}

