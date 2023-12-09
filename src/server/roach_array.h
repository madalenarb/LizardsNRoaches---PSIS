#ifndef ROACHE_LIST_H
#define ROACHE_LIST_H

#include "../../common/protocol.h"
#include "../../common/constants.h"

typedef struct Roach{
    int score;
    direction_t direction;
    position_t position;
} Roach;

typedef struct RoachClientS {
    int id;
    int num_roaches;
    Roach roaches[MAX_ROACHES_PER_CLIENT];
    
    struct RoachClientS *next; // Pointer to next roach in the list
} RoachClientS;



typedef struct RoachClient
{
    int id;
    int score; // id given by the server, the client uses it to verify
    direction_t direction;
    position_t position;
} RoachClient;

RoachClient *initRoachArray();
void addRoachClient(RoachClientS **headRoachList, int *score, int n_roaches, int id_roach);
RoachClientS* findRoachClient(RoachClientS **headRoachList, int id_roach);

#endif /* ROACHE_LIST_H */
