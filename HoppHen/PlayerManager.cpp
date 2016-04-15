#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
	playerTexture = new QPixmap("Eivind.png");
	playerRect = new QRect(P_START_POS_X, P_START_POS_Y, P_WIDTH, P_HEIGHT);
	//playerRect = new QRect(P_START_POS_X, 50 ,P_WIDTH, P_HEIGHT);
	_yvel = 1;

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
	if ((playerRect->left() + 25) > 600)
		playerRect->setLeft(-25);
	playerRect->moveLeft(playerRect->x() + MOVESPEED);
}

void PlayerManager::MoveLeft()
{
	if ((playerRect->left() + 25) < 0)
		playerRect->setLeft(625);
	playerRect->moveLeft(playerRect->x() - MOVESPEED);
}

void PlayerManager::initialize()
{
	playerRect->moveTopLeft(QPoint(P_START_POS_X, P_START_POS_Y));
}

void PlayerManager::Update()
{
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
	painter.drawPixmap(playerRect->x(),playerRect->y(),P_WIDTH, P_HEIGHT, *playerTexture);
}	

 float PlayerManager::getyvel()
 {
	 return _yvel;
 }

 void PlayerManager::setyvel(float yvel)
 {
	 _yvel = yvel;
 }