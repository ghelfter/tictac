/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------   renderer.c    --------------  */

#include "renderer.h"

/* This will be referenced by outside files */
SDL_Renderer *renderer = NULL;
SDL_Window *tictac_window = NULL;

SDL_Texture* board_textures[3];

int initialize_renderer(int w, int h)
{
    /* Create window */
    tictac_window = SDL_CreateWindow(
                            "Tic Tac",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            w,
                            h,
                            SDL_WINDOW_SHOWN);

    /* Create renderer */
    renderer = SDL_CreateRenderer(tictac_window, -1, SDL_RENDERER_ACCELERATED);

    return 0;
}

void cleanup_renderer()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(tictac_window);
}

void render_board(const char *game_board)
{
    int size = 9;
    int i = 0;
    /* Go through our board and render all the textures */
    for(i = 0; i < size; ++i)
    {
        /* Store our textures simply */
    }
}

/* Give a texture and a 2-d coordinate for its position */
bool render_texture(SDL_Texture *tex, struct vector2 *pos)
{
    /*  Have not initialized the renderer yet  */
    if(renderer == NULL)
    {
        return false;
    }
    /*  We were passed a NULL texture  */
    if(tex == NULL)
    {
        return false;
    }

    /* Construct our position rectangle */

    /* Construct our dimension rectangle */

    return true;
}
