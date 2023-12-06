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
    // int n_chars = 0;
    message_t m;
    int id = 0;
	void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(socket, "tcp://*:5555");
    assert(rc == 0);

    //Linked list to manage Lizard clients
    LizardClient* headLizardList = NULL;

    //char char_cauda= '.'; // quando for para imprimir os . descomenta-se
    //int cauda_x[5]={0}; //coordenadas da cauda e inicializados a 0
    //int cauda_y[5]={0};

	// initscr();		    	
	// cbreak();				
    // keypad(stdscr, TRUE);   
	// noecho();			    

    /* creates a window and draws a border */
    WINDOW * my_win = newwin(WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
    box(my_win, 0 , 0);	
	wrefresh(my_win);
    int flag = 0;
    do
    {
        zmq_recv(socket, &m, sizeof(message_t), 0);
        zmq_send(socket, &m, sizeof(m), 0);        
        
        // printf("msg_type: %d, ch: %c, direction: %d\n", m.msg_type, m.ch, m.direction);
        // int ch_pos = find_ch_info(char_data, n_chars, m.ch);
        if(m.msg_type == MSG_TYPE_LIZARD_CONNECT){
            LizardClient* lizardClient = findLizardClient(headLizardList, m.ch);
            if(lizardClient == NULL){
                addLizardClient(&headLizardList, m.ch);
            }
            
        } else if(m.msg_type == MSG_TYPE_LIZARD_MOVEMENT){
            
            LizardClient* lizardClient = findLizardClient(headLizardList, m.ch);
            if(lizardClient != NULL){
                //Calculates new mark position
                //new_position(&lizardClient->position.position_x, &lizardClient->position.position_y,cauda_x,cauda_y, m.direction);
		        new_position(&lizardClient->position.position_x, &lizardClient->position.position_y,lizardClient->cauda_x,lizardClient->cauda_y, m.direction);
            } else {
                printf("LizardClient not found\n");
            }
        } else if(m.msg_type == MSG_TYPE_DISCONNECT){
            disconnectLizardClient(&headLizardList, m.ch);
            // printf("LizardClient %c disconnected\n", m.ch);
        }

        /* draw mark on new position */	
        printList(headLizardList);
	/*for(int i=0; i<5; i++)
        {
            printf("cauda_x[%d]=%d cauda_y[%d]=%d\n", i, cauda_x[i], i, cauda_y[i]);
        }*/
        if(headLizardList == NULL){
            flag = -1;
        }
    } while (flag != -1);
  	// endwin();			/* End curses mode		  */
    // freeList(&headLizardList);
    // zmq_close(socket);
    // zmq_ctx_destroy(context);
	return 0;
}
