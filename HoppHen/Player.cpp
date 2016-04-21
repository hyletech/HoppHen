#include "Player.h"
#include <QtGui/QKeyEvent>
#include <QTimer>
#include <initializer_list>


Player::Player()
{
	playerTexture = new QPixmap("Eivind.png");
	playerRect = new QRect(P_START_POS_X, P_START_POS_Y, P_WIDTH, P_HEIGHT);

	yVel = 2;
	xVel = 0;
	moveXSpeed = 0.2;
	maxXSpeed = 7;
	xDampen = 0.2;
}


//Destruktor
Player::~Player()
{
	delete playerRect;
	delete playerTexture;
}

void Player::MoveRight()
{
	//Ökar hastigheten i X
	if (xVel < maxXSpeed)
		xVel += moveXSpeed;
}

void Player::MoveLeft()
{
	//Minskar hastigheten i X
	if (xVel > -maxXSpeed)
		xVel -= moveXSpeed;
}

void Player::MoveDampen()
{
	//Stannar spelaren i X-Led
	if (xVel <= 0)
		xVel += xDampen;
	else if (xVel >= 0)
		xVel -= xDampen;
	if (xVel < P_DAMP_INTERVAL && xVel > -P_DAMP_INTERVAL)
		xVel = 0;
}

void Player::update(int _worldSpeed)
{
	//Uppdaterar spelaren position
	int newX = playerRect->x() + xVel;
	playerRect->moveLeft(newX);

	//PlayerTeleport
	//Teleporterar spelaren om han når kanten av skärmen
	if (playerRect->left() > W_WIDTH)
		playerRect->moveLeft(-P_WIDTH / 2);
	else if (playerRect->right() < 0)
		playerRect->moveLeft(W_WIDTH - P_WIDTH / 2);

	//Gravitation
	playerRect->moveBottom(playerRect->bottom() + yVel + _worldSpeed);
	//Om hastighet är större än 6 nedåt
	if (yVel > 6)
		yVel = 6;
	//Om hastighet nedåt
	if (yVel >= 0)
		yVel *= 1.05;
	//Om slår i taket, ge 1 nedåt
	if (playerRect->top() <= 0)
		yVel = 1;
	//Om hastighet uppåt
	if (yVel <= 0)
		yVel *= 0.95;
	if (yVel > -0.3 && yVel < 0)
		yVel = 1;

	for (int i = 0; i < _shots.size(); i++)
	{
		_shots[i]->update();
		if (_shots[i]->getRect().y() == (W_HEIGHT - S_HEIGHT))
		{
			_shots.erase(_shots.begin() + i);
		}
	}
}


void Player::Shoot()
{
	Shot* shot = new Shot(playerRect->x(), playerRect->y() - 60);
	_shots.push_back(shot);
	setyvel(getyvel() + 5);
}


void Player::Reset()
{
	playerRect->moveTopLeft(QPoint(P_START_POS_X, P_START_POS_Y));
	playerTexture = new QPixmap("Eivind.png");
	enemyHit = false;
}

void Player::enemyPlayerHit()
{
	enemyHit = true;
	//Ändrar spelarens aniskte till "ett dött ansikte"
	playerTexture = new QPixmap("EivindDead.png");
}

std::vector<Shot*>& Player::getShots()
{
	return _shots;
}


void Player::paint(QPainter& painter) const
{
	painter.drawPixmap(playerRect->x(), playerRect->y(), P_WIDTH, P_HEIGHT, *playerTexture);
	for (int i = 0; i < _shots.size(); i++)
	{
		_shots[i]->paint(painter);
	}
}
