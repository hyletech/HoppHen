#ifndef HOPPHEN_H
#define HOPPHEN_H

#include <QtWidgets/QMainWindow>
#include "ui_hopphen.h"
#include <QMouseEvent>
#include "includes.h"

class HoppHen : public QMainWindow
{
	Q_OBJECT

public:
	enum GameState{Intro, Lose, Game, Pause };

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
	GameState gameState;

	//Object
	Ground* _ground;
	Enemy* _enemy;
	Player* _player;
	WorldManager* _worldManager;
	ScoreManager* _scoreManager;
	QMap<int, bool> _keys;

	float introTime;
	bool _moveWorld;
	float _worldSpeed;
	int _bgYPos;

};

#endif // HOPPHEN_H