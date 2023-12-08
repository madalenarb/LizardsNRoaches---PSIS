#ifndef ROACHE_LIST_H
#define ROACHE_LIST_H

#include "../../common/protocol.h"
#include "../../common/constants.h"

typedef struct RoachClient
{
    int id;
    int score; // id given by the server, the client uses it to verify
    direction_t direction;
    position_t position;
} RoachClient;

RoachClient *initRoachArray();


#endif /* ROACHE_LIST_H */
