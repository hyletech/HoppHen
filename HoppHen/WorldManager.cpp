#include "WorldManager.h"
#include <math.h>

WorldManager::WorldManager()
{
	player = new Player();
	enemy = new Enemy();
	
	groundTexture = new QPixmap("Dirt.png");


	//WorldMovement
	worldSpeed = 0;

	//Boundaries
	bottomBoundary = W_HEIGHT + 50;
	topBoundary = -100;
}
WorldManager::WorldManager(Player* _player, Enemy* _enemy)
{
	//Ground
	//groundRect = new QRect(xPos, yPos, GROUND_WIDTH, GROUND_HEIGHT);

	player = _player;
	enemy = _enemy;
	//WorldMovement
	worldSpeed = 0;

	//Boundaries
	bottomBoundary = W_HEIGHT + 50;
	topBoundary = -100;
}

//Init of platforms
void WorldManager::initPlatforms()
{
	for (int i = 0; i < platFormCount; i++)
	{
		int xPos = rand() % (W_WIDTH - PF_WIDTH) + 1; 
		int yPos = i * platformYDistance;
		Platform* p = new Platform(xPos, yPos);
		platforms->push_back(*p);
	}
}

void WorldManager::Update(Player* _player)
{
	enemy->update(_player);
	player->Update();

	if (player->getYPos() > 0)
	{
		worldSpeed = -((player->getYPos()-W_HEIGHT)*2)*0.003;
	}
	/*if (player->getYPos < groundRect->getRect.top())
	{

	}*/
}

void WorldManager::initEnemies()
{
	//Funkade inte skapa ny enemy?
	/*
	for (int i = 0; i < enemieCount; i++)
	{
		int xPos = rand() % (W_WIDTH - E_WIDTH) + 1;
		int yPos = i * enemieYDistance;
		Enemy* e = new Enemy(xPos, yPos);

		enemies->push_back(*e);
	}
	*/
}

float WorldManager::getWorldSpeed()
{
	return worldSpeed;
}

void WorldManager::paint(QPainter& painter) const
{
	//painter.drawPixmap(groundRect->x(), groundRect->y(), GROUND_WIDTH, GROUND_HEIGHT, *groundTexture);
}
