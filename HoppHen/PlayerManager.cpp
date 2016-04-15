#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
	playerTexture = new QPixmap("Eivind.png");
	playerRect = new QRect(P_START_POS_X, P_START_POS_Y, P_WIDTH, P_HEIGHT);

	xVel = 0;
	moveSpeed = 1;
	maxSpeed = 5;
	xDampen = 1;

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
	if (xVel < maxSpeed)
		xVel += moveSpeed;
}

void PlayerManager::MoveLeft()
{
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
}

void PlayerManager::paint(QPainter& painter) const
{
#if 1
	painter.drawPixmap(playerRect->x(), playerRect->y(), P_WIDTH, P_HEIGHT, *playerTexture);
#else
	QBrush br;
	br.setColor(Qt::blue);
	painter.setBrush(br);
	painter.drawRect(playerRect->x(), playerRect->y(), playerRect->width(), playerRect->height());
#endif
}
