#include "hopphen.h"

HoppHen::HoppHen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	playerManager = new PlayerManager();
	playerBottom = new QPoint();

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
	else
		playerManager->MoveDampen();

		playerManager->MoveLeft();

	if (keys[Qt::Key_Escape])
		close();

	QPoint* point = new QPoint(playerManager->getRect()->x() + (PF_WIDTH/2), playerManager->getRect()->y() + PF_HEIGHT);

	for (int i = 0; i < _platforms.size(); i++)
	{
		if (point->y() <= 400)
			_platforms[i]->startMoving();

		_platforms[i]->Update(playerManager);
	}

	playerManager->Update();

	repaint();
}

void HoppHen::paintEvent(QPaintEvent * e)
{
	QPainter p(this);

	p.drawPixmap(0, bgYPos, *background);		//bakgrund

	for (int i = 0; i < _platforms.size(); i++)
		_platforms[i]->paint(p);

	playerManager->paint(p);
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
}