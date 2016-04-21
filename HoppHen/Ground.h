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

	void update(Player* _player);
	void paint(QPainter& painter) const;

	void Reset();

private:
	QPixmap* groundTexture;
	QRect* groundRect;
	float _yvel;

};

