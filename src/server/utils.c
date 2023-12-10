#include "utils.h"

position_t auxNextPosition(position_t position, direction_t direction){
    position_t nextPosition = position;
    switch (direction)
    {
    case UP:
        nextPosition.position_x--;
        if(nextPosition.position_x == 0){
            nextPosition.position_x++;
        } else if(nextPosition.position_x >= WINDOW_WIDTH-2 && nextPosition.position_x <= WINDOW_WIDTH-6) {
            nextPosition.position_x = WINDOW_WIDTH-7;
        }
        break;
    case DOWN:
        nextPosition.position_x++;
        if(nextPosition.position_x == WINDOW_HEIGHT-1){
            nextPosition.position_x --;
        } else if (nextPosition.position_x >= 1 && nextPosition.position_x <= 5) {
            nextPosition.position_x = 6;
        }
        break;
    case LEFT:
        nextPosition.position_y--;
        if(nextPosition.position_y == 0){
            nextPosition.position_y++;
        } else if(nextPosition.position_y >= WINDOW_HEIGHT-2 && nextPosition.position_y <= WINDOW_HEIGHT-6) {
            nextPosition.position_y = WINDOW_HEIGHT-7;
        }
        break;
    case RIGHT:
        nextPosition.position_y++;
        if(nextPosition.position_y == WINDOW_WIDTH-1){
            nextPosition.position_y--;
        } else if (nextPosition.position_y >= 1 && nextPosition.position_y <= 5) {
            nextPosition.position_y = 6;
        }
        break;
    default:
        break;
    }
    return nextPosition;
}

int isPositionValid(position_t position){
    return (position.position_x >= 1 && position.position_x < WINDOW_HEIGHT-1 && position.position_y >= 1 && position.position_y < WINDOW_WIDTH-1);
}
