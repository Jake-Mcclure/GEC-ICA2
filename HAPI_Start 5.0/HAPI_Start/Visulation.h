#pragma once
#include <HAPI_lib.h>
#include <unordered_map>
#include "Texture.h"
using namespace HAPISPACE;
class Visulation
{
public:
	void clearToColour(HAPI_TColour col);
	void drawTexture(const std::string& name, int posx,int posy,bool fast);
	bool Initialise(int screenwidth, int screenheight);
	bool LoadTexture(const std::string& filename, const std::string& name);

protected:
	std::unordered_map<std::string, Texture*> m_texturemap;
	int m_screenWidth, m_screenHeight;
	BYTE* m_screen{nullptr};

};

