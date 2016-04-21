#include "WorldManager.h"
#include <ctime>

WorldManager::WorldManager(Player* _player, ScoreManager* _scoreManager)
{
	srand(time(NULL));

	player = _player;
	scoreManager = _scoreManager;
	ground = new Ground();

	//WorldMovement
	worldSpeed = 0;

	//Boundaries
	bottomBoundary = W_HEIGHT + 100;
	topBoundary = -100;

	resetWorld();
	initEnemies();

}

void WorldManager::Update()
{
	//Move world
	if (player->getRect()->y() > 0)
		worldSpeed = -((player->getRect()->y() - W_HEIGHT) * 2)*0.003;



	// (sätter till förlorarstate?) yup
	if (player->getRect()->y() > bottomBoundary)
	{
		lose = true;
	}

	//Gör att player flyttas med i världen
	player->update(worldSpeed);

	//Kontrollera vanliga plattformar
	for (int i = 0; i < _platforms.size(); i++)
	{
		_platforms[i]->startMove(worldSpeed);
		_platforms[i]->update(player);

		//Flyttar plattformen om den går under bottomboundary
		if (_platforms[i]->getRect().y() > bottomBoundary)
		{
			_platforms.erase(_platforms.begin() + i);
			initPlatforms(topBoundary);
		}
	}

	//Kontrollera breakable plattformar
	for (int i = 0; i < _breakablePlatforms.size(); i++)
	{
		_breakablePlatforms[i]->startMove(worldSpeed);
		_breakablePlatforms[i]->update(player);

		//Flyttar plattformen om den går under bottomboundary
		if (_breakablePlatforms[i]->getRect().y() > bottomBoundary)
		{
			_breakablePlatforms.erase(_breakablePlatforms.begin() + i);
			initPlatforms(topBoundary);
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
					player->getShots().erase(player->getShots().begin() + e);
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
		topBoundary = -scoreManager->GetScore();
	}
}

void WorldManager::resetWorld()
{
	//Tar bort ev platformar
	if (!_platforms.size() == 0)
	{
		for_each(_platforms.begin(), _platforms.end(), std::default_delete<Platform>());
		_platforms.clear();
	}
	for (int i = 0; i < PF_NUM_OF_PLATFORMS; i++)
	{
		int yPos = W_HEIGHT - (i * 100) - 200; 
		initPlatforms(yPos);
	}
 	initEnemies();
	ground->Reset();
	player->Reset();
	worldSpeed = 0;
}

void WorldManager::initPlatforms(int _yPos)
{
	//Random
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(10, 530);
	int xPos = dis(gen);

	uniform_int_distribution<> dis1(0,1);
	int rand = dis1(gen);
	if (rand == 1)
	{
		Platform* p = new Platform(xPos, _yPos);
		_platforms.push_back(p);
	}
	else
	{
		PlatformBreakable* p = new PlatformBreakable(xPos, _yPos);
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
	Enemy* e = new Enemy(topBoundary - 500);
	_enemies.push_back(e);
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
