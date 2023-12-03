#ifndef LIZARD_LIST_H
#define LIZARD_LIST_H

#include "../../common/protocol.h"

typedef struct LizardClient{
    char id; // id of the Lizard client
    int position_x, position_y; // position of the Lizard client
    int score; // score of the Lizard client

    struct LizardClient *next; // pointer to the next Lizard client
} LizardClient;

#endif /* LIZARD_LIST_H */