#pragma once
#include <QPainter>
class ScoreManager
{
public:
	ScoreManager();
	~ScoreManager();

	void Update();
	void paint(QPainter& painter) const;

private:
	QPixmap* darkenedLose;
	QPixmap* scoreTexture;

	QRect* scoreTextRect;
	QRect* scoreRect;
	QRect* hiScoreRect;

};

