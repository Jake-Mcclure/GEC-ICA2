#include "Player.h"
#include "Projectile.h"

std::vector<Projectile*> Player::GetProjectiles()
{
	return m_bullets;
}

void Player::Shoot()
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		if (m_bullets[i]->GetActive() == false)
		{
			if (m_hasShot >= 100)
			{
				m_bullets[i]->Shoot(m_position, m_Rotation);
				m_hasShot = 0;
				//std::cout << "hasshot = true" << std::endl;
			}
		}
	}
	
}

void Player::Move()
{
	if (m_currentDirection.y == -1)
	{
		if (m_position.y > 0)
			m_position.y += m_currentDirection.y;
	}
	if (m_currentDirection.y == 1)
	{
		if (m_position.y < 768 - m_texture.GetHeight())
			m_position.y += m_currentDirection.y;
	}
	if (m_currentDirection.x == -1)
	{
		if (m_position.x > 0)
			m_position.x += m_currentDirection.x;
	}
	if (m_currentDirection.x == 1)
	{
		if (m_position.x < 1024 - m_texture.GetWidth())
			m_position.x += m_currentDirection.x;
	}
}

void Player::Render(BYTE* screen)
{
	if (m_isAlive)
	{
		m_texture.Render(screen, m_position.x, m_position.y);
		for (int i = 0; i < m_bullets.size(); i++)
		{
			if (m_bullets[i]->GetActive() && m_bullets[i]->GetAlive())
			{
				m_bullets[i]->Render(screen);
			}
		}
	}
}

void Player::Update()
{
	if (m_isAlive)
	{
		Move();
		for (int i = 0; i < m_bullets.size(); i++)
		{
		//	std::cout << "Bullet " << i << " is " << m_bullets[i].GetAlive() << std::endl;
			m_bullets[i]->Update();
		}
		m_hasShot += 1;
	}
}

void Player::SetDirection(Vector2 direction)
{
	m_currentDirection = direction;
}

Player::Player(const std::string& fileName, Vector2 newpos) : Entity(fileName, newpos, Friendly,150)
{
	for (int i = 0; i < 10; i++)
	{
		Projectile* proj = new Projectile("Data//Projectile.png", m_position);
		m_bullets.push_back(proj);
		m_bullets[i]->SetSide(Friendly);
	}
}
