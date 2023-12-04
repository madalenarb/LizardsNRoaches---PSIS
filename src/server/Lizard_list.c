#include "Lizard_list.h"

// Create a new LizardClient
LizardClient* CreateLizardClient(int id){
    LizardClient* newClient = malloc(sizeof(LizardClient));
    if(newClient == NULL){
        perror("malloc lizardClient");
        exit(EXIT_FAILURE);
    }
    newClient->id = id;
    newClient->position.position_x = WINDOW_SIZE/2;
    newClient->position.position_y = WINDOW_SIZE/2;
    newClient->score = 0;
    newClient->next = NULL;
    return newClient;
}


// Add a new LizardClient to the end of the list
void addLizardClient(LizardClient** headLizardList, int id){
    LizardClient* lizardClient = CreateLizardClient(id);
    if(*headLizardList == NULL){
        *headLizardList = lizardClient;
    } else {
        LizardClient* current = *headLizardList;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = lizardClient;
    }
}

// Print the list of LizardClient
void printList(LizardClient* headLizardList){
    LizardClient* current = headLizardList;
    while(current != NULL){
        printf("id: %d, position: %d, %d, score: %d\n", current->id, current->position.position_x, current->position.position_y, current->score);
        current = current->next;
    }
}

// Disconect a LizardClient from the list
void disconectLizardClient(LizardClient** headLizardList, int id){
    LizardClient* current = *headLizardList, *prev;
    if(current != NULL && current->id == id){
        *headLizardList = current->next;
        free(current);
        return;
    }
    while(current != NULL && current->id != id){
        prev = current;
        current = current->next;
    }
    if(current == NULL) return;
    prev->next = current->next;
    free(current);
}

// Free the list of LizardClient
void freeList(LizardClient** headLizardList){
    LizardClient* current;
    while(*headLizardList != NULL){
        current = *headLizardList;
        *headLizardList = (*headLizardList)->next;
        free(current);
    }
}

// Get the LizardClient with the id
LizardClient* findLizardClient(LizardClient* headLizardList, int id){
    LizardClient* current = headLizardList;
    while(current != NULL){
        if(current->id == id){
            return current;
        }
        current = current->next;
    }
    return NULL;
}
