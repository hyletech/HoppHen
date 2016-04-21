#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>

class Shot : public QObject
{
public:
	Shot(int xPos, int yPos);
	void update();
	void paint(QPainter& painter) const;  
	QRect getRect() const		{ return *shotRect; }
	~Shot();

private:
	QPixmap* shotTexture;
	QRect* shotRect;
};