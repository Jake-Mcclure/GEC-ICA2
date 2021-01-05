#pragma once
#include "Entity.h"

class Projectile : public Entity
{
private:
	int m_speed;
	bool isActive{ false };
	Vector2 m_Direction{0,-1};

public:
	void Shoot(Vector2 pos,int rotation);
	void Move();
	void SetActive(bool activestate);
	void Update() override;
	
	bool GetActive();
	
	Projectile(const std::string& fileName, Vector2 newpos);
};

