#include "Player.h"


Player::Player()
{
	playerTexture = new QPixmap("Eivind.png");
	playerRect = new QRect(P_START_POS_X, P_START_POS_Y, P_WIDTH, P_HEIGHT);

	_yvel = 1;
	xVel = 0;
	moveSpeed = 0.2;
	maxSpeed = 7;
	xDampen = 0.2;

	moveLeft = false;
	moveRight = false;
	jumpBool = 0; 
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
	if (xVel < maxSpeed)
		xVel += moveSpeed;
}

void Player::MoveLeft()
{
	//Minskar hastigheten i X
	if (xVel > -maxSpeed)
		xVel -= moveSpeed;
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

void Player::initialize()
{
	//Ändrar spelarens startposition
	playerRect->moveTopLeft(QPoint(P_START_POS_X, P_START_POS_Y));
}

void Player::Update()
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

void Player::paint(QPainter& painter) const
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
