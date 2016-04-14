#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
	playerTexture = new QPixmap("Eivind.png");
	playerRect = new QRect(P_START_POS_X, P_START_POS_Y, P_WIDTH, P_HEIGHT);

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
	playerRect->moveLeft(playerRect->x() + MOVESPEED);
}

void PlayerManager::MoveLeft()
{
	playerRect->moveLeft(playerRect->x() - MOVESPEED);
}

void PlayerManager::initialize()
{
	playerRect->moveTopLeft(QPoint(P_START_POS_X, P_START_POS_Y));
}

void PlayerManager::Update()
{
	
}

 void PlayerManager::paint(QPainter& painter) const
 {
	painter.drawPixmap(playerRect->x(),playerRect->y(),P_WIDTH, P_HEIGHT, *playerTexture);
}	