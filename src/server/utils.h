#ifndef UTILS_H
#define UTILS_H

#include "../../common/protocol.h"
#include "../../common/constants.h"

position_t auxNextPosition(position_t position, direction_t direction);
int isPositionValid(position_t position);

#endif // UTILS_H