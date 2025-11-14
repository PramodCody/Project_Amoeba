//The Includes
#include <SDL3/SDL.h>
#include <iostream>

using namespace std;

//The Functions from GridLines.cpp
void InitialBG();
void UpdateGrid();

//the movements function from GridLines.cpp
void CheckInfiniteCondition();
void MoveRight();
void MoveLeft();
void MoveUp();
void MoveDown();



//Creating Window and Renderer
int width, height;
float w = 400, h = 300;
SDL_Window* window = SDL_CreateWindow("Project_Amoeba", w, h, SDL_WINDOW_FULLSCREEN);
SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);


int main(int argc, char* argv[]) {
    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return -1;
    }

	
	SDL_GetWindowSize(window, &width, &height);
	//w & h needs to be float for accurate division in Line.cpp
	w = width;
	h = height;

    //For Initial Grid
    InitialBG();
    UpdateGrid();


    //Keep Running
    bool running = true;
    SDL_Event event;

    while (running) {

        while (SDL_PollEvent(&event)) {
            switch (event.type) {

                case SDL_EVENT_KEY_DOWN:
                    if (event.key.key == SDLK_F4 && (event.key.mod & SDL_KMOD_ALT)) {
                        running = false;
                    }
                    
                    break;
            }
        }

        //The Movements wrt Amoeba
        const bool* state = SDL_GetKeyboardState(nullptr);

        if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
            CheckInfiniteCondition();
            MoveRight();
            UpdateGrid();
        }
        if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
            CheckInfiniteCondition();
            MoveLeft();
            UpdateGrid();
        }

        if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
            CheckInfiniteCondition();
            MoveUp();
            UpdateGrid();
        }
        if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
            CheckInfiniteCondition();
            MoveDown();
            UpdateGrid();
        }


        

        

        SDL_Delay(16); // ~60 FPS
    }

    //Ending Code
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}