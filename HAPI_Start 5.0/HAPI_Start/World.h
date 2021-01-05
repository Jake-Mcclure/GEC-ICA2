#pragma once
#include <HAPI_lib.h>
#include "Visulation.h" 
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"


class World
{
private:
	const DWORD m_kTickTime = 1000 / 50;
	DWORD m_lastTimeUpdated = HAPI.GetTime();
	int m_width = 1024;
	int m_height = 768;
	Visulation* Game = new Visulation();
	const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
	Player m_player = Player("Data//Player_Up.tga", { m_width / 2, m_height / 2 });;
	BYTE* m_screen;
	std::vector<Entity*> entities;

public:
	void Update();
	void Initialise();
	void Render();
	void CheckEnemyCollisions(std::vector<Entity*> entity);

};
