#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>
#include "PlayerManager.h"


class Platform
{
public:
	Platform(int xPos, int yPos);

	void Update(PlayerManager* playerManager);
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
