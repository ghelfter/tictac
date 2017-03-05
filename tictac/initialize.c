/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------  initialize.c   --------------  */

/* Acquire any SDL headers */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* Acquire any C standard library headers */
#include <stdio.h>
#include <stdlib.h>

#include "renderer.h"
#include "image_load.h"

/* Declare global variables to access our images */
SDL_Texture *circle_tex = NULL;
SDL_Texture *cross_tex = NULL;
SDL_Texture *board_tex = NULL;

int tictac_init(int w, int h)
{
    int result = 0;
    int flags = IMG_INIT_PNG;
    int flags_res = 0;

    /* Initialize any SDL systems */
    result |= SDL_Init(SDL_INIT_VIDEO);

    /* Initialize SDL_Image */
    flags_res = IMG_Init(flags);

    result |= (flags_res ^ flags);

    /* Initialize our renderer */
    result |= initialize_renderer(w, h);

    fprintf(stdout, "Result: %d\n", result);

    /* Check if we have any errors, we'll need to perform cleanup if we do */
    return result;
}

void tictac_close()
{
    SDL_DestroyTexture(circle_tex);
    IMG_Quit();
    SDL_Quit();
}

/* Load our art assets */
void load_assets()
{
    /* Declare variables for the filenames */
    const char *circle = "./assets/circle.png";
    const char *cross = "./assets/cross.png";
    const char *board = "./assets/board.png";

    /* Load our images in */
    circle_tex = load_image(circle, renderer);
    board_tex = load_image(board, renderer);

    /* Make sure they were properly loaded */
}
