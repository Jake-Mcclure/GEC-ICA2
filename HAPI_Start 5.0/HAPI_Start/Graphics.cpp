#include "Graphics.h"
#include <HAPI_lib.h>

void Graphics::Initialise()
{
	if (!HAPI.Initialise(screenWidth, screenHeight, "Milestone 2"))
	{
		return;
	}
	m_screen = HAPI.GetScreenPointer();
}

void Graphics::LoadTexture(const std::string filelocation)
{
	if (!HAPI.LoadTexture(filelocation, &textureData, textureWidth, textureHeight))
	{
		std::cout << "File not found!" << std::endl;
		return;

	}
}

void Graphics::Blit(int posx, int posy)
{
	auto* pntr = HAPI.GetScreenPointer();
	for (int newY = 0; newY < textureHeight; newY++)
	{
		
			int offset = (screenWidth * (posy + newY) + posx) * 4;
			int textureOffset = textureHeight * newY * 4;
			
			memcpy(pntr + offset, textureData + textureOffset, textureWidth * 4);
		
	}
}

void Graphics::ClearScreenToColour(HAPI_TColour col)
{
	for (int i = 0; i < screenWidth * screenHeight; i++)
	{
		memcpy(m_screen + i * 4, &col, 4);

	}

}



