#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <SDL.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Pacman.h"

using namespace std;

const int XMAX = 800;
const int YMAX = 500;
const int XMIN = 400;
const int YMIN = 50;
const int WALL = 1;
const int SPACE = 0;
const int DOT = 2;

struct ToaDo {
    int x;
    int y;
    int size = 5;
    int StepX = 0;
    int StepY = 0;

    void render(SDL_Renderer* renderer) {
        SDL_Rect filledRect;
        filledRect.x = x-size/2;
        filledRect.y = y-size/2;
        filledRect.w = size;
        filledRect.h = size;
        setColor(GREEN_COLOR, renderer);
        SDL_RenderFillRect(renderer, &filledRect);
    }

    void move() {
        x += StepX;
        y += StepY;
    }

    bool inside(int minX, int minY, int maxX, int maxY) {
        return (minX <= x && minY <= y && x+size <= maxX && y+size <= maxY);
    }

    void turnLeft() {
        StepX = -15;
        StepY = 0;
    }

    void turnRight() {
        StepX = 15;
        StepY = 0;
    }

    void turnDown() {
        StepX = 0;
        StepY = 15;
    }

    void turnUp() {
        StepX = 0;
        StepY = -15;
    }
};

class Matrix {
private:
    int matrix[XMAX+3][YMAX+3];
    ToaDo Pac;
public:
    void menu(SDL_Renderer* renderer);
    void creatMap();
    void drawMap(SDL_Renderer* renderer);
    void drawWall(SDL_Renderer* renderer);
};

#endif
