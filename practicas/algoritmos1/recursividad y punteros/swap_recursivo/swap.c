#include <stdio.h>
// 3456 -> 6543
int swap_dig(int n){
    
    if (n < 10)
    {
        return n;
    }else{
        
        int ud = n%10;
        int l = 1;
        int aux =n;    
        while(aux>=10){
            aux = aux/10;
            l = l*10;
        }
        return ud*l + swap_dig(n/10);
    }
    
}


int main(){
    printf("%d\n",swap_dig(3456));
    return 0;
}