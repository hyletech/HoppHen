#pragma once
#include "Platform.h"
#include "Enemy.h"
#include "Ground.h"
#include <math.h>
#include <memory>

class WorldManager
{
public:
	WorldManager(Player* _player);
	~WorldManager();

	void initPlatforms();
	void initEnemies();

	float getScore()	const { return score; }
	float getHeight()	const { return height; }

	void Update();
	void paint(QPainter& painter) const;

private:
	std::vector<Enemy*> _enemies;
	std::vector<Platform*> _platforms;


	Ground* ground;
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