#include "Point.h"
#include "ConfigManager.h"

extern ConfigManager cm;

#include "PerlinNoiseMap.h"
extern PerlinNoiseMap terrain;


Point::Point()
{
}

Point::~Point()
{
}


void Point::load(SDL_Renderer* renderer)
{

	pointRect.w = (float)(1920.0f / (float)(COLLS));
	pointRect.h = (float)(1080.0f / (float)(ROWS));
	
	value = -1;
}

void Point::update()
{
}

void Point::draw(SDL_Renderer* renderer,int k)
{
	//SDL_RenderClear(renderer);
	int K = 0 ;// (5 - terrain.NUMBER);
	int valueModifier = 5;
	if (k != 50) k = value;

	pointRect.y += 250;
	pointRect.x += 0;
	if (value != -1)
	{
		pointRect.y -= value * valueModifier + K;
		//D(pointRect.w);
		//D(pointRect.h);
		
		pointRect.h += value * valueModifier;
		if (k == 50) {
			SDL_RenderCopyF(renderer, cm.m_models.at(k), NULL, &pointRect);
		}
		else {
			SDL_RenderCopyF(renderer, cm.m_models.at(value), NULL, &pointRect);
		}
		
		pointRect.h -= value * valueModifier;
		
		/*pointRect.w += 0.3f;
		if (value + 20 <= 100) SDL_RenderCopyF(renderer, cm.m_models.at(value + 20), NULL, &pointRect);
		pointRect.w -= 0.3f;*/
		//D(value);

		SDL_RenderCopyF(renderer, cm.m_models.at(value), NULL, &pointRect);
		//D(" ");
		pointRect.y += value * valueModifier + K;
	}
	//pointTexture = orPointTexture;

	//SDL_RenderPresent(renderer);
}
