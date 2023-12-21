#include "display.h"

void handleDisplayUpdate(void *socket_display, LizardClient *headLizardList, RoachClient *headRoachList)
{
    display_update_t display_update;

    LizardClient *currentLizardClient = headLizardList;
    while(currentLizardClient != NULL){
        display_update.entity_type = LIZARD;
        display_update.position = currentLizardClient->position;
        display_update.direction = currentLizardClient->direction;
        display_update.ch = currentLizardClient->id;
        display_update.score = currentLizardClient->score;

        zmq_send(socket_display, &display_update, sizeof(display_update_t), 0);

        currentLizardClient = currentLizardClient->next;
    }

    RoachClient *currentRoachClient = headRoachList;
    while(currentRoachClient != NULL){
        display_update.entity_type = ROACH;
        for(int i = 0; i < currentRoachClient->num_roaches; i++){
            display_update.position = currentRoachClient->roaches[i].position;
            display_update.score = currentRoachClient->roaches[i].score;
            zmq_send(socket_display, &display_update, sizeof(display_update_t), 0);
        }        
        currentRoachClient = currentRoachClient->next;
    }
}
