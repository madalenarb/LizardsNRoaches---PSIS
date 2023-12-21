/**
 * @file render_funcs.c
 * @brief Implementation of functions responsible for rendering lizards and managing game windows.
 *
 * This file contains the definitions of functions that handle the rendering of lizard heads and tails,
 * as well as managing the game window and updating lizard positions in the context of the game.
 */

#include "render_funcs.h"   

void updateRoachesVisibility(RoachClient **headRoachList, int id_roach){
    RoachClient *currentRoachClient = findRoachClient(headRoachList, id_roach);

    while(currentRoachClient != NULL){
        for(int i = 0; i < currentRoachClient->num_roaches; i++){
            if(currentRoachClient->roaches[i].on_board == 0){
                if(difftime(elapsed_time, currentRoachClient->roaches[i].eaten_time) >= 5){
                    currentRoachClient->roaches[i].on_board = 1;
                    currentRoachClient->roaches[i].position.position_x = rand() % (WINDOW_HEIGHT-2) + 1;
                    currentRoachClient->roaches[i].position.position_y = rand() % (WINDOW_WIDTH-2) + 1;
                }
            }
        }
        currentRoachClient = currentRoachClient->next;
    }
}

void setupWindows(WINDOW **my_win){
    initscr();			/* Start curses mode 		*/
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    *my_win = newwin(WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
    box(*my_win, 0 , 0);
    wrefresh(*my_win);
}

void renderLizardhead(WINDOW *my_win, LizardClient *otherLizard){
    wmove(my_win, otherLizard->position.position_x, otherLizard->position.position_y);
    waddch(my_win, otherLizard->id | A_BOLD);	
    wrefresh(my_win);
}

void renderLizardTail(WINDOW *my_win, LizardClient *otherLizard){
    for(int i = 0; i < TAIL_LENGTH; i++){
        wmove(my_win, otherLizard->cauda_x[i], otherLizard->cauda_y[i]);
        waddch(my_win, (otherLizard->score < 50) ? '.' | A_BOLD : '*' | A_BOLD);
    }
    wrefresh(my_win);
}

void cleanLizard(WINDOW *my_win, LizardClient *otherLizard){
    wmove(my_win, otherLizard->position.position_x, otherLizard->position.position_y);
    waddch(my_win, ' ');
    for(int i = 0; i < 5; i++){
        wmove(my_win, otherLizard->cauda_x[i], otherLizard->cauda_y[i]);
        waddch(my_win, ' ');
    }
    wrefresh(my_win);
}

void updateAndRenderLizardsHeads(WINDOW *my_win, LizardClient *headLizardList){
    LizardClient *currentLizard = headLizardList;
    while(currentLizard != NULL){
        //Update lizard position
        renderLizardhead(my_win, currentLizard);
        currentLizard = currentLizard->next;
    }
}



void updateAndRenderLizardsTails(WINDOW *my_win, LizardClient *headLizardList){
    LizardClient *currentLizard = headLizardList;
    while(currentLizard != NULL){
        //Update lizard position
        renderLizardTail(my_win, currentLizard);
        currentLizard = currentLizard->next;
    }
}

void updateAndRenderOneLizard(WINDOW *my_win, LizardClient *otherLizard){
    //Update lizard position
    cleanLizard(my_win, otherLizard);
    new_position(otherLizard);

    //Render updated lizard
    renderLizardhead(my_win, otherLizard);
    renderLizardTail(my_win, otherLizard);
}

void renderRoach(WINDOW *my_win, RoachClient *roachClient, int id, LizardClient *headLizardList){
    wmove(my_win, roachClient->roaches[id].position.position_x, roachClient->roaches[id].position.position_y);
    waddch(my_win, ' ');
    wrefresh(my_win);
    position_t nextPosition = auxNextPosition(roachClient->roaches[id].position, roachClient->roaches[id].direction);
    int occupied_position = checkPositionforLizard(headLizardList, nextPosition);
    if(occupied_position == 0){
        new_position_roaches(roachClient, id);
    }

    wmove(my_win, roachClient->roaches[id].position.position_x, roachClient->roaches[id].position.position_y);
    waddch(my_win,'0' + roachClient->roaches[id].score);
    wrefresh(my_win);
}

void updateAndRenderRoaches(WINDOW *my_win, RoachClient *headRoachList){
    RoachClient *currentRoachClient = headRoachList;
    while(currentRoachClient != NULL){
        for(int i = 0; i < currentRoachClient->num_roaches; i++){
            if(currentRoachClient->roaches[i].on_board == 1){
                wmove(my_win, currentRoachClient->roaches[i].position.position_x, currentRoachClient->roaches[i].position.position_y);
                waddch(my_win,'0' + currentRoachClient->roaches[i].score);
            }
        }
        currentRoachClient = currentRoachClient->next;
    }
    wrefresh(my_win);
}


