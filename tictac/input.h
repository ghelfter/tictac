/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------     input.h     --------------  */

#ifndef _INPUT_H_
#define _INPUT_H_

#include "Vector2.h"

/* Normalize mouse coordinates */
void get_mouse_norm(const struct vector2 *mpos, const struct vector2 *dim,
                    struct vector2 *mnorm);
int get_cell(const struct vector2 *mnorm);

#endif
