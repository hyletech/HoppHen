#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>
#include "Player.h"


class Enemy
{
public:
	Enemy();
	Enemy(int xPos, int yPos, Player* _player);
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
	Player* player;

	float _yvel;
	float xVel;
	float moveSpeed;
	float maxSpeed;
	float xDampen;
};