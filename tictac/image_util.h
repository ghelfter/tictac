/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------  image_util.h   --------------  */

#ifndef _IMAGE_UTIL_H_
#define _IMAGE_UTIL_H_

#include <SDL2/SDL.h>

/* Query an image for its dimensions */
void image_dim(SDL_Texture *img, int *w, int *h);
int image_width(SDL_Texture *img);
int image_height(SDL_Texture *img);

#endif
