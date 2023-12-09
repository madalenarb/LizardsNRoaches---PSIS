
// This is Lizard-funcs.c
// display_funcs.h
#ifndef DISPLAY_FUNCS_H
#define DISPLAY_FUNCS_H

#include <ncurses.h>
#include <assert.h>

//#include "../../common/constants.h" //nao tava a ir buscar
//#include "../../common/protocol.h"

#define WINDOW_WIDTH 30
#define WINDOW_HEIGHT 30

typedef struct {
    int content[30][30];
} display_message_t;

void setupWindows(WINDOW **my_win);

#endif  // DISPLAY_FUNCS_H
