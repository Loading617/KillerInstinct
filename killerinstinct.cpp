#include <SDL2/SDL.h>
#include <emscripten.h>

SDL_Window* window;
SDL_Renderer* renderer;

void gameLoop() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            emscripten_cancel_main_loop();
            break;
        }
        // Handle input (character movement, attacks)
        // Update game logic (character movement, combo detection)
    }

    // Clear screen and render characters and backgrounds
    SDL_RenderClear(renderer);
    // Render character, background, health bars, etc.
    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Killer Instinct", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    emscripten_set_main_loop(gameLoop, 0, 1);
    return 0;
}
