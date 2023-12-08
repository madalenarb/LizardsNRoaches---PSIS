#ifndef SERVER_FUNCS_H
#define SERVER_FUNCS_H

#include "../../common/constants.h"
#include "../../common/protocol.h"
#include "Lizard_list.h"
#include "roach_array.h"
#include <assert.h>

void new_position(LizardClient* lizardClient);
void new_position_roaches(RoachClient *roachArray, int i);
void setupWindows(WINDOW **my_win);
void renderLizard(WINDOW *my_win, LizardClient *lizardClient);
void cleanLizard(WINDOW *my_win, LizardClient *lizardClient);
void handleLizardMovement(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket);
void updateAndRenderOneLizard(WINDOW *my_win, LizardClient *lizardClient);
void updateAndRenderLizards(WINDOW *my_win, LizardClient *headLizardList);
void forceLizardDisconnect(message_t *m, void *socket);
void handleLizardConnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket);
void handleLizardDisconnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket);
void handleRoachesConnect(WINDOW *my_win, RoachClient *roachArray, message_t *m, void *socket, int *NroachesTotal);
void handleRoachMovement(WINDOW *my_win, RoachClient *roachArray, message_t *m, void *socket, int *NroachesTotal);
void renderRoach(WINDOW *my_win, RoachClient *roachArray, int i);
void updateAndRenderRoaches(WINDOW *my_win, RoachClient *roachArray, int N_roaches);
void disconnectAllLizards(LizardClient **headLizardList, void *socket);
void forceRoachDisconnect(message_t *m, void *socket);

#endif /* SERVER_FUNCS_H */
