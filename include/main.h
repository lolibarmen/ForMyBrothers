#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <nlohmann/json.hpp>
#include <SDL3/SDL.h>
// #include <SDL3_image/SDL_image.h>

class APP // Program - класс программы, содержит все переменные и функции для работы программы
{
	public:
		APP();

		void LoadSetting();
		void LoadDestribut();
		
		int N;
		int X;
		int Y;
		int ROWS;
		int COLS;
};

class DIST // Distribution - класс распределения, содержит все переменные и функции для работы с распределениями
{
	public:
		DIST(APP);

		void LoadDistFromFile();
		void SaveDistToFile();
		void PushZeroToDist();
		int CalcQ();

		int ROWS;
		int COLS;
		int** array;
};
