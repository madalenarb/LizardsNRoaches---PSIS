#ifndef SERVER_FUNCS_H
#define SERVER_FUNCS_H

#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <stdlib.h>
#include <zmq.h>
#include "../../common/constants.h"
#include <assert.h>

typedef enum direction_t {UP, DOWN, LEFT, RIGHT} direction_t;

typedef struct remote_char_t
{   
    int msg_type; /* 0 join   1-move */
    char ch; 
    direction_t direction ;
    /* data */
}remote_char_t;

typedef struct ch_info_t
{
    int ch;
    int pos_x, pos_y;
} ch_info_t;

direction_t random_direction();

void new_position(int* x, int *y, direction_t direction);
int find_ch_info(ch_info_t char_data[], int n_char, int ch);
#endif