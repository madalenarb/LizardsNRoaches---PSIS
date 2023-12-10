/**
 * @file display.c
 * @brief Implementation of functions related to updating the display message with information about lizards and roaches.
 *
 * This file contains the definitions for functions responsible for updating the display message with information
 * about the positions of lizards and roaches in the context of the game.
 */
#include "display.h"

void updateDisplayMessage(message_to_display *displayMessage, LizardClient *headLizardList, RoachClient *headRoachList) {
    // Inicializa todas as células como pontos vazios
    for (int i = 0; i < WINDOW_HEIGHT; i++) {
        for (int j = 0; j < WINDOW_WIDTH; j++) {
            displayMessage->content[i][j] = 0;
        }
    }

    // Adiciona informações sobre lagartos
    LizardClient *currentLizard = headLizardList;
    while (currentLizard != NULL) {
        int x = currentLizard->position.position_x;
        int y = currentLizard->position.position_y;
        displayMessage->content[x][y] = currentLizard->id;
        
        // Adds
        for (int i = 0; i < 5; i++) {
            int cauda_x = currentLizard->cauda_x[i];
            int cauda_y = currentLizard->cauda_y[i];
            if (currentLizard->score<50)
                displayMessage->content[cauda_x][cauda_y] = '.';
            else
                displayMessage->content[cauda_x][cauda_y] = '*';
        }

        currentLizard = currentLizard->next;
    }

    RoachClient *currentRoach = headRoachList;
    while (currentRoach != NULL) {
        for (int i = 0; i < currentRoach->num_roaches; i++) {
            int x = currentRoach->roaches[i].position.position_x;
            int y = currentRoach->roaches[i].position.position_y;
            displayMessage->content[x][y] = '0' + currentRoach->roaches[i].score;
        }

        currentRoach = currentRoach->next;
    }
}
// void lizardHitsLizard()
