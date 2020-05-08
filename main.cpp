#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Pacman.h"
#include "Matrix.h"
#include "SDL_Utils.h"

using namespace std;

SDL_Event e;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texturePac = NULL;
SDL_Texture* textureGhost = NULL;
SDL_Surface* surfacePac = NULL;
SDL_Surface* surfaceGhost = NULL;
SDL_Texture* textureHeart = NULL;
SDL_Surface* surfaceHeart = NULL;

int main(int argc, char* argv[]) {
    srand(time(0));

    initSDL(window, renderer);

    Matrix P;
    P.menu(renderer, e);
    SDL_RenderPresent(renderer);

    CleanUp();

    quitSDL(window, renderer);
    return 0;
}
