#ifndef CONSTANTS_H
# define CONSTANTS_H

// ----------------------------
// Window configuration
// ----------------------------
# define WIDTH 1200
# define HEIGHT 1000

// ----------------------------
// Basic colors
// ----------------------------
# define COLOR_BLACK     0x000000
# define COLOR_WHITE     0xFFFFFF
# define COLOR_RED       0xFF0000
# define COLOR_GREEN     0x00FF00
# define COLOR_BLUE      0x0000FF
# define COLOR_YELLOW    0xFFFF00
# define COLOR_CYAN      0x00FFFF
# define COLOR_MAGENTA   0xFF00FF
# define COLOR_GRAY      0x808080
# define COLOR_DARK_GRAY 0x404040
# define COLOR_LIGHT_GRAY 0xC0C0C0
# define COLOR_ORANGE    0xFFA500
# define COLOR_PURPLE    0x800080
# define COLOR_PINK      0xFFC0CB
# define COLOR_BROWN     0xA52A2A

// ----------------------------
// Keyboard input (X11)
// ----------------------------
# define KEY_ESC    65307
# define KEY_LEFT   65361
# define KEY_UP     65362
# define KEY_RIGHT  65363
# define KEY_DOWN   65364
# define KEY_PLUS   61
# define KEY_MINUS  45
# define KEY_SPACE  32
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100
# define KEY_F      102
# define KEY_H      104
# define KEY_J      106
# define KEY_K      107
# define KEY_L      108
# define KEY_W      119
# define KEY_Q      113
# define KEY_E      101
# define KEY_R      114

// ----------------------------
// Mouse input (X11)
// ----------------------------
# define MOUSE_LEFT        1
# define MOUSE_RIGHT       2
# define MOUSE_MIDDLE      3
# define MOUSE_SCROLL_UP   4
# define MOUSE_SCROLL_DOWN 5
# define MOUSE_CLICK       1  // Preferimos click izquierdo por convención

// ----------------------------
// Events
// ----------------------------
# define CLOSE_EVENT 17

// ----------------------------
// Fractal config
// ----------------------------
# define ZOOM_FACTOR 1.1
# define MAX_ITERATIONS 100

# define JULIA         0
# define JULIA_STR     "julia"
# define MANDELBROT    1
# define MANDELBROT_STR "mandelbrot"
# define BURNING_SHIP  2
# define BURNING_SHIP_STR "burning_ship"

# define NUM_PALETTES 5

#endif
