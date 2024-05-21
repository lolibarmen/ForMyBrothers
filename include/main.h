#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

class APP // Program - класс программы, содержит все переменные и функции для работы программы
{
	public:
		void LoadSetting();
		void LoadDestribut();
	
	private:
		std::string PerfDistFileName;
		
};

class DIST // Distribution - класс распределения, содержит все переменные и функции для работы с распределениями
{
	public:
		int LoadFile();
		int LoadFromFile();
};
