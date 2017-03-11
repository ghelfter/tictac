/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------   renderer.h    --------------  */

#ifndef RENDERER_H_
#define RENDERER_H_

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "Vector2.h"

/* Declare our renderer as a global variable */
extern SDL_Renderer *tictac_renderer;
extern SDL_Window *tictac_window;
extern SDL_Texture *board_textures[3];

int initialize_renderer(int w, int h);
void render_board(const char *game_board);

void cleanup_renderer();
bool render_texture(SDL_Texture *tex, struct vector2 *pos,
                    struct vector2 *dim);

#endif
