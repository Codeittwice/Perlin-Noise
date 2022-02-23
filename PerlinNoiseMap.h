#pragma once

#include <SDL.h>
#include <vector>
#include "Point.h"
#include <iomanip>
#include "defines.h"

class PerlinNoiseMap
{

public:

	PerlinNoiseMap();
	~PerlinNoiseMap();

	int NUMBER = 2;
	int map[ROWS][COLLS];
	Point points[ROWS][COLLS];
	/*
	SDL_Rect rect;
	SDL_Texture* texture;*/

	//vector<Point*> points;
	//vector<Point*> points2;

	float coefficient = 1920 / COLLS;

	void create();
	void loadPoints(int count, SDL_Renderer* renderer);
	void update();
	void draw(SDL_Renderer* renderer);
	void paintSurroundings(int c,int r, SDL_Renderer* renderer);

	void printMap();


	bool thereIs(int val);

};

