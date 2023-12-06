#ifndef SERVER_FUNCS_H
#define SERVER_FUNCS_H

#include "../../common/constants.h"
#include "../../common/protocol.h"
#include "Lizard_list.h"
#include <assert.h>

void setupWindows(WINDOW **my_win);
void new_position(LizardClient* lizardClient);
int getIdFromChar(char id_char);
char getCharFromId(int id);
void sigintHandler(int sig_num);

#endif
