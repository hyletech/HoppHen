#pragma once
#include <QPainter>
#include <qfont.h>
#include <QTimer>
#include <ctime>
#include <qstring.h>
#include <iostream>
#include <fstream>
class ScoreManager
{
public:
	ScoreManager();
	~ScoreManager();

	int ReadHiScore() const;
	void WriteHiScore(int _score) const;
	void Update();
	void AddScore(float _scoreToAdd);
	int GetScore(){ return score; };
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

