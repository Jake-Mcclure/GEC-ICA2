#pragma once
#include "Entity.h"
#include "Projectile.h"

class Enemy : public Entity
{
private:
	Vector2 Direction{ 1, 0};
	void Shoot();
	void Move();

public:

	void Update() override;
	void Render(BYTE* screen) override;
	void ChangeDirection(Vector2 newdirection);

	Enemy(const std::string &filename, Vector2 pos);
};

