#include "Lizard-funcs.h"

direction_t select_direction(int ch, int n, message_t m){
    switch (ch)
    {
        // If the Left arrow key is pressed
        case KEY_LEFT:
            mvprintw(0,0,"%d Left arrow is pressed", n);
            m.direction = LEFT;
            break;

        // If the Right arrow key is pressed
        case KEY_RIGHT:
            mvprintw(0,0,"%d Right arrow is pressed", n);
            m.direction = RIGHT;
            break;

        // If the Down arrow key is pressed
        case KEY_DOWN:
            mvprintw(0,0,"%d Down arrow is pressed", n);
            m.direction = DOWN;
            break;

        // If the Up arrow key is pressed
        case KEY_UP:
            mvprintw(0,0,"%d :Up arrow is pressed", n);
            m.direction = UP;
            break;

        default:
            break;
    }
    return m.direction;
}

