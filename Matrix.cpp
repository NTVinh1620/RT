#include <iostream>
#include <SDL.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Matrix.h"
#include "Pacman.h"
#include "SDL_Utils.h"

using namespace std;

void Matrix::creatMap() {
    for (int i = XMIN; i <= XMAX; i++) {
        for (int j = YMIN; j <= YMAX; j++) {
            matrix[i][j] = SPACE;
        }
    }
    for (int i = YMIN+20; i <= YMAX-20; i++) {
        matrix[i][XMIN+(XMAX-XMIN)/2] = WALL;
    }
}

void Matrix::drawWall(SDL_Renderer* renderer) {
    setColor(BLUE_COLOR, renderer);
    /*SDL_RenderDrawLine(renderer, XMIN-7, YMIN-7, XMIN-7, YMAX+7); //left
    SDL_RenderDrawLine(renderer, XMAX-3, YMIN-7, XMAX-3, YMAX+7); //right
    SDL_RenderDrawLine(renderer, XMIN-7, YMIN-7, XMAX-3, YMIN-7); //up
    SDL_RenderDrawLine(renderer, XMIN-7, YMAX+7, XMAX-3, YMAX+7); //down*/

    SDL_RenderDrawLine(renderer, XMIN-7, YMIN-7, XMIN-7, YMAX+7); //left
    SDL_RenderDrawLine(renderer, XMAX+7, YMIN-7, XMAX+7, YMAX+7); //right
    SDL_RenderDrawLine(renderer, XMIN-7, YMIN-7, XMAX+7, YMIN-7); //up
    SDL_RenderDrawLine(renderer, XMIN-7, YMAX+7, XMAX+7, YMAX+7); //down

    SDL_RenderDrawLine(renderer, XMIN+(XMAX-XMIN)/2+2, YMIN+38, XMIN+(XMAX-XMIN)/2+2, YMAX-38);
}

void Matrix::drawMap(SDL_Renderer* renderer) {
    for (int i = XMIN; i <= XMAX; i+=15) {
        for (int j = YMIN; j <= YMAX; j+=15) {
            if (matrix[i][j] == SPACE) {
                setColor(RED_COLOR, renderer);
                SDL_RenderDrawPoint(renderer, i, j);
            }
            matrix[Pac.x][Pac.y] = DOT;
        }
    }
}

void Matrix::menu(SDL_Renderer* renderer) {
    SDL_Event e;

    Pac.x = XMIN;
    Pac.y = YMIN;

    while (Pac.inside(XMIN, YMIN, XMAX, YMAX)) {
        Pac.move();

        setColor(BLACK_COLOR, renderer);
        SDL_RenderClear(renderer);

        drawWall(renderer);

        drawMap(renderer);

        Pac.render(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(65);

        if (SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE:
        		    break;
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
    waitUntilKeyPressed();
}

