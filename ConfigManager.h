#pragma once

#include <map>
#include <string>
#include <iostream>

#include <SDL.h>

using namespace std;

class ConfigManager
{
public:
	map<int, SDL_Texture*> m_models;

	void init(SDL_Renderer* renderer);
};