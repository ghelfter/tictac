/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------     input.c     --------------  */

#include "input.h"

/* TODO Here we'll normalize the mouse position and place it into the
 * given pointer
 * */
void get_mouse_norm(const struct vector2 *mpos, const struct vector2 *dim,
                    struct vector2 *mnorm)
{
    mnorm->x = (mpos->x / dim->x);
    mnorm->y = (mpos->y / dim->y);
}
