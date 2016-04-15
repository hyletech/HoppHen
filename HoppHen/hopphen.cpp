#include "hopphen.h"

HoppHen::HoppHen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	_player = new Player();
	_enemy = new Enemy();
	_playerBottom = new QPoint();

#if MOVE_WORLD 1
	_worldSpeed = 2;
#else
	_worldSpeed = 0;
#endif
	_moveWorld = false;
	initPlatforms();


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

//Destruktor
HoppHen::~HoppHen()
{

}

void HoppHen::update() //hitcheck
{
	srand(time(NULL));

	//KeyInput
	//Player movement
	if (_keys[Qt::Key_Right] || _keys[Qt::Key_D])
		_player->MoveRight();
	else if(_keys[Qt::Key_Left] || _keys[Qt::Key_A])
		_player->MoveLeft();
	else
		_player->MoveDampen();

	//Stäng av spelet
	if (_keys[Qt::Key_Escape]) 
		close();


	_moveWorld = _player->getRect()->y() <= W_HEIGHT / 2; //flytta världen om player är över en viss y-position

	//Uppdatera plattformerna, samt hitcheck med spelare och plattform
	for (int i = 0; i < _platforms.size(); i++)
	{
		if (_moveWorld)
			_platforms[i]->startMove(_worldSpeed);
		else 
			_platforms[i]->stopMove();

		
		_platforms[i]->Update(_player);
	}

	if (_moveWorld)
		_enemy->startMove(_worldSpeed);
	else
		_enemy->stopMove();

	_enemy->update();
	_player->Update();

	repaint();
}

void HoppHen::paintEvent(QPaintEvent * e)
{
	QPainter p(this);

	//Bakgrund
	p.drawPixmap(0, _bgYPos, *_background);

	//Plattformer
	for (int i = 0; i < _platforms.size(); i++)
		_platforms[i]->paint(p);

	_enemy->paint(p);
	_player->paint(p);
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

void HoppHen::initPlatforms()
{
#if 0 
	int spaceX = 0;
	int spaceY = 50;
	if (_platforms.size() == 0)
	{
		for (int x = 0; x < 25; x++)
		{
			Platform* n = new Platform(spaceX, spaceY);
			_platforms.push_back(n);
			spaceX += 25;
			spaceY += 120;
		}
	}
<<<<<<< HEAD
}
=======
#else
	//Random i x-led
	if (_platforms.size() == 0)
	{
		for (int i = 0; i < 20; i++)
		{
			int xPos = rand() % (W_WIDTH - PF_WIDTH - E_PADDING) + 1; 
			int yPos = W_HEIGHT - (i * 100) - 200;
			Platform* p = new Platform(xPos, yPos);
			_platforms.push_back(p);
		}
	}
#endif
}
>>>>>>> 541c19b61b8956758bd1ea24130887544d5c3bc3
