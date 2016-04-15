#include "WorldManager.h"

WorldManager::WorldManager()
{
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
	/*for (int i = 0; i < platforms->size; i++)
	{
		if (platforms[i])
	}*/
}

void WorldManager::paint(QPainter& painter) const
{
	//painter.drawPixmap(playerRect->x(), playerRect->y(), P_WIDTH, P_HEIGHT, *playerTexture);
}
