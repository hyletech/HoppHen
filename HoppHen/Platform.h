#pragma once
#include <qrect.h>
#include <QPainter>
#include "Player.h"


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
