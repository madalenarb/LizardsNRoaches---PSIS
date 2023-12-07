#ifndef SERVER_FUNCS_H
#define SERVER_FUNCS_H

#include "../../common/constants.h"
#include "../../common/protocol.h"
#include "Lizard_list.h"
#include <assert.h>

void setupWindows(WINDOW **my_win);
void renderLizard(WINDOW *my_win, LizardClient *lizardClient);
void cleanLizard(WINDOW *my_win, LizardClient *lizardClient);
void updateAndRenderLizards(WINDOW *my_win, LizardClient *headLizardList);
void new_position(LizardClient* lizardClient);
int getIdFromChar(char id_char);
char getCharFromId(int id);
void handleLizardConnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket, int *n_lizards);
void handleLizardMovement(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket, int *n_lizards);
void handleLizardDisconnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket, int *n_lizards);
void disconnectAllLizards(LizardClient **headLizardList, void *socket);

#endif
