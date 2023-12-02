#ifndef server_funcs_h_included
#define server_funcs_h_included //nao sei se isto é preciso

#include <ncurses.h>
#include "remote-char.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <stdlib.h>
#include <zmq.h>

typedef struct ch_info_t
{
    int ch;
    int pos_x, pos_y;
} ch_info_t;

direction_t random_direction();

void new_position(int* x, int *y, direction_t direction);
int find_ch_info(ch_info_t char_data[], int n_char, int ch);
