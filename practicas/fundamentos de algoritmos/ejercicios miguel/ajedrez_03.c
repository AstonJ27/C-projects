#include <stdio.h>

#define FILA 8
#define COLUMNA 8
#define JUGADORES 32

struct coords
{
    int x;
    int y;
};

struct ajedrez
{
    struct coords posicion;
    char pieza;
    char color[10];
};

void cargar(char matriz[FILA][COLUMNA]);
void mensaje(FILE *archivo, struct ajedrez enemy[JUGADORES / 2], int n);
void amenaza(char pieza, struct coords partner, struct ajedrez enemy, char color, struct ajedrez *victima, int *n);
void relleno(struct ajedrez *pieza_a, struct ajedrez pieza_b);

int pawn(char color, int enemy_x, int enemy_y, int partner_x, int partner_y);
int rook(int enemy_x, int enemy_y, int partner_x, int partner_y);
int bishop(int enemy_x, int enemy_y, int partner_x, int partner_y);
int knight(int enemy_x, int enemy_y, int partner_x, int partner_y);

int main(int argc, char *argv[])
{
    FILE *ent, *sal;
    struct ajedrez ataque[JUGADORES], piezas[JUGADORES];
    char pieza, posx, color[10], turno[10], tablero[FILA][COLUMNA];
    int posy, n = 0, m = 0;

    do
    {
        n++;
        ent = fopen(argv[n], "r");
    } while (ent == NULL && n < argc);
    sal = fopen("03-salida-tablero.txt", "w");
    printf("Listo\n");

    cargar(tablero);

    fscanf(ent, "%s", turno);

    while (fscanf(ent, "%d %c %c %s", &posy, &posx, &pieza, piezas[m].color) != EOF)
    {
        tablero[posy - 1][posx - 65] = pieza;

        piezas[m].posicion.x = posx - 65;
        piezas[m].posicion.y = posy - 1;
        piezas[m].pieza = pieza;
        m++;
    }
    n = 0;
    for (int i = 0; i < m; i++)
    {
        if (piezas[i].color[0] == turno[0])
        {
            for (int j = 0; j < m; j++)
            {
                if (piezas[j].color[0] != turno[0])
                {
                    amenaza(piezas[i].pieza, piezas[i].posicion, piezas[j], piezas[i].color[0], &ataque[n], &n);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ataque[i].posicion.x == ataque[j].posicion.x && ataque[i].posicion.y == ataque[j].posicion.y)
            {
                for (int m = i; m < n - 1; m++)
                {
                    relleno(&ataque[m], ataque[m + 1]);
                }
                n -= 1;
            }
        }
    }

    mensaje(sal, ataque, n);

    for (int i = FILA - 1; i >= 0; i--)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            fprintf(sal, "%c", tablero[i][j]);
        }
        fprintf(sal, "\n");
    }

    fclose(ent);
    fclose(sal);

    return 0;
}

void cargar(char matriz[FILA][COLUMNA])
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            matriz[i][j] = '*';
        }
    }
}

void mensaje(FILE *archivo, struct ajedrez enemy[JUGADORES / 2], int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(archivo, "%d %c %c %s\n", enemy[i].posicion.y + 1, enemy[i].posicion.x + 65, enemy[i].pieza, enemy[i].color);
    }
}

void amenaza(char pieza, struct coords partner, struct ajedrez enemy, char color, struct ajedrez *victima, int *n)
{
    int y, x, fily, colx, band;
    struct coords aux1, aux2;

    x = enemy.posicion.x;
    y = enemy.posicion.y;
    colx = partner.x;
    fily = partner.y;

    switch (pieza)
    {
    case 'P':
        if (color == 'W')
        {
            if (fily + 1 < FILA)
            {
                band = pawn(color, x, y, colx, fily + 1);
            }
            
        }
        else
        {
            if (fily - 1 >= 0)
            {
                band = pawn(color, x, y, colx, fily - 1);
            }
        }
        
        if (band)
        {
            relleno(victima, enemy);
            *n += 1;
        }
        break;

    case 'R':
        if (rook(x, y, colx, fily) || rook(x, y, fily, colx))
        {
            relleno(victima, enemy);
            *n += 1;
        }
        break;

    case 'N':
        if (knight(x, y, colx, fily) || rook(x, y, colx, fily))
        {
            relleno(victima, enemy);
            *n += 1;
        }
        break;

    case 'B':
        if (bishop(x, y, colx, fily))
        {
            relleno(victima, enemy);
            *n += 1;
        }
        break;

    case 'Q':
        if (rook(x, y, colx, fily))
        {
            relleno(victima, enemy);
            *n += 1;
        }
        else if (bishop(x, y, colx, fily))
        {
            relleno(victima, enemy);
            *n += 1;
        }
        break;

    case 'K':
        aux1.x = colx + 1;
        aux1.y = fily + 1;

        aux2.x = colx - 1;
        aux2.y = fily - 1;

        if (x >= aux2.x && x <= aux1.x && y >= aux2.y && y <= aux1.y)
        {
            relleno(victima, enemy);
            *n += 1;
        }
        
        break;

    default:
        printf("Pieza no reconocida");
        break;
    }
}

void relleno(struct ajedrez *pieza_a, struct ajedrez pieza_b)
{
    pieza_a->pieza = pieza_b.pieza;
    pieza_a->posicion.x = pieza_b.posicion.x;
    pieza_a->posicion.y = pieza_b.posicion.y;

    for (int i = 0; i < 10; i++)
    {
        pieza_a->color[i] = pieza_b.color[i];
    }
}

int pawn(char color, int enemy_x, int enemy_y, int partner_x, int partner_y)
{
    if ((partner_x - 1 == enemy_x || partner_x + 1 == enemy_x) && partner_y == enemy_y)
    {
        return 1;
    }

    return 0;
}

int rook(int enemy_x, int enemy_y, int partner_x, int partner_y)
{
    for (int m = partner_x; m < COLUMNA; m++)
    {
        if (m == enemy_x && enemy_y == partner_y)
        {
            return 1;
        }
    }
    for (int m = partner_y; m >= 0; m--)
    {
        if (partner_x == enemy_x && enemy_y == m)
        {
            return 1;
        }
    }

    return 0;
}

int bishop(int enemy_x, int enemy_y, int partner_x, int partner_y)
{
    int auxx, auxy;

    auxx = partner_x;
    auxy = partner_y;
    while (auxx < COLUMNA && auxy < FILA)
    {
        auxx += 1;
        auxy += 1;

        if (auxy == enemy_y && auxx == enemy_x)
        {
            return 1;
        }
    }
    
    auxx = partner_x;
    auxy = partner_y;
    while (auxx >= 0 && auxy >= 0)
    {
        auxx -= 1;
        auxy -= 1;

        if (auxy == enemy_y && auxx == enemy_x)
        {
            return 1;
        }
    }
    
    auxx = partner_x;
    auxy = partner_y;
    while (auxx >= 0 && auxy < FILA)
    {
        auxx -= 1;
        auxy += 1;

        if (auxy == enemy_y && auxx == enemy_x)
        {
            return 1;
        }
    }
    
    auxx = partner_x;
    auxy = partner_y;
    while (auxx < COLUMNA && auxy >= 0)
    {
        auxx += 1;
        auxy -= 1;

        if (auxy == enemy_y && auxx == enemy_x)
        {
            return 1;
        }
    }

    return 0;
}

int knight(int enemy_x, int enemy_y, int partner_x, int partner_y)
{
    if (partner_y + 2 < FILA)
    {
        if ((partner_x - 1 == enemy_x || partner_x + 1 == enemy_x) && partner_y + 2 == enemy_y)
        {
            return 1;
        }
    }
    if (partner_x - 2 >= 0)
    {
        if ((partner_y - 1 == enemy_y || partner_y + 1 == enemy_y) && partner_x - 2 == enemy_x)
        {
            return 1;
        }
    }
    return 0;
}
