#include "WorldManager.h"

WorldManager::WorldManager()
{
	player = new Player();

	//WorldMovement
	worldSpeed = 0;

	//Boundaries
	bottomBoundary = W_HEIGHT + 50;
	topBoundary = -100;
}
WorldManager::WorldManager(Player* _player, Enemy* _enemy)
{
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

void WorldManager::Update()
{
	enemy->update();
	player->Update();

//	worldSpeed = (1/(player->getYPos()) * 5);
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
	//painter.drawPixmap(playerRect->x(), playerRect->y(), P_WIDTH, P_HEIGHT, *playerTexture);
}
