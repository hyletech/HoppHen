#include <QtWidgets/QMainWindow>
#include "defines.h"
#include <vector>
#include <QPainter>

#pragma once
class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();


	void initialize();
	void Update();
	void paint(QPainter& painter) const;

	//Movement
	void MoveRight();
	void MoveLeft();
	void MoveDampen();


private:
	QPixmap* playerTexture;
	QRect* playerRect;

	int xVel;	//Velocity of player
	double moveSpeed;
	double maxSpeed;
	int xDampen;

	bool moveLeft;
	bool moveRight;
	bool jumpBool; //Allows the player to jump once
};

