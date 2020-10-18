#include <SDL.h>
#include <iostream>
using namespace std;

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;

bool init()
{
    bool ok = true;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        cout << "Can't init SDL: " << SDL_GetError() << endl;

    win = SDL_CreateWindow("House", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

    SDL_Rect rect = { 100, 240, 300, 200 };
    SDL_RenderDrawRect(ren, &rect);

    rect = { 150, 330, 60, 110 };
    SDL_RenderDrawRect(ren, &rect);
    SDL_RenderDrawLine(ren, 200, 380, 200, 390);

    rect = { 300, 300, 60, 60 };
    SDL_RenderDrawRect(ren, &rect);
    rect = { 330, 300, 30, 60 };
    SDL_RenderDrawRect(ren, &rect);
    rect = { 330, 320, 30, 40 };
    SDL_RenderDrawRect(ren, &rect);

    SDL_RenderDrawLine(ren, 100, 240, 250, 100);
    SDL_RenderDrawLine(ren, 250, 100, 400, 240);

    SDL_RenderDrawLine(ren, 330, 240 - 65, 330, 100);
    SDL_RenderDrawLine(ren, 370, 240 - 28, 370, 100);
    SDL_RenderDrawLine(ren, 330, 100, 370, 100);

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
