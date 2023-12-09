#include "server_funcs.h"

void new_position(LizardClient* lizardClient){
        int i;
        switch (lizardClient->direction)
        {
        case UP:
            (lizardClient->position.position_x)--;
            for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
            {
                lizardClient->cauda_y[i]=lizardClient->position.position_y;
            }
            if(lizardClient->position.position_x ==0){ //caso va contra a parede
                
                for(i=0;i<5;i++)
                {
                    lizardClient->cauda_x[i]=i+2;
                }
               (lizardClient->position.position_x)++; //5 da cauda + 2
            }
            else if(lizardClient->position.position_x==WINDOW_WIDTH-2 || lizardClient->position.position_x==WINDOW_HEIGHT-3 || lizardClient->position.position_x==WINDOW_WIDTH-4 || lizardClient->position.position_x==WINDOW_WIDTH-5|| lizardClient->position.position_x==WINDOW_WIDTH-6) //para a cauda ficar dentro da janela
            {
                lizardClient->position.position_x = WINDOW_WIDTH-7;
                for (i=0;i<5;i++)
                {
                    lizardClient->cauda_x[i]=WINDOW_WIDTH-2-i;
                }
            }
            else
            { 
                for (i=0;i<5;i++)
                {
                    lizardClient->cauda_x[i]= (lizardClient->position.position_x)+i+1;
                }
            }
            break;

        case DOWN:
            (lizardClient->position.position_x) ++;
            for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
            {
                lizardClient->cauda_y[i]=lizardClient->position.position_y;
            }

            if(lizardClient->position.position_x ==WINDOW_WIDTH-1) //caso va contra a parede
            {
                for(i=0;i<5;i++)
                {
                    lizardClient->cauda_x[i]=WINDOW_WIDTH-i-3;
                }
                (lizardClient->position.position_x)--;
            }
            else if (lizardClient->position.position_x==1 || lizardClient->position.position_x==2 || lizardClient->position.position_x==3 || lizardClient->position.position_x==4 || lizardClient->position.position_x==5) //para a cauda ficar dentro da janela
            {
                lizardClient->position.position_x = 6;
                for (i=0;i<5;i++)
                {
                    lizardClient->cauda_x[i]=i+1;
                }
            }
            else
            {
                for (i=0;i<5;i++)
                {
                    lizardClient->cauda_x[i]= (lizardClient->position.position_x)-i-1;
                }
            }
            break;
        case LEFT:
            (lizardClient->position.position_y) --;
            for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
            {
                lizardClient->cauda_x[i]=lizardClient->position.position_x;
            }
            if(lizardClient->position.position_y ==0) //caso va contra a parede
            {
                for(i=0;i<5;i++)
                {
                    lizardClient->cauda_y[i]=i+2;
                }
                (lizardClient->position.position_y)++; //5 da cauda + 2
            }
            else if(lizardClient->position.position_y==WINDOW_HEIGHT-2 || lizardClient->position.position_y==WINDOW_HEIGHT-3 || lizardClient->position.position_y==WINDOW_HEIGHT-4 || lizardClient->position.position_y==WINDOW_HEIGHT-5 || lizardClient->position.position_y==WINDOW_HEIGHT-6 ) //para a cauda ficar dentro da janela
            {
                lizardClient->position.position_y = WINDOW_HEIGHT-7;
                for (i=0;i<5;i++)
                {
                    lizardClient->cauda_y[i]=WINDOW_HEIGHT-2-i;
                }
            }
            else
            { 
                for (i=0;i<5;i++)
                {
                    lizardClient->cauda_y[i]= (lizardClient->position.position_y)+i+1;
                }
            }
            break;

        case RIGHT:
            (lizardClient->position.position_y) ++;
            for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
            {
                lizardClient->cauda_x[i]=lizardClient->position.position_x;
            }

            if(lizardClient->position.position_y ==WINDOW_HEIGHT-1) //caso va contra a parede
            {
                for(i=0;i<5;i++)
                {
                    lizardClient->cauda_y[i]=WINDOW_HEIGHT-i-3;
                }
                (lizardClient->position.position_y) --;
            }
            else if (lizardClient->position.position_y==1 || lizardClient->position.position_y==2 || lizardClient->position.position_y==3 || lizardClient->position.position_y==4 || lizardClient->position.position_y==5) //para a cauda ficar dentro da janela
            {
                lizardClient->position.position_y = 6;
                for (i=0;i<5;i++)
                {
                    lizardClient->cauda_y[i]=i+1;
                }
            }
            else
            {
                for (i=0;i<5;i++)
                {
                    lizardClient->cauda_y[i]= (lizardClient->position.position_y)-i-1;
                }
            }
            break;

        default:
            break;
        }
    }

void new_position_roaches(RoachClient *roachClient, int id){
    switch (roachClient->roaches[id].direction)
    {
    case UP:
        (roachClient->roaches[id].position.position_x) --;
        if(roachClient->roaches[id].position.position_x == 0)
            roachClient->roaches[id].position.position_x = 2;
        break;
    case DOWN:
        (roachClient->roaches[id].position.position_x) ++;
        if(roachClient->roaches[id].position.position_x == WINDOW_HEIGHT-1)
            roachClient->roaches[id].position.position_x = WINDOW_HEIGHT-3;
        break;
    case LEFT:
        (roachClient->roaches[id].position.position_y) --;
        if(roachClient->roaches[id].position.position_y == 0)
            roachClient->roaches[id].position.position_y = 2;
        break;
    case RIGHT:
        (roachClient->roaches[id].position.position_y) ++;
        if(roachClient->roaches[id].position.position_y == WINDOW_WIDTH-1)
            roachClient->roaches[id].position.position_y = WINDOW_WIDTH-3;
        break;
    default:
        break;
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

void renderLizard(WINDOW *my_win, LizardClient *lizardClient){
    wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
    waddch(my_win, lizardClient->id | A_BOLD);	
    for(int i = 0; i < 5; i++){
        wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
        waddch(my_win, (lizardClient->score < 50) ? '.' | A_BOLD : '*' | A_BOLD);
    }
    wrefresh(my_win);
}

void cleanLizard(WINDOW *my_win, LizardClient *lizardClient){
    wmove(my_win, lizardClient->position.position_x, lizardClient->position.position_y);
    waddch(my_win, ' ');
    for(int i = 0; i < 5; i++){
        wmove(my_win, lizardClient->cauda_x[i], lizardClient->cauda_y[i]);
        waddch(my_win, ' ');
    }
    wrefresh(my_win);
}

void updateAndRenderOneLizard(WINDOW *my_win, LizardClient *lizardClient){
    //Update lizard position
    cleanLizard(my_win, lizardClient);
    new_position(lizardClient);

    //Render updated lizard
    renderLizard(my_win, lizardClient);
}


void updateAndRenderLizards(WINDOW *my_win, LizardClient *headLizardList){
    LizardClient *currentLizard = headLizardList;
    while(currentLizard != NULL){
        //Update lizard position
        renderLizard(my_win, currentLizard);
        currentLizard = currentLizard->next;
    }
}

void forceLizardDisconnect(message_t *m, void *socket){
    m->msg_type = MSG_TYPE_DISCONNECT;
    zmq_send(socket, m, sizeof(*m), 0);
}

void handleLizardConnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket, int *nClients){
    if(findLizardClient(*headLizardList, m->ch) != NULL || *nClients >= MAX_CLIENTS){
        forceLizardDisconnect(m, socket);
    } else {
        nClients++;
        m->msg_type = MSG_TYPE_ACK;
        zmq_send(socket, m, sizeof(*m), 0);
        addLizardClient(headLizardList, m->ch);
        LizardClient *newLizard = findLizardClient(*headLizardList, m->ch);
        renderLizard(my_win, newLizard);
    }
}

void handleLizardMovement(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket){
    LizardClient *lizardClient = findLizardClient(*headLizardList, m->ch);
    // printList(*headLizardList);
    if(lizardClient != NULL){
        lizardClient->direction = m->direction;
        m->msg_type = MSG_TYPE_ACK;
        zmq_send(socket, m, sizeof(*m), 0);
        updateAndRenderOneLizard(my_win, lizardClient);
    } else {
        forceLizardDisconnect(m, socket);
    }
}

void handleLizardDisconnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket, int *nClients){
    LizardClient *lizardClient = findLizardClient(*headLizardList, m->ch);
    if(lizardClient != NULL){
        m->msg_type = MSG_TYPE_DISCONNECT;
        zmq_send(socket, m, sizeof(*m), 0);
        cleanLizard(my_win, lizardClient);
        disconnectLizardClient(headLizardList, m->ch);
        nClients--;
    }
}

void handleRoachesConnect(WINDOW *my_win, RoachClient **headRoachList, message_t *m, void *socket, int *NroachesTotal, int id_roach){
    m->index = id_roach;
    *NroachesTotal += m->N_roaches;
    if(*NroachesTotal>=MAX_ROACHES){
        forceRoachDisconnect(m, socket);
    } 
    else
    {
        m->msg_type = MSG_TYPE_ACK;
        addRoachClient(headRoachList, m->score_roaches, m->N_roaches, id_roach);
        RoachClient *roachClient = findRoachClient(headRoachList, id_roach);

        for (int i = 0; i < roachClient->num_roaches; i++)
        {
            wmove(my_win, roachClient->roaches[i].position.position_x, roachClient->roaches[i].position.position_y);
            waddch(my_win, '0' + roachClient->roaches[i].score);
        }
        wrefresh(my_win);
        zmq_send(socket, m, sizeof(*m), 0);
    }
}

void handleRoachMovement(WINDOW *my_win, RoachClient **headRoachList, message_t *m, direction_t direction,void *socket)
{
    int id_roach = m->index;
    int roach = m->roach_index;
    // printf("id_roach: %d, directiosadsadn: %d\n", id_roach, direction);
    RoachClient *roachClient = findRoachClient(headRoachList, id_roach);
    // printf("id_roach: %d, direction: %d\n", id_roach, direction);
    if(roachClient == NULL){
        // printf("Roach client not found\n");
        forceRoachDisconnect(m, socket);
    } else {
        roachClient->roaches[roach].direction = direction;
        // printf("id %d in direction: %d\n", id_roach, roachClient->roaches[id_roach].direction);
        m->msg_type = MSG_TYPE_ACK;
        renderRoach(my_win, roachClient, roach);

        zmq_send(socket, m, sizeof(*m), 0);
    }
}

void renderRoach(WINDOW *my_win, RoachClient *roachClient, int id){
    wmove(my_win, roachClient->roaches[id].position.position_x, roachClient->roaches[id].position.position_y);
    waddch(my_win, ' ');
    wrefresh(my_win);

    // printf("id %d in direction: %d\n", id, roachClient->roaches[id].direction);
    // printf("posicao x: %d\n", roachClient->roaches[id].position.position_x);
    // printf("posicao y: %d\n", roachClient->roaches[id].position.position_y);
    new_position_roaches(roachClient, id);
    // printf("nova posicao x: %d\n", roachClient->roaches[id].position.position_x);
    // printf("nova posicao y: %d\n", roachClient->roaches[id].position.position_y);
    
    wmove(my_win, roachClient->roaches[id].position.position_x, roachClient->roaches[id].position.position_y);
    waddch(my_win,'0' + roachClient->roaches[id].score);
    wrefresh(my_win);
}

void updateAndRenderRoaches(WINDOW *my_win, RoachClient *headRoachList){
    RoachClient *currentRoachClient = headRoachList;
    while(currentRoachClient != NULL){
        for(int i = 0; i < currentRoachClient->num_roaches; i++){
            wmove(my_win, currentRoachClient->roaches[i].position.position_x, currentRoachClient->roaches[i].position.position_y);
            waddch(my_win,'0' + currentRoachClient->roaches[i].score);
        }
        currentRoachClient = currentRoachClient->next;
    }
    wrefresh(my_win);
}


void disconnectAllLizards(LizardClient **headLizardList, void *socket) {
    LizardClient *currentLizard = *headLizardList;
    while (currentLizard != NULL) {
        
        // Send a message before disconnecting
        // message_t m;
        // zmq_recv(socket, &m, sizeof(m), 0);
        
        // Disconnect lizard
        message_t disconnectMessage;
        disconnectMessage.msg_type = MSG_TYPE_DISCONNECT;
        disconnectMessage.ch = currentLizard->id;
        zmq_send(socket, &disconnectMessage, sizeof(disconnectMessage), 0);
        // Clean and disconnect
        disconnectLizardClient(headLizardList, currentLizard->id);
        currentLizard = currentLizard->next;
    }

    freeList(headLizardList);
}

void forceRoachDisconnect(message_t *m, void *socket){
    m->msg_type = MSG_TYPE_DISCONNECT;
    zmq_send(socket, m, sizeof(*m), 0);
}

void updateDisplayMessage(display_message_t *displayMessage, LizardClient *headLizardList, RoachClient *headRoachList) {
    // Inicializa todas as células como pontos vazios
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            displayMessage->content[i][j] = 0;
        }
    }

    // Adiciona informações sobre lagartos
    LizardClient *currentLizard = headLizardList;
    while (currentLizard != NULL) {
        int x = currentLizard->position.position_x;
        int y = currentLizard->position.position_y;
        displayMessage->content[x][y] = currentLizard->id;
        
        // Adiciona informações sobre a cauda (se houver)
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

    // Adiciona informações sobre baratas
    RoachClient *currentRoach = headRoachList;
    while (currentRoach != NULL) {
        int x = currentRoach->position.position_x;
        int y = currentRoach->position.position_y;
        displayMessage->content[x][y] = '0' + currentRoach->score;

        currentRoach = currentRoach->next;
    }
}

// void lizardHitsLizard()
