#pragma once

#include <SDL.h>
#include <iostream>
#include <string>
#include "defines.h"

using namespace std;

class Point
{
public:
	Point();
	~Point();

	string image;

	SDL_FRect pointRect;
	SDL_Texture* pointTexture;
	SDL_Texture* orPointTexture;

	int value;

	void load(SDL_Renderer* renderer);
	void update();
	void draw(SDL_Renderer* renderer,int k);
};

