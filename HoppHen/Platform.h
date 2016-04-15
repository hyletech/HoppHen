#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>
#include "Player.h"


class Platform
{
public:
	Platform(int xPos, int yPos);

	void Update(Player* player);
	void paint(QPainter& painter) const;
	void setPosition(int x, int y);
	QRect getRect() const { return *platformRect; }

	void startMoving();

private:
	QPixmap* platformTexture;
	QRect* platformRect;
	float _yvel;

	bool moving;
};
