#include <iostream>
#include <SDL.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Pacman.h"
#include "Matrix.h"

using namespace std;

int main(int argc, char* argv[]) {
    srand(time(0));

    SDL_Window* window;
    SDL_Renderer* renderer;

    initSDL(window, renderer);

    Matrix P;
    //setColor(WHITE_COLOR, renderer);
    //P.completeMap(renderer);
    P.menu(renderer);
    SDL_RenderPresent(renderer);

    quitSDL(window, renderer);
    return 0;
}
