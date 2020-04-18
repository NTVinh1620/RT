#include <iostream>
#include <SDL.h>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

void setColor(SDL_Color color, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
}



