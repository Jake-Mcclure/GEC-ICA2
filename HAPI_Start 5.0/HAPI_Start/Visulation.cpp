#include "Visulation.h"

void Visulation::clearToColour(HAPI_TColour col)
{
	for (int i = 0; i <m_screenWidth * m_screenHeight; i++)
	{
		memcpy(m_screen + i * 4, &col, 4);

	}
}

void Visulation::drawTexture(const std::string& name, int posx, int posy,bool fast)
{
	if (fast)
		m_texturemap[name]->Blit(m_screen,posx,posy);
	else 
		m_texturemap[name]->ClippingBlit(m_screen, m_screenWidth, m_screenHeight, posx, posy);
}

bool Visulation::Initialise(int screenwidth, int screenheight)
{
	if (!HAPI.Initialise(screenwidth, screenheight, "Milestone 4"))
	{
		return false;
	}
	m_screenHeight = screenheight;
	m_screenWidth = screenwidth;
	m_screen = HAPI.GetScreenPointer();
}

bool Visulation::LoadTexture(const std::string& filename, const std::string& name)
{
	Texture* newTexture = new Texture(filename);

	if (!newTexture->Create(filename))
	{
		delete newTexture;
		return false;
	}
	m_texturemap[name] = newTexture;
	return true;
}
