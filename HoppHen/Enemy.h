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
	void update(float worldSpeed);
	void paint(QPainter& painter) const;

	QRect* getRect() { return enemyRect; }

private:
	QPixmap* enemyTexture;
	QRect* enemyRect;
	float xVel;
	float moveSpeed;
	float maxSpeed;
	float xDampen;
};