#include "WorldManager.h"
#include <ctime>

WorldManager::WorldManager(Player* _player, ScoreManager* _scoreManager)
{
	srand(time(NULL));

	player = _player;
	scoreManager = _scoreManager;
	ground = new Ground();

	resetWorld();
	initEnemies();

}

void WorldManager::Update()
{
	//Random
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(10, 530);

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
			int xPos = dis(gen);
			_platforms[i]->setPos(topBoundary, xPos);
		}
	}

	//Flytta och uppdatera fiender samt kontrollera hitcheck
	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i]->startMove(worldSpeed);
		_enemies[i]->update(player);

		//Flyttar Fienden om den går under bottomboundary
		if (_enemies[i]->getRect()->y() > bottomBoundary)
		{
			_enemies.erase(_enemies.begin() + i);
			initEnemies();
		}

		if (player->getShots().size() > 0)
		{

			for (int e = 0; e < player->getShots().size(); e++)
			{
				if (_enemies[i]->getRect()->contains(player->getShots()[e]->getRect().x(), player->getShots()[e]->getRect().y()))
				{
					_enemies.erase(_enemies.begin() + i);
					initEnemies();
				}
			}
		}
		
	}

	//Uppdatera och flytta mark
	ground->startMove(worldSpeed);
	ground->update(player);

	//Lägg till score
	scoreManager->AddScore(worldSpeed);

	//ändra top boundary och bakgrund
	if (topBoundary > MAX_TOP_BONDARY)
	{
		topBoundary = -scoreManager->GetScore() * 0.1f;
	}

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
	if (!_enemies.size() == 0)
	{
		for_each(_enemies.begin(), _enemies.end(), std::default_delete<Enemy>());
		_enemies.clear();
	}
	Enemy* e = new Enemy(topBoundary - 400);
	_enemies.push_back(e);
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
