#include <SDL2/SDL.h>
#include <stdio.h>
//#include "colores.h"

#define XSIZE 600
#define YSIZE 600
#define MS 10
#define NAVE_LEN 10
#define NAVE_VEL 15





typedef struct Nave Nave;
typedef struct Misil Misil;


struct Nave
{
    int x1,y1;
    int x2,y2;
    int x3,y3;
    int vx,vy;
    Misil *misiles;
};

struct Misil{
    int x1,y1;
    int x2,y2;
    int vx,vy;
    struct Misil *siguiente;
};

void NavePinta(Nave *nave, SDL_Renderer *renderer);
void NaveMueveX(Nave *nave);
void NaveMueveY(Nave *nave);

int main(){
    //char msg[MIN_ARREGLO+10] = "fin del programa";
   // formatear(msg,sizeof(msg),PURPURA,NULL,NEGRITA);

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"error", SDL_GetError(), NULL);
        SDL_Quit();
        return -1;
    }else{
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "ventana_ramdom", "mensaje ramdom", NULL);

    }
    const unsigned char *keys;
    int typeEvent;
    int gameover;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    Nave nave = { XSIZE/2, YSIZE/2, XSIZE/2-NAVE_LEN, YSIZE/2+NAVE_LEN, XSIZE/2 +NAVE_LEN, YSIZE/2 +NAVE_LEN,
        NAVE_VEL,NAVE_VEL,NULL
    };
    
    window = SDL_CreateWindow("game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, XSIZE, YSIZE, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

   
    gameover = 0;
    keys = SDL_GetKeyboardState(NULL);
    while(!gameover){
        if(SDL_PollEvent(&event)){
            typeEvent = event.type;
            if(typeEvent == SDL_QUIT){
                gameover = 1;
            }else if(typeEvent == SDL_MOUSEBUTTONDOWN){
                if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
                    //pendiente...

                }

            }else if(typeEvent == SDL_KEYDOWN){
                
    
                
                
                if(keys[SDL_SCANCODE_ESCAPE]){
                    gameover = 1;
                }else if(keys[SDL_SCANCODE_LEFT]){
                    nave.vx = abs(nave.vx) * (-1);
                    NaveMueveX(&nave);
                    
                    
                }else if(keys[SDL_SCANCODE_RIGHT]){
                    nave.vx = abs(nave.vx);
                    NaveMueveX(&nave);
                }else if(keys[SDL_SCANCODE_UP]){
                    if(nave.y1 <= 10){

                    }else{
                        nave.y1 -= nave.vy;
                        nave.y2 -= nave.vy;
                        nave.y3 -= nave.vy;

                    }
                    

                }else if(keys[SDL_SCANCODE_DOWN]){
                    if(nave.y2 >= YSIZE-10){

                    }else{
                        nave.y1 += nave.vy;
                        nave.y2 += nave.vy;
                        nave.y3 += nave.vy;
                        
                    }

                }else if(keys[SDL_SCANCODE_SPACE]){

                }
            }
        }
        //PANTALLA
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        
        NavePinta(&nave,renderer);
        
        SDL_RenderPresent(renderer);
        //SDL_Delay(10);

        //pintar objeto
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

   // printf("%s\n",msg);
    
    return 0;
}
void NavePinta(Nave *nave, SDL_Renderer *renderer){

    SDL_Point points[4] = {
        {nave->x1,nave->y1},
        {nave->x2,nave->y2},
        {nave->x3,nave->y3},
    };
    points[3] = points[0];
    SDL_RenderDrawLines(renderer,points,4);

}

void NaveMueveX(Nave *nave){
    if(nave->x3 >= XSIZE-10 && nave->vx > 0){
        //derecha
    }else if(nave->x2 <= 10 && nave->vx < 0){
        //izquierda
    }else{
        nave->x1 += nave->vx;
        nave->x2 += nave->vx;
        nave->x3 += nave->vx;

    }
}

void NaveMueveY(Nave *nave);