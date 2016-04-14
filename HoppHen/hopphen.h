#ifndef HOPPHEN_H
#define HOPPHEN_H

#include <QtWidgets/QMainWindow>
#include "ui_hopphen.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>
#include <ctime>

#include "defines.h"
#include "PlayerManager.h"

class HoppHen : public QMainWindow
{
	Q_OBJECT

public:
	HoppHen(QWidget *parent = 0);
	~HoppHen();

	void paintEvent(QPaintEvent * e);
	void mouseMoveEvent(QMouseEvent* e);
	void mousePressEvent(QMouseEvent* e);
	void keyPressEvent(QKeyEvent* e);
	void keyReleaseEvent(QKeyEvent *e);

private slots:
	void update();

private:
	Ui::HoppHenClass ui;
	QTimer* timer;
	QPixmap* background;
	int bgYPos;

	//Object
	PlayerManager playerManager;
	QMap<int, bool> keys;
};

#endif // HOPPHEN_H