/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------  text_render.c  --------------  */

#include <SDL2/SDL_ttf.h>

#include "text_render.h"

static TTF_Font *msg_font = NULL;
static int is_init = 0;

SDL_Color white = {255, 255, 255, 255};
SDL_Color red = {255, 0, 0, 255};

int text_renderer_is_init()
{
    return is_init;
}

void cleanup_text_render()
{
    if(msg_font != NULL)
    {
        TTF_CloseFont(msg_font);
        msg_font = NULL;
    }
}

static void init_text_render()
{
    /* Load our font */
    msg_font = TTF_OpenFont("font/Latinia.ttf", 24);
}

/*
 * Note: This is inefficient. More likely, we'd want to generate our texture
 * and save it for efficiency.
 * */
void render_text(SDL_Renderer *renderer, const char *msg,
                 const struct vector2 *pos, const struct vector2 *dim)
{
    /* create our rectangle */
    SDL_Rect pos_rect;
    SDL_Surface *surfacetex = NULL;
    SDL_Texture *tex = NULL;

    if(!is_init)
    {
        init_text_render();
        is_init = 1;
    }

    pos_rect.x = (int) pos->x;
    pos_rect.y = (int) pos->y;
    pos_rect.w = (int) dim->x;
    pos_rect.h = (int) dim->y;

    /* Create surface */
    surfacetex = TTF_RenderText_Solid(msg_font, msg, red);

    /* Create texture */
    tex = SDL_CreateTextureFromSurface(renderer, surfacetex);

    /* Destroy surface */
    SDL_FreeSurface(surfacetex);


    /* Render texture */
    SDL_RenderCopy(renderer, tex, NULL, &pos_rect);

    /* Destroy texture */
    SDL_DestroyTexture(tex);
}
