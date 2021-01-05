#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;
class Texture
{
public:
	Texture(const std::string& fileName);
	void Render(BYTE* screen,int posx, int posy);
	void Blit(BYTE* screen, int posx, int posy);
	void AlphaBlit(BYTE* screen, int posx, int posy);
	void ClippingBlit(BYTE* screen, int screenwidth, int screenheight, int posx, int posy);
	void RotateImage(int theta);
	bool Create(const std::string& filename);

	int GetHeight();
	int GetWidth();

private:
	BYTE* m_textureData;
	int m_width;
	int m_height;
	
	
};

