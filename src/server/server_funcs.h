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
void renderLizardhead(WINDOW *my_win, LizardClient *lizardClient);
void renderLizardTail(WINDOW *my_win, LizardClient *lizardClient);
void cleanLizard(WINDOW *my_win, LizardClient *lizardClient);
void renderRoach(WINDOW *my_win, RoachClient *roachClient, int id, LizardClient *headLizardList);
void handleLizardMovement(WINDOW *my_win, LizardClient **headLizardList, RoachClient **headRoachList, message_t *m, void *socket);
void updateAndRenderOneLizard(WINDOW *my_win, LizardClient *lizardClient);
void updateAndRenderLizardsHeads(WINDOW *my_win, LizardClient *headLizardList);
void updateAndRenderLizardsTails(WINDOW *my_win, LizardClient *headLizardList);
void forceLizardDisconnect(message_t *m, void *socket);
void handleLizardConnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket, int *nClients);
void handleLizardDisconnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket, int *nClients);
void handleRoachesConnect(WINDOW *my_win, RoachClient **headRoachList, message_t *m, void *socket, int *NroachesTotal, int id_roach);
void handleRoachMovement(WINDOW *my_win, RoachClient **headRoachList, message_t *m, direction_t direction,void *socket, LizardClient *headLizardList);
void updateAndRenderRoaches(WINDOW *my_win, RoachClient *headRoachList);
void disconnectAllLizards(LizardClient **headLizardList, void *socket);
void forceRoachDisconnect(message_t *m, void *socket);
void updateDisplayMessage(message_to_display *displayMessage, LizardClient *headLizardList, RoachClient *headRoachList);

#endif /* SERVER_FUNCS_H */
