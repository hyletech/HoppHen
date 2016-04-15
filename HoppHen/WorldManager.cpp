#include "WorldManager.h"

WorldManager::WorldManager()
{
	
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

void WorldManager::paint(QPainter& painter) const
{
	//painter.drawPixmap(playerRect->x(), playerRect->y(), P_WIDTH, P_HEIGHT, *playerTexture);
}
