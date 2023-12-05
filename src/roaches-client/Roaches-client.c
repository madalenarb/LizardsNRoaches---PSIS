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

// int main()
// {	 
//     char answer[10];
//     // Initialize the ZeroMQ context and socket
//     void *context = zmq_ctx_new();
//     void *socket = zmq_socket(context, ZMQ_REQ);
//     zmq_connect(socket, "tcp://localhost:5555");

//     //TODO_5
//     // read the character from the user
//     char ch;
//     do{
//         printf("what is your symbol(a..z)?: ");
//         ch = getchar();
//         ch = tolower(ch);  
//     }while(!isalpha(ch));

//     // TODO_6
//     // send connection message
//     message_t m;
//     m.msg_type = MSG_TYPE_LIZARD_CONNECT;
//     m.ch = ch;
//     zmq_send(socket, &m, sizeof(message_t), 0);
//     zmq_recv(socket, answer, 10, 0);

//     int sleep_delay;
//     direction_t direction;
//     int n = 0;
//     int key=0;
//     do
//     {
//         sleep_delay = rand()%700000;
//         n++;
//         usleep(sleep_delay);
//         direction = rand()%4;
//         switch (direction)
//         {
//         case LEFT:
//            printf("%d Going Left   \n", n);
//             break;
//         case RIGHT:
//             printf("%d Going Right   \n", n);
//            break;
//         case DOWN:
//             printf("%d Going Down   \n", n);
//             break;
//         case UP:
//             printf("%d Going Up    \n", n);
//             break;
//         }

//         //TODO_9
//         // prepare the movement message
//         m.direction = direction;
//         m.msg_type = MSG_TYPE_LIZARD_MOVEMENT;

//         if(key != 'x'){
//             zmq_send(socket, &m, sizeof(message_t), 0);
//             zmq_recv(socket, answer, 10, 0);        
//         }
//     } while (key != 'x');

//     endwin();			/* End curses mode		  */
//     zmq_close(socket);
//     zmq_ctx_destroy(context);
 
// 	return 0;
// }
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
    
    /*do{
        printf("what is your symbol(a..z)?: ");
        ch = getchar();
        ch = tolower(ch);  
    }while(!isalpha(ch));
    */
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

    endwin();			/* End curses mode		  */
    zmq_close(socket);
    zmq_ctx_destroy(context);
 
	return 0;
}
