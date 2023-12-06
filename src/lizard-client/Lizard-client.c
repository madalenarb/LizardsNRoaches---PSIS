#include "Lizard-funcs.h"

int main()
{
    message_t ACK_server;
    // Initialize the ZeroMQ context and socket
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REQ);
    zmq_connect(socket, "tcp://localhost:5555");

    char ch;
    do{
        printf("what is your character(a..z)?: ");
        ch = getchar();
        ch = tolower(ch);  
    } while (!isalpha(ch));

    // send connection message
    message_t m;
    m.msg_type = MSG_TYPE_LIZARD_CONNECT;
    m.ch = ch;
    zmq_send(socket, &m, sizeof(message_t), 0);
    zmq_recv(socket, &ACK_server, 3, 0);
    m.id = ACK_server.id;

	initscr();			/* Start curses mode 		*/
    cbreak();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */

    int n = 0;

    //TODO_9

    // prepare the movement message
    m.msg_type = MSG_TYPE_LIZARD_MOVEMENT;
    int key;
    do
    {
    	key = getch();		
        n++;
        m.direction = select_direction(key, n, m);

        if (key != 'q'){
            zmq_send(socket, &m, sizeof(m), 0);
            zmq_recv(socket, answer, 3, 0);  
        }
        refresh();			/* Print it on to the real screen */
    }while(key != 'q');
        
    
  	endwin();			/* End curses mode		  */
    m.msg_type = MSG_TYPE_DISCONNECT;
    printf("Sending disconnect message %d\n", m.msg_type);
    zmq_send(socket, &m, sizeof(m), 0);
    zmq_close(socket);
    zmq_close(context);
    printf("Bye\n");
	return 0;
}