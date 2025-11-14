#include <SDL3/SDL.h>
#include "Graphics.h"
extern SDL_Renderer* renderer;

Graphics::Graphics() : InitX(0), InitY(0) {}

int Graphics::SetInitialPosition(int x, int y) {
	InitX = x;
	InitY = y;
	return 0;
}
void Graphics::DrawRect(int RelativePosition) {
	int w = 10; //later change it as to size of rectangle i need.
	int h = 10;
	SDL_FRect rect = { InitX + 10*RelativePosition, InitY, w, h }; //For now just moving in X axis
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}

//class graphics {
//public:
//	int InitX, InitY;
//
//	int SetInitialPosition(int x, int y) {
//		InitX = x;
//		InitY = y;
//		return 0;
//	}
//
//	void DrawRect(int RelativePosition) {
//		int w = 10; //later change it as to size of rectangle i need.
//		int h = 10;
//		SDL_FRect rect = { InitX + 10*RelativePosition, InitY, w, h }; //For now just moving in X axis
//
//		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//		SDL_RenderFillRect(renderer, &rect);
//	}
//};