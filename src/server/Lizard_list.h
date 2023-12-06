#ifndef LIZARD_LIST_H
#define LIZARD_LIST_H

#include "../../common/protocol.h"
#include "../../common/constants.h"

typedef struct LizardClient{
    char id; // id of the Lizard client
    position_t position; // position of the Lizard client
    int cauda_x[5]; // x position of tail elements 
    int cauda_y[5]; // y position of tail elements
    int score; // score of the Lizard client
    int connected; // 1 if connected, 0 if disconnected char ch; // character of the Lizard client

    struct LizardClient *next; // pointer to the next Lizard client
} LizardClient;


void addLizardClient(LizardClient** headLizardList, char id);
void printList(LizardClient* headLizardList);
void disconnectLizardClient(LizardClient** headLizardList, char id);
void freeList(LizardClient** headLizardList);
LizardClient* findLizardClient(LizardClient* headLizardList, char id);

#endif /* LIZARD_LIST_H */
