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
    //STEP 2
    // int n_chars = 0;

    remote_char_t m;
	void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(socket, "tcp://*:5555");
    assert(rc == 0);


	// initscr();		    	
	// cbreak();				
    // keypad(stdscr, TRUE);   
	// noecho();			    

    // /* creates a window and draws a border */
    // WINDOW * my_win = newwin(WINDOW_SIZE, WINDOW_SIZE, 0, 0);
    // box(my_win, 0 , 0);	
	// wrefresh(my_win);

    int ch;
    int pos_x;
    int pos_y;

    do
    {
        zmq_recv(socket, &m, sizeof(remote_char_t), 0);
        printf("msg_type: %d, ch: %c, direction: %d\n", m.msg_type, m.ch, m.direction);
        // int ch_pos = find_ch_info(char_data, n_chars, m.ch);
        if(m.msg_type == 0){
            // if(ch_pos < 0)
            // {
            ch = m.ch;
            pos_x = WINDOW_SIZE/2;
            pos_y = WINDOW_SIZE/2;

            //STEP 3
            // char_data[n_chars].ch = ch;
            // char_data[n_chars].pos_x = pos_x;
            // char_data[n_chars].pos_y = pos_y;
            // n_chars++;
            // }    
        }
        // if(m.msg_type == 1){
            //STEP 4
            // if(ch_pos != -1){
                // pos_x = char_data[ch_pos].pos_x;
                // pos_y = char_data[ch_pos].pos_y;
                // ch = char_data[ch_pos].ch;

                // /* claculates new mark position */
                // new_position(&pos_x, &pos_y, direction);

            // }        
        // }
        /* draw mark on new position */	
        zmq_send(socket, "OK", 2, 0);
        printf("ch: %c, pos_x: %d, pos_y: %d\n", ch, pos_x, pos_y);
    } while (ch != 'q');
  	endwin();			/* End curses mode		  */

	return 0;
}
