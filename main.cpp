#include <iostream>
#include <SDL.h>

#include "PerlinNoiseMap.h"
#include "ConfigManager.h"

#undef main

SDL_Window* window = SDL_CreateWindow("Perlin Noise", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, 0);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
SDL_Texture* texture;

PerlinNoiseMap terrain;
PerlinNoiseMap noise1;
PerlinNoiseMap noise2;
PerlinNoiseMap noise3;
ConfigManager cm;

void initWorld()    ///OK
{

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Surface* loadSurface = SDL_LoadBMP("img//blue.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, loadSurface);
    SDL_FreeSurface(loadSurface);


}

void drawWorld()     ///OK
{
    //SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, texture, NULL, NULL);
    
    //SDL_RenderPresent(renderer);

}

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    initWorld();

    terrain.loadPoints(20 , renderer);
    //noise1.loadPoints(60 , renderer);
    D("map1 ready ...");
    
    noise2.loadPoints(1 , renderer);
    D("map2 ready ...");
    noise3.loadPoints(10 , renderer);
    D("map3 ready ...");


    int a = 3, b = 1, c = 1;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLLS; j++)
        {
            terrain.map[i][j] = (a * terrain.map[i][j] + b * noise2.map[i][j] + c * noise3.map[i][j]) / (a + b + c);
            if (terrain.map[i][j] < 0)  terrain.map[i][j] = 0;
        }
    }
    
    
    D("merging maps ready ...");
    //terrain.printMap();
    SDL_RenderClear(renderer);

    D("drawing ...");
    drawWorld();

    terrain.draw(renderer);
    /*for (int i = 0; i < 1; i++) {
        SDL_RenderClear(renderer);
        terrain.NUMBER = i;
        terrain.draw(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
    */
    D("Drawn ...");
    SDL_RenderPresent(renderer);
    
    SDL_Delay(50000000);
    return EXIT_SUCCESS;
}
