#include "World.h"

void World::Update()
{
		Game->clearToColour(HAPI_TColour::BLACK);
		Game->drawTexture("Background", 0, 0, true);
		m_lastTimeUpdated = HAPI.GetTime() - m_lastTimeUpdated;
		if (m_lastTimeUpdated >= m_kTickTime)
		{
			Vector2 Direction{ 0,0 };
			bool HasShot = false;
			//Vector2 playerpos = m_player.GetPosition();
			if (KeyData.scanCode['W'])
			{
				Direction.y -= 1;
				m_player.RotateImage(0);
				//m_player = Player("Data//Player_Up.tga", { playerpos.x,playerpos.y });
			}
			if (KeyData.scanCode['S'])
			{
				Direction.y += 1;
				m_player.RotateImage(180);
				//m_player = Player("Data//Player_Down.tga", { playerpos.x,playerpos.y });
			}
			if (KeyData.scanCode['A'])
			{
				Direction.x -= 1;
				m_player.RotateImage(90);
				//m_player = Player("Data//Player_Left.tga", { playerpos.x,playerpos.y });
			}
			if (KeyData.scanCode['D'])
			{
				Direction.x += 1;
				m_player.RotateImage(270);
				//m_player = Player("Data//Player_Right.tga", { playerpos.x,playerpos.y });
			}

			if (KeyData.scanCode['F'] && HasShot == false)
			{
				m_player.Shoot();
				std::cout << "shoot" << std::endl;
				HasShot = true;
			}
			m_player.SetDirection(Direction);
			CheckEnemyCollisions(entities);

			//Update
			m_player.Update();

			for (auto& Enemy : entities)
			{
				Enemy->Update();
			}
			m_lastTimeUpdated = HAPI.GetTime();
		}
}

void World::Initialise()
{
	if (!Game->Initialise(m_width, m_height))
		return;

	if (!Game->LoadTexture("Data//spacebackground.tga", "Background"))
		return;

	if (!Game->LoadTexture("Data//alphaThing.tga", "Alphathing"))
		return;

	m_screen = HAPI.GetScreenPointer();
			
	HAPI.SetShowFPS(true);

	for (int y = 0; y < 4; y++)
	{
		for (int i = 0; i < 4; i++)
		{
			
			Enemy* enemy = new Enemy("Data//enemy.tga", { i * 64, y * 64 + 10 });
			entities.push_back(enemy);
		}
	}
	//m_player = Player("Data//Player_Up.tga", { m_width / 2, m_height / 2 });
}



void World::Render()
{
	int i = 0;
	m_player.Render(m_screen);
	
	for (auto& Enemy : entities)
	{
		Enemy->Render(m_screen);
		i++;
	}
}

void World::CheckEnemyCollisions(std::vector<Entity*> entity)
{
	for (auto& Enemy : entities)
	{
		if (Enemy->GetAlive())
		{
			m_player.CheckCollision(* Enemy);

		}
		for (auto& projectile:m_player.GetProjectiles())
		{
			if (projectile->GetActive())
			{
				projectile->CheckCollision(*Enemy);
			}
		}
	}
}
