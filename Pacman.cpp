#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Pacman.h"

using namespace std;

extern SDL_Texture* texturePac;
extern SDL_Texture* textureGhost;
extern SDL_Texture* textureHeart;
extern SDL_Surface* surfacePac;
extern SDL_Surface* surfaceGhost;
extern SDL_Surface* surfaceHeart;
extern SDL_Texture* texture;
extern SDL_Surface* surface;

void setColor(SDL_Color color, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
}

void CleanUp() {
    SDL_FreeSurface(surfacePac);
    SDL_FreeSurface(surfaceGhost);
    SDL_DestroyTexture(texturePac);
    SDL_DestroyTexture(textureGhost);
    SDL_FreeSurface(surfaceHeart);
    SDL_DestroyTexture(textureHeart);
    TTF_Quit();
    Mix_CloseAudio();
}

SDL_Rect RectPac(SDL_Renderer* renderer) {
    surfacePac = IMG_Load("Pac.png");
    SDL_SetColorKey(surfacePac, SDL_TRUE, SDL_MapRGB(surfacePac->format, 247, 247, 247));
    texturePac = SDL_CreateTextureFromSurface(renderer, surfacePac);
    SDL_Rect sourceRect;
    SDL_QueryTexture(texturePac, NULL, NULL, &sourceRect.w, &sourceRect.h);
    return sourceRect;
}

SDL_Rect RectGhost(SDL_Renderer* renderer) {
    surfaceGhost = IMG_Load("Ghost.png");
    SDL_SetColorKey(surfaceGhost, SDL_TRUE, SDL_MapRGB(surfacePac->format, 246, 246, 246));
    textureGhost = SDL_CreateTextureFromSurface(renderer, surfaceGhost);
    SDL_Rect sourceRect;
    SDL_QueryTexture(texturePac, NULL, NULL, &sourceRect.w, &sourceRect.h);
    return sourceRect;
}

SDL_Rect RectHeart(SDL_Renderer* renderer) {
    surfaceHeart = IMG_Load("Heart.png");
    SDL_SetColorKey(surfaceHeart, SDL_TRUE, SDL_MapRGB(surfaceHeart->format, 0, 255, 255));
    textureHeart = SDL_CreateTextureFromSurface(renderer, surfaceHeart);
    SDL_Rect sourceRect;
    SDL_QueryTexture(texturePac, NULL, NULL, &sourceRect.w, &sourceRect.h);
    return sourceRect;
}

SDL_Rect Rect_Background(SDL_Renderer* renderer) {
    surface = IMG_Load("Image.jpg");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect sourceRect;
    SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w, &sourceRect.h);
    return sourceRect;
}

void DrawText(SDL_Renderer* renderer, string str, int x, int y) {
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = NULL;
    TTF_Font* font = NULL;

    TTF_Init();
    font = TTF_OpenFont("VeraMoBd.ttf", 30);

    surface = TTF_RenderText_Solid(font, str.c_str(), FG);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect srcRest;
    SDL_Rect desRect;
    TTF_SizeText(font, str.c_str(), &srcRest.w, &srcRest.h);

	desRect.x = x;
	desRect.y = y;

    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy(renderer, texture, NULL, &desRect);

    SDL_DestroyTexture(texture);
}

void PlayAudio(string path) {
    Mix_Chunk* chunk = NULL;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    chunk = Mix_LoadWAV(path.c_str());
    Mix_PlayChannel(-1, chunk, 0);
}



