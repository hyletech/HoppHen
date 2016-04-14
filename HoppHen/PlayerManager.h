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


private:
	QPixmap* playerTexture;
	QRect* playerRect;

	bool moveLeft;
	bool moveRight;
	bool jumpBool; //Allows the player to jump once
};

