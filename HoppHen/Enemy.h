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

	void initialize();
	void update(Player* _player);
	void paint(QPainter& painter) const;

	void startMove(float vel) { yVel = vel; }
	void stopMove() { yVel = 0; }

	QRect* getRect() { return enemyRect; }

private:
	QPixmap* enemyTexture;
	QRect* enemyRect;

	Player* player;
	
	int xPos;
	int yPos;

	float yVel;
	float xVel;
	float moveSpeed;
	float maxSpeed;
	float xDampen;
};