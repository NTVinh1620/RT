#include <iostream>
#include <SDL.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Pacman.h"
#include "Matrix.h"
#include "SDL_Utils.h"

using namespace std;

int main(int argc, char* argv[]) {
    srand(time(0));

    SDL_Window* window;
    SDL_Renderer* renderer;

    initSDL(window, renderer);

    Matrix P;

    P.menu(renderer);
    SDL_RenderPresent(renderer);

    quitSDL(window, renderer);
    return 0;
}
