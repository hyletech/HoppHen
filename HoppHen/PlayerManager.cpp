#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
	playerTexture = new QPixmap("Eivind.png");
	playerRect = new QRect(50,50,P_WIDTH,P_HEIGHT);

	moveLeft = false;
	moveRight = false;

}


PlayerManager::~PlayerManager()
{

}

void PlayerManager::MoveRight()
{
	playerRect->moveLeft(playerRect->x() + MOVESPEED);
}

void PlayerManager::MoveLeft()
{
	playerRect->moveLeft(playerRect->x() - MOVESPEED);
}

void PlayerManager::Update()
{
	
}

 void PlayerManager::paint(QPainter& painter) const
 {
	painter.drawPixmap(playerRect->x(),playerRect->y(),P_WIDTH, P_HEIGHT, *playerTexture);
}	