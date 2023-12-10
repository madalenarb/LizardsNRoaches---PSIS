// display_funcs.h
#ifndef DISPLAY_FUNCS_H
#define DISPLAY_FUNCS_H

#include "../../common/constants.h" //nao tava a ir buscar
#include "../../common/protocol.h"
#include <ncurses.h>
#include <assert.h>



#define WINDOW_WIDTH 30
#define WINDOW_HEIGHT 30

void setupWindows(WINDOW **my_win);

#endif  // DISPLAY_FUNCS_H
