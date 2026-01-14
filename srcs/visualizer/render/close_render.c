#include "lem_in.h"

void	close_render(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *map_cache)
{
	if (map_cache)
		SDL_DestroyTexture(map_cache);
	if (renderer)
		SDL_DestroyRenderer(renderer);
	if (window)
		SDL_DestroyWindow(window);
	SDL_Quit();
}