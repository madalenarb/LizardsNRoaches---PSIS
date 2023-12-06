#include "server_funcs.h"

void new_position(int* x, int *y, int cauda_x[], int cauda_y[], direction_t direction){
        int i;
        switch (direction)
        {
        case UP:
            (*x) --;
            for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
            {
                cauda_y[i]=*y;
            }
            if(*x ==0){ //caso va contra a parede
                
                for(i=0;i<5;i++)
                {
                    cauda_x[i]=i+2;
                }
                *x = 7; //5 da cauda + 2
            }
            else if(*x==WINDOW_WIDTH-2 || *x==WINDOW_HEIGHT-3 || *x==WINDOW_WIDTH-4 || *x==WINDOW_WIDTH-5|| *x==WINDOW_WIDTH-6) //para a cauda ficar dentro da janela
            {
                *x = WINDOW_WIDTH-7;
                for (i=0;i<5;i++)
                {
                    cauda_x[i]=WINDOW_WIDTH-2-i;
                }
            }
            else
            { 
                for (i=0;i<5;i++)
                {
                    cauda_x[i]= (*x)+i+1;
                }
            }
            break;

        case DOWN:
            (*x) ++;
            for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
            {
                cauda_y[i]=*y;
            }

            if(*x ==WINDOW_WIDTH-1) //caso va contra a parede
            {
                for(i=0;i<5;i++)
                {
                    cauda_x[i]=WINDOW_WIDTH-i-3;
                }
                *x = WINDOW_WIDTH-8;
            }
            else if (*x==1 || *x==2 || *x==3 || *x==4 || *x==5) //para a cauda ficar dentro da janela
            {
                *x = 6;
                for (i=0;i<5;i++)
                {
                    cauda_x[i]=i+1;
                }
            }
            else
            {
                for (i=0;i<5;i++)
                {
                    cauda_x[i]= (*x)-i-1;
                }
            }
            break;
        case LEFT:
            (*y) --;
            for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
            {
                cauda_x[i]=*x;
            }
            if(*y ==0) //caso va contra a parede
            {
                for(i=0;i<5;i++)
                {
                    cauda_y[i]=i+2;
                }
                *y = 7; //5 da cauda + 2
            }
            else if(*y==WINDOW_HEIGHT-2 || *y==WINDOW_HEIGHT-3 || *y==WINDOW_HEIGHT-4 || *y==WINDOW_HEIGHT-5 || *y==WINDOW_HEIGHT-6 ) //para a cauda ficar dentro da janela
            {
                *y = WINDOW_HEIGHT-7;
                for (i=0;i<5;i++)
                {
                    cauda_y[i]=WINDOW_HEIGHT-2-i;
                }
            }
            else
            { 
                for (i=0;i<5;i++)
                {
                    cauda_y[i]= (*y)+i+1;
                }
            }
            break;

        case RIGHT:
            (*y) ++;
            for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
            {
                cauda_x[i]=*x;
            }

            if(*y ==WINDOW_HEIGHT-1) //caso va contra a parede
            {
                for(i=0;i<5;i++)
                {
                    cauda_y[i]=WINDOW_HEIGHT-i-3;
                }
                *y = WINDOW_HEIGHT-8;
            }
            else if (*y==1 || *y==2 || *y==3 || *y==4 || *y==5) //para a cauda ficar dentro da janela
            {
                *y = 6;
                for (i=0;i<5;i++)
                {
                    cauda_y[i]=i+1;
                }
            }
            else
            {
                for (i=0;i<5;i++)
                {
                    cauda_y[i]= (*y)-i-1;
                }
            }
            break;

        default:
            break;
        }
    }

int getIdFromChar(char id_char){
    // Get from an algorithm the ID from the char
    return (((int)id_char + 10042) * 7) % 100128;
}

char getCharFromId(int id){
    //Get from an algorith the char from the ID (reverse of getIdFromChar)
    return (char)(id/7 - 10042);
}