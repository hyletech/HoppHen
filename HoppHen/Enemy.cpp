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
	if (enemyRect->right() < W_WIDTH - E_PADDING && xVel > 0)
		MoveRight();
	else
		xVel *= -1;

	if (enemyRect->left() > E_PADDING && xVel < 0)
		MoveLeft();
	else 
		xVel *= -1;


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

void Enemy::MoveRight()
{
	//Ökar hastigheten i X
	if (xVel < maxSpeed)
		xVel += moveSpeed;
}

void Enemy::MoveLeft()
{
	//Minskar hastigheten i X
	if (xVel > -maxSpeed)
		xVel -= moveSpeed;
}

void Enemy::MoveDampen()
{
	//Stannar spelaren i X-Led
	if (xVel <= 0)
		xVel += xDampen;
	else if (xVel >= 0)
		xVel -= xDampen;
	if (xVel < P_DAMP_INTERVAL && xVel > -P_DAMP_INTERVAL)
		xVel = 0;
}
