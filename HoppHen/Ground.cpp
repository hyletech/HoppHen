#include "Ground.h"


Ground::Ground()
{
	groundRect = new QRect(GROUND_START_X, GROUND_START_Y, GROUND_WIDTH, GROUND_HEIGHT);
	groundTexture = new QPixmap("Dirt.png");
	_yvel = 0;
}

void Ground::update(Player* _player)
{
	//Uppdatera pos
	groundRect->moveBottom(groundRect->bottom() + _yvel);

	//Kollar kollision med spelare
	if (groundRect->contains(_player->getRect()->bottomLeft()) || groundRect->contains(_player->getRect()->bottomRight()))
	{
		if ((_player->getRect()->bottom() > groundRect->top()) && (_player->getyvel() >= 0))
			_player->setyvel(-15);
	}
}

void Ground::paint(QPainter& painter) const
{
	painter.drawPixmap(groundRect->x(), groundRect->y(), GROUND_WIDTH, GROUND_HEIGHT, *groundTexture);
}


Ground::~Ground()
{
}
