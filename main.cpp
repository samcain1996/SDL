#include <iostream>
#include "/usr/include/SDL2/SDL.h"
#include "SpriteController.h"
#include <vector>

#define FPS 60
#define WIDTH 600
#define HEIGHT 480

// Caps FPS to whatever it is defined to
void capFPS(Uint32 prevTicks) {
    if ((1000/FPS) > SDL_GetTicks() - prevTicks)
        SDL_Delay(1000/FPS - (SDL_GetTicks() - prevTicks));
}

// Update game until exit is pressed
void update(SDL_Window *window, SDL_Surface *surface) {
    SpriteController s;
    s.createPlayer(32, 32, 0, 0, "thing.bmp");
    s.createSprite(32, 32, 100, 200, "other.bmp");
    for (auto& thing : s.getSprites()) {
        std::cout << thing->getId() << std::endl;
    }
    const Uint32 white = SDL_MapRGB(surface->format, 255, 255, 255);
    SDL_Event event;
    Uint32 ticks;
    bool exit = false;
    while (!exit) {

        ticks = SDL_GetTicks();

        // Get user interaction
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                exit = true;
                break;
            }
            
            s.update(event);
        }
        
        SDL_FillRect(surface, NULL, white);
        s.draw(surface);
        SDL_UpdateWindowSurface(window);
        capFPS(ticks);

    }
}

int main(int argc, char** argv) {

    SDL_Init( SDL_INIT_EVERYTHING );
    
    const char* title = "Medeivel War UFO Aliens 3";

    // Create window
    SDL_Window *window = SDL_CreateWindow(title,
                                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                WIDTH, HEIGHT, NULL);

    SDL_Surface *surface = SDL_GetWindowSurface(window);

    update(window, surface);

    // Destroy window and quit SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}