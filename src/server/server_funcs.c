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
            else if(*x==WINDOW_SIZE-2 || *x==WINDOW_SIZE-3 || *x==WINDOW_SIZE-4 || *x==WINDOW_SIZE-5|| *x==WINDOW_SIZE-6) //para a cauda ficar dentro da janela
            {
                *x = WINDOW_SIZE-7;
                for (i=0;i<5;i++)
                {
                    cauda_x[i]=WINDOW_SIZE-2-i;
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

            if(*x ==WINDOW_SIZE-1) //caso va contra a parede
            {
                for(i=0;i<5;i++)
                {
                    cauda_x[i]=WINDOW_SIZE-i-3;
                }
                *x = WINDOW_SIZE-8;
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
            else if(*y==WINDOW_SIZE-2 || *y==WINDOW_SIZE-3 || *y==WINDOW_SIZE-4 || *y==WINDOW_SIZE-5 || *y==WINDOW_SIZE-6 ) //para a cauda ficar dentro da janela
            {
                *y = WINDOW_SIZE-7;
                for (i=0;i<5;i++)
                {
                    cauda_y[i]=WINDOW_SIZE-2-i;
                }
            }
            else
            { 
                for (i=0;i<5;i++)
                {
                    cauda_y[i]= (*x)+i+1;
                }
            }
            break;

        case RIGHT:
            (*y) ++;
            for (i=0;i<5;i++) //a cauda fica na mesma direção da cabeça
            {
                cauda_x[i]=*x;
            }

            if(*y ==WINDOW_SIZE-1) //caso va contra a parede
            {
                for(i=0;i<5;i++)
                {
                    cauda_y[i]=WINDOW_SIZE-i-3;
                }
                *y = WINDOW_SIZE-8;
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
                    cauda_y[i]= (*x)-i-1;
                }
            }
            break;

        default:
            break;
        }
    }

