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

	void HoppHen::keyReleaseEvent(QKeyEvent *e){_keys[e->key()] = false;}
	void HoppHen::keyPressEvent(QKeyEvent* e){_keys[e->key()] = true;}

	void LoseGame();

private slots:
	void update();

private:
	Ui::HoppHenClass ui;
	QTimer* _timer;
	QPixmap* _background;
	QPixmap* introTexture;
	QPixmap* scoreTab;
	GameState gameState;

	//Object
	Player* _player;
	Shot* _shot;
	WorldManager* _worldManager;
	ScoreManager* _scoreManager;
	QMap<int, bool> _keys;

	float introTime;
	bool _moveWorld;
	float _worldSpeed;
	int _bgYPos;
	bool keyPress;
};

#endif // HOPPHEN_H