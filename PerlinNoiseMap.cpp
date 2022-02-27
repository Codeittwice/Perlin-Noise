#include "PerlinNoiseMap.h"
#include <Windows.h>;
#include "ConfigManager.h"

extern ConfigManager cm;

PerlinNoiseMap::PerlinNoiseMap()
{
	//texture = NULL;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			map[i][j] = -1;
		}
	}


}

PerlinNoiseMap::~PerlinNoiseMap()
{
}

void PerlinNoiseMap::create()
{



}

void PerlinNoiseMap::loadPoints(int count ,SDL_Renderer* renderer)
{
	cm.init(renderer);
	D(coefficient);
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			points[i][j].load(renderer);
		}
	}

	Point* point;
	srand((unsigned)time(NULL));
	for (int i = 0; i < count; i++)
	{
		point = new Point();
		point->load(renderer);
		point->pointRect.x = (rand() % COLLS) * coefficient;
		point->pointRect.y = (rand() % ROWS) * coefficient;
		//D(point->pointRect.x);
		//D(point->pointRect.y);
		int y = point->pointRect.y / coefficient;
		int x = point->pointRect.x / coefficient;

		map[y][x] = 100;
		points[y][x] = *point;
		
		delete point;
	}

	//srand((unsigned)time(NULL));
	for (int m = 100; m > -1; m--)
	{
		for (int n = 0; n < 5; n++)
		{
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLLS; j++)
				{
					if (map[i][j] == m && map[i][j] != -1)
					{
						paintSurroundings(i, j, renderer);
					}
				}
			}
		}
	}
	

}

void PerlinNoiseMap::update()
{

}

void PerlinNoiseMap::draw(SDL_Renderer* renderer)
{
	float const multiply = float(1920) / float(ROWS + COLLS - 1);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			points[i][j].value = map[i][j];
			points[i][j].pointRect.x = j * coefficient; // (ROWS + COLLS - 1 - i + j)* coefficient / 1.0f * multiply;
			points[i][j].pointRect.y = i * coefficient; // (j + i)* coefficient / 4.0f;

			/*if (j == COLLS - 1) points[i][j].draw(renderer, 50);

			else if (i == ROWS - 1) points[i][j].draw(renderer, 50);

			else points[i][j].draw(renderer, i);*/
			points[i][j].draw(renderer, i);

		}
		SDL_RenderPresent(renderer);

		//Beep(500 + herz*2, 1);
	}
	SDL_RenderPresent(renderer);

}

void PerlinNoiseMap::paintSurroundings(int c, int r,SDL_Renderer* renderer)
{
	///Get Right
	if ((r + 1) <= COLLS && map[c][r + 1] == -1 && map[c][r] != -1)
	{  
		map[c][r + 1] = map[c][r] - 2;
		map[c][r + 1] += (rand() % 3);
		if (map[c][r + 1] > 100)
		{
			map[c][r + 1] = 100;
		}
		if (map[c][r + 1] < 0)
		{
			map[c][r + 1] = 0;
		}
	}

	///Get Left
	if ((r - 1) >= 0 && map[c][r - 1] == -1 && map[c][r] != -1)
	{
		map[c][r - 1] = map[c][r] - 2;
		map[c][r - 1] += (rand() % 3);
		if (map[c][r - 1] > 100)
		{
			map[c][r - 1] = 100;
		}
		if (map[c][r - 1] < 0)
		{
			map[c][r - 1] = 0;
		}
	}

	///Get Bottom
	if ((c + 1) <= ROWS && map[c + 1][r] == -1 && map[c][r] != -1)
	{
		map[c + 1][r] = map[c][r] - 2;
		map[c + 1][r] += (rand() % 3);
		if (map[c + 1][r] > 100)
		{
			map[c + 1][r] = 100;
		}
		if (map[c + 1][r] < 0)
		{
			map[c + 1][r] = 0;
		}
	}

	///Get Top
	if ((c - 1) >= 0 && map[c - 1][r] == -1 && map[c][r] != -1)
	{
		map[c - 1][r] = map[c][r] - 2;
		map[c - 1][r] += (rand() % 3);
		//D(map[c - 1][r]);
		if (map[c - 1][r] > 100)
		{
			map[c - 1][r] = 100;
		}
		if (map[c - 1][r] < 0)
		{
			map[c - 1][r] = 0;
		}
	}

}

void PerlinNoiseMap::printMap() {

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			//cout << setw(2);
			cout << (char)(/*140*/119 +  map[i][j]) << " ";
		}
		cout << endl;
	}


}

bool PerlinNoiseMap::thereIs(int val)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			if (map[i][j] == val) return true;
		}
	}
	return false;
}

unsigned int PerlinNoiseMap::randomNumber()
{
	unsigned int lfsr = 0xACE1u;
	unsigned int bit, t = 0;

	int* p = new int();
	t = t ^ (int)p;

	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;

	lfsr = ((bit << 15) | (lfsr >> 1) | t) % INT_MAX;

	while (lfsr < 0)
	{
		lfsr = lfsr + INT_MAX - 0;
	}

	return lfsr;
}