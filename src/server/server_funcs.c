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
            //printf("position_y: %d\n", lizardClient->position.position_y);
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
            //printf("position_y: %d\n", lizardClient->position.position_y);
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



