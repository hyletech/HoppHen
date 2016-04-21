#include "Shot.h"
 
Shot::Shot(int xPos, int yPos)
{
	shotTexture = new QPixmap("shot.png"); //Lägg till bild på skott
	shotRect = new QRect(xPos, yPos, S_WIDTH, S_HEIGHT);

}

Shot::~Shot()
{
	delete shotRect;
	delete shotTexture;
}

void Shot::update()//Player* player, Enemy* enemy)
{
	shotRect->moveBottom(shotRect->y() + SHOT_SPEED);
}
	
void Shot::paint(QPainter& painter) const
{
	painter.drawPixmap(shotRect->x(), shotRect->y(), 50,100, *shotTexture);

}