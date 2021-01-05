#include "Entity.h"

void Entity::Render(BYTE* screen)
{
	if (m_isAlive)
	{
		m_texture.AlphaBlit(screen, m_position.x, m_position.y);
	}
}

void Entity::RotateImage(int theta)
{
	int temp = m_Rotation;
	if (theta == m_Rotation)
	{
		return;
	}
	else if (theta > m_Rotation)
	{
		m_Rotation = theta;
		theta = theta - temp;
		
	}
	else
	{
		m_Rotation = theta;
		theta = (360 - temp) + theta;
		
	}
	//std::cout << theta << "  " << m_Direction << std::endl;
	m_texture.RotateImage(theta);
}

void Entity::SetPosition(Vector2 newpos)
{
	m_position = newpos;
}

void Entity::SetSide(Sides side)
{
	m_side = side;
}

void Entity::SetAlive(bool state)
{
	m_isAlive = state;
}

void Entity::CheckCollision(Entity& other)
{
	//checks if current is to the right of other
	if ((m_position.x >  other.m_position.x + other.m_texture.GetWidth() ||
		//checks if current is to the left of other
		m_position.x + m_texture.GetWidth() < other.m_position.x) ||
		//checks if current is above other
		(m_position.y + m_texture.GetHeight() < other.m_position.y) ||
		//checks if current is below other
		m_position.y > other.m_position.y + other.m_texture.GetHeight())
	{

	}
	else
	{
		if (m_side != Neutral && other.m_side != Neutral && m_side != other.m_side)
		{
			std::cout << "Opposite Collision" << std::endl;
			if (m_isAlive && other.m_isAlive)
			{
				int temp = m_health;
				m_health -= other.m_health;
				other.m_health -= temp;
				if (m_health <= 0)
				{
					m_isAlive = false;
				}
				if (other.m_health <= 0)
				{
					other.m_isAlive = false;
				}
			}
		}
		
	}
}

Sides Entity::GetSide()
{
	return m_side;
}

Vector2 Entity::GetPosition()
{
	return m_position;
	
}

bool Entity::GetAlive()
{
	return m_isAlive;
}

Entity::Entity(const std::string& fileName, Vector2 newpos,Sides side,int health):
	m_health(health),
	m_side(side),
	m_texture(fileName),
	m_position(newpos)
{
}
