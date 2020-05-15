#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Pacman.h"
#include "Object.h"

using namespace std;

#define XMAX 850
#define YMAX 500
#define XMIN 400
#define YMIN 50
#define WALL 1
#define SPACE 0
#define DOT 2
#define LIFE 2
#define SCORE 1

class Matrix {
private:
    int matrix[XMAX+30][YMAX+30];
    PacObject Pac;
    GhostObject Ghost;
    LifeNumber Heart;
public:
    void GeneralHandling(SDL_Renderer* renderer, SDL_Event e);
    void creatMap();
    void drawMap(SDL_Renderer* renderer);
    void drawWall(SDL_Renderer* renderer);
    int random();
    void GhostAction();
    bool collision(int x1, int x2, int y1, int y2);
};

#endif
