#include <stdio.h>
int main(){
    int mat[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    for (int i = 0; i < 4; i++)
    {
        printf("(%d,%d) ",mat[i][0],mat[i][1]);
        
    }
    printf("\n");
    return 0;
}
