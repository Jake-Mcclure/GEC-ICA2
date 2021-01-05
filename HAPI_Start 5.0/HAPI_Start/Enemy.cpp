#include "Enemy.h"

void Enemy::Move()
{
	//m_position.x += Direction.x;
	//m_position.y += Direction.y;
}

void Enemy::Shoot()
{
//	std::cout << "i shoot" << std::endl;
}

void Enemy::Update()
{
	Move();
	
	if (rand() % 100 <= 50)
	{
		Shoot();
	}
}

void Enemy::Render(BYTE* screen)
{
	if (m_isAlive)
	{
		m_texture.Render(screen, m_position.x, m_position.y);
	}
}

void Enemy::ChangeDirection(Vector2 newdirection)
{
	Direction = newdirection;
}

Enemy::Enemy(const std::string &filename, Vector2 pos) : Entity(filename,pos, Enemies, 20)
{
}
