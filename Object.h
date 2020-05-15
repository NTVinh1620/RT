#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Pacman.h"
#include "Matrix.h"
#include <vector>

using namespace std;

#define XMAX 850
#define YMAX 500
#define XMIN 400
#define YMIN 50

extern SDL_Texture* texturePac;
extern SDL_Texture* textureGhost;
extern SDL_Texture* textureHeart;
extern SDL_Surface* surfacePac;
extern SDL_Surface* surfaceGhost;
extern SDL_Surface* surfaceHeart;

struct PacObject {
    int x;
    int y;
    int StepX = 0;
    int StepY = 0;

    void render(SDL_Renderer* renderer) {
        SDL_Rect sourceRect = RectPac(renderer);
        SDL_Rect desRect;
        desRect.x = x-sourceRect.w/2;
        desRect.y = y-sourceRect.h/2;
        desRect.w = sourceRect.w;
        desRect.h = sourceRect.h;
        SDL_RenderCopy(renderer, texturePac, NULL, &desRect);
    }

    void movePac() {
        x += StepX;
        /*if (x < XMIN || x > XMAX) {
            x -= StepX;
        }*/
        y += StepY;
        /*if (y < YMIN || y > YMAX) {
            y -= StepY;
        }*/
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

    void stop() {
        StepX = 0;
        StepY = 0;
    }
};

struct GhostObject {
    int x;
    int y;
    int StepX = 0;
    int StepY = 0;

    void render(SDL_Renderer* renderer) {
        SDL_Rect sourceRect = RectGhost(renderer);
        SDL_Rect desRect;
        desRect.x = x-sourceRect.w/2;
        desRect.y = y-sourceRect.h/2;
        desRect.w = sourceRect.w;
        desRect.h = sourceRect.h;
        SDL_RenderCopy(renderer, textureGhost, NULL, &desRect);
    }

    void moveGhost() {
        x += StepX;
        if (x < XMIN || x > XMAX) {
            x -= StepX;
        }
        y += StepY;
        if (y < YMIN || y > YMAX) {
            y -= StepY;
        }
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

    void stop() {
        StepX = 0;
        StepY = 0;
    }
};

struct LifeNumber {
    int x;
    int y;

    void render(SDL_Renderer* renderer) {
        SDL_Rect sourceRect = RectHeart(renderer);
        SDL_Rect desRect;
        desRect.x = x-sourceRect.w/2;
        desRect.y = y-sourceRect.h/2;
        desRect.w = sourceRect.w;
        desRect.h = sourceRect.h;
        SDL_RenderCopy(renderer, textureHeart, NULL, &desRect);
    }
};

#endif

