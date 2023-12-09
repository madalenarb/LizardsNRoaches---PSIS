// This is Lizard-funcs.c
// This is Lizard-funcs.c
// display_funcs.c
#include "display_funcs.h"

void setupWindows(WINDOW **my_win){
    initscr();			/* Start curses mode 		*/
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    *my_win = newwin(WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
    box(*my_win, 0 , 0);
    wrefresh(*my_win);
}
