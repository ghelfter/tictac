/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------  image_load.c   --------------  */

#include <stdio.h>

#include "image_load.h"

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;
#else
    Uint32 rmask = 0x000000ff;
    Uint32 gmask = 0x0000ff00;
    Uint32 bmask = 0x00ff0000;
    Uint32 amask = 0xff000000;
#endif

/* Load in an image. Assumes that SDL and SDL_Image have been initialized */
SDL_Texture* load_image(const char *filename, SDL_Renderer *rend)
{
    SDL_Surface *surface = NULL;
    SDL_Texture *res = NULL;
    surface = IMG_Load(filename);

    /* Get a texture from our SDL surface */
    res = SDL_CreateTextureFromSurface(rend, surface);

    SDL_FreeSurface(surface);
    
    return res;
}
