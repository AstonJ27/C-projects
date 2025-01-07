#include <stdio.h>
#include <stdlib.h>

#define MAX 9

struct sudoku
{
    int board[MAX][MAX];
    int solucion[MAX][MAX];    
};
typedef struct sudoku sudoku;


void paintMat(int dim, int mat[MAX][MAX], int n)
{
    for(int i = 0; i < dim;i++){
        for(int j = 0; j < dim;j++){
            if(j % n == 0){
                printf("  ");
            }
            printf("%d ", mat[i][j]);
        }
        printf("\n");
        if((i+1)% n == 0){
            printf("\n");
        }
    }
    printf("\n");
}

void paintArr(int n, int arr[MAX])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void refill(int *num, int board[MAX][MAX])
{
    FILE *ent;
    int dim, value;
    ent = fopen("entrada.txt", "r");

    fscanf(ent, "%d", num);
    dim = *num * *num;

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            fscanf(ent, "%d", &value);
            board[i][j] = value;
        }   
    }
    
    printf("TABLERO DE SUDOKU ORIGINAL:\n\n");
    paintMat(dim, board, *num);

    fclose(ent);
}

void getRow(int len, int mat[MAX][MAX], int arr[MAX], int row)
{
    for (int i = 0; i < len; i++)
    {
        arr[i] = mat[row][i];
    }
}

void getCol(int len, int mat[MAX][MAX], int arr[MAX], int col)
{
    for (int i = 0; i < len; i++)
    {
        arr[i] = mat[i][col];
    }
}

void getBox(int len, int mat[MAX][MAX], int arr[MAX][MAX], int row, int col)
{
    int add1, add2;

    add1 = row + 1;
    while(add1 % len != 1){
        add1--;
    }
    
    add2 = col +1;
    while(add2 % len != 1){
        add2--;
    }
    
    add1--;
    add2--;
    int lim_f = add1 + len;
    int lim_c = add2 + len; 

    for(int i = add1; i < lim_f; i++){
        for(int j = add2; j < lim_c; j++){
            
        }
    }
    

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            arr[i][j] = mat[i + add1][j + add2];
        }
    }
    
}

int valida(int alternativa, int board[MAX][MAX], int n, int row, int col)
{
    int arrR[MAX], arrC[MAX], arrB[MAX][MAX];

    getBox(n, board, arrB, row, col);
    getRow(n*n, board, arrR, row);
    getCol(n*n, board, arrC, col);

    for (int i = 0; i < n*n; i++)
    {
        if (arrR[i] == alternativa)
        {
            return 0;
        }
    }

    for (int i = 0; i < n*n; i++)
    {
        if (arrC[i] == alternativa)
        {
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arrB[i][j] == alternativa)
            {
                return 0;
            }
            
        }
        
    }
    return 1;
    

}

int llena(int n, sudoku sudoku)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sudoku.board[i][j] == 0)
            {
                return 0;
            }
            
        }
        
    }
    return 1;
    
}

int mejor(int dim, int board[MAX][MAX], int solucion[MAX][MAX])
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (board[i][j] > solucion[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void copiar(int dim, int board[MAX][MAX], int solucion[MAX][MAX])
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            solucion[i][j] = board[i][j];
            
        }
        
    }
}

void searchOptimalSolution(int n, sudoku sudoku, int solucion[MAX][MAX], int dim, int *bool)
{
    int row = 0, col = 0, alt = 0, val = 0, mej = 0, i;

    while (row < dim)
    {
        if (col < dim)
        {
            if (!sudoku.board[row][col])
            {

                for (i = 0; i < dim; i++)
                {
                    val = valida(i + 1, sudoku.board, n, row, col);
                    if (val)
                    {                    

                        sudoku.board[row][col] = i + 1;
                        if (llena(dim, sudoku))
                        {
                            *bool += 1;
                            if (*bool == 1)
                            {
                                copiar(dim, sudoku.board, solucion);
                            }
                            
                            mej = mejor(dim, sudoku.board, solucion);

                            if (mej)
                            {
                                copiar(dim, sudoku.board, solucion);
                            }
                        }
                         else
                        {
                            searchOptimalSolution(n, sudoku, solucion, dim, bool);
                        }
                        sudoku.board[row][col] = 0;
                        
                    }
                }    

                if (i == dim || !val)
                {
                    return;
                }                    
            }
            else if (llena(dim, sudoku))
            {
                if (mejor(dim, sudoku.board, sudoku.solucion))
                {
                    copiar(dim, sudoku.board, sudoku.solucion);
                }
            }
            col += 1;
            
        }
        else
        {
            col = 0;
            row += 1;
        }
    }
    

}

int main()
{   
    sudoku sudoku;
    int n, dim, bool;
    int options[MAX], row[MAX], col[MAX], box[MAX][MAX];

    refill(&n, sudoku.board);
    dim = n*n;

    searchOptimalSolution(n, sudoku, sudoku.solucion, dim, &bool);

    if (bool)
    {
        printf("HUBIERON %d SOLUCIONES\n", bool);
        paintMat(dim, sudoku.solucion, n);
    }
    else
    {
        printf("NO HAY SOLUCION");
    }

    return 0;
}