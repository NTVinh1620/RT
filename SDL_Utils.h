#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <SDL.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();

#endif


