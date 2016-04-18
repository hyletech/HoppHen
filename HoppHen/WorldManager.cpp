#include "WorldManager.h"
#include <ctime>

WorldManager::WorldManager(Player* _player)
{
	srand(time(NULL));

	initPlatforms();
	initEnemies();

	player = _player;
	ground = new Ground();

	//WorldMovement
	worldSpeed = 0;

	//Boundaries
	bottomBoundary = W_HEIGHT + 100;
	topBoundary = -100;
}

void WorldManager::Update()
{
	//Move world
	if (player->getYPos() > 0)
		worldSpeed = -((player->getYPos() - W_HEIGHT) * 2)*0.003;

	// (sätter till förlorarstate?)
	if (player->getYPos() > bottomBoundary)
	{
		lose = true;
	}


	//Gör att player flyttas med i världen
	player->startMoveWithWorld(worldSpeed);
	player->update();

	//Uppdatera plattformerna, samt hitcheck med spelare och plattform
	for (int i = 0; i < _platforms.size(); i++)
	{
		_platforms[i]->startMove(worldSpeed);
		_platforms[i]->update(player);
	}

	//Flytta och uppdatera fiender
	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i]->startMove(worldSpeed);
		_enemies[i]->update(player);
	}

	//Uppdatera och flytta mark
	ground->startMove(worldSpeed);
	ground->update(player);
}

void WorldManager::resetWorld()
{
	ground->Reset();
	player->Reset();
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
	//Tar bort ev platformar
	if (!_platforms.size() == 0)
		for_each(_platforms.begin(), _platforms.end(), std::default_delete<Platform>());

	//Skapar nya platforms och lägger till i vector
	for (int i = 0; i < PF_NUM_OF_PLATFORMS; i++)
	{
		int xPos = rand() % (W_WIDTH - PF_WIDTH - E_PADDING) + 1;
		int yPos = W_HEIGHT - (i * 100) - 200;
		Platform* p = new Platform(xPos, yPos);
		_platforms.push_back(p);
	}
	
#endif
}

void WorldManager::initEnemies()
{
	//Tar bort fiender om det finns
	if (!_enemies.size() == 0)
		for_each(_enemies.begin(), _enemies.end(), std::default_delete<Enemy>());
	
	//Skapar nya enemies och lägger till i list
	for (int i = 0; i < E_NUM_OF_ENEMIES; i++)
	{
		int yPos = -((i + 1) * 1500) + 1000;
		Enemy* e = new Enemy(yPos);
		_enemies.push_back(e);
	}

}

void WorldManager::paint(QPainter& painter) const
{
	player->paint(painter);

	//Plattformer
	for (int i = 0; i < _platforms.size(); i++)
		_platforms[i]->paint(painter);

	//Fiender
	for (int i = 0; i < _enemies.size(); i++)
		_enemies[i]->paint(painter);

	//Mark
	ground->paint(painter);
}
