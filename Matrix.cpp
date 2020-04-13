#include <iostream>
#include <SDL.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Matrix.h"
#include "Pacman.h"

using namespace std;

void Matrix::creatMap() {
    for (int i =  XMIN; i <= XMAX; i++) {
        for (int j = YMIN; j <= YMAX; j++) {
            matrix[i][j] = SPACE;
        }
    }
}

void Matrix::drawWall(SDL_Renderer* renderer) {
    setColor(RED_COLOR, renderer);
    SDL_RenderDrawLine(renderer, XMIN-7, YMIN-7, XMIN-7, YMAX+7);
    SDL_RenderDrawLine(renderer, XMAX+7, YMIN-7, XMAX+7, YMAX+7);
    SDL_RenderDrawLine(renderer, XMIN-7, YMIN-7, XMAX+7, YMIN-7);
    SDL_RenderDrawLine(renderer, XMIN-7, YMAX+7, XMAX+7, YMAX+7);

    //SDL_RenderDrawLine(renderer, XMIN+(XMAX-XMIN)/2, YMIN, XMIN+(XMAX-XMIN)/2, YMAX);
}

void Matrix::drawMap(SDL_Renderer* renderer) {
    for (int i = XMIN; i <= XMAX; i+=10) {
        for (int j = YMIN; j <= YMAX; j+=10) {
            if (matrix[i][j] == SPACE) {
                setColor(RED_COLOR, renderer);
                SDL_RenderDrawPoint(renderer, i, j);
            }
        }
    }
}

void Matrix::menu(SDL_Renderer* renderer) {
    ToaDo Pac(XMIN, YMIN);
    SDL_Event e;

    /*setColor(WHITE_COLOR, renderer);
    SDL_RenderClear(renderer);

    drawWall(renderer);
    drawMap(renderer);

    SDL_RenderPresent(renderer);*/

    while (Pac.inside(XMIN, YMIN, XMAX, YMAX)) {
        Pac.move();

        setColor(WHITE_COLOR, renderer);
        SDL_RenderClear(renderer);

        drawWall(renderer);

        for (int i = XMIN; i <= XMAX; i+=10) {
            for (int j = YMIN; j <= YMAX; j+=10) {
                if (Pac.x != i && Pac.y != j) {
                    setColor(RED_COLOR, renderer);
                    SDL_RenderDrawPoint(renderer, i, j);
                }
            }
        }

        Pac.render(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(50);

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

