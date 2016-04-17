#include "hopphen.h"

HoppHen::HoppHen(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);

	_player = new Player();
	
	_scoreManager = new ScoreManager();
	_worldManager = new WorldManager(_player);

	introTime = 20000;

	//Starting gameState
	gameState = Game;

	//Window
	setFixedWidth(W_WIDTH);	
	setFixedHeight(W_HEIGHT);

	//Background
	_background = new QPixmap("BackGround.png");
	_bgYPos = BG_MINPOS;

	//Timer
	_timer = new QTimer(this);
	connect(_timer, SIGNAL(timeout()), this, SLOT(update()));
	_timer->start(16);
}


void HoppHen::update() //hitcheck
{
	srand(time(NULL));

	switch (gameState)
	{

		//Intro
	case Intro:
		introTime--;
		if (introTime < 0)
		{
			gameState = Game;
		}

		break;

		//Game
	case Game:
		//Updates
		_worldManager->Update();

		//_moveWorld = _player->getRect()->y() <= W_HEIGHT / 2; //flytta världen om player är över en viss y-position

		//KeyInput
		//Player movement
		if (_keys[Qt::Key_Right] || _keys[Qt::Key_D])
			_player->MoveRight();
		else if (_keys[Qt::Key_Left] || _keys[Qt::Key_A])
			_player->MoveLeft();
		else
			_player->MoveDampen();

		//Pause
		if (_keys[Qt::Key_P])
			gameState = Pause;

		//Stäng av spelet
		if (_keys[Qt::Key_Escape])
			close();

		repaint();
		break;


		//Lose
	case Lose:
		_scoreManager->Update();
		repaint();
		break;


		//Pause
	case Pause:
		if (_keys[Qt::Key_P])
			gameState = Game;
		break;

	}
}


//void HoppHen::mouseMoveEvent(QMouseEvent* e)
//{
//	//rack->setPosition(e->x());
//}
//
//void HoppHen::mousePressEvent(QMouseEvent* e)
//{
//
//}


void HoppHen::keyReleaseEvent(QKeyEvent *e)
{
	_keys[e->key()] = false; 
}


void HoppHen::keyPressEvent(QKeyEvent* e)
{
	_keys[e->key()] = true; 
}


void HoppHen::paintEvent(QPaintEvent * e)
{
	QPainter p(this);
	switch (gameState)
	{
	case Game:
		//Bakgrund
		p.drawPixmap(0, _bgYPos, *_background);

		_worldManager->paint(p);
		break;

	case Lose:
		_scoreManager->paint(p);
		break;
	}

}


HoppHen::~HoppHen()
{

}