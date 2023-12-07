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

void updateAndRenderaLizard(WINDOW *my_win, LizardClient *lizardClient){
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

void handleLizardConnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket){
    if(findLizardClient(*headLizardList, m->ch) != NULL){
        forceLizardDisconnect(m, socket);
    } else {
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
        updateAndRenderaLizard(my_win, lizardClient);
    } else {
        forceLizardDisconnect(m, socket);
    }
}

void handleLizardDisconnect(WINDOW *my_win, LizardClient **headLizardList, message_t *m, void *socket){
    LizardClient *lizardClient = findLizardClient(*headLizardList, m->ch);
    if(lizardClient != NULL){
        m->msg_type = MSG_TYPE_DISCONNECT;
        zmq_send(socket, m, sizeof(*m), 0);
        cleanLizard(my_win, lizardClient);
        disconnectLizardClient(headLizardList, m->ch);
    }
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