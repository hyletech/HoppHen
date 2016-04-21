#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>
#include "Player.h"


class Enemy
{
public:
	Enemy(int height);
	~Enemy();

	void update(Player* _player);
	void paint(QPainter& painter) const;

	void startMove(float vel) { yVel = vel; }
	void setPos(const int _newY, const int _newX);

	QRect* getRect() { return enemyRect; }

private:
	QPixmap* enemyTexture;
	QRect* enemyRect;

	Player* player;

	float yVel;
	float xVel;
	float moveSpeed;
	float maxSpeed;
	float xDampen;
};