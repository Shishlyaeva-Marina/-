#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>
#include <SDL2/SDL.h>

#ifdef _WIN32
# include <SDL2/SDL_main.h>
#endif

constexpr int WIDTH = 800, HEIGHT = 800;

int main(int, char**)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    auto win = std::shared_ptr<SDL_Window>(
            SDL_CreateWindow(
                        "Синус",
                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        WIDTH, HEIGHT,
                        SDL_WINDOW_SHOWN),
            SDL_DestroyWindow);
    if (win == nullptr) {
        std::cerr << "При создании окна произошла ошибка: " <<
                SDL_GetError() << std::endl;
        return 1;
    }
    auto renden = std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(win.get(), -1,
                    SDL_RENDERER_ACCELERATED |
                    SDL_RENDERER_PRESENTVSYNC),
            SDL_DestroyRenderer);
    if (renden == nullptr) {
        std::cerr << "При создании renderer-а произошла ошибка: " <<
                SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Event event;
    while(1){
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) return 0;
        }

        SDL_SetRenderDrawColor(renden.get(), 230, 230, 250, 255);
        SDL_RenderClear(renden.get());

        SDL_SetRenderDrawColor(renden.get(), 0, 128, 128, 0);
        for(int i=-WIDTH/2; i<WIDTH/2;i++)
        {
            SDL_RenderDrawPoint(renden.get(), i+WIDTH/2, (100*sin(i*(6.284/360.0)*3.14)/(i*(6.284/360.0))*3.14)+HEIGHT/2);
        }
        SDL_RenderPresent(renden.get());
    }
    return 0;
}
