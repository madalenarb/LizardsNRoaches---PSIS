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

    //char char_cauda= '.'; // quando for para imprimir os . descomenta-se
    
	initscr();		    	
	cbreak();				
    keypad(stdscr, TRUE);   
	noecho();			    

    /* creates a window and draws a border */
    WINDOW * my_win = newwin(WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
    box(my_win, 0 , 0);	
	wrefresh(my_win);
    int flag = 0;
    do
    {
        zmq_recv(socket, &m, sizeof(message_t), 0);
        if(findLizardClient(headLizardList, m.ch) != NULL && m.msg_type == MSG_TYPE_LIZARD_CONNECT){
            m.msg_type = MSG_TYPE_DISCONNECT;
            m.ch = 'q'; 
            zmq_send(socket, &m, sizeof(m), 0);
        }
        lizardClient->direction=m.direction;
        //// print("msg_type: %d, ch: %c, direction: %d\n", m.msg_type, m.ch, m.direction);
        zmq_send(socket, &m, sizeof(m), 0);

        // // print("msg_type: %d, ch: %c, direction: %d\n", m.msg_type, m.ch, m.direction);
        // int ch_pos = find_ch_info(char_data, n_chars, m.ch);
        if(m.msg_type == MSG_TYPE_LIZARD_CONNECT){
            // print("LizardClient %c connected\n", m.ch);
            addLizardClient(&headLizardList, m.ch);
            n_lizards++;
            // print("n_lizards: %d\n", n_lizards);
            lizardClient = findLizardClient(headLizardList, m.ch);
            wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
            waddch(my_win,lizardClient->id| A_BOLD);
            wrefresh(my_win);	
            for(i=0; i<5; i++)
            {
                wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
                if (lizardClient->score<50)
                    waddch(my_win,'.'| A_BOLD);
                else
                    waddch(my_win,'*'| A_BOLD);
                wrefresh(my_win);
            }
        } else if(m.msg_type == MSG_TYPE_LIZARD_MOVEMENT){
            lizardClient = findLizardClient(headLizardList, m.ch);
            if(lizardClient != NULL){
                //// print("aaaaaaa");
                //atualizar o grafico
                //clean old position
                wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
                waddch(my_win,' ');
                //--------------------
                for(i=0; i<5; i++)
                {
                    wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
                    waddch(my_win,' ');
                }
                wrefresh(my_win);

                new_position(lizardClient);

                lizardClient = findLizardClient(headLizardList, m.ch);
                wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
                waddch(my_win,lizardClient->id| A_BOLD);

                for(int i=0; i<5; i++)
                {
                    wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
                    if (lizardClient->score<50)
                        waddch(my_win,'.'| A_BOLD);
                    else
                        waddch(my_win,'*'| A_BOLD);
                
                }            
                wrefresh(my_win);

                if(lizardClient != NULL){

                    //Calculates new mark position
                    //new_position(&lizardClient->position.position_x, &lizardClient->position.position_y,cauda_x,cauda_y, m.direction);
                    /*for(int i=0; i<5; i++)
                    {
                        lizardClient->cauda_x[i] = lizardClient->position.position_x;
                        lizardClient->cauda_y[i] = lizardClient->position.position_y;
                    }
                    */
                }
            } else {
                //// print("açreaud");
                zmq_recv(socket, &m, sizeof(message_t), 0);
                m.msg_type = MSG_TYPE_DISCONNECT;
                m.ch = 'q'; 
                zmq_send(socket, &m, sizeof(m), 0);
                m.msg_type = -1;
                //apagar o lagarto
                wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
                waddch(my_win,' ');
                printf("LizardClient %c disconnected\n", m.ch);
                //--------------------
                for(i=0; i<5; i++)
                {
                    wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
                    waddch(my_win,' ');
                }
                wrefresh(my_win);
            }
        } else if(m.msg_type == MSG_TYPE_DISCONNECT){
            //// print("LizardClient %c disconnected11111111\n", m.ch);
                lizardClient = findLizardClient(headLizardList, m.ch);

                wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
                waddch(my_win,' ');

                for(i=0; i<5; i++)
                {
                    wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
                    waddch(my_win,' ');
                }

            wrefresh(my_win);
            disconnectLizardClient(&headLizardList, m.ch);

            lizardClient = NULL;

            n_lizards--;
            // printf("LizardClient %c disconnected!!!!\n", m.ch);
        }

        /* draw mark on new position */	
        // printList(headLizardList);
    } while (1);
  	endwin();			/* End curses mode		  */
    freeList(&headLizardList);
    zmq_close(socket);
    zmq_ctx_destroy(context);
	return 0;
}
