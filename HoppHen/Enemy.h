#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>


class Enemy
{
public:
	Enemy();
	Enemy(int xPos, int yPos);
	~Enemy();


	void initialize();
	void update();
	void paint(QPainter& painter) const;

	void startMove(float vel) { _yvel = vel; }
	void stopMove() { _yvel = 0; }


	QRect* getRect() { return enemyRect; }

private:
	QPixmap* enemyTexture;
	QRect* enemyRect;

	float _yvel;
	float xVel;
	float moveSpeed;
	float maxSpeed;
	float xDampen;
};