/**
 * @file display_funcs.h
 * @brief Prototypes for display-related functions in the LizardsNRoaches game.
 *
 * This file contains the function prototypes used for setting up and managing the display window using the ncurses library.
 */

#ifndef DISPLAY_FUNCS_H
#define DISPLAY_FUNCS_H

#include "../../common/constants.h"  // Ensure this path is correct and accessible
#include "../../common/protocol.h"
#include <ncurses.h>
#include <assert.h>

#define WINDOW_WIDTH 30   ///< Width of the game window.
#define WINDOW_HEIGHT 30  ///< Height of the game window.

/**
 * @brief Sets up a new ncurses window for the game display.
 * 
 * @param my_win Pointer to a pointer of WINDOW, representing the game window.
 */
void setupWindows(WINDOW **my_win);

#endif  // DISPLAY_FUNCS_H
