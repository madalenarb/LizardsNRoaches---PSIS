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

    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REQ);
    zmq_connect(socket, "tcp://localhost:5555");

    //roach_message_t roach_msg;

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
            usleep(rand() % 1000000);  // Esperar até 1 segundo

            n++;
            direction = rand() % 4;
            direction = random()%4;
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




















/*
int main() {
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REQ);
    zmq_connect(socket, "tcp://localhost:5555");

    roach_message_t roach_msg;

    roach_msg.msg_type = MSG_TYPE_ROACHES_CONNECT;
    roach_msg.N_roaches= rand() % 10 + 1;  // Número aleatório de roaches entre 1 e 10

    for (int i = 0; i < roach_msg.N_roaches; i++) {
        roach_msg.scores_roaches[i] = rand() % 5 + 1;  // Score aleatório entre 1 e 5
        // Preencher as coordenadas aleatórias
        roach_msg.roach_positions_x[i] = rand() % WINDOW_WIDTH;
        roach_msg.roach_positions_y[i] = rand() % WINDOW_WIDTH;
    }

    // Enviar a mensagem de conexão para o servidor
    zmq_send(socket, &roach_msg, sizeof(roach_message_t), 0);

    
    roach_msg.msg_type =MSG_TYPE_ROACHES_MOVEMENT;
    int n = 0;
    int key=0;
    do {
        // Preencher os movimentos aleatórios para cada barata
        for (int i = 0; i < roach_msg.N_roaches; i++) {
            // Esperar um tempo aleatório antes do movimento de cada barata
            usleep(rand() % 1000000);  // Esperar até 1 segundo

            n++;
            int direction = rand() % 4;

            switch (direction) {
                case 0:  // UP
                printf("%d Going UP   \n", n);
                roach_msg.roach_positions_x[i]--;
                if(roach_msg.roach_positions_x[i] ==0){
                roach_msg.roach_positions_x[i] = 2;}
                    break;
                case 1:  // DOWN
                printf("%d Going DOWN   \n", n);
                roach_msg.roach_positions_x[i]++;
                if(roach_msg.roach_positions_x[i] == WINDOW_WIDTH-1){
                    roach_msg.roach_positions_x[i] = WINDOW_WIDTH-3;}
                    break;
                case 2:  // LEFT
                printf("%d Going LETF   \n", n);
                roach_msg.roach_positions_y[i]--;
                if(roach_msg.roach_positions_y[i] ==0){
                    roach_msg.roach_positions_y[i] = 2;}
                    break;
                case 3:  // RIGHT
                printf("%d Going RIGHT   \n", n);
                roach_msg.roach_positions_y[i]++;
                if(roach_msg.roach_positions_y[i] == WINDOW_WIDTH-1){
                    roach_msg.roach_positions_y[i] = WINDOW_WIDTH-3;}
                    break;
                default:
                    break;
            }

            roach_msg.msg_type =MSG_TYPE_ROACHES_MOVEMENT;

            if(key != 'x'){
                zmq_send(socket, &roach_msg, sizeof(roach_message_t), 0);
                //zmq_recv(socket, answer, 10, 0);        
            }
        }
            
        }while (key != 'x');
   

   // Adicione uma pequena pausa antes de encerrar
    sleep(1);

    endwin();			
    zmq_close(socket);
    zmq_ctx_destroy(context);

    return 0;
}
*/
/*


int main() //ver se ja funciona algumas coisas
{	 
    //const char *server_address = argv[1];
    //const char *server_port = argv[2];
    //char ch;
    message_t m;

    char answer[10];
    // Initialize the ZeroMQ context and socket
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REQ);
    zmq_connect(socket, "tcp://localhost:5555");

    //TODO_5
    // read the character from the user
    

   int num_roaches = rand() % 10 + 1;
    // TODO_6
    // send connection message
    
    
    m.msg_type = MSG_TYPE_LIZARD_CONNECT;
    m.ch = 0;
    zmq_send(socket, &m, sizeof(message_t), 0);
    zmq_recv(socket, answer, 10, 0);

    for(int i=0;i<num_roaches;i++)
    {
        int score = rand() % 5 + 1;
        m.ch=score;
        int sleep_delay;
        direction_t direction;
        int n = 0;
        int key=0;
        do
        {
            sleep_delay = rand()%700000;
            usleep(sleep_delay);
            n++;
            direction = rand()%4;
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

            //TODO_9
            // prepare the movement message
            m.direction = direction;
            m.msg_type = MSG_TYPE_LIZARD_MOVEMENT;

            if(key != 'x'){
                zmq_send(socket, &m, sizeof(message_t), 0);
                zmq_recv(socket, answer, 10, 0);        
            }
        } while (key != 'x');
    }

    endwin();			
    zmq_ctx_destroy(context);
 
	return 0;
}
*/
