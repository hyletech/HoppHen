#include "hopphen.h"

HoppHen::HoppHen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

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

void HoppHen::update() //hitcheck
{
	repaint();
}

void HoppHen::paintEvent(QPaintEvent * e)
{
	QPainter p(this);

	p.drawPixmap(0, bgYPos, *background); //bakgrund

	playerManager.paint(p);

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

void HoppHen::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_Space)
	{

	}
	else if (e->key() == Qt::Key_Space)
	{

	}
	else if (e->key() == Qt::Key_R)
	{

	}
}


//Destruktor
HoppHen::~HoppHen()
{

}

