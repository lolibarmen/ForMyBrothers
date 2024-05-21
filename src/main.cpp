#include <main.h>


using json = nlohmann::json;


void APP::LoadSetting() {
	std::fstream f("setting.json");
	json data = json::parse(f);

	this->PerfDistFileName = data["PerfDistFileName"];
}


void LoadDestribut() {
		
}


int main() {

	APP App = APP(); // создание экземпляра приложения

	App.LoadSetting(); // загрузка настроек приложения
	
	App.LoadDestribut();

	return 0;
}
