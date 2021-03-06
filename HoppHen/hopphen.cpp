#include "hopphen.h"

HoppHen::HoppHen(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);

	_player = new Player();
	
	//Score
	_scoreManager = new ScoreManager();
	scoreTab = new QPixmap("ScoreTab.png");

	_worldManager = new WorldManager(_player, _scoreManager);

	//intro
	introTexture = new QPixmap("IntroScreen.png");
	introTime = 250;

	//Starting gameState
	gameState = Intro;

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

	//Keypress
	keyPressShoot = false;
	keyPressPause = false;
}


void HoppHen::update() //hitcheck
{
	srand(time(NULL));

	switch (gameState)
	{

	case Intro:
			_sleep(1);
			introTime--;
			if (introTime < 0)
			{
				gameState = Game;
			}
		break;

	case Game:
		_worldManager->Update();

		if (_worldManager->lose)
		{
			gameState = Lose;
		}

		//KeyInput
		//Player movement
		if (_keys[Qt::Key_Right] || _keys[Qt::Key_D])
			_player->MoveRight();
		else if (_keys[Qt::Key_Left] || _keys[Qt::Key_A])
			_player->MoveLeft();
		else
			_player->MoveDampen();
		
		//Om spelaren skjuter
		if (_keys[Qt::Key_Space] && !keyPressShoot)
		{
			_player->Shoot();
			keyPressShoot = true;
		}
		else if (!_keys[Qt::Key_Space])
			keyPressShoot = false;

		//Pause
		if (_keys[Qt::Key_P] && !keyPressPause)
		{
			gameState = Pause;
			keyPressPause = true;
		}
		else if (!_keys[Qt::Key_P])
			keyPressPause = false;


		//St�ng av spelet
		if (_keys[Qt::Key_Escape])
			close();

		if (_bgYPos < BG_MAXPOS)
		{
			_bgYPos = (_scoreManager->GetScore() * 0.1f) + BG_MINPOS;
		}

		repaint();
		break;


		//Lose
	case Lose:
		_scoreManager->Update();
		repaint();

		if (_keys[Qt::Key_R])
		{
			_worldManager->lose = false;
			gameState = Game;
			_worldManager->resetWorld();
			_scoreManager->Reset();
			_bgYPos = BG_MINPOS;
		}
		break;


		//Pause
	case Pause:
		if (_keys[Qt::Key_P] && !keyPressPause)
		{
			gameState = Game;
			keyPressPause = true;
		}
		else if (!_keys[Qt::Key_P])
			keyPressPause = false;

		break;

	}
}


void HoppHen::LoseGame()
{
	gameState = Lose;
}


void HoppHen::paintEvent(QPaintEvent * e)
{
	QPainter p(this);
	QBrush br;
	br.setColor(Qt::blue);
	p.setBrush(br);

	QFont font;
	font.setPointSize(24);

	QPen pen(QColor("#FFF"));
	p.setPen(pen);
	p.setFont(font);

	switch (gameState)
	{
	case Intro:
		//Intro
		p.drawPixmap(0, 0, *introTexture);

		break;

	case Game:
		//Bakgrund
		p.drawPixmap(0, _bgYPos, *_background);

		_worldManager->paint(p);
		p.drawPixmap(0, 0, *scoreTab);
		p.drawText(220, 45, "Height:");
		p.drawText(340, 45, QString::number(_scoreManager->GetScore()));
		break;
		
	case Pause:
		//Bakgrund
		p.drawPixmap(0, _bgYPos, *_background);

		_worldManager->paint(p);
		p.drawPixmap(0, 0, *scoreTab);
		p.drawText(220, 45, "Height:");
		p.drawText(340, 45, QString::number(_scoreManager->GetScore()));

		break;

	case Lose:
		_worldManager->paint(p);
		_scoreManager->paint(p);
		break;
	}

}


HoppHen::~HoppHen()
{

}