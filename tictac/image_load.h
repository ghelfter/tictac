/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------  image_load.h   --------------  */

#ifndef IMAGE_LOAD_H_
#define IMAGE_LOAD_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* Creates an SDL_Texture, using the renderer given. It allocates the memory
 * for the SDL_Texture, which must be destroyed later.
 * */
SDL_Texture* load_image(const char *filename, SDL_Renderer *rend);

#endif
