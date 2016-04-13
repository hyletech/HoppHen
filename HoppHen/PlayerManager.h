#include <QtWidgets/QMainWindow>
#include "defines.h"
#include <vector>
#include <QPainter>
#include <QKeyEvent>
#include "qpainter.h"

#pragma once
class PlayerManager
{
public:
	PlayerManager();

	void Update();
	void keyPressEvent(QKeyEvent* e);
	void paint(QPainter& painter) const;

	~PlayerManager();

private:

	QPixmap* playerTexture;
	QRect* playerRect;


};

