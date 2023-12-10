// displayapp.c
#include <ncurses.h>
#include <zmq.h>
#include "display_funcs.h"

int main() {

    void *context = zmq_ctx_new();
    
    // void *socket_display = zmq_socket(context, ZMQ_PULL);
    // int rc_display = zmq_bind(socket_display, "tcp://*:5556");   
    // assert(rc_display == 0);
    
    void *socket_display = zmq_socket(context, ZMQ_SUB);
    int rc_display = zmq_connect(socket_display, "tcp://localhost:5556");
    assert(rc_display == 0);

    // Configurando o assinante para receber todas as mensagens
    zmq_setsockopt(socket_display, ZMQ_SUBSCRIBE, "", 0);

    WINDOW *my_win;
    setupWindows(&my_win);
  
   //message_to_display displayMessage;

    while (1) {
        message_to_display displayMessage;
        
        zmq_recv(socket_display, &displayMessage, sizeof(message_to_display), 0);

        clear();  


        // Exibe as informações na tela usando ncurses
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                if (displayMessage.content[i][j] == 0) {
                    //printw(" ");  // Espaço vazio
                    wmove(my_win, i,j);
                    waddch(my_win, ' ' | A_BOLD);
                } else {
                    //printw("%c", displayMessage.content[i][j]);
                    wmove(my_win, i,j);
                    waddch(my_win, displayMessage.content[i][j] | A_BOLD);
                }
            }
            printw("\n");
        }
        
        wrefresh(my_win);
        //refresh();  // Atualiza a tela


        // Verifica se o usuário pressionou 'q' para sair
        if (getch() == 'q') {
            break;
        }
    }

    endwin();  // Encerra a biblioteca ncurses
    zmq_close(socket_display);
    zmq_ctx_destroy(context);

    return 0;
}

