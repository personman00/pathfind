#ifndef _RENDER_UTIL
#define _RENDER_UTIL

#include "SDL2/SDL.h"

class renderutil {
    public:
        renderutil();
        ~renderutil();
        static void draw_square(SDL_Renderer* renderer, int x, int y, int size, const SDL_Color & color, const SDL_Color & outline_color);
        static void set_color(SDL_Renderer* renderer, const SDL_Color & color);
};

#endif