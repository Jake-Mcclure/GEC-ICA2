#pragma once
#include <HAPI_lib.h>
using namespace HAPISPACE;

class Graphics
{

protected:
	int screenWidth{1024}, screenHeight{768};
	BYTE* m_screen;
	
public:
	
	BYTE* textureData{ nullptr };
	int textureWidth = 64, textureHeight = 64;
	
	void Initialise();
	void LoadTexture(const std::string filelocation);
	void Blit(int posx, int posy);
	void ClearScreenToColour(HAPI_TColour col);


};

