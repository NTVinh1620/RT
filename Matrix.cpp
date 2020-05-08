#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Matrix.h"
#include "Pacman.h"
#include "SDL_Utils.h"
#include "Object.h"

using namespace std;

int Matrix::random() {
    return rand() % 40;
}

bool Matrix::collision(int x1, int x2, int y1, int y2) {
    return ((x1 == x2 && y1 == y2));
}

void Matrix::creatMap() {
    for (int i = XMIN; i <= XMAX; i+=15) {
        for (int j = YMIN; j <= YMAX; j+=15) {
            matrix[i][j] = SPACE;
        }
    }

    for (int i = YMIN+60; i <= YMAX-60; i+=15) {
        matrix[XMIN+60][i] = WALL;
    }
    for (int i = YMIN+60; i <= YMAX-60; i+=15) {
        matrix[XMAX-60][i] = WALL;
    }
}

void Matrix::drawWall(SDL_Renderer* renderer) {
    setColor(BLUE_COLOR, renderer);

    SDL_RenderDrawLine(renderer, XMIN-10, YMIN-7, XMIN-10, YMAX+7); //left
    SDL_RenderDrawLine(renderer, XMAX+10, YMIN-7, XMAX+10, YMAX+7); //right
    SDL_RenderDrawLine(renderer, XMIN-10, YMIN-10, XMAX+10, YMIN-10); //up
    SDL_RenderDrawLine(renderer, XMIN-10, YMAX+10, XMAX+10, YMAX+10); //down

    SDL_RenderDrawLine(renderer, XMIN+60, YMIN+60, XMIN+60, YMAX-60);
    SDL_RenderDrawLine(renderer, XMAX-60, YMIN+60, XMAX-60, YMAX-60);
}

void Matrix::drawMap(SDL_Renderer* renderer) {
    for (int i = XMIN; i <= XMAX; i+=15) {
        for (int j = YMIN; j <= YMAX; j+=15) {
            if (matrix[i][j] == SPACE) {
                setColor(RED_COLOR, renderer);
                SDL_RenderDrawPoint(renderer, i, j);
                matrix[Pac.x][Pac.y] = DOT;
            }
        }
    }
}

void Matrix::GhostAction() {
    switch (random()) {
        case 2: Ghost.turnLeft();
            break;
        /*case 4: Ghost.turnRight();
            break;
        case 8: Ghost.turnDown();
            break;
        case 12: Ghost.turnUp();
            break;
        default: break;*/
    }
}

void Matrix::menu(SDL_Renderer* renderer, SDL_Event e) {
    Pac.x = XMIN;
    Pac.y = YMIN;

    Ghost.x = XMAX;
    Ghost.y = YMAX;

    Heart.x = XMAX+100;
    Heart.y = YMIN;

    creatMap();
    int life = LIFE;

    while (true) {
        bool col = collision(Pac.x, Ghost.x, Pac.y, Ghost.y);
        cout << Pac.x << " " << Pac.y << endl;
        cout << Ghost.x << " " << Ghost.y << endl << endl;
        if (col) {
            Pac.x = XMIN;
            Pac.y = YMIN;
            Ghost.x = XMAX;
            Ghost.y = YMAX;

            life--;
            SDL_Delay(500);
        }
        if (life == 0) break;

        setColor(BLACK_COLOR, renderer);
        SDL_RenderClear(renderer);

        Pac.movePac();
        Ghost.moveGhost();

        Pac.render(renderer);
        Ghost.render(renderer);
        Heart.render(renderer);

        if (matrix[Pac.x-15][Pac.y] == WALL && e.key.keysym.sym == SDLK_LEFT) {
            Pac.stop();
        }
        if (matrix[Pac.x+15][Pac.y] == WALL && e.key.keysym.sym == SDLK_RIGHT) {
            Pac.stop();
        }
        if (matrix[Pac.x][Pac.y-15] == WALL && e.key.keysym.sym == SDLK_UP) {
            Pac.stop();
        }
        if (matrix[Pac.x][Pac.y+15] == WALL && e.key.keysym.sym == SDLK_DOWN) {
            Pac.stop();
        }

        drawWall(renderer);
        drawMap(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(100);

        if (e.type == SDL_QUIT) break;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT: Pac.turnLeft();
                        break;
                    case SDLK_RIGHT: Pac.turnRight();
                        break;
                    case SDLK_DOWN: Pac.turnDown();
                        break;
                    case SDLK_UP: Pac.turnUp();
                        break;
                    default: break;
                }
            }
        }

        GhostAction();

        if (matrix[Pac.x-15][Pac.y] == WALL && e.key.keysym.sym == SDLK_LEFT) {
            Pac.stop();
        }
        if (matrix[Pac.x+15][Pac.y] == WALL && e.key.keysym.sym == SDLK_RIGHT) {
            Pac.stop();
        }
        if (matrix[Pac.x][Pac.y-15] == WALL && e.key.keysym.sym == SDLK_UP) {
            Pac.stop();
        }
        if (matrix[Pac.x][Pac.y+15] == WALL && e.key.keysym.sym == SDLK_DOWN) {
            Pac.stop();
        }
    }
    waitUntilKeyPressed();
}
