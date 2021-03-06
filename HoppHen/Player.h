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

	void update(int _worldSpeed);
	void Shoot();
	void paint(QPainter& painter) const;

	//Movement
	void MoveRight();
	void MoveLeft();
	void MoveDampen();

	float getyvel() const  { return yVel; }
	void setyvel(float vel) { yVel = vel; }
	QRect* getRect() const { return playerRect; }		

	//Fiende col med player
	void enemyPlayerHit();
	bool getEnemyHit() const{ return enemyHit; }

	void Reset();
	std::vector<Shot*>& getShots();

	

private:
	QPixmap* playerTexture;
	QRect* playerRect;

	float yVel;	//lokal Y

	double xVel;	//Velocity of player
	double moveXSpeed;
	double maxXSpeed;
	double xDampen;

	std::vector<Shot*> _shots;

	bool enemyHit = false;

};

