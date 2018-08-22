// Include this file to get OpenGL.

#ifdef __linux__
// TODO: Don't have a class called Window that collides with X11's Window type.
#define Window X11Window
#define GL_GLEXT_PROTOTYPES
#include <GL/glx.h>
#undef Window
#endif

#ifdef __mac__
// TODO
#endif
