#include "Projectile.h"

void Projectile::Shoot(Vector2 pos, int rotation)
{
	switch (rotation)
	{
	case  0:
		m_Direction = { 0,-1 };
		isActive = true;
		pos.x += 25;
		pos.y -= 25;
		m_position = pos;
		break;

	case 90:
		m_Direction = { -1,0 };
		isActive = true;
		pos.x += 50;
		pos.y += 25;
		RotateImage(rotation);
		m_position = pos;
		break;

	case 180:
		m_Direction = { 0,1 };
		isActive = true;
		pos.x += 25;
		pos.y += 50;
		RotateImage(rotation);
		m_position = pos;
		break;

	case 270:
		m_Direction = { 1,0 };
		isActive = true;
		pos.x += 50;
		pos.y += 25;
		RotateImage(rotation);
		m_position = pos;
		break;
	default:
		break;
	}
	
}

void Projectile::Move()
{
	if (isActive == true && GetAlive())
	{
		if (m_position.y <= 0)
		{
			isActive = false;
		}
		else if(m_position.x <= 0)
		{
			isActive = false;
		}
		else
		{
			m_position.y += m_Direction.y;
			m_position.x += m_Direction.x;
		}
	}
}

void Projectile::SetActive(bool activestate)
{
	isActive = activestate;
}

bool Projectile::GetActive()
{
	return isActive;
}

void Projectile::Update()
{
	
	Move();
}

Projectile::Projectile(const std::string& fileName, Vector2 newpos) : Entity(fileName,newpos,Neutral, 20)
{
}
