#include "WorldManager.h"
#include <math.h>

WorldManager::WorldManager(Player* _player, Enemy* _enemy)
{
	//Ground
	groundRect = new QRect(GROUND_START_X, GROUND_START_Y, GROUND_WIDTH, GROUND_HEIGHT);

	initPlatforms();

	player = new Player();
	enemy = new Enemy();

	groundTexture = new QPixmap("Dirt.png");

	player = _player;
	enemy = _enemy;
	//WorldMovement
	worldSpeed = 0;

	//Boundaries
	bottomBoundary = W_HEIGHT + 50;
	topBoundary = -100;
}

////Init of platforms
//void WorldManager::initPlatforms()
//{
//	for (int i = 0; i < platFormCount; i++)
//	{
//		int xPos = rand() % (W_WIDTH - PF_WIDTH) + 1; 
//		int yPos = i * platformYDistance;
//		Platform* p = new Platform(xPos, yPos);
//		platforms->push_back(*p);
//	}
//}

void WorldManager::Update(Player* _player)
{
	enemy->update(_player);
	player->Update();

	if (player->getYPos() > 0)
	{
		worldSpeed = -((player->getYPos()-W_HEIGHT)*2)*0.003;
	}

	//Uppdatera plattformerna, samt hitcheck med spelare och plattform
	for (int i = 0; i < _platforms.size(); i++)
	{
		_platforms[i]->startMove(worldSpeed);
		_platforms[i]->Update(_player);
	}
	enemy->startMove(worldSpeed);

	/*if (player->getYPos < groundRect->getRect.top())
	{

	}*/
}

void WorldManager::initPlatforms()
{
#if 0 
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
#else
	//Random i x-led
	if (_platforms.size() == 0)
	{
		for (int i = 0; i < 20; i++)
		{
			int xPos = rand() % (W_WIDTH - PF_WIDTH - E_PADDING) + 1;
			int yPos = W_HEIGHT - (i * 100) - 200;
			Platform* p = new Platform(xPos, yPos);
			_platforms.push_back(p);
		}
	}
#endif
}


void WorldManager::paint(QPainter& painter) const
{
	//painter.drawPixmap(groundRect->x(), groundRect->y(), GROUND_WIDTH, GROUND_HEIGHT, *groundTexture);
	
	enemy->paint(painter);

	//Plattformer
	for (int i = 0; i < _platforms.size(); i++)
		_platforms[i]->paint(painter);

}
