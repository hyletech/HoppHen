#include "Enemy.h"

Enemy::Enemy(Player* _player)
{
	player = _player;
	xPos = E_START_POS_X;
	yPos = E_START_POS_Y;
	enemyRect = new QRect(xPos, yPos, E_WIDTH, E_HEIGHT);
	enemyTexture = new QPixmap("monster1.png"); //Fixa bild
	_yvel = 0;

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

void Enemy::update()
{
	if (enemyRect->right() > W_WIDTH - E_PADDING && xVel > 0)
		xVel *= -1;
	else if (enemyRect->left() < E_PADDING && xVel < 0)
		xVel *= -1;

	enemyRect->moveLeft(enemyRect->x() + xVel);

	enemyRect->moveBottom(enemyRect->bottom() + _yvel);

	//Om player/enemy-kollision
	if (enemyRect->contains(player->getXPos(), player->getYPos()))
	{
		player->setyvel(5);
		player->playerDead();
	}
}


void Enemy::paint(QPainter& painter) const
{
	QBrush br;
	br.setColor(Qt::blue);
	painter.setBrush(br);
	//painter.drawRect(enemyRect->x(), enemyRect->y(), E_WIDTH, E_HEIGHT);
	painter.drawPixmap(enemyRect->x(), enemyRect->y(), E_WIDTH, E_HEIGHT, *enemyTexture);

}

