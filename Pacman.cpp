#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

extern SDL_Texture* texturePac;
extern SDL_Texture* textureGhost;
extern SDL_Texture* textureHeart;
extern SDL_Surface* surfacePac;
extern SDL_Surface* surfaceGhost;
extern SDL_Surface* surfaceHeart;

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
}

SDL_Rect RectPac(SDL_Renderer* renderer) {
    surfacePac = IMG_Load("Pac2.png");
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


