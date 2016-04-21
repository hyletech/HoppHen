#pragma once
#include "Platform.h"
#include "PlatformBreakable.h"
#include "Enemy.h"
#include "Ground.h"
#include <math.h>
#include <memory>
#include <ScoreManager.h>
#include <iostream>
#include <random>
#include "PlatformBreakable.h"
#include "PlatformNormal.h"

using namespace std;

class WorldManager
{
public:
	WorldManager(Player* _player, ScoreManager* _scoreManager);
	~WorldManager();

	void initPlatforms(int _yPos);
	void initEnemies();

	void Update();
	void paint(QPainter& painter) const;

	bool lose = false;
	void resetWorld();

private:
	std::vector<Enemy*> _enemies;
	std::vector<Platform*> _platforms;
	std::vector<PlatformBreakable*> _breakablePlatforms;

	Ground* ground;
	Player* player;
	ScoreManager* scoreManager;

	//Boundaries
	int bottomBoundary;
	int topBoundary;
	float worldSpeed;
};