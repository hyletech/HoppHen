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
	void MoveRight();
	void MoveLeft();

	float getyvel() const  { return _yvel; }
	void setyvel(float yvel) { _yvel = yvel; }


	QRect* getRect() { return playerRect; }


private:
	QPixmap* playerTexture;
	QRect* playerRect;
	float _yvel;

	bool moveLeft;
	bool moveRight;
	bool jumpBool; //Allows the player to jump once
};

