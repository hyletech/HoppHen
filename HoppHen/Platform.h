#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>
#include "Player.h"


class Platform
{
public:
	Platform(int xPos, int yPos);

	void update(Player* player);
	void paint(QPainter& painter) const;
	QRect getRect() const		{ return *platformRect; }

	void startMove(float vel)	{ _yvel = vel; }
	void stopMove()				{ _yvel = 0; }
	virtual void giveEffect(){}

protected:
	QPixmap* platformTexture;
	QRect* platformRect;
	float _yvel;
};
