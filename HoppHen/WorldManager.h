#pragma once
#include "Platform.h"
#include "Enemy.h"
#include "Ground.h"
#include <math.h>
#include <memory>
#include <ScoreManager.h>

class WorldManager/*: public HoppHen*/
{
public:
	WorldManager(Player* _player, ScoreManager* _scoreManager);
	~WorldManager();

	void initPlatforms();
	void initEnemies();
	void initWorld();

	float getScore()	const { return score; }
	float getHeight()	const { return height; }
//	void LoseGame() { HoppHen::LoseGame(); };

	void Update();
	void paint(QPainter& painter) const;

	bool lose = false;
	void resetWorld();

private:
	std::vector<Enemy*> _enemies;
	std::vector<Platform*> _platforms;


	Ground* ground;
	Player* player;
	ScoreManager* scoreManager;

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