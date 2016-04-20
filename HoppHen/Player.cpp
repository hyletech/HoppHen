#include "Player.h"
#include <QtGui/QKeyEvent>


Player::Player()
{
	playerTexture = new QPixmap("Eivind.png");
	playerRect = new QRect(P_START_POS_X, P_START_POS_Y, P_WIDTH, P_HEIGHT);

	yVel = 2;
	worldSpeed = 0;
	xVel = 0;
	moveXSpeed = 0.2;
	maxXSpeed = 7;
	xDampen = 0.2;

	moveLeft = false;
	moveRight = false;
}



//Destruktor
Player::~Player()
{
	delete playerRect;
	delete playerTexture;
}

void Player::MoveRight()
{
	//�kar hastigheten i X
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

//�ndrar spelarens aniskte till "ett d�tt ansikte"
void Player::playerDead()
{
	playerTexture = new QPixmap("EivindDead.png");
}

void Player::initialize()
{
	//�ndrar spelarens startposition
	playerRect->moveTopLeft(QPoint(P_START_POS_X, P_START_POS_Y));
}

void Player::update()
{
	//Uppdaterar spelaren position
	int newX = playerRect->x() + xVel;
	playerRect->moveLeft(newX);

	//PlayerTeleport
	//Teleporterar spelaren om han n�r kanten av sk�rmen
	if (playerRect->left() > W_WIDTH)
		playerRect->moveLeft(-P_WIDTH / 2);
	else if (playerRect->right() < 0)
		playerRect->moveLeft(W_WIDTH - P_WIDTH / 2);

	//Gravitation
	playerRect->moveBottom(playerRect->bottom() + yVel + worldSpeed);
	//Om hastighet �r st�rre �n 6 ned�t
	if (yVel > 6)
		yVel = 6;
	//Om hastighet ned�t
	if (yVel >= 0)
		yVel *= 1.05;
	//Om sl�r i taket, ge 1 ned�t
	if (playerRect->top() <= 0)
		yVel = 1;
	//Om hastighet upp�t
	if (yVel <= 0)
		yVel *= 0.95;
	if (yVel > -0.3 && yVel < 0)
		yVel = 1;

	for (int i = 0; i < _shots.size(); i++)
	{
		_shots[i]->update();
	}
}


void Player::Shoot()
{
	Shot* shot = new Shot(playerRect->x(), playerRect->y());
	_shots.push_back(shot);
}



void Player::Reset()
{
	playerRect->moveLeft(P_START_POS_X);
	playerRect->moveTop(P_START_POS_Y);
	playerTexture = new QPixmap("Eivind.png");
}


void Player::paint(QPainter& painter) const
{
	painter.drawPixmap(playerRect->x(), playerRect->y(), P_WIDTH, P_HEIGHT, *playerTexture);
	for (int i = 0; i < _shots.size(); i++)
	{
		_shots[i]->paint(painter);
	}
}
