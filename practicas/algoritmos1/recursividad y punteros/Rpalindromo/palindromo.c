#include <stdio.h>
#include <string.h>
#include <ctype.h>

void preparar(char s[], int *t){
    int r = 0;
    *t = strlen(s);
    while(s[r] != '\0'){
        if(!isalpha(s[r])){
            for(int i=r; i<*t; i++){
                s[i] = s[i+1];
            }
            *t -= 1;
            r--;
        }
        else{
            s[r] = tolower(s[r]);
        }
        r++;    
    }


}

_Bool palindromo(char s[], int inf, int sup){
    if(!(s[inf] == s[sup])){
        return 0;
    }else{
        if(inf == sup || sup == inf + 1){
            return 1;
        }
        return 1 && palindromo(s,inf+1,sup-1);
    }

}

int main(){
     
    char n[1000];
    int a = 0;
    printf("entrada:");
    scanf("%[^\n]",n);
    preparar(n,&a);
    
    if(palindromo(n,0,a-1)){
        printf("es palindromo\n");
    }
    else{
        printf("no es palindromo\n");
    }
    
    
    return 0;    
}
