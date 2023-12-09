#include "roaches_function.h"
/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <ncurses.h>
#include <zmq.h>
*/
#include <unistd.h>

int main() {
    message_t ACK_server;

    char answer[10];
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REQ);
    zmq_connect(socket, "tcp://localhost:5555");

    message_t m;

    m.msg_type = MSG_TYPE_ROACHES_CONNECT;

    m.N_roaches= rand() % 10 + 1;  // Número aleatório de roaches entre 1 e 10

    for (int i = 0; i < m.N_roaches; i++) {
       m.score_roaches[i] = rand() % 5 + 1;  // Score aleatório entre 1 e 5
       
    }

    zmq_send(socket, &m, sizeof(message_t), 0);
    zmq_recv(socket, &ACK_server, sizeof(message_t), 0);
    if(ACK_server.msg_type == MSG_TYPE_DISCONNECT){
        printf("You have been disconnected\n");
        zmq_close(socket);
        zmq_close(context);
        printf("Bye\n");
        exit(1);
    }
    
    m.msg_type = MSG_TYPE_ROACHES_MOVEMENT;
    //roach_msg.msg_type =MSG_TYPE_ROACHES_MOVEMENT;

    //int sleep_delay;
    direction_t direction;
    int n = 0;
    int key=0;
    do {
        // Preencher os movimentos aleatórios para cada barata
        for (int i = 0; i < m.N_roaches; i++) {
            // Esperar um tempo aleatório antes do movimento de cada barata
           usleep(rand() % 3000000);  // Esperar até 3 segundos


            n++;
            direction = rand() % 4;
            //direction = random()%4;
            switch (direction)
            {
            case LEFT:
            printf("%d Going Left   \n", n);
                break;
            case RIGHT:
                printf("%d Going Right   \n", n);
            break;
            case DOWN:
                printf("%d Going Down   \n", n);
                break;
            case UP:
                printf("%d Going Up    \n", n);
                break;
            }

            m.index=i; //para saber qual o indifice que vamos mudar
            m.msg_type =MSG_TYPE_ROACHES_MOVEMENT;
            m.direction=direction;

            if(key != 'x'){
                zmq_send(socket, &m, sizeof(message_t), 0);
                zmq_recv(socket, answer, 10, 0);           
            }
        }
            
        }while (key != 'x');
   
   // Adicione uma pequena pausa antes de encerrar
    sleep(1);

    endwin();			/* End curses mode		  */
    m.msg_type = MSG_TYPE_DISCONNECT;
    printf("Sending disconnect message %d\n", m.msg_type);

    zmq_send(socket, &m, sizeof(m), 0);
    zmq_close(socket);
    zmq_ctx_destroy(context);

    return 0;
}

