#include "server_funcs.h"

position_t auxNextPosition(position_t position, direction_t direction){
    position_t nextPosition = position;
    switch (direction)
    {
    case UP:
        nextPosition.position_x--;
        if(nextPosition.position_x == 0){
            nextPosition.position_x++;
        } else if(nextPosition.position_x >= WINDOW_WIDTH-2 && nextPosition.position_x <= WINDOW_WIDTH-6) {
            nextPosition.position_x = WINDOW_WIDTH-7;
        }
        break;
    case DOWN:
        nextPosition.position_x++;
        if(nextPosition.position_x == WINDOW_HEIGHT-1){
            nextPosition.position_x --;
        } else if (nextPosition.position_x >= 1 && nextPosition.position_x <= 5) {
            nextPosition.position_x = 6;
        }
        break;
    case LEFT:
        nextPosition.position_y--;
        if(nextPosition.position_y == 0){
            nextPosition.position_y++;
        } else if(nextPosition.position_y >= WINDOW_HEIGHT-2 && nextPosition.position_y <= WINDOW_HEIGHT-6) {
            nextPosition.position_y = WINDOW_HEIGHT-7;
        }
        break;
    case RIGHT:
        nextPosition.position_y++;
        if(nextPosition.position_y == WINDOW_WIDTH-1){
            nextPosition.position_y--;
        } else if (nextPosition.position_y >= 1 && nextPosition.position_y <= 5) {
            nextPosition.position_y = 6;
        }
        break;
    default:
        break;
    }
    return nextPosition;
}
void new_position(LizardClient* otherLizard){
    int i;
    switch (otherLizard->direction)
    {
    case UP:
        (otherLizard->position.position_x)--;
        for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
        {
            otherLizard->cauda_y[i]=otherLizard->position.position_y;
        }
        if(otherLizard->position.position_x ==0){ //caso va contra a parede
            
            for(i=0;i<5;i++)
            {
                otherLizard->cauda_x[i]=i+2;
            }
            (otherLizard->position.position_x)++; //5 da cauda + 2
        }
        else if(otherLizard->position.position_x==WINDOW_WIDTH-2 || otherLizard->position.position_x==WINDOW_HEIGHT-3 || otherLizard->position.position_x==WINDOW_WIDTH-4 || otherLizard->position.position_x==WINDOW_WIDTH-5|| otherLizard->position.position_x==WINDOW_WIDTH-6) //para a cauda ficar dentro da janela
        {
            otherLizard->position.position_x = WINDOW_WIDTH-7;
            for (i=0;i<5;i++)
            {
                otherLizard->cauda_x[i]=WINDOW_WIDTH-2-i;
            }
        }
        else
        { 
            for (i=0;i<5;i++)
            {
                otherLizard->cauda_x[i]= (otherLizard->position.position_x)+i+1;
            }
        }
        break;

    case DOWN:
        (otherLizard->position.position_x) ++;
        for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
        {
            otherLizard->cauda_y[i]=otherLizard->position.position_y;
        }

        if(otherLizard->position.position_x ==WINDOW_WIDTH-1) //caso va contra a parede
        {
            for(i=0;i<5;i++)
            {
                otherLizard->cauda_x[i]=WINDOW_WIDTH-i-3;
            }
            (otherLizard->position.position_x)--;
        }
        else if (otherLizard->position.position_x >= 1 && otherLizard->position.position_x <= 5)
        {
            otherLizard->position.position_x = 6;
            for (i=0;i<5;i++)
            {
                otherLizard->cauda_x[i]=i+1;
            }
        }
        else
        {
            for (i=0;i<5;i++)
            {
                otherLizard->cauda_x[i]= (otherLizard->position.position_x)-i-1;
            }
        }
        break;
    case LEFT:
        (otherLizard->position.position_y) --;
        for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
        {
            otherLizard->cauda_x[i]=otherLizard->position.position_x;
        }
        if(otherLizard->position.position_y ==0) //caso va contra a parede
        {
            for(i=0;i<5;i++)
            {
                otherLizard->cauda_y[i]=i+2;
            }
            (otherLizard->position.position_y)++; //5 da cauda + 2
        }
        else if(otherLizard->position.position_y==WINDOW_HEIGHT-2 || otherLizard->position.position_y==WINDOW_HEIGHT-3 || otherLizard->position.position_y==WINDOW_HEIGHT-4 || otherLizard->position.position_y==WINDOW_HEIGHT-5 || otherLizard->position.position_y==WINDOW_HEIGHT-6 ) //para a cauda ficar dentro da janela
        {
            otherLizard->position.position_y = WINDOW_HEIGHT-7;
            for (i=0;i<5;i++)
            {
                otherLizard->cauda_y[i]=WINDOW_HEIGHT-2-i;
            }
        }
        else
        { 
            for (i=0;i<5;i++)
            {
                otherLizard->cauda_y[i]= (otherLizard->position.position_y)+i+1;
            }
        }
        break;

    case RIGHT:
        (otherLizard->position.position_y) ++;
        for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
        {
            otherLizard->cauda_x[i]=otherLizard->position.position_x;
        }

        if(otherLizard->position.position_y ==WINDOW_HEIGHT-1) //caso va contra a parede
        {
            for(i=0;i<5;i++)
            {
                otherLizard->cauda_y[i]=WINDOW_HEIGHT-i-3;
            }
            (otherLizard->position.position_y) --;
        }
        else if (otherLizard->position.position_y==1 || otherLizard->position.position_y==2 || otherLizard->position.position_y==3 || otherLizard->position.position_y==4 || otherLizard->position.position_y==5) //para a cauda ficar dentro da janela
        {
            otherLizard->position.position_y = 6;
            for (i=0;i<5;i++)
            {
                otherLizard->cauda_y[i]=i+1;
            }
        }
        else
        {
            for (i=0;i<5;i++)
            {
                otherLizard->cauda_y[i]= (otherLizard->position.position_y)-i-1;
            }
        }
        break;

    default:
        break;
    }
}

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

void renderLizardhead(WINDOW *my_win, LizardClient *otherLizard){
    wmove(my_win, otherLizard->position.position_x, otherLizard->position.position_y);
    waddch(my_win, otherLizard->id | A_BOLD);	
    wrefresh(my_win);
}

void renderLizardTail(WINDOW *my_win, LizardClient *otherLizard){
    for(int i = 0; i < 5; i++){
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

void forceLizardDisconnect(message_t *m, void *socket){
    m->msg_type = MSG_TYPE_DISCONNECT;
    zmq_send(socket, &m, sizeof(message_t), 0);
}

void handleLizardConnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket, int *nClients){
    if(findLizardClient(*headLizardList, m->ch) != NULL || *nClients >= MAX_CLIENTS){
        forceLizardDisconnect(m, socket);
    } else {
        nClients++;
        m->msg_type = MSG_TYPE_ACK;
        m->score_lizard = 0;
        zmq_send(socket, m, sizeof(*m), 0);

        addLizardClient(headLizardList, m->ch);
        LizardClient *newLizard = findLizardClient(*headLizardList, m->ch);
        renderLizardhead(my_win, newLizard);    
        renderLizardTail(my_win, newLizard);
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

int comparePosition(position_t position1, position_t position2){
    if(position1.position_x == position2.position_x && position1.position_y == position2.position_y){
        return 1;
    }
    return 0;
}

int isPositionValid(position_t position){
    return (position.position_x >= 1 && position.position_x < WINDOW_HEIGHT-1 && position.position_y >= 1 && position.position_y < WINDOW_WIDTH-1);
}

void lizardTailOrientation(LizardClient *currentClient){
    int flag = 0;
    for(int i = 0; i < 5; i++){
        position_t newTailPosition;

        switch(currentClient->direction){
            case UP:
                newTailPosition.position_x = currentClient->position.position_x + i + 1;
                newTailPosition.position_y = currentClient->position.position_y;
                break;

            case DOWN:
                newTailPosition.position_x = currentClient->position.position_x - i - 1;
                newTailPosition.position_y = currentClient->position.position_y;
                break;

            case LEFT:
                newTailPosition.position_y = currentClient->position.position_y + i + 1;
                newTailPosition.position_x = currentClient->position.position_x;
                break;

            case RIGHT:
                newTailPosition.position_y = currentClient->position.position_y - i - 1;
                newTailPosition.position_x = currentClient->position.position_x;
                break;

            default:
                break;
        }
        flag = isPositionValid(newTailPosition);

    }
    if(flag == 1){
        for(int i = 0; i < 5; i++){
            switch (currentClient->direction){
                case UP:
                    currentClient->cauda_x[i] = currentClient->position.position_x + i + 1;
                    currentClient->cauda_y[i] = currentClient->position.position_y;
                    break;
                case DOWN:
                    currentClient->cauda_x[i] = currentClient->position.position_x - i - 1;
                    currentClient->cauda_y[i] = currentClient->position.position_y;
                    break;
                case LEFT:
                    currentClient->cauda_y[i] = currentClient->position.position_y + i + 1;
                    currentClient->cauda_x[i] = currentClient->position.position_x;
                    break;
                case RIGHT:
                    currentClient->cauda_y[i] = currentClient->position.position_y - i - 1;
                    currentClient->cauda_x[i] = currentClient->position.position_x;
                    break;
                default:
                    break;
            }
        }
    }
}


void lizardHitsLizard(WINDOW *my_win, LizardClient **headLizardList, LizardClient *currentLizard){
    LizardClient *otherLizard = *headLizardList;
    position_t nextPosition1 = auxNextPosition(currentLizard->position, currentLizard->direction);
    int new_score = 0;
    int flag = 0;
    while(otherLizard != NULL){
        if(otherLizard->id != currentLizard->id){
            if(comparePosition(nextPosition1, otherLizard->position)){
                new_score = (otherLizard->score + currentLizard->score)/2;
                cleanLizard(my_win, currentLizard);
                lizardTailOrientation(currentLizard);
                renderLizardTail(my_win, currentLizard);
                otherLizard->score = new_score;
                currentLizard->score = new_score;

    
                flag = 1;
            }
        }
        otherLizard = otherLizard->next;
    }
    if(flag == 0){
        updateAndRenderOneLizard(my_win, currentLizard);
    }
}




void cleanRoach(WINDOW *my_win, RoachClient *roachClient, int id){
    wmove(my_win, roachClient->roaches[id].position.position_x, roachClient->roaches[id].position.position_y);
    waddch(my_win, ' ');
    wrefresh(my_win);
}


void lizardEatsRoach(WINDOW *my_win, RoachClient **headRoachList, LizardClient *currentLizard){
    RoachClient *roachClient = *headRoachList;
    while(roachClient != NULL){
        for(int i = 0; i < roachClient->num_roaches; i++){
            if(comparePosition(currentLizard->position, roachClient->roaches[i].position)){
                currentLizard->score += roachClient->roaches[i].score;

                cleanRoach(my_win, roachClient, i);
                roachClient->roaches[i].on_board = 0;
                roachClient->roaches[i].eaten_time = elapsed_time;
            }
        }
        roachClient = roachClient->next;
    }
}


void handleLizardMovement(WINDOW *my_win, LizardClient **headLizardList, RoachClient **headRoachList, message_t *m, void *socket){
    LizardClient *otherLizard = findLizardClient(*headLizardList, m->ch);
    if(otherLizard != NULL){
        otherLizard->direction = m->direction;
        m->msg_type = MSG_TYPE_ACK;
        lizardHitsLizard(my_win, headLizardList, otherLizard);
        lizardEatsRoach(my_win, headRoachList, otherLizard);
        m->direction = otherLizard->direction;
        m->score_lizard = otherLizard->score;
        // printf("core lizard: %d\n", m->score_lizard);
        m->ch = otherLizard->id;
        // Before sending the message
        // printf("Sending score: %d\n", m->score_lizard);
        zmq_send(socket, m, sizeof(*m), 0);
    } else {
        forceLizardDisconnect(m, socket);
    }
}



void handleLizardDisconnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket, int *nClients){
    LizardClient *otherLizard = findLizardClient(*headLizardList, m->ch);
    if(otherLizard != NULL){
        m->msg_type = MSG_TYPE_DISCONNECT;
        zmq_send(socket, &m, sizeof(*m), 0);
        cleanLizard(my_win, otherLizard);
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

int checkPositionforLizard(LizardClient *headLizardList, position_t position){
    LizardClient *currentLizard = headLizardList;
    while(currentLizard != NULL){
        if(comparePosition(currentLizard->position, position)){
            return 1;
        }
        currentLizard = currentLizard->next;
    }
    return 0;
}

void handleRoachMovement(WINDOW *my_win, RoachClient **headRoachList, message_t *m, direction_t direction,void *socket, LizardClient *headLizardList)
{
    int id_roach = m->index;
    int roach = m->roach_index;
    // printRoachList(*headRoachList);
    RoachClient *roachClient = findRoachClient(headRoachList, id_roach);
    if(roachClient == NULL){
        forceRoachDisconnect(m, socket);
    } else {
        roachClient->roaches[roach].direction = direction;
        m->msg_type = MSG_TYPE_ACK;
        if(roachClient->roaches[roach].on_board == 1){
            renderRoach(my_win, roachClient, roach, headLizardList);
        }
        
        zmq_send(socket, m, sizeof(*m), 0);
    }
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


void disconnectAllLizards(LizardClient **headLizardList, void *socket) {
    LizardClient *currentLizard = *headLizardList;
    while (currentLizard != NULL) {
        
        // Send a message before disconnecting
        // message_t m;
        // zmq_recv(socket, &m, sizeof(m), 0);
        
        // Disconnect lizard
        // Clean and disconnect
        disconnectLizardClient(headLizardList, currentLizard->id);
        currentLizard = currentLizard->next;
        message_t disconnectMessage;
        disconnectMessage.msg_type = MSG_TYPE_DISCONNECT;
        zmq_send(socket, &disconnectMessage, sizeof(message_t), 0);
    }

    freeList(headLizardList);
}

void forceRoachDisconnect(message_t *m, void *socket){
    m->msg_type = MSG_TYPE_DISCONNECT;
    zmq_send(socket, &m, sizeof(*m), 0);
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
    
    // RoachClient *currentRoach = headRoachList;
    // while (currentRoach != NULL) {
    //     currentRoach.
    //     int x = currentRoach->position.position_x;
    //     int y = currentRoach->position.position_y;
    //     displayMessage->content[x][y] = '0' + currentRoach->score;

    //     currentRoach = currentRoach->next;
    // }

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
