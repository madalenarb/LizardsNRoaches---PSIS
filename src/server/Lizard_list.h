#ifndef LIZARD_LIST_H
#define LIZARD_LIST_H

#include "../../common/protocol.h"
#include "../../common/constants.h"

typedef struct LizardClient{
    char id; // id of the Lizard client
    position_t position; // position of the Lizard client
    int score; // score of the Lizard client

    struct LizardClient *next; // pointer to the next Lizard client
} LizardClient;

LizardClient* CreateLizardClient(int id);
void addLizardClient(LizardClient** headLizardList, int id);
void printList(LizardClient* headLizardList);
void disconectLizardClient(LizardClient** headLizardList, int id);
void freeList(LizardClient** headLizardList);
LizardClient* findLizardClient(LizardClient* headLizardList, int id);

#endif /* LIZARD_LIST_H */