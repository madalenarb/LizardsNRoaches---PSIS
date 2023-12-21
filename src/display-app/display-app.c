#include "display-app.h"

position_t* DeriveTailPosition(position_t head_position, direction_t direction){
    static position_t tail_position[TAIL_LENGTH];
    for(int i = 0; i < TAIL_LENGTH; i++){
        switch(direction){
            case UP:
                tail_position[i].position_x = head_position.position_x+i+1;
                tail_position[i].position_y = head_position.position_y;
                break;
            case DOWN:
                tail_position[i].position_x = head_position.position_x-i-1;
                tail_position[i].position_y = head_position.position_y;
                break;
            case LEFT:
                tail_position[i].position_x = head_position.position_x;
                tail_position[i].position_y = head_position.position_y + i + 1;
                break;
            case RIGHT:
                tail_position[i].position_x = head_position.position_x;
                tail_position[i].position_y = head_position.position_y - i - 1;
                break;
        }
    }
    return tail_position;
}

int main()
{
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    zmq_connect(subscriber, "tcp://localhost:5556");
    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "", 0);

    initscr();
    cbreak();
    noecho();

    //Set up the window to draw the game in
    WINDOW *display_win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);
    box(display_win, 0, 0);

    display_update_t game_update;
    while(1){
        //Receive the game update message
        zmq_recv(subscriber, &game_update, sizeof(message_t), 0);
        position_t* tailPositions = DeriveTailPosition(game_update.position, game_update.direction);
        //Clear the window
        wclear(display_win);
        box(display_win, 0, 0);

        //check if the entity is a lizard or a roach
        if(game_update.entity_type == LIZARD){
            //Draw the lizard
            mvwaddch(display_win, game_update.position.position_x, game_update.position.position_y, game_update.ch);
            //Draw the tail
            for(int i = 0; i < TAIL_LENGTH; i++){
                mvwaddch(display_win, tailPositions[i].position_x, tailPositions[i].position_y, game_update.ch);
            }
        }
        wrefresh(display_win);
    }
    return 0;
}

