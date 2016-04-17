#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>
#include "Player.h"

class Ground
{
public:
	Ground();
	~Ground();

	void startMove(float vel) { _yvel = vel; }
	void stopMove() { _yvel = 0; }

	void Update();
	void paint(QPainter& painter) const;

private:
	QPixmap* groundTexture;
	QRect* groundRect;
	float _yvel;

};

