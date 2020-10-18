#include <SDL.h>
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;

bool init()
{
    bool ok = true;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        cout << "Can't init SDL: " << SDL_GetError() << endl;

    win = SDL_CreateWindow("Sin(x)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL)
    {
        cout << "Can't create window: " << SDL_GetError() << endl;
        ok = false;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (ren == NULL)
    {
        cout << "Can't create renderer: " << SDL_GetError() << endl;
        ok = false;
    }
    return ok;
}

void quit()
{
    SDL_DestroyWindow(win);
    win = NULL;
    SDL_DestroyRenderer(ren);
    ren = NULL;
    SDL_Quit;
}

int main(int arhc, char** argv)
{
    if (!init())
    {
        quit();
        system("pause");
        return 1;
    }

    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);

    for (int i = 0; i <= 640; i++)
        SDL_RenderDrawPoint(ren, i, 240 - sin((double)i / 141 * PI) * 45);

    for (double i = 0; i <= 640; i += 70.5)
        SDL_RenderDrawLine(ren, i, 235, i, 245);

    SDL_RenderDrawLine(ren, 0, 240, 640, 240);
    SDL_RenderPresent(ren);
    bool _quit = false;
    SDL_Event e;
    while (!_quit)
    {
        while (SDL_PollEvent(&e))
            if (e.type == SDL_QUIT)
                _quit = true;
        SDL_Delay(10);
    }
    quit();
    return 0;
}
