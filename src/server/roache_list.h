#ifndef ROACHE_LIST_H
#define ROACHE_LIST_H

#include "../../common/protocol.h"
#include "../../common/constants.h"

typedef struct roach_message_t
{
    int msg_type; // Define o tipo de mensagem para roaches (por exemplo, MSG_TYPE_ROACHES_CONNECT)
    position_t position; // position of the Lizard client
    direction_t direction; // direction of the Lizard client
    int N_roaches; // Número de roaches
    int score[10]; //score das reoaches
    int score_roaches[10]; // Pontuações dos roaches
    int roach_positions_x[10]; // Posições x dos roaches
    int roach_positions_y[10]; // Posições y dos roaches
    int connected; // 1 if connected, 0 if disconnected
} roach_message_t; 


#endif /* ROACHE_LIST_H */
