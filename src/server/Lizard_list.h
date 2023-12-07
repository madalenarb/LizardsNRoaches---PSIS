#ifndef LIZARD_LIST_H
#define LIZARD_LIST_H

#include "../../common/protocol.h"
#include "../../common/constants.h"

typedef struct LizardClient{
    char id; // id of the Lizard client
    position_t position; // position of the Lizard client
    direction_t direction; // direction of the Lizard client
    int cauda_x[5]; // x position of tail elements 
    int cauda_y[5]; // y position of tail elements
    int score; // score of the Lizard client
    int connected; // 1 if connected, 0 if disconnected
    struct LizardClient *next; // pointer to the next Lizard client
} LizardClient;


typedef struct roach_message_t
{
    int msg_type; // Define o tipo de mensagem para roaches (por exemplo, MSG_TYPE_ROACHES_CONNECT)
    position_t position; // position of the Lizard client
    direction_t direction; // direction of the Lizard client
    //int N_roaches; // Número de roaches
    int scores_roaches[10]; // Pontuações dos roaches
    int roach_positions_x[10]; // Posições x dos roaches
    int roach_positions_y[10]; // Posições y dos roaches
    int connected; // 1 if connected, 0 if disconnected
} roach_message_t; 


void addLizardClient(LizardClient** headLizardList, char id);
void printList(LizardClient* headLizardList);
void disconnectLizardClient(LizardClient** headLizardList, char id);
void freeList(LizardClient** headLizardList);
LizardClient* findLizardClient(LizardClient* headLizardList, char id);

#endif /* LIZARD_LIST_H */
