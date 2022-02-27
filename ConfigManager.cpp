#include "ConfigManager.h"
#include "defines.h"

void ConfigManager::init(SDL_Renderer* renderer)
{
	string image;
	for (int i = 0; i <= 100; i++)
	{

		image = "white.bmp";
		image = "img//" + image;

		SDL_Surface* loadSurface = SDL_LoadBMP(image.c_str());

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadSurface);
		SDL_FreeSurface(loadSurface);

		
		int r = 255 - (int)(2.55 * double(i));
		//cout << i << " - " << r << endl;
		SDL_SetTextureColorMod(texture, r, r, r);
		
		/*
		int r = 255 - (int)(2.55 * double(i));
		if (i < 40)
		{
			SDL_SetTextureColorMod(texture, 0, 0, 205 + r);
		}
		else if (i > 39 && i < 41)
		{
			SDL_SetTextureColorMod(texture, 100 + r, 100 + r, 0);
		}
		else if (i > 40 && i < 80)
		{
			SDL_SetTextureColorMod(texture, 0, r - 40, 0);
		}
		else if (i > 79 && i < 90)
		{
			SDL_SetTextureColorMod(texture, r, r, r);
		}
		else if (i > 89 && i <= 100)
		{
			SDL_SetTextureColorMod(texture, 255,255, 255);
		}
		*/

		/// LAVA MAP
		/*
		int r = (int)(2.55 * double(i));
		if (i < 1)
		{

			SDL_SetTextureColorMod(texture, 255 - i, 102 - i, 0);
		}
		else if (i > 0 && i < 80)
		{
			SDL_SetTextureColorMod(texture, 20 - i / 4 , 20 - i / 4, 20 - i / 4);
		}
		else if (i > 79 && i < 90)
		{
			SDL_SetTextureColorMod(texture, 10, 10, 10);
		}
		else if (i > 89 && i <= 100)
		{
			SDL_SetTextureColorMod(texture, 0, 0, 0);
		}
		*/
		m_models.insert(pair<int, SDL_Texture*>(i, texture));
	}
}