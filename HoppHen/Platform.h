#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>


class Platform
{
public:
	Platform(int xPos, int yPos);

	void Update();
	void paint(QPainter& painter) const;
	void setPosition(int x, int y);

private:
	QPixmap* platformTexture;
	QRect* platformRect;
};
