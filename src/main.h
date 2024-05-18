#pragma once

#include <stdio.h>

class PROG // Program - класс программы, содержит все переменные и функции для работы программы
{
	public:
		int LoadSetting();
}

class DIST // Distribution - класс распределения, содержит все переменные и функции для работы с распределениями
{
	public:
		int LoadFile();
		int LoadFromFile();
}
