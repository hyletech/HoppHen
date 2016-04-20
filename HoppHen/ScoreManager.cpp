#include "ScoreManager.h"
#include "defines.h"

ScoreManager::ScoreManager()
{
	darkenedLose = new QPixmap("DarkenedLose.png");
	scoreTexture = new QPixmap("ScoreScreen.png");
	scoreTextY = W_HEIGHT;
	score = 0;

	//QTimer *timer = new QTimer(this);
	//connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
	//timer->start(1000);
}

ScoreManager::~ScoreManager()
{
	delete(darkenedLose);
	delete(scoreTexture);
}

void ScoreManager::Update()
{
	if (scoreTextY > 0)
	{
		scoreTextY -= 4;
	}
	else
		scoreTextY = 0;
}

void ScoreManager::AddScore(float _scoreToAdd)
{
	score += _scoreToAdd;
}

void ScoreManager::Reset()
{
	scoreTextY = W_HEIGHT;
	score = 0;
}

void ScoreManager::paint(QPainter& painter) const
{
	QBrush br;
	br.setColor(Qt::blue);
	painter.setBrush(br);

	QFont font;
	font.setPointSize(24);
	
	QPen pen(QColor("#FFF"));
	painter.setPen(pen);

	
	//font.setWeight(QFont::DemiBold);
	painter.setFont(font);

	painter.drawPixmap(0,0, W_WIDTH , W_HEIGHT, *darkenedLose);
	painter.drawPixmap(0, scoreTextY, W_WIDTH, W_HEIGHT, *scoreTexture);

	QString s = QString::number(score);

	painter.drawText(320, scoreTextY + 300, s);
}
