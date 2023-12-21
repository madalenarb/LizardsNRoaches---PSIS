#include "display-app.h"

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
    WINDOW *game_win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);
    box(game_win, 0, 0);

    while(1){
        message_t game_update;
        zmq_recv(subscriber, &game_update, sizeof(message_t), 0);
        
    }
    return 0;
}
