#include <QtWidgets/QMainWindow>
#include "defines.h"
#include <vector>
#include <QPainter>
#include <QtGui/QKeyEvent>
#include "Shot.h"




#pragma once
class Player
{
public:
	Player();
	~Player();


	void initialize();
	void update();
	void Shoot();
	void paint(QPainter& painter) const;

	//Movement
	void MoveRight();
	void MoveLeft();
	void MoveDampen();

	float getyvel() const  { return yVel; }
	void setyvel(float vel) { yVel = vel; }

	void startMoveWithWorld(float vel) { worldSpeed = vel; }
	void stopMoveWithWorld() { worldSpeed = 0; }


	int getYPos(){ return playerRect->y(); }
	int getXPos(){ return playerRect->x(); }
	QRect* getRect() { return playerRect; }		

	void Player::keyPressEvent(QKeyEvent *e) { _keys[e->key()] = true; }
	void Player::keyReleaseEvent(QKeyEvent* e) { _keys[e->key()] = false; }
	
	QMap<int, bool> _keys;

	void playerDead(); 
	void Reset();


private:
	QPixmap* playerTexture;
	QRect* playerRect;

	float yVel;
	float worldSpeed;

	double xVel;	//Velocity of player
	double moveXSpeed;
	double maxXSpeed;
	double xDampen;

	std::vector<Shot*> _shots;

	bool moveLeft;
	bool moveRight;
};

