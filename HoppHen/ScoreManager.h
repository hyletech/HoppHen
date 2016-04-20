#pragma once
#include <QPainter>
#include <qfont.h>
#include <QTimer>
#include <ctime>
#include <qstring.h>
class ScoreManager
{
public:
	ScoreManager();
	~ScoreManager();

	void Update();
	void AddScore(float _scoreToAdd);
	void Reset();
	void paint(QPainter& painter) const;

private:
	QPixmap* darkenedLose;
	QPixmap* scoreTexture;

	QTimer* timer;
	float scoreTextY;
	int score;


	QRect* scoreRect;
	QRect* hiScoreRect;

};

