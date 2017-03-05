/*  --------------  Galen Helfter  --------------  */
/*  --------------    CPSC 4160    --------------  */
/*  --------------     tictac      --------------  */
/*  --------------  initialize.h   --------------  */

#ifndef INITIALIZE_H_
#define INITIALIZE_H_

extern SDL_Texture *circle_tex;
extern SDL_Texture *cross_tex;
extern SDL_Texture *board_tex;

int tictac_init(int w, int h);

void load_assets();

void tictac_close();

#endif
