#include "renderutil.hpp"

void renderutil::set_color(SDL_Renderer* renderer, const SDL_Color & color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.b, color.g, color.a);
}

void renderutil::draw_square(SDL_Renderer* renderer, int x, int y, int size,
    const SDL_Color & color, const SDL_Color & outline_color) {
    set_color(renderer, color);
    SDL_Rect r = {x, y, size, size};
    SDL_RenderFillRect(renderer, &r);
    set_color(renderer, outline_color);
    SDL_RenderDrawRect(renderer, &r);
}

