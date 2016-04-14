#pragma once
#include "Platform.h"
#include <math.h>

class WorldManager
{
public:
	WorldManager();
	~WorldManager();
	
	void changeSpeed(int speed) { worldSpeed = speed; }
	void initPlatforms();

	std::list<Platform>& getPlatforms() { return *platforms; }
	float getWorldSpeed()		const { return worldSpeed; }
	float getSpeedDecrease()	const { return speedDecrease; }
	float getScore()			const { return score; }
	float getHeight()			const { return height; }


private:
	std::list<Platform> *platforms; //Byta ut till vector? Gör det som du kan bäst

	float worldSpeed;
	float speedDecrease;
	float score;
	float height;

	int platFormCount     = 10;
	int platformYDistance = 100;
};