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
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
#include "WorldManager.h"

class HoppHen : public QMainWindow
{
	Q_OBJECT

public:
	HoppHen(QWidget *parent = 0);
	~HoppHen();

	void paintEvent(QPaintEvent * e);
	void keyPressEvent(QKeyEvent* e);
	void keyReleaseEvent(QKeyEvent *e);


private slots:
	void update();

private:
	Ui::HoppHenClass ui;
	QTimer* _timer;
	QPixmap* _background;

	//Object
	Enemy* _enemy;
	Player* _player;
	WorldManager* _worldManager;
	QPoint* _playerBottom;
	QMap<int, bool> _keys;

	bool _moveWorld;
	float _worldSpeed;
	int _bgYPos;

};

#endif // HOPPHEN_H