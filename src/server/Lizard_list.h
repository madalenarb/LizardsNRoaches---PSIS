#ifndef LIZARD_LIST_H
#define LIZARD_LIST_H

#include "../../common/protocol.h"
#include "../../common/constants.h"

typedef struct LizardClient{
    int id; // id of the Lizard client
    position_t position; // position of the Lizard client
    int score; // score of the Lizard client
    int connected; // 1 if connected, 0 if disconnected

    struct LizardClient *next; // pointer to the next Lizard client
} LizardClient;

LizardClient* CreateLizardClient(char id);
void addLizardClient(LizardClient** headLizardList, char id);
void printList(LizardClient* headLizardList);
void disconnectLizardClient(LizardClient** headLizardList, char id);
void freeList(LizardClient** headLizardList);
LizardClient* findLizardClient(LizardClient* headLizardList, char id);

#endif /* LIZARD_LIST_H */