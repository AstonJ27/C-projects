/*#include <stdio.h>
#define MAX 4
int main(){

int v[MAX][MAX], a=0;

for(int i=MAX-1;i>=0;i--)
{
    for(int j=MAX-1;j>=0;j--)
    {
        a++;
        v[i][j] = a ;
    }
}

for(int i=0;i<MAX;i++)
{
    for(int j=0;j<MAX;j++)
    {
        printf("%d ",v[i][j]);
    }
    printf("\n");
}
return 0;
}*/
#include <stdio.h>
#define MAX 4

void fill_matrix(int v[MAX][MAX], int row_index, int col, int a, int j) {
    if (row_index < 0 || col < 0) {
        return;
    }

    int current_num = a + 1;

    v[row_index][col] = current_num;
    fill_matrix(v, row_index, col - 1, current_num, j);
    fill_matrix(v, row_index - 1, col + j-1, current_num, j);
}

int main() {

    int v[MAX][MAX];

    fill_matrix(v, MAX - 1, MAX - 1, 0, MAX);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    return 0;
}