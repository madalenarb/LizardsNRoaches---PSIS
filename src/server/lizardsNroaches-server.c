#include "server_funcs.h"

/*
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <stdlib.h>
#include <assert.h>
#include <zmq.h>
*/

int main()
{
    signal(SIGINT, handle_signal);
    int n_lizards = 0;
    int i;
    message_t m;
    LizardClient* lizardClient;
    // int id = 0;
	void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(socket, "tcp://*:5555");
    assert(rc == 0);
    

    //Linked list to manage Lizard clients
    LizardClient* headLizardList = NULL;

    WINDOW *my_win;
    setupWindows(&my_win);

    int flag = 0;
    do
    {
        // print("Waiting for message\n");
        zmq_recv(socket, &m, sizeof(message_t), 0);

        switch (m.msg_type)
        {
        case MSG_TYPE_LIZARD_CONNECT:
            handleLizardConnect(my_win, &headLizardList, &m, socket, &n_lizards);
            break;
        
        case MSG_TYPE_LIZARD_MOVEMENT:
            lizardClient = findLizardClient(headLizardList, m.ch);
            handleLizardMovement(my_win, &headLizardList, &m, socket, &n_lizards);
            break;
        
        case MSG_TYPE_DISCONNECT:
            // printList(headLizardList);
            handleLizardDisconnect(my_win, &headLizardList, &m, socket, &n_lizards);
            break;

        default:
            break;
        }
        updateAndRenderLizards(my_win, headLizardList);

    } while (!flag_exit);
  	endwin();			/* End curses mode		  */
    printf("Bye\n");
    disconnectAllLizards(&headLizardList, socket);
    zmq_close(socket);
    zmq_ctx_destroy(context);
	return 0;
}
