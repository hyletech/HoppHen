#include "WorldManager.h"
#include <ctime>

WorldManager::WorldManager(Player* _player, ScoreManager* _scoreManager)
{
	srand(time(NULL));

	initPlatforms();
	initEnemies();
	initWorld();

	player = _player;
	scoreManager = _scoreManager;
	ground = new Ground();
}

void WorldManager::Update()
{
	//Move world
	if (player->getYPos() > 0)
		worldSpeed = -((player->getYPos() - W_HEIGHT) * 2)*0.003;

	// (sätter till förlorarstate?) yup
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

		//Flyttar plattformen om den går under bottomboundary
		if (_platforms[i]->getRect().y() > bottomBoundary)
		{
			_platforms[i]->setPos(topBoundary);
		}
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

	//Lägg till score
	scoreManager->AddScore(worldSpeed);
}

void WorldManager::resetWorld()
{
	initPlatforms();
 	initEnemies();
	initWorld();
	ground->Reset();
	player->Reset();
}

void WorldManager::initPlatforms()
{
	//Tar bort ev platformar
	if (!_platforms.size() == 0)
	{
		for_each(_platforms.begin(), _platforms.end(), std::default_delete<Platform>());
		_platforms.clear();
	}

	//Skapar nya platforms och lägger till i vector
	for (int i = 0; i < PF_NUM_OF_PLATFORMS; i++)
	{
		int xPos = rand() % (W_WIDTH - PF_WIDTH - E_PADDING) + 1;
		int yPos = W_HEIGHT - (i * 100) - 200;
		Platform* p = new Platform(xPos, yPos);
		_platforms.push_back(p);
	}
}

void WorldManager::initEnemies()
{
	//Tar bort fiender om det finns
	if (!_enemies.size() == 0)
	{
		for_each(_enemies.begin(), _enemies.end(), std::default_delete<Enemy>());
		_enemies.clear();
	}
	
	//Skapar nya enemies och lägger till i list
	for (int i = 0; i < E_NUM_OF_ENEMIES; i++)
	{
		int yPos = -((i + 1) * 1500) + 1000;
		Enemy* e = new Enemy(yPos);
		_enemies.push_back(e);
	}

}

void WorldManager::initWorld()
{
	//WorldMovement
	worldSpeed = 0;

	//Boundaries
	bottomBoundary = W_HEIGHT + 100;
	topBoundary = -100;
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
