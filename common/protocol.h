#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <ctype.h> 
#include <stdlib.h>
#include <zmq.h>

#include "constants.h"

#define MSG_TYPE_LIZARD_CONNECT 0
#define MSG_TYPE_LIZARD_MOVEMENT 1
#define MSG_TYPE_ROACHES_CONNECT 2
#define MSG_TYPE_ROACHES_MOVEMENT 3
#define MSG_TYPE_DISCONNECT -1

typedef enum direction_t {UP, DOWN, LEFT, RIGHT} direction_t;

typedef struct message_t
{   
    int msg_type; /* 0 join   1 - move */
    char ch;
    direction_t direction;
} remote_char_t;

typedef struct position_t
{
    int position_x;
    int position_y;
} position_t;

#define FIFO_NAME "/tmp/lizard_fifo"

#endif