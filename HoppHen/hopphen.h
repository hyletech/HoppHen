#ifndef HOPPHEN_H
#define HOPPHEN_H

#include <QtWidgets/QMainWindow>
#include "ui_hopphen.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>
#include <ctime>
#include <vector>

#include "defines.h"
#include "PlayerManager.h"
#include "Platform.h"

class HoppHen : public QMainWindow
{
	Q_OBJECT

public:
	HoppHen(QWidget *parent = 0);
	~HoppHen();

	void paintEvent(QPaintEvent * e);
	void keyPressEvent(QKeyEvent* e);
	void keyReleaseEvent(QKeyEvent *e);

	void initPlatforms();

private slots:
	void update();

private:
	Ui::HoppHenClass ui;
	QTimer* timer;
	QPixmap* background;
	int bgYPos;

	//Object
	std::vector<Platform*> _platforms;
	PlayerManager* playerManager;
	QPoint* playerBottom;
	QMap<int, bool> keys;
};

#endif // HOPPHEN_H