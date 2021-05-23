#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>
#include <SDL2/SDL.h>

#ifdef _WIN32
# include <SDL2/SDL_main.h>
#endif

constexpr int WIDTH = 800, HEIGHT = 600;

int main(int, char**)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    auto win = std::shared_ptr<SDL_Window>(
            SDL_CreateWindow(
                        "Окно нашего графического приложения",
                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        WIDTH, HEIGHT,
                        SDL_WINDOW_SHOWN),
            SDL_DestroyWindow);
    if (win == nullptr) {
        std::cerr << "При создании окна произошла ошибка: " <<
                SDL_GetError() << std::endl;
        return 1;
    }

    auto ren = std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(win.get(), -1,
                    SDL_RENDERER_ACCELERATED |
                    SDL_RENDERER_PRESENTVSYNC),
            SDL_DestroyRenderer);
    if (ren == nullptr) {
        std::cerr << "При создании renderer-а произошла ошибка: " <<
                SDL_GetError() << std::endl;
        return 1;
    }


    SDL_Event event;
    while(1){
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) return 0;
        }

        SDL_SetRenderDrawColor(ren.get(), 230, 230, 250, 255);
        SDL_RenderClear(ren.get());

        SDL_SetRenderDrawColor(ren.get(), 75, 0, 130, 0);

        SDL_Rect house = {250, 200, 200, 150};
        SDL_RenderDrawRect(ren.get(), &house);
        SDL_RenderDrawLine(ren.get(), 250, 200, 350, 90);
        SDL_RenderDrawLine(ren.get(), 350, 90, 450, 200);
        SDL_Rect door = {275, 250, 50, 100};
        SDL_RenderDrawRect(ren.get(), &door);

        SDL_Rect window = {375, 250, 50, 50};
        SDL_RenderDrawRect(ren.get(), &window);

        SDL_Rect truba = {375, 95, 20, 50};
        SDL_RenderDrawRect(ren.get(), &truba);


        int x0=345, y0 = 150, r = 25;
        int x = 0;
            int y = r;
            int delta = 1 - 2 * r;
            int error = 0;
            while(y >= 0) {
                SDL_RenderDrawPoint(ren.get(), x0 + x, y0 + y);
                SDL_RenderDrawPoint(ren.get(), x0 + x, y0 - y);
                SDL_RenderDrawPoint(ren.get(), x0 - x, y0 + y);
                SDL_RenderDrawPoint(ren.get(), x0 - x, y0 - y);

                error = 2 * (delta + y) - 1;
                if(delta < 0 && error <= 0) {
                    ++x;
                    delta += 2 * x + 1;
                    continue;
                }
                error = 2 * (delta - x) - 1;
                if(delta > 0 && error > 0) {
                    --y;
                    delta += 1 - 2 * y;
                    continue;
                }
                ++x;
                delta += 2 * (x - y);
                --y;
            }
        SDL_RenderPresent(ren.get());
    }


    return 0;
}
