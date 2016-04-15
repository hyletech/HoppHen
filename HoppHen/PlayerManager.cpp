#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
	playerTexture = new QPixmap("Eivind.png");
	playerRect = new QRect(P_START_POS_X, P_START_POS_Y, P_WIDTH, P_HEIGHT);

	_yvel = 1;
	xVel = 0;
	moveSpeed = 0.2;
	maxSpeed = 5;
	xDampen = 0.2;

	moveLeft = false;
	moveRight = false;
	jumpBool = 0; 
}


PlayerManager::~PlayerManager()
{
	delete playerRect;
	delete playerTexture;
}

void PlayerManager::MoveRight()
{
	if (playerRect->center().x() > W_WIDTH)
		playerRect->moveLeft(-P_WIDTH / 2);	
	if (xVel < maxSpeed)
		xVel += moveSpeed;
}

void PlayerManager::MoveLeft()
{
	if (playerRect->center().x() < 0)
		playerRect->moveLeft(W_WIDTH - P_WIDTH / 2);
	if (xVel > -maxSpeed)
		xVel -= moveSpeed;
}

void PlayerManager::MoveDampen()
{
	if (xVel < 0)
		xVel += xDampen;
	if (xVel > 0)
		xVel -= xDampen;
}

void PlayerManager::initialize()
{
	playerRect->moveTopLeft(QPoint(P_START_POS_X, P_START_POS_Y));
}

void PlayerManager::Update()
{
	int newX = playerRect->x() + xVel;
	playerRect->moveLeft(newX);

	playerRect->moveBottom(playerRect->bottom() + _yvel);
	if (_yvel >= 0)
		_yvel *= 1.05;
	if (playerRect->bottom() >= W_HEIGHT)
		_yvel = -15;
	if (playerRect->top() <= 0)
		_yvel = 1;
	if (_yvel <= 0)
		_yvel = (_yvel * 0.95);
	if (_yvel > -0.5 && _yvel < 0)
		_yvel = 1;

}

void PlayerManager::paint(QPainter& painter) const
{
#if 1
	painter.drawPixmap(playerRect->x(), playerRect->y(), P_WIDTH, P_HEIGHT, *playerTexture);
	painter.drawPixmap(playerRect->x(), playerRect->y(), P_WIDTH, P_HEIGHT, *playerTexture);
#else
	QBrush br;
	br.setColor(Qt::blue);
	painter.setBrush(br);
	painter.drawRect(playerRect->x(), playerRect->y(), playerRect->width(), playerRect->height());
#endif
}
