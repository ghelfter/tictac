/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------   renderer.c    --------------  */

#include "renderer.h"

/* This will be referenced by outside files */
SDL_Renderer *tictac_renderer = NULL;
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
    tictac_renderer = SDL_CreateRenderer(tictac_window, -1,
                                         SDL_RENDERER_ACCELERATED);

    return 0;
}

void cleanup_renderer()
{
    board_textures[0] = board_textures[1] = board_textures[2] = NULL;
    SDL_DestroyRenderer(tictac_renderer);
    SDL_DestroyWindow(tictac_window);
}

void render_board(const char *game_board)
{
    int size = 9;
    int i = 0;
    struct vector2 pos;
    struct vector2 dim;
    int w = 0, h = 0;

    /* Acquire render size */
    SDL_GetWindowSize(tictac_window, &w, &h);
    double third_w = (double)w / 3.0;
    double third_h = (double)h / 3.0;

    /* Go through our board and render all the textures */
    for(i = 0; i < size; ++i)
    {
        /* Acquire our position */
        pos.x = (i % 3) * third_w;
        pos.y = (i / 3) * third_h;

        dim.x = third_w;
        dim.y = third_w;

        /* Store our textures simply */
        render_texture(board_textures[(int)game_board[i]], &pos, &dim);
    }
}

/* Give a texture and a 2-d coordinate for its position */
bool render_texture(SDL_Texture *tex, struct vector2 *pos,
                    struct vector2 *dim)
{
    SDL_Rect pos_rect;
    /*  Have not initialized the renderer yet  */
    if(tictac_renderer == NULL)
    {
        return false;
    }
    /*  We were passed a NULL texture  */
    if(tex == NULL)
    {
        return false;
    }

    /* Construct our position rectangle */
    pos_rect.x = (int) pos->x;
    pos_rect.y = (int) pos->y;

    pos_rect.w = (int) dim->x;
    pos_rect.h = (int) dim->y;

    SDL_RenderCopy(tictac_renderer, tex, NULL, &pos_rect);

    return true;
}
