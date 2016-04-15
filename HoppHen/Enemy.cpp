#include "Enemy.h"

Enemy::Enemy()
{
	enemyTexture = new QPixmap(""); //Fixa bild
	enemyRect = new QRect(E_START_POS_X, E_START_POS_Y, E_WIDTH, E_HEIGHT);

	xVel = 5;
	moveSpeed = 0.2;
	maxSpeed = 5;
	xDampen = 0.2;
}

Enemy::Enemy(int xPos, int yPos)
{
	enemyTexture = new QPixmap(""); //Fixa bild
	enemyRect = new QRect(xPos, yPos, E_WIDTH, E_HEIGHT);

	xVel = 5;
	moveSpeed = 0.2;
	maxSpeed = 5;
	xDampen = 0.2;
}

Enemy::~Enemy()
{
	delete enemyRect;
	delete enemyTexture;
}

void Enemy::initialize()
{

}

void Enemy::update(float worldSpeed)
{
	if (enemyRect->right() > W_WIDTH - E_PADDING && xVel > 0)
		xVel *= -1;
	else if (enemyRect->left() < E_PADDING && xVel < 0)
		xVel *= -1;

	enemyRect->moveLeft(enemyRect->x() + xVel);


#if MOVE_WORLD 1 //se i defines.h
	if (worldSpeed > 0)
		enemyRect->moveBottom(enemyRect->bottom() + worldSpeed);
#endif
}

void Enemy::paint(QPainter& painter) const
{
	QBrush br;
	br.setColor(Qt::blue);
	painter.setBrush(br);
	painter.drawRect(enemyRect->x(), enemyRect->y(), E_WIDTH, E_HEIGHT);
}

