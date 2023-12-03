#include "Lizard-funcs.h"

int main()
{
    char answer[3];
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


    // TODO_6
    // send connection message
    remote_char_t m;
    m.msg_type = 0;
    m.ch = ch;
    zmq_send(socket, &m, sizeof(remote_char_t), 0);
    zmq_recv(socket, answer, 3, 0);

	initscr();			/* Start curses mode 		*/
    cbreak();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */

    int n = 0;

    //TODO_9

    // prepare the movement message
    m.msg_type = 1;
    m.ch = ch;
    
    direction_t direction;

    int key;
    do
    {
    	key = getch();		
        n++;
        select_direction(key);
        direction = select_direction(key);

        if (key != 'q'){
            zmq_send(socket, &m, sizeof(m), 0);
            zmq_recv(socket, answer, 3, 0);  
        }
        refresh();			/* Print it on to the real screen */
    }while(key != 'q');
    
    
  	endwin();			/* End curses mode		  */
    zmq_close(socket);
    zmq_close(context);
    printf("Bye\n");
	return 0;
}