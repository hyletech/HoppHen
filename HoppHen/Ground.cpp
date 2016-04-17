#include "Ground.h"


Ground::Ground()
{
	groundRect = new QRect(GROUND_START_X, GROUND_START_Y, GROUND_WIDTH, GROUND_HEIGHT);
	groundTexture = new QPixmap("Dirt.png");
	_yvel = 0;
}

void Ground::Update()
{
	groundRect->moveBottom(groundRect->bottom() + _yvel);
}

void Ground::paint(QPainter& painter) const
{
	painter.drawPixmap(groundRect->x(), groundRect->y(), GROUND_WIDTH, GROUND_HEIGHT, *groundTexture);
}


Ground::~Ground()
{
}
