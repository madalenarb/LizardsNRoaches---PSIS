/**
 * @file protocol.h
 * @brief This file contains the definitions and structures for the messaging protocol used in the LizardsNRoaches game.
 */

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
#include <assert.h>
// #include <zlib.h>

/**
 * @brief Handles signals, specifically the interrupt signal (SIGINT).
*/
extern volatile sig_atomic_t flag_exit;

#include "constants.h"

#define MSG_TYPE_LIZARD_CONNECT 0
#define MSG_TYPE_LIZARD_MOVEMENT 1
#define MSG_TYPE_ROACHES_CONNECT 2
#define MSG_TYPE_ROACHES_MOVEMENT 3
#define MSG_TYPE_ACK 5
#define MSG_TYPE_SCORE_UPDATE 6
#define MSG_TYPE_DISCONNECT -1


/**
 * @brief Enumerates the possible directions a lizard can move.
*/
typedef enum direction_t {UP, DOWN, LEFT, RIGHT} direction_t;

/**
 * @brief Structure representing a message in the game.
*/
typedef struct message_t
{   
    int msg_type;
    char ch;
    int N_roaches; // number of roaches sent by the client
    int index; // index of the roachClient
    int roach_index; // index of a single roach, which belongs to the roachClient
    int score_roaches[MAX_ROACHES_PER_CLIENT];
    int score_lizard;
    direction_t direction;
} message_t;

/**
 * @brief Structure for the message to be sent to the display application.
*/
typedef struct message_to_display {
    char content[WINDOW_HEIGHT][WINDOW_WIDTH];  // Conteúdo de cada coordenada (ponto, letra, número, etc.)
} message_to_display;


/**
 * @brief Structure representing a position in 2D space.
*/
typedef struct position_t
{
    int position_x;
    int position_y;
} position_t;

#define FIFO_NAME "/tmp/lizard_fifo"

/**
 * @brief Handles signals, specifically the interrupt signal (SIGINT).
 * 
 * @param signum The signal number.
 */
void handle_signal(int signum);

#endif
