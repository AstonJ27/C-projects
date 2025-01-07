/*
-El programa solo avanzara cuando ingreses un 1 o un 2 (numeros definidos para escoger una parada).
-El programa asignara asientos aleatorios dentro de los asientos permitidos  Arco:(asientos 1 a 7), Av. Cedeño:(asientos 8 a 20).
-Si los asientos para bajarse en Arco estan llenos cuando se escoja esa opcion el programa le ofrecera al usuario si quiere un asiento a la Av. Cedeño.
-Si los asientos para bajarse en Av. Cedeño estan llenos cuando se escoja esa opcion el programa dara el mensaje "El proximo autobus sale en 15 minutos".
-Si todos los asientos estan llenos se finaliza el programa. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
#define MAX_ARC 7
#define MIN_CED 8
int main()
{
    int autobus[MAX],a,ran_m=0,cont=0,cont2=MAX_ARC;
    char decision[10];
    for(int j=0;j<MAX;j++)
    {
        autobus[j]=0;
    }

    for(int i=0;i<MAX;i++)
    {
        printf("Por favor, digite 1 para “Bajar en Arco”\n");
        printf("Por favor, digite 2 para “Bajar en Av. Cedeño”\n");
        scanf("%d",&a);
        srand(time(0));
        if(a==1 && cont<MAX_ARC)
        {
            system("clear");
            ran_m = (rand()%MAX_ARC);
            while(autobus[ran_m]==1)
            {
                ran_m = (rand()%MAX_ARC);
            }

            autobus[ran_m] = 1;
            printf("Usted esta en la seccion de arco en el asiento %d\n",ran_m+1);
            system("read -p 'Presione Enter para continuar' var");
            system("clear");
            cont++;
        }
        else if(a==1 && cont>=MAX_ARC)
        {
            do
            {
                system("clear");
                printf("Todos los asientos para bajar en arco estan ocupados, ¿acepta que se le asigne un asiento a Av. Cedeño? [s/n]\n");
                scanf("%s",decision);
                system("clear");
            }while(!((decision[0]=='s')||(decision[0]=='n')));
            
            if(decision[0]=='n')
            {
                system("clear");
                printf("El proximo autobus sale en 15 minutos\n");
                i-=1;
                system("read -p 'Presione Enter para continuar' var");
                system("clear");
            }
        }
        if(((decision[0]=='s')||(a==2)) && cont2<MAX)
        {
            system("clear");
            ran_m=(rand()%(MAX-MAX_ARC))+MAX_ARC;
            while(autobus[ran_m]==1)
            {
                ran_m=(rand()%(MAX-MAX_ARC))+MAX_ARC;
            }

            autobus[ran_m] = 1;
            printf("usted esta en la seccion de Av. Cedeño en el asiento %d\n",ran_m+1);
            system("read -p 'Presione Enter para continuar' var");
            system("clear");
            cont2++;
        }
        else if(((decision[0]=='s')||(a==2)) && cont2>=MAX)
        {
            system("clear");
            printf("El proximo autobus sale en 15 minutos\n");
            i-=1;
            system("read -p 'Presione Enter para continuar' var");
            system("clear");
        }
        if(a<1 || a>2)
        {
            printf("Eleccion desconocida\n");
            i-=1;
            system("read -p 'Presione Enter para continuar' var");
            system("clear");
        }    
    } 
    printf("El autobus esta lleno\n");
    return 0;
}
