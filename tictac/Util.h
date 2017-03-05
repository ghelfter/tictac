/*  ============== Galen Helfter ==============  */
/*  ==============     Util.h    ==============  */

#ifndef _UTIL_H_
#define _UTIL_H_

/*  We must keep a definition of M_PI, since it isn't guaranteed
 *  in the C90 specification, which I usually target  */
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/* Basic mathematical macros */
#define SQR(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define DEG2RAD(theta) ((theta)*(M_PI)/(180.0))
#define RAD2DEG(theta) ((theta)/(M_PI)*(180.0))

/*  Define an epsilon value  */
#ifndef EPS
#define EPS 0.001
#endif

#endif
