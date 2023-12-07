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
            handleLizardMovement(my_win, &headLizardList, &m, socket, &n_lizards);
            updateAndRenderLizards(my_win, headLizardList);
            break;
        
        case MSG_TYPE_DISCONNECT:
            printList(headLizardList);
            handleLizardDisconnect(my_win, &headLizardList, &m, socket, &n_lizards);
            break;

        default:
            break;
        }

        // // print("msg_type: %d, ch: %c, direction: %d\n", m.msg_type, m.ch, m.direction);
        // int ch_pos = find_ch_info(char_data, n_chars, m.ch);
        // if(m.msg_type == MSG_TYPE_LIZARD_CONNECT){
        //     // print("LizardClient %c connected\n", m.ch);
        //     addLizardClient(&headLizardList, m.ch);
        //     n_lizards++;
        //     // print("n_lizards: %d\n", n_lizards);
        //     lizardClient = findLizardClient(headLizardList, m.ch);
        //     wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
        //     waddch(my_win,lizardClient->id| A_BOLD);
        //     wrefresh(my_win);	
        //     for(i=0; i<5; i++)
        //     {
        //         wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
        //         if (lizardClient->score<50)
        //             waddch(my_win,'.'| A_BOLD);
        //         else
        //             waddch(my_win,'*'| A_BOLD);
        //         wrefresh(my_win);
        //     }
        // } else if(m.msg_type == MSG_TYPE_LIZARD_MOVEMENT){
            
        //     lizardClient = findLizardClient(headLizardList, m.ch);
        //     if(lizardClient != NULL){
        //         //// print("aaaaaaa");
        //         //atualizar o grafico
        //         //clean old position
        //         wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
        //         waddch(my_win,' ');
        //         //--------------------
        //         for(i=0; i<5; i++)
        //         {
        //             wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
        //             waddch(my_win,' ');
        //         }
        //         wrefresh(my_win);

        //         new_position(lizardClient);

        //         lizardClient = findLizardClient(headLizardList, m.ch);
        //         wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
        //         waddch(my_win,lizardClient->id| A_BOLD);

        //         for(int i=0; i<5; i++)
        //         {
        //             wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
        //             if (lizardClient->score<50)
        //                 waddch(my_win,'.'| A_BOLD);
        //             else
        //                 waddch(my_win,'*'| A_BOLD);
                
        //         }            
        //         wrefresh(my_win);

        //         if(lizardClient != NULL){

        //             //Calculates new mark position
        //             //new_position(&lizardClient->position.position_x, &lizardClient->position.position_y,cauda_x,cauda_y, m.direction);
        //             /*for(int i=0; i<5; i++)
        //             {
        //                 lizardClient->cauda_x[i] = lizardClient->position.position_x;
        //                 lizardClient->cauda_y[i] = lizardClient->position.position_y;
        //             }
        //             */
        //         }
        //     } else {
        //         //// print("açreaud");
        //         zmq_recv(socket, &m, sizeof(message_t), 0);
        //         m.msg_type = MSG_TYPE_DISCONNECT;
        //         m.ch = 'q'; 
        //         zmq_send(socket, &m, sizeof(m), 0);
        //         m.msg_type = -1;
        //         //apagar o lagarto
        //         wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
        //         waddch(my_win,' ');
        //         // printf("LizardClient %c disconnected\n", m.ch);
        //         //--------------------
        //         for(i=0; i<5; i++)
        //         {
        //             wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
        //             waddch(my_win,' ');
        //         }
        //         wrefresh(my_win);
        //     }
        // } else if(m.msg_type == MSG_TYPE_DISCONNECT){
        //         // printf("LizardClient %c disconnected11111111\n", m.ch);
        //         lizardClient = findLizardClient(headLizardList, m.ch);

        //         wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
        //         waddch(my_win,' ');

        //         for(i=0; i<5; i++)
        //         {
        //             wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
        //             waddch(my_win,' ');
        //         }

        //     wrefresh(my_win);
        //     disconnectLizardClient(&headLizardList, m.ch);

        //     n_lizards--;
        //     // printf("LizardClient %c disconnected!!!!\n", m.ch);
        // }

        // /* draw mark on new position */	
        // // printList(headLizardList);
    } while (!flag_exit);
  	endwin();			/* End curses mode		  */
    printf("Bye\n");
    disconnectAllLizards(&headLizardList, socket);
    zmq_close(socket);
    zmq_ctx_destroy(context);
	return 0;
}
