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
#include "timer.h"
#include <unistd.h>
#include <signal.h>
// #include <zlib.h>
extern volatile sig_atomic_t flag_exit;

#include "constants.h"

#define MSG_TYPE_LIZARD_CONNECT 0
#define MSG_TYPE_LIZARD_MOVEMENT 1
#define MSG_TYPE_ROACHES_CONNECT 2
#define MSG_TYPE_ROACHES_MOVEMENT 3
#define MSG_TYPE_ACK 5
#define MSG_TYPE_SCORE_UPDATE 6
#define MSG_TYPE_DISCONNECT -1

typedef enum direction_t {UP, DOWN, LEFT, RIGHT} direction_t;

typedef struct message_t
{   
    int msg_type;
    char ch;
    int N_roaches; // number of roaches sent by the client
    int index; // index of the roachClient
    int roach_index; // index of the roach
    int score_roaches[MAX_ROACHES_PER_CLIENT];
    int score_lizard;
    direction_t direction;
} message_t;

typedef struct message_to_display {
    char content[30][30];  // Conteúdo de cada coordenada (ponto, letra, número, etc.)
} message_to_display;

typedef struct position_t
{
    int position_x;
    int position_y;
} position_t;

#define FIFO_NAME "/tmp/lizard_fifo"

void handle_signal(int signum);

#endif
