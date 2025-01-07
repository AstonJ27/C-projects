#include "Lib/Libreria.h"

nodo *ganadorMovimiento(nodo *pila, int a, int b)
{
    pila = addStartTail(pila, a);
    pila = addStartTail(pila, b);

    return(pila);
}

nodo *ganadorGuerra(nodo *pila, nodo *sub1, nodo *sub2, int *move)
{
    int num1, num2;

    while(lenghtPill(sub1) != 0)
    {
        if (sub1->prox == NULL)
        {
            pila = ganadorMovimiento(pila, sub2->info, sub1->info);

            sub1 = deletePill(sub1);
            sub2 = deletePill(sub2);
        }
        else
        {
            num1 = extratClimbPill(sub1);
            num2 = extratClimbPill(sub2);

            pila = ganadorMovimiento(pila, num2, num1);
        }
    }

    return(pila);
}

nodo *subpila(nodo *pila)
{
    nodo *newPila;
    int climb;

    if (lenghtPill(pila) == 2)
    {
        climb = climbElementPill(pila);
        newPila = createPill(climb);

        climb = climbElementPill(pila);
        newPila = addEndPill(newPila, climb);

        pila = deletePill(pila);
    }
    else
    {
        climb = extratClimbPill(pila);
        newPila = createPill(climb);

        climb = extratClimbPill(pila);
        newPila = addEndPill(newPila, climb);

    }
    
    
    return(newPila);
}

void guerra(nodo *ejercito1, nodo *ejercito2, nodo *warior1, nodo *warior2, char *result, int *move)
{
    int climb1, climb2, lenght1, lenght2;
    nodo *sub1, *sub2;

    climb1 = climbElementPill(warior1);
    climb2 = climbElementPill(warior2);
    *move += 2;

    lenght1 = lenghtPill(ejercito1);
    lenght2 = lenghtPill(ejercito2);

    if(lenght1 <= 1 && lenght2 <= 1)
    {
        strcpy(result, "Empate");
        *move += 1;
        return;
    }
    else if(lenght1 <= 1)
    {
        strcpy(result, "Jugador_2");
        *move += 1;
        return;
    }
    else if(lenght2 <= 1)
    {
        strcpy(result, "Jugador_1");
        return;
    }

    if(climb1 > climb2)
    {
        ejercito1 = ganadorGuerra(ejercito1, warior1, warior2, move);
    }
    else if(climb1 < climb2)
    {
        ejercito2 = ganadorGuerra(ejercito2, warior1, warior2, move);
    }
    else
    {
        sub1 = subpila(ejercito1);
        sub2 = subpila(ejercito2);

        guerra(ejercito1, ejercito2, sub1, sub2, result, move);
    }
}

void gameWar(nodo *tail1, nodo *tail2, char *win, int *moves)
{
    nodo *sub1, *sub2;
    int cima1, cima2;

    while(lenghtPill(tail1) > 1 && lenghtPill(tail2) > 1)
    {

        cima1 = extratClimbPill(tail1);
        cima2 = extratClimbPill(tail2);
        *moves += 1;

        if(cima1 > cima2)
        {
            tail1 = ganadorMovimiento(tail1, cima1, cima2);
        }
        else if(cima1 < cima2)
        {
            tail2 = ganadorMovimiento(tail2, cima1, cima2);
        }
        else
        {
            sub1 = subpila(tail1);
            sub2 = subpila(tail2);

            guerra(tail1, tail2, sub1, sub2, win, moves);
        }
    }

    if(lenghtPill(tail1) == 0 && lenghtPill(tail2) == 0)
    {
        strcpy(win, "Empate");
        return;
    }
    else if(lenghtPill(tail1) == 0)
    {
        strcpy(win, "Jugador_2");
        return;
    }
    else if(lenghtPill(tail2) == 0)
    {
        strcpy(win, "Jugador_1");
        return;
    }

}

int main()
{
    FILE *ent, *sal;
    nodo *tail_player1, *tail_player2;
    int casos, val, moves = 0;
    char win[100];

    ent = fopen("guerras.txt", "r");
    sal = fopen("salida.txt", "w");

    fscanf(ent, "%d", &casos);

    for(int i = 0; i < casos; i++)
    {
        fscanf(ent, "%d", &val);
        tail_player1 = createTail(val);

        
        for(int j = 0; j < 25; j++)
        {
            fscanf(ent, "%d", &val);
            tail_player1 = addStartTail(tail_player1, val);
        }

        fscanf(ent, "%d", &val);
        tail_player2 = createTail(val);

        for(int j = 0; j < 25; j++)
        {
            fscanf(ent, "%d", &val);
            tail_player2 = addStartTail(tail_player2, val);
        }

        gameWar(tail_player1, tail_player2, win, &moves);

        fprintf(sal, "%s\n%d\n", win, moves);
        printf("%s\n%d\n", win, moves);
        moves = 0;  
    }

    return(0);
}