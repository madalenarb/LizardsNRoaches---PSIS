// displayapp.c
#include <ncurses.h>
#include <zmq.h>
#include "display_funcs.h"

int main() {

    void *context = zmq_ctx_new();
    void *socket_display = zmq_socket(context, ZMQ_PULL);
    int rc_display = zmq_bind(socket_display, "tcp://*:5556");  // Substitua pelo endereço correto
    assert(rc_display == 0);



    // initscr();			/* Start curses mode 		*/
    // cbreak();
    // keypad(stdscr, TRUE);
    // noecho();

    // *my_win = newwin(WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
    // box(*my_win, 0 , 0);

    //initscr(); // Inicializa a biblioteca ncurses
    //noecho();  // Não exibe as teclas pressionadas

    
    //printf("ola!!!!!!!!!");

    WINDOW *my_win;
    setupWindows(&my_win);
  // display_message_t displayMessage;
   message_to_display displayMessage;

    while (1) {
        zmq_recv(socket_display, &displayMessage, sizeof(message_to_display), 0);

        clear();  // Limpa a tela antes de exibir as novas informações


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

        // Adicione aqui qualquer lógica adicional necessária para interação com o usuário

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

