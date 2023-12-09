#ifndef SERVER_FUNCS_H
#define SERVER_FUNCS_H

#include "../../common/constants.h"
#include "../../common/protocol.h"
#include "Lizard_list.h"
#include "roach_array.h"
#include <assert.h>


typedef struct {
    int content[30][30];
} display_message_t;

void new_position(LizardClient* lizardClient);
void new_position_roaches(RoachClient *roachClient, int id);
void setupWindows(WINDOW **my_win);
void renderLizard(WINDOW *my_win, LizardClient *lizardClient);
void cleanLizard(WINDOW *my_win, LizardClient *lizardClient);
void renderRoach(WINDOW *my_win, RoachClient *roachClient, int id);
void handleLizardMovement(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket);
void updateAndRenderOneLizard(WINDOW *my_win, LizardClient *lizardClient);
void updateAndRenderLizards(WINDOW *my_win, LizardClient *headLizardList);
void forceLizardDisconnect(message_t *m, void *socket);
void handleLizardConnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket, int *nClients);
void handleLizardDisconnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket, int *nClients);
void handleRoachesConnect(WINDOW *my_win, RoachClient **headRoachList, message_t *m, void *socket, int *NroachesTotal, int id_roach);
void handleRoachMovement(WINDOW *my_win, RoachClient **headRoachList, message_t *m, direction_t direction,void *socket);
void updateAndRenderRoaches(WINDOW *my_win, RoachClient *headRoachList);
void disconnectAllLizards(LizardClient **headLizardList, void *socket);
void forceRoachDisconnect(message_t *m, void *socket);
void updateDisplayMessage(display_message_t *displayMessage, LizardClient *headLizardList, RoachClient *headRoachList);

#endif /* SERVER_FUNCS_H */
