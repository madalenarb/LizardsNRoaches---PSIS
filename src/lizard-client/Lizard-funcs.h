#ifndef lizard_funcs_h_included
#define lizard_funcs_h_included //nao sei se isto é preciso


#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <ctype.h> 
#include <stdlib.h>
#include <zmq.h>

typedef enum direction_t {UP, DOWN, LEFT, RIGHT} direction_t;

typedef struct remote_char_t
{   
    int msg_type; /* 0 join   1 - move */
    char ch; 
    direction_t direction ;
    /* data */
}remote_char_t;
