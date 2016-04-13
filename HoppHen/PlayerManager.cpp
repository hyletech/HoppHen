#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
	playerTexture = new QPixmap("Eivind.png");
	playerRect = new QRect(50,50,P_WIDTH,P_HEIGHT);

}

void PlayerManager::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_A)
	{
		//playerRect->moveLeft(playerRect->getCoords.x += MOVESPEED);
	}
}

PlayerManager::~PlayerManager()
{
}

void Update()
{

}

 void PlayerManager::paint(QPainter& painter) const
 {
	painter.drawPixmap(playerRect->x(),playerRect->y(), *playerTexture);
}	