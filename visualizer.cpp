#include <SDL.h>
#include <iostream>
using namespace std;

const int SCREEN_WIDTH = 910, SCREEN_HEIGHT = 750;
const int arrSize = 130, rectSize = 7;

int arr[arrSize];
int Barr[arrSize];

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
bool complete = false;

void visualize(int x = -1, int y = -1, int z = -1) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    int j = 0;
    for (int i = 0; i <= SCREEN_WIDTH - rectSize; i += rectSize) {
        SDL_Rect rect = {i, SCREEN_HEIGHT - arr[j], rectSize, arr[j]};
        if (complete)
            SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
        else if (j == x || j == z)
            SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
        else if (j == y)
            SDL_SetRenderDrawColor(renderer, 165, 105, 189, 0);
        else
            SDL_SetRenderDrawColor(renderer, 170, 183, 184, 0);
        SDL_RenderFillRect(renderer, &rect);
        j++;
    }
    SDL_RenderPresent(renderer);
}

bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL Error: " << SDL_GetError();
        return false;
    }

    window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        cout << "Window Error: " << SDL_GetError();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        cout << "Renderer Error: " << SDL_GetError();
        return false;
    }

    return true;
}

void close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
