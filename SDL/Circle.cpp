#include <SDL.h>
#include <iostream>
using namespace std;

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 640;

SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;

bool init()
{
    bool ok = true;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        cout << "Can't init SDL: " << SDL_GetError() << endl;

    win = SDL_CreateWindow("Circle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
    int r = 0;
    while (r < 1 || r > 10)
    {
        cout << "Enter radius of a circle (1 <= r <= 10): ";
        cin >> r;
    }

    if (!init())
    {
        quit();
        system("pause");
        return 1;
    }

    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);

    int x = 0;
    int X1 = 320;
    int Y1 = 320;
    int y = r * 30;
    int delta = 1 - 2 * r * 30;
    int error = 0;
    while (y >= 0)
    {
        SDL_RenderDrawPoint(ren, X1 + x, Y1 + y);
        SDL_RenderDrawPoint(ren, X1 + x, Y1 - y);
        SDL_RenderDrawPoint(ren, X1 - x, Y1 + y);
        SDL_RenderDrawPoint(ren, X1 - x, Y1 - y);
        error = 2 * (delta + y) - 1;
        if ((delta < 0) && (error <= 0))
        {
            delta += 2 * ++x + 1;
            continue;
        }
        if ((delta > 0) && (error > 0))
        {
            delta -= 2 * --y + 1;
            continue;
        }
        delta += 2 * (++x - --y);
    }

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
