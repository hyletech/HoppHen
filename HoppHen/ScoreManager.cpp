#include "ScoreManager.h"
#include "defines.h"

using namespace std;

ScoreManager::ScoreManager()
{
	darkenedLose = new QPixmap("DarkenedLose.png");
	scoreTexture = new QPixmap("ScoreScreen.png");
	scoreTextY = W_HEIGHT;
	score = 0;

	ReadHiScore();
}

//Läser från fil
int ScoreManager::ReadHiScore() const
{
	ifstream in("HiScores.txt");
	int hiScore;
	in >> hiScore;
	in.close();
	return hiScore;
}

//Skriver till fil
void ScoreManager::WriteHiScore(int _score) const
{
	ofstream out("HiScores.txt");
	out.clear();
	out << _score;
	out.close();
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


	painter.drawPixmap(0,0, W_WIDTH , W_HEIGHT, *darkenedLose);
	painter.drawPixmap(0, scoreTextY, W_WIDTH, W_HEIGHT, *scoreTexture);

	QString s = QString::number(score);
	QString hs = QString::number(ReadHiScore());

	painter.drawText(320, scoreTextY + 298, s);
	painter.drawText(320, scoreTextY + 366, hs);

	//Uppdaterar HiScore
	if (score > ReadHiScore())
	{
		WriteHiScore(score);
	}
}
