#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <algorithm>
#include <time.h>
#include "ht_types.h"

class HuskySTD
{
public:
	//copies from array1 into array2
	//static bool addArrayTile(Tile *array1, int size, Tile new_tile);
	//static bool tile_memcpy(Tile* dst, Tile* src, size_t size);


	static Point generateRectFromArea(int area);

	//finds the position in a rect from an integer, using right to left, top to bottom. x is -1 if not in bounds
	static Point getPointFromRectInt(int position, Point rect);

	//static int* genCardinalArray(int max);


	template<typename T>
	static void shuffleArray(T arr[], size_t size);
	template<typename T>
	static void swap(T* a, T* b);
};

template<typename T>
inline void HuskySTD::shuffleArray(T arr[], size_t size)
{
	srand(time(NULL));
	//fisher yates algorithm
	for (int i = size - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(&arr[i], &arr[j]);
	}
}

template<typename T>
inline void HuskySTD::swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}
