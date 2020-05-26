#ifndef _VIS_H
#define _VIS_H

#include "SDL2/SDL.h"

class visualizer {
    public:
        visualizer() {};
        virtual ~visualizer() {};
        virtual void run_visualizer() = 0;
        virtual void stop_visualizer() = 0;
        virtual void update(double delta_time) = 0;
        virtual void render(SDL_Renderer* renderer);
        virtual void event_poll(const SDL_Event & event);

        virtual bool is_running() = 0;
};

#endif