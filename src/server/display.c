#include "display.h"

/**
 * 
 * @brief Handles the display update
 * 
 * This function handles the display update by sending the display update message to the display application.
 * 
 * @param socket_display The socket to send the display update message to
 * @param headLizardList The head of the lizard client linked list
 * @param headRoachList The head of the roach client linked list
 * 
*/
void handleDisplayUpdate(void *socket_display, LizardClient *headLizardList, RoachClient *headRoachList)
{
    LizardClient *currentLizardClient = NULL;
    RoachClient *currentRoachClient = NULL;

    display_update_t display_update;
    if(headLizardList == NULL && headRoachList == NULL){
        return;
    }

    if(headLizardList != NULL)
        currentLizardClient = headLizardList;

    while(currentLizardClient != NULL){
        display_update.entity_type = LIZARD;
        display_update.position = currentLizardClient->position;
        display_update.direction = currentLizardClient->direction;
        display_update.ch = currentLizardClient->id;
        display_update.score = currentLizardClient->score;

        zmq_send(socket_display, &display_update, sizeof(display_update_t), 0);

        currentLizardClient = currentLizardClient->next;
    }

    if(headRoachList != NULL)
        currentRoachClient = headRoachList;

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
