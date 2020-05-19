#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Pacman.h"
#include "Matrix.h"
#include "SDL_Utils.h"
#include <SDL_ttf.h>
#include <SDL_mixer.h>

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
SDL_Texture* texture = NULL;
SDL_Surface* surface = NULL;

bool askIfContinue() {
    bool is_quit = false;

    setColor(GREEN_COLOR, renderer);
    SDL_RenderClear(renderer);

    string again = "Play Again";
    string fagain = "Y/N";
    DrawText(renderer, again, 530, 300);
    DrawText(renderer, fagain, 595, 360);

    while (!is_quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                is_quit = true;
                break;
            }
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_n: return false;
                        break;
                    case SDLK_y: return true;
                        break;
                    case SDLK_ESCAPE: return false;
                    default: break;
                }
            }
        }
        SDL_RenderPresent(renderer);
    }
}

int main(int argc, char* argv[]) {
    srand(time(0));

    initSDL(window, renderer);

    Matrix P;

    bool is_running = false;

    SDL_Rect sourceRect = Rect_Background(renderer);
    SDL_Rect desRect;
    desRect.x = 0;
    desRect.y = 0;
    desRect.w = sourceRect.w;
    desRect.h = sourceRect.h;
    SDL_RenderCopy(renderer, texture, NULL, &desRect);

    while (!is_running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                is_running = true;
                break;
            }
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE: return 0;
                        break;
                    case SDLK_SPACE: is_running = true;
                        break;
                    default: break;
                }
            }
            string text = "Press SPACE to continue";
            DrawText(renderer, text, 425, 300);
            PlayAudio("background.wav");
        }
        SDL_RenderPresent(renderer);
    }

    bool playAgain = false;
    do {
        P.GeneralHandling(renderer, e);
        SDL_RenderClear(renderer);
        playAgain = askIfContinue();
    } while (playAgain);

    CleanUp();
    quitSDL(window, renderer);
    return 0;
}
