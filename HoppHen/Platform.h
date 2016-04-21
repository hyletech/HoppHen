#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>
#include "Player.h"
#include <stdlib.h>
#include <ctime>

class Platform
{
public:
	Platform(int xPos, int yPos);

	void update(Player* player);
	void paint(QPainter& painter) const;
	QRect getRect() const		{ return *platformRect; }
	void setPos(const int _newY, const int _newX);
	void startMove(float _vel);

protected:
	QPixmap* platformTexture;
	QRect* platformRect;

};
