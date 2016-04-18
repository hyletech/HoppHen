#include "ScoreManager.h"
#include "defines.h"

ScoreManager::ScoreManager()
{
	darkenedLose = new QPixmap("DarkenedLose.png");
	scoreTexture = new QPixmap("ScoreScreen.png");
}


ScoreManager::~ScoreManager()
{
}

void ScoreManager::Update()
{

}

void ScoreManager::paint(QPainter& painter) const
{
	painter.drawPixmap(0,0, W_WIDTH , W_HEIGHT, *darkenedLose);
}
