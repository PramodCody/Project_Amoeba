#include "Line.h"
#include <SDL3/SDL.h>

void check( );

//To Calculate The GridLines Position
int countR = 0;
int countL = 0;
int countU = 0;
int countD = 0;
int m = 3; //movement speed

//Defining Line Class
extern float w, h;
extern SDL_Window* window;
extern SDL_Renderer* renderer;


Line::Line() : x1(0), y1(0), x2(0), y2(0) {}
void Line::draw_line(int a1, int b1, int a2, int b2) {
	x1 = a1;
	y1 = b1;
	x2 = a2;
	y2 = b2;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 50);
	SDL_RenderLine(renderer, x1, y1, x2, y2);

}

// Creating Line Objects

//vertical lines
int nv = 8;
Line Lv[9];

//horizental lines
int nh = 6;
Line Lh[7];


// For Initial Lines
void InitialBG() {
    
    float a = w / (nv+1);
    //vertical lines
    for (int i = 0; i <= nv; i++) {
        Lv[i].draw_line((i + 1) * a, 0, (i + 1) * a, h);
    }

    float b = h / (nh + 1);
    //horizental lines
    for (int i = 0; i <= nh; i++) {
        Lh[i].draw_line(0, (i + 1) * b, w, (i + 1) * b);
    }

}

//Checking right condition to spawn a new line in X or Y axis
void CheckInfiniteCondition() {

    //X axis
    for (int i = 0; i <= nv; i++) {

        if (Lv[i].x1 < 0 || Lv[i].x2 < 0) {
            Lv[i].x1 = w;
            Lv[i].x2 = w;
        }

        else if (Lv[i].x1 > w || Lv[i].x2 > w) {
            Lv[i].x1 = 0;
            Lv[i].x2 = 0;
        }
    }

    //Y axis
    for (int i = 0; i <= nh; i++) {

        if (Lh[i].y1 > h || Lh[i].y2 > h) {
            Lh[i].y1 = 0;
            Lh[i].y2 = 0;
        }

        else if (Lh[i].y1 < 0 || Lh[i].y2 < 0) {
            Lh[i].y1 = h;
            Lh[i].y2 = h;
        }
    }
}

//Resized Lines New Position Calculation
void ResizedValue() {

    //vertical lines
    for (int i = 0; i <= nv; i++) {
        Lv[i].x1 -= countR * m;
        Lv[i].x2 -= countR * m;
    }

    //horizental lines
    for (int i = 0; i <= nh; i++) {
        Lh[i].y1 += countU * m;
        Lh[i].y2 += countU * m;
    }
}

//TO Update Line Coordinates
void UpdateGrid() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //vertical lines
    for (int i = 0; i <= nv; i++) {
        Lv[i].draw_line(Lv[i].x1, Lv[i].y1, Lv[i].x2, Lv[i].y2);
    }

    //horizental lines
    for (int i = 0; i <= nh; i++) {
        Lh[i].draw_line(Lh[i].x1, Lh[i].y1, Lh[i].x2, Lh[i].y2);
    }

    check( );

    SDL_RenderPresent(renderer);
}

//Move GridLines in different direction wrt Amoeba

void MoveRight() {
    countR += 1;

    for (int i = 0; i <= nv; i++) {
        Lv[i].x1 -= m;
        Lv[i].x2 -= m;
    }
}

void MoveLeft() {
    countL += 1;

    for (int i = 0; i <= nv; i++) {
        Lv[i].x1 += m;
        Lv[i].x2 += m;
    }
}

void MoveUp() {
    countU += 1;

    for (int i = 0; i <= nh; i++) {
        Lh[i].y1 += m;
        Lh[i].y2 += m;
    }
}

void MoveDown() {
    countD += 1;

    for (int i = 0; i <= nh; i++) {
        Lh[i].y1 -= m;
        Lh[i].y2 -= m;
    }
}