#include <QtWidgets/QMainWindow>
#include "defines.h"
#include <vector>
#include <QPainter>

#pragma once
class PlayerManager
{
public:
	PlayerManager();

	bool moveLeft;
	bool moveRight;

	void Update();
	void paint(QPainter& painter) const;
	void MoveRight();
	void MoveLeft();

	~PlayerManager();

private:

	QPixmap* playerTexture;
	QRect* playerRect;

};

