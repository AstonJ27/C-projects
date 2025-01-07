#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
//#include <sys/types.h>
int main(){
    DIR *carpeta;
    char arr[1024], *sufix;
    struct dirent *entrada;
    carpeta = opendir(".");
    if(carpeta == NULL){
        printf("directorio no encontrado\n");
        return 1;
    }
    
    while((entrada = readdir(carpeta)) != NULL){
        //ignorando el directorio actual y el directorio siguiente
        if(strcmp(entrada->d_name,".") != 0 && strcmp(entrada->d_name,"..") != 0){
            if(entrada->d_type == DT_REG ){
                sufix = strrchr(entrada->d_name,'.'); 
                if(sufix != NULL && strcmp(sufix, ".py") == 0 ){
                    printf("\e[38;5;226m""\n\nejecutando archivo python\033[0m""\n\n");

                    snprintf(arr,sizeof(arr), "python3 %s",entrada->d_name);
                    if(system(arr) == -1){
                        printf("error con el archivo python\n");
                        return 1;
                    }
                    printf("\n");
                }
                if(entrada->d_name[0] == '.'){
                    printf("archivo oculto: %s\n", entrada->d_name);
                }else{
                    printf("archivo: %s\n", entrada->d_name);
                }

            }else if(entrada->d_type == DT_DIR){
                if(entrada->d_name[0] == '.'){
                    printf("directorio oculto: %s\n", entrada->d_name);
                }else{
                    printf("directorio: %s\n", entrada->d_name);

                }
            }
        }
    }
    
    if(closedir(carpeta) == -1){
        printf("error al cerrar el directorio\n");
        return 1;
    }
    //            amarillo                                reinicio
    //printf("\e[38;5;226m""\n\ndirectorio anterior:\n\n""\e[0m");
    //--------------------------------------------
    
    return 0;
}