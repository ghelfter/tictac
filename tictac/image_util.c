/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------  image_util.c   --------------  */

#include "image_util.h"

void image_dim(SDL_Texture *img, int *w, int *h)
{
    SDL_QueryTexture(img, NULL, NULL, w, h);
}

int image_width(SDL_Texture *img)
{
    int retval = 0;

    SDL_QueryTexture(img, NULL, NULL, &retval, NULL);

    return retval;
}

int image_height(SDL_Texture *img)
{
    int retval = 0;

    SDL_QueryTexture(img, NULL, NULL, NULL, &retval);

    return retval;
}
