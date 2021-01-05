#pragma once
#include "Graphics.h"
#include "Texture.h"

struct Vector2
{
	int x;
	int y;
};

enum Sides
{
	Neutral = 0,
	Friendly = 1,
	Enemies = 2
};

class Entity 
{

private:
	

protected:
	Sides m_side;
	Texture m_texture;
	int m_health;
	Vector2 m_position{ 0,0 };
	int m_Rotation{0};
	bool m_isAlive = true;
	
public:
	void RotateImage(int theta);
	void SetPosition(Vector2 newpos);
	void SetSide(Sides side);
	void SetAlive(bool state);

	void CheckCollision(Entity& other);

	Sides GetSide();
	Vector2 GetPosition();
	bool GetAlive();
	virtual void Update() = 0;
	virtual void Render(BYTE* screen);
	
	Entity(const std::string& fileName, Vector2 newpos,Sides side, int health);
};

