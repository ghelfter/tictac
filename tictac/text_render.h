/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------  text_render.h  --------------  */

#ifndef _TEXT_RENDER_H_
#define _TEXT_RENDER_H_

#include <SDL2/SDL.h>

#include "Vector2.h"

extern SDL_Color white;
extern SDL_Color red;

/*
 * Render text to the screen
 * */

void render_text(SDL_Renderer *renderer, const char *msg,
                 const struct vector2 *pos, const struct vector2 *dim);

void cleanup_text_render();
int text_renderer_is_init();

#endif
