#include "Lizard-funcs.h"

direction_t select_direction(int ch){
    switch (ch)
    {
        // If the Left arrow key is pressed
        case KEY_LEFT:
            mvprintw(0,0,"%c Left arrow is pressed", n);
            m.direction = LEFT;
            break;

        // If the Right arrow key is pressed
        case KEY_RIGHT:
            mvprintw(0,0,"%c Right arrow is pressed", n);
            m.direction = RIGHT;
            break;

        // If the Down arrow key is pressed
        case KEY_DOWN:
            mvprintw(0,0,"%c Down arrow is pressed", n);
            m.direction = DOWN;
            break;

        // If the Up arrow key is pressed
        case KEY_UP:
            mvprintw(0,0,"%c :Up arrow is pressed", n);
            m.direction = UP;
            break;

        default:
            key = 'x'; 
            break;
    }
    return m.direction;
}