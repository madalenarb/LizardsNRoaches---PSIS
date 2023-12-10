/**
 * @file display.h
 * @brief Prototypes for functions related to updating the display message in the LizardsNRoaches game.
 *
 * This header file declares the function responsible for updating the display message with the positions and states of lizards and roaches in the game.
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include "roach_array.h"
#include "Lizard_list.h"

/**
 * @brief Updates the display message with the current positions and states of lizards and roaches.
 *
 * @param displayMessage Pointer to the message structure to be updated.
 * @param headLizardList Pointer to the head of the linked list of lizard clients.
 * @param headRoachList Pointer to the head of the linked list of roach clients.
 */
void updateDisplayMessage(message_to_display *displayMessage, LizardClient *headLizardList, RoachClient *headRoachList);

#endif // DISPLAY_H
