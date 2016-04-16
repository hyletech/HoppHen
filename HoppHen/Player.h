#include <QtWidgets/QMainWindow>
#include "defines.h"
#include <vector>
#include <QPainter>

#pragma once
class Player
{
public:
	Player();
	~Player();


	void initialize();
	void Update();
	void paint(QPainter& painter) const;

	//Movement
	void MoveRight();
	void MoveLeft();
	void MoveDampen();

	float getyvel() const  { return _yvel; }
	void setyvel(float yvel) { _yvel = yvel; }

	int getYPos(){ return playerRect->y(); }
	QRect* getRect() { return playerRect; }


private:
	QPixmap* playerTexture;
	QRect* playerRect;
	QRect* playerRect1;
	float _yvel;

	double xVel;	//Velocity of player
	double moveSpeed;
	double maxSpeed;
	double xDampen;

	bool moveLeft;
	bool moveRight;
	bool jumpBool; //Allows the player to jump once
};
