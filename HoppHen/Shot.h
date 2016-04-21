#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>

class Shot : public QObject
{
public:
	Shot(int xPos, int yPos);
	~Shot();
	void update();
	void paint(QPainter& painter) const;
	QRect getRect() const { return *shotRect; }

private:
	
	QPixmap* shotTexture;
	QRect* shotRect;
	float _yVel = -1;

	int xPos;
	int yPos;
};