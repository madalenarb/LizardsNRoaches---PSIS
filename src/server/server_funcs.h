#ifndef SERVER_FUNCS_H
#define SERVER_FUNCS_H

#include "../../common/constants.h"
#include "../../common/protocol.h"
#include "Lizard_list.h"
#include <assert.h>

void new_position(int* x, int *y, int cauda_x[], int cauda_y[], direction_t direction);
int getIdFromChar(char id_char);
char getCharFromId(int id);

#endif
