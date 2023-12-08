#include "roach_array.h"

RoachClient *initRoachArray()
{
    RoachClient *roachArray = malloc(sizeof(RoachClient) * MAX_ROACHES);
    for (int i = 0; i < MAX_ROACHES; i++)
    {
        roachArray[i].id = i;
        roachArray[i].score = 0;
        roachArray[i].direction = -1;
    }
    return roachArray;
}

void printRoachArray(RoachClient *roachArray)
{
    for (int i = 0; i < MAX_ROACHES; i++)
    {
        printf("id: %d, score: %d, direction: %d\n", roachArray[i].id, roachArray[i].score, roachArray[i].direction);
    }
}

void freeRoachArray(RoachClient *roachArray)
{
    free(roachArray);
}