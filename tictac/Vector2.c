/*  ============== Galen Helfter ==============  */
/*  ==============   Vector2.c   ==============  */

#include <math.h>

#include "Vector2.h"

const struct vector2 empty2 = {0.0, 0.0};

void vector2_init(struct vector2 *vec)
{
    vec->x = 0.0;
    vec->y = 0.0;
}

struct vector2 vector2_add(struct vector2 v1, struct vector2 v2)
{
    struct vector2 result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;

    return result;
}

struct vector2 vector2_sub(struct vector2 v1, struct vector2 v2)
{
    struct vector2 result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;

    return result;
}

struct vector2 vector2_scale(struct vector2 vec, double scale)
{
    struct vector2 result;
    result.x = vec.x * scale;
    result.y = vec.y * scale;

    return result;
}

struct vector2 vector2_scale_div(struct vector2 vec, double scale)
{
    struct vector2 result;
    double s_val = 1.0 / scale; /* Create a scale value for optimization */
    result.x = vec.x * s_val;
    result.y = vec.y * s_val;

    return result;
}

double vector2_dot(struct vector2 v1, struct vector2 v2)
{
    return (v1.x * v2.x + v1.y * v2.y);
}

double vector2_norm(struct vector2 vec)
{
    return sqrt(vector2_dot(vec, vec));
}

struct vector2 vector2_unit(struct vector2 vec)
{
    struct vector2 result;
    double length = vector2_norm(vec);
    double s_val = 1.0 / length;
    result.x = vec.x * s_val;
    result.y = vec.y * s_val;

    return  result;
}
