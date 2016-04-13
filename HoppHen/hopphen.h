#ifndef HOPPHEN_H
#define HOPPHEN_H

#include <QtWidgets/QMainWindow>
#include "ui_hopphen.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include "defines.h"
#include "qtimer.h"
#include "qpainter.h"

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

private slots:
	void update();

private:
	Ui::HoppHenClass ui;
	QTimer* timer;
	QPixmap* background;
	int bgYPos;
};

#endif // HOPPHEN_H
