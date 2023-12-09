#ifndef ROACHE_LIST_H
#define ROACHE_LIST_H

#include "../../common/protocol.h"
#include "../../common/constants.h"

typedef struct Roach{
    int score;
    direction_t direction;
    position_t position;
} Roach;

typedef struct RoachClient {
    int id;
    int num_roaches;
    Roach roaches[MAX_ROACHES_PER_CLIENT];
    
    struct RoachClient *next; // Pointer to next roach in the list
} RoachClient;


RoachClient *initRoachArray();
void addRoachClient(RoachClient **headRoachList, int *score, int n_roaches, int id_roach);
RoachClient* findRoachClient(RoachClient **headRoachList, int id_roach);

#endif /* ROACHE_LIST_H */
