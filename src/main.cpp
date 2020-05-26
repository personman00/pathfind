#include <iostream>
#include <SDL2/SDL.h>
#include "visualizer.hpp"


int main(int argc, char *argv[])
{
	visualizer* visualizer;
	SDL_Window * window;
	SDL_Surface * surface;
	SDL_Renderer * renderer;

	if(initialize_sdl(&window, &surface, &renderer) == 1) {
		return 1;
	}	

	//pass to visualizer
	visualizer = NULL;

	SDL_Event ev;	
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double dT = 0;

	while(visualizer->is_running()) {
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		dT = (double)((NOW-LAST)*1000/(double)SDL_GetPerformanceFrequency());
		while(SDL_PollEvent(&ev)) {
			visualizer->event_poll(ev);
		}
		visualizer->update(dT);
		visualizer->render(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();	
	return 0;
}


int initialize_sdl(SDL_Window ** window, SDL_Surface ** surface, SDL_Renderer ** renderer) {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("ERROR loading SDL: %s\n", SDL_GetError());
		return 1;
	}

	*window = SDL_CreateWindow("pathfinding", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

	if(*window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}
	*surface = SDL_GetWindowSurface(*window);
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);

	if(*renderer == NULL) {
		printf("Could not create renderer: %s\n", SDL_GetError());
		return 1;
	}

	return 0;
}
