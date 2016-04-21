#include "Enemy.h"

Enemy::Enemy(int height)
{
	enemyRect = new QRect(E_START_POS_X, height, E_WIDTH, E_HEIGHT);
	enemyTexture = new QPixmap("monster1.png"); //Fixa bild

	yVel = 0;
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

void Enemy::update(Player* player)
{
	if (enemyRect->right() > W_WIDTH - E_PADDING && xVel > 0)
		xVel *= -1;
	else if (enemyRect->left() < E_PADDING && xVel < 0)
		xVel *= -1;

	enemyRect->moveLeft(enemyRect->x() + xVel);

	enemyRect->moveBottom(enemyRect->bottom() + yVel);

	//Om player/enemy-kollision
	if (enemyRect->contains(player->getRect()->x(), player->getRect()->y()))
	{
		player->enemyPlayerHit();
		player->setyvel(5);
	}
}

void Enemy::setPos(const int _newY, const int _newX)
{
	enemyRect->moveBottom(_newY);
	enemyRect->moveLeft(_newX);
}

void Enemy::paint(QPainter& painter) const
{
	QBrush br;
	br.setColor(Qt::blue);
	painter.setBrush(br);
	//painter.drawRect(enemyRect->x(), enemyRect->y(), E_WIDTH, E_HEIGHT);
	painter.drawPixmap(enemyRect->x(), enemyRect->y(), E_WIDTH, E_HEIGHT, *enemyTexture);

}

