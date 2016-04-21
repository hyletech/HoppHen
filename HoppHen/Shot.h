#pragma once
#include <qrect.h>
#include "defines.h"
#include <QPainter>
#include <QTimer>
#include <QObject>
#include <QtWidgets/QMainWindow>




class Shot : public QObject
{
	Q_OBJECT
public:
	Shot(int xPos, int yPos);
	void update();
	void paint(QPainter& painter) const;  
	QRect getRect() const		{ return *shotRect; }

private:
	QPixmap* shotTexture;
	QRect* shotRect;
};