/**
 * @file Display-app.c
 * @brief Main program for the display application, responsible for receiving and displaying messages from the server.
 *
 * This file contains the main program for the display application, which connects to the server, receives messages, and displays them using the ncurses library.
 */
 
#include <ncurses.h>
#include <zmq.h>
#include "display_funcs.h"

int main() {

    void *context = zmq_ctx_new();
    
    // void *socket_display = zmq_socket(context, ZMQ_PULL);
    // int rc_display = zmq_bind(socket_display, "tcp://*:5556");   
    // assert(rc_display == 0);
    
    void *socket_display = zmq_socket(context, ZMQ_SUB);
    int rc_display = zmq_connect(socket_display, "tcp://localhost:5556"); // Change to the server's IP if different
    assert(rc_display == 0);

    zmq_setsockopt(socket_display, ZMQ_SUBSCRIBE, "", 0); // Subscribe to all messages


    // Configurando o assinante para receber todas as mensagens
    zmq_setsockopt(socket_display, ZMQ_SUBSCRIBE, "", 0);

    initscr();  // Inicializa a biblioteca ncurses
    cbreak();  // Desabilita o buffer de entrada
    keypad(stdscr, TRUE);  // Habilita o uso das teclas especiais, como as setas
    noecho();  // Não exibe os caracteres digitados pelo usuário
    curs_set(0);  // Não exibe o cursor na tela
    WINDOW *my_win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);  // Cria uma nova janela
    box(my_win, 0 , 0);  // Adiciona bordas à janela


    message_to_display displayMessage;
   //message_to_display displayMessage;

    while (1) {
        int size = zmq_recv(socket_display, &displayMessage, sizeof(message_to_display), 0);
        if (size == -1) {
            // Handle error
            continue;
        }

        // Process the received display message
        for (int i = 0; i < WINDOW_HEIGHT; i++) {
            for (int j = 0; j < WINDOW_WIDTH; j++) {
                char ch = displayMessage.content[i][j];
                wmove(my_win, i, j);
                if (ch == 0) {
                    waddch(my_win, ' ' | A_BOLD);
                } else {
                    waddch(my_win, ch | A_BOLD);
                }
            }
        }
        wrefresh(my_win);
        
        if (getch() == 'q') {
            break;
        }
    }

    endwin();  // Encerra a biblioteca ncurses
    zmq_close(socket_display);
    zmq_ctx_destroy(context);

    return 0;
}

