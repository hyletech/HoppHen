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

	void paintEvent(QPaintEvent * e);
	void update();
	void paint(QPainter& painter) const;
	

	QRect getRect() const		{ return *shotRect; }

	

	QMap<int, bool> _keys;

	
	

private:
	//WorldManager* _worldManager;

	QPixmap* shotTexture;
	QRect* shotRect;
	float _yVel = -1;

	int xPos;
	int yPos;

	

};