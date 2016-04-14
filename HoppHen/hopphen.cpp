#include "hopphen.h"

HoppHen::HoppHen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	playerManager = new PlayerManager();

	initPlatforms();

	//Window
	setFixedWidth(W_WIDTH);	
	setFixedHeight(W_HEIGHT);

	//Mouse
	setMouseTracking(true);
	qDebug() << "HasMouseTracking:" << hasMouseTracking();

	//Background
	background = new QPixmap("BackGround.png");
	bgYPos = BG_MINPOS;

	//Timer
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(16);
}

//Destruktor
HoppHen::~HoppHen()
{

}

void HoppHen::update() //hitcheck
{
	srand(time(NULL));
	//KeyInput
	if (keys[Qt::Key_Right] || keys[Qt::Key_D])
		playerManager->MoveRight();
	else if (keys[Qt::Key_Left] || keys[Qt::Key_A])
		playerManager->MoveLeft();

	if (keys[Qt::Key_Escape])
		close();

	for (int i = 0; i < _platforms.size(); i++)
	{
		_platforms[i]->Update(playerManager);
	}

	playerManager->Update();

	repaint();
}

void HoppHen::paintEvent(QPaintEvent * e)
{
	QPainter p(this);

	p.drawPixmap(0, bgYPos, *background); //bakgrund

	for (int i = 0; i < _platforms.size(); i++)
		_platforms[i]->paint(p);

	playerManager->paint(p);

	/*for (int i = 0; i < _blocks.size(); i++)
		_blocks[i]->paint(p);

	if (_powerups.size() > 0)
	{
		for (int i = 0; i < _powerups.size(); i++)
			_powerups[i]->paint(p);
	}

	rack->paint(p);
	boll->paint(p);
	score->paint(p, *score, *boll);*/
}

void HoppHen::mouseMoveEvent(QMouseEvent* e)
{
	//rack->setPosition(e->x());
}

void HoppHen::mousePressEvent(QMouseEvent* e)
{
}

void HoppHen::keyReleaseEvent(QKeyEvent *e)
{
	keys[e->key()] = false; 
}


void HoppHen::keyPressEvent(QKeyEvent* e)
{
	keys[e->key()] = true; 
}

void HoppHen::initPlatforms()
{
	int space = 0;

	if (_platforms.size() == 0)
	{
		for (int x = 0; x < 25; x++)
		{
			Platform* n = new Platform(space, space);
			_platforms.push_back(n);
			space += 25;
		}
	}
}