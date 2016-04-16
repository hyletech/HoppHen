#include "Enemy.h"

Enemy::Enemy()
{
	enemyTexture = new QPixmap("monster1.png"); //Fixa bild
	enemyRect = new QRect(E_START_POS_X, E_START_POS_Y, E_WIDTH, E_HEIGHT);
	_yvel = 0;
	xVel = 5;
	moveSpeed = 0.2;
	maxSpeed = 5;
	xDampen = 0.2;
}

Enemy::Enemy(Player* _player)
{
	//enemyRect = new QRect(xPos, yPos, E_WIDTH, E_HEIGHT);
	player = _player;

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

//#if MOVE_WORLD 1 //se i defines.h
//	if (worldSpeed > 0)
//		enemyRect->moveBottom(enemyRect->bottom() + worldSpeed);
//#endif
	//Om player/enemy-kollision
	/*if (enemyRect->contains(player->getRect()->bottomLeft()) || enemyRect->contains(player->getRect()->bottomRight()) || enemyRect->contains(player->getRect()->topLeft()) || enemyRect->contains(player->getRect()->topRight()))
	{
		player->setyvel(-100);

	}*/
}


void Enemy::paint(QPainter& painter) const
{
	QBrush br;
	br.setColor(Qt::blue);
	painter.setBrush(br);
	//painter.drawRect(enemyRect->x(), enemyRect->y(), E_WIDTH, E_HEIGHT);
	painter.drawPixmap(enemyRect->x(), enemyRect->y(), E_WIDTH, E_HEIGHT, *enemyTexture);

}

