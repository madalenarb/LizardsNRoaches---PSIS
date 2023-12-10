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
    initializeTimer();
    signal(SIGINT, handle_signal);
    message_t m;
    int id_roach=0;
    int direction = 0;
    int NroachesTotal=0; // 30*30/3=300(numero de roaches total )
    int nClients=0;
    // int id = 0;
	
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(socket, "tcp://*:5555");
    assert(rc == 0);

    //acrescentei agora esta parte
    void *socket_display = zmq_socket(context, ZMQ_PUB);
    int rc_display = zmq_bind(socket_display, "tcp://*:5556");
    assert(rc_display == 0);

    message_to_display display_message;

    //Linked list to manage Lizard clients
    LizardClient* headLizardList = NULL;

    //Linked list to manage Roach clients
    RoachClient* headRoachList = NULL;


    WINDOW *my_win;
    setupWindows(&my_win);
 
    do
    {
        updateTimer();
        zmq_recv(socket, &m, sizeof(message_t), 0);
        switch (m.msg_type)
        {
        case MSG_TYPE_LIZARD_CONNECT:
            handleLizardConnect(my_win, &headLizardList, &m, socket, &nClients);
            break;
        
        case MSG_TYPE_LIZARD_MOVEMENT:
            handleLizardMovement(my_win, &headLizardList, &headRoachList, &m, socket);
            break;
        
        case MSG_TYPE_DISCONNECT:
            handleLizardDisconnect(my_win, &headLizardList, &m, socket, &nClients);
            break;

        case MSG_TYPE_ROACHES_CONNECT:
            id_roach++;
            handleRoachesConnect(my_win, &headRoachList, &m, socket, &NroachesTotal, id_roach);
            break;

        case MSG_TYPE_ROACHES_MOVEMENT:
            direction = m.direction;
            handleRoachMovement(my_win, &headRoachList, &m, direction, socket, headLizardList);
            break;

        default:
            break;
        }
        if(m.msg_type != MSG_TYPE_DISCONNECT){
            m.msg_type = MSG_TYPE_ACK;
            updateRoachesVisibility(&headRoachList, id_roach);
            updateAndRenderLizardsTails(my_win, headLizardList);
            updateAndRenderLizardsHeads(my_win, headLizardList);
            updateAndRenderRoaches(my_win, headRoachList);
        } else {
            zmq_send(socket, &m, sizeof(m), 0);
        }


	updateDisplayMessage(&display_message, headLizardList, headRoachList);

        zmq_send(socket_display, &display_message, sizeof(message_to_display), 0); //envia para o display
	    
    } while (!flag_exit);
  	endwin();			/* End curses mode		  */
    printf("Bye\n");
    disconnectAllLizards(&headLizardList, socket);
<<<<<<< HEAD
    disconnectAllRoaches(&headRoachList, socket);
=======
    zmq_close(socket_display);
>>>>>>> 41f9ae6a39d28a01663cd6c5b944f2f86ce974cf
    zmq_close(socket);
    zmq_ctx_destroy(context);
	return 0;
}
