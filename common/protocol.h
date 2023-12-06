#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string.h>
#include <ncurses.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <ctype.h> 
#include <stdlib.h>
#include <zmq.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
// #include <zlib.h>


#include "constants.h"

#define MSG_TYPE_LIZARD_CONNECT 0
#define MSG_TYPE_LIZARD_MOVEMENT 1
#define MSG_TYPE_ROACHES_CONNECT 2
#define MSG_TYPE_ROACHES_MOVEMENT 3
#define MSG_TYPE_PASSWORD_REQUEST 4
#define MSG_TYPE_CORRECT_PASSWORD 10
#define MSG_TYPE_WRONG_PASSWORD -10
#define MSG_TYPE_DISCONNECT -1

typedef enum direction_t {UP, DOWN, LEFT, RIGHT} direction_t;

typedef struct message_t
{   
    int msg_type; /* 0 join   1 - move */
    char ch;
    char password[20];
    char id; // id given by the server, the client uses it to verify
    direction_t direction;
} message_t;

typedef struct position_t
{
    int position_x;
    int position_y;
} position_t;

#define FIFO_NAME "/tmp/lizard_fifo"

message_t *init_message();
message_t *create_message(int msg_type, char ch, direction_t direction);
uint32_t checksum(message_t *m);
int is_corrupted(message_t *m);

#endif