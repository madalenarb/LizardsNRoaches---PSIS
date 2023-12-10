/**
 * @file display_funcs.c
 * @brief Implementation of functions related to display functionality.
 *
 * This file contains the definitions for functions responsible for displaying messages received from the server using the ncurses library.
 */

#include "display_funcs.h"

/**
 * @brief Initializes and configures a new ncurses window for the game.
 * 
 * This function initializes the ncurses library, sets various terminal modes for the window, creates a new window with specified dimensions, and draws a box around it.
 *
 * @param my_win Pointer to a pointer of WINDOW, which will be assigned to the newly created window.
 */
void setupWindows(WINDOW **my_win) {
    initscr();      // Start curses mode
    cbreak();       // Line buffering disabled
    keypad(stdscr, TRUE);  // Enable function keys
    noecho();       // Don't echo user input
    *my_win = newwin(WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);  // Create new window
    box(*my_win, 0 , 0);  // Draw a box around the window
    wrefresh(*my_win);    // Refresh the window to show box
}
