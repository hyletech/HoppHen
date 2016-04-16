#pragma once
#include "Platform.h"
#include "Enemy.h"
#include <math.h>

class WorldManager
{
public:
	WorldManager();
	WorldManager(Player* _player);
	~WorldManager();

	void changeSpeed(int speed) { worldSpeed = speed; }
	void initPlatforms();
	void initEnemies();

	std::list<Platform>& getPlatforms() { return *platforms; }
	std::list<Enemy>& getEnemies()		{ return *enemies; }
	float getWorldSpeed();
	float getSpeedDecrease()	const { return speedDecrease; }
	float getScore()			const { return score; }
	float getHeight()			const { return height; }

	void Update();
	void paint(QPainter& painter) const;

private:
	std::list<Platform> *platforms;
	std::list<Enemy> *enemies;

	Player* player;

	//Boundaries
	int bottomBoundary;
	int topBoundary;

	float speedDecrease;
	float score;
	float height;
	float worldSpeed;

	int platFormCount		= 10;
	int platformYDistance	= 100;
	int enemieCount			= 10;
	int enemieYDistance		= 100;

};