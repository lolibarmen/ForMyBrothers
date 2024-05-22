#include <main.h>


using json = nlohmann::json;


APP::APP() {
	X = 0;
	Y = 0;
	N = 1;
	ROWS = 100;
	COLS = 100;
}


void APP::LoadSetting() {
	std::fstream f("setting.json");
	json data = json::parse(f);
}


DIST::DIST (APP App) {
	ROWS = App.ROWS;
	COLS = App.COLS;
	array = new int* [ROWS];
    for (int i = 0; i < ROWS; ++i) {
        array[i] = new int[COLS];
    }
}


int DIST::CalcQ() {
    int Q = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            Q += array[i][j];
        }
    }
    return Q;
}


void DIST::LoadDistFromFile() {
	FILE * f = fopen("image.txt", "rb");

	for(int i = 0; i < ROWS; ++i) {
		for(int j = 0; j < COLS; ++j) {
			fread(&array[i][j], sizeof(int), 1, f);
		}
	}
    fclose(f);
}


void DIST::SaveDistToFile() {
	FILE * f = fopen("image2.txt", "wb");

	for(int i = 0; i < ROWS; ++i) {
		for(int j = 0; j < COLS; ++j) {
			fwrite(&array[i][j], sizeof(int), 1, f);
		}
	}
    fclose(f);
}


void DIST::PushZeroToDist() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            array[i][j] = 0;
        }
    }
}


int main() {

	APP App = APP(); // создание экземпляра приложения
	App.LoadSetting(); // загрузка настроек приложения

	DIST PerfDist = DIST(App);

	PerfDist.LoadDistFromFile();

	DIST CurrDist = DIST(App);
	CurrDist.PushZeroToDist();

	// инициализация переменных движка
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("Test", (App.ROWS + 4) * 8, (App.COLS + 4) * 8 + 4, 0, &window, &renderer);
	SDL_SetRenderScale(renderer, 8, 8);


	for(int iter = 0; iter < 500000; ++iter){
		// подготовка экрана
		SDL_SetRenderDrawColor(renderer, 43, 49, 64, 255);
		SDL_RenderClear(renderer);


		CurrDist.array[App.X][App.Y]++;
        int R = PerfDist.CalcQ();
		int Q = CurrDist.CalcQ();
        double maxP = INT_MIN;
        int newX = App.X;
        int newY = App.Y;
        int q = CurrDist.array[App.X][App.Y];
        for (int i = App.X - 1; i <= App.X + 1; ++i) {
            for (int j = App.Y - 1; j <= App.Y + 1; ++j) {
                if (i >= 0 && i < App.ROWS && j >= 0 && j < App.COLS && (i != App.X || j != App.Y)) {
                    double P = -1 * CurrDist.array[i][j] + PerfDist.array[i][j];

                    if (P > maxP) {
                    	maxP = P;
                        newX = i;
                        newY = j;	
					}
                }
            }
        }
        App.X = newX;
        App.Y = newY;

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderPoint(renderer, newX, newY);
		SDL_RenderPresent(renderer);	
    }
	
	CurrDist.SaveDistToFile();

	return 0;
}
