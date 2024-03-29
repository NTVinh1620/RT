#ifndef PACMAN_H
#define PACMAN_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

const SDL_Color CYAN_COLOR = {0, 255, 255};
const SDL_Color BLUE_COLOR = {0, 0, 255};
const SDL_Color ORANGE_COLOR = {255, 165, 0};
const SDL_Color YELLOW_COLOR = {255, 255, 0};
const SDL_Color LIME_COLOR = {0, 255, 0};
const SDL_Color PURPLE_COLOR = {128, 0, 128};
const SDL_Color RED_COLOR = {255, 0, 0};
const SDL_Color WHITE_COLOR = {255, 255, 255};
const SDL_Color BLACK_COLOR = {0, 0, 0};
const SDL_Color GREEN_COLOR = {0, 128, 0};
const SDL_Color FG = {243, 156, 18};
const SDL_Color DEFAULT_COLOR = BLACK_COLOR;

void setColor(SDL_Color color, SDL_Renderer* renderer);

void CleanUp();

SDL_Rect RectPac(SDL_Renderer* renderer);
SDL_Rect RectGhost(SDL_Renderer* renderer);
SDL_Rect RectHeart(SDL_Renderer* renderer);
SDL_Rect Rect_Background(SDL_Renderer* renderer);

void DrawText(SDL_Renderer* renderer, string str, int x, int y);
void PlayAudio(string path);

#endif

