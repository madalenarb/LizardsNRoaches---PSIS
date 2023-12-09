#include "roach_array.h"

RoachClient *initRoachArray()
{
    RoachClient *roachArray = malloc(sizeof(RoachClient) * MAX_ROACHES);
    for (int i = 0; i < MAX_ROACHES; i++)
    {
        roachArray[i].score = 0;
        roachArray[i].direction = -1;
    }
    return roachArray;
}

RoachClientS *initRoachClient(int n_roaches, int *score, int id_roach){
    RoachClientS *newRoachClient = (RoachClientS *)malloc(sizeof(RoachClientS));
    if(newRoachClient == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newRoachClient->id = id_roach;
    newRoachClient->num_roaches = n_roaches;
    newRoachClient->next = NULL;
    for(int i = 0; i < n_roaches; i++){
        newRoachClient->roaches[i].score = score[i];
        newRoachClient->roaches[i].direction = UP;
        newRoachClient->roaches[i].position.position_x = rand() % (WINDOW_WIDTH - 2) + 1;
        newRoachClient->roaches[i].position.position_y = rand() % (WINDOW_HEIGHT - 2) + 1;
    }
    return newRoachClient;
}

void addRoachClient(RoachClientS **headRoachList, int *score, int n_roaches, int id_roach){
    RoachClientS *newRoachClient = initRoachClient(n_roaches, score, id_roach);
    if(*headRoachList == NULL){
        *headRoachList = newRoachClient;
    }
    else{
        RoachClientS *currentRoachClient = *headRoachList;
        while(currentRoachClient->next != NULL){
            currentRoachClient = currentRoachClient->next;
        }
        currentRoachClient->next = newRoachClient;
    }
}

RoachClientS* findRoachClient(RoachClientS **headRoachList, int id_roach){
    RoachClientS *currentRoachClient = *headRoachList;
    while(currentRoachClient != NULL){
        if(currentRoachClient->id == id_roach){
            break;
        }
        currentRoachClient = currentRoachClient->next;
    }
    return currentRoachClient;
}

void printRoachList(RoachClientS *headRoachList){
    RoachClientS *currentRoachClient = headRoachList;
    while(currentRoachClient != NULL){
        printf("Positions:\n");
        for(int i = 0; i < currentRoachClient->num_roaches; i++){
            printf("x: %d, y: %d\n", currentRoachClient->roaches[i].position.position_x, currentRoachClient->roaches[i].position.position_y);
        }
        currentRoachClient = currentRoachClient->next;
    }
}

void printRoachArray(RoachClient *roachArray)
{
    for (int i = 0; i < MAX_ROACHES; i++)
    {
        printf("score: %d, direction: %d\n", roachArray[i].score, roachArray[i].direction);
    }
}

void freeRoachArray(RoachClient *roachArray)
{
    free(roachArray);
}