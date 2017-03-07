/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------     input.c     --------------  */

#include <math.h>

#include "input.h"

static double cell_width = (1.00 / 3.00);
static double cell_height = (1.00 / 3.00);

/* TODO Here we'll normalize the mouse position and place it into the
 * given pointer
 * */
void get_mouse_norm(const struct vector2 *mpos, const struct vector2 *dim,
                    struct vector2 *mnorm)
{
    mnorm->x = (mpos->x / dim->x);
    mnorm->y = (mpos->y / dim->y);
}

/* We'll acquire the cell they clicked here */
int get_cell(const struct vector2 *mnorm)
{
    int px = (int) floor(mnorm->x / cell_width);
    int py = (int) floor(mnorm->y / cell_height);

    return (py*3 + px);
}
