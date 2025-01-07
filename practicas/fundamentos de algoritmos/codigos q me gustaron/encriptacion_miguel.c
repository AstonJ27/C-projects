#include <stdio.h>

void encriptar();
void desencriptar();

int main()
{
    int llave, ejec;
    char archivo[20];

    printf("Ingrese el entero llave: ");
    scanf("%d", &llave);
    
    do
    {
        printf("Opcion 1: encriptar archivo\n"
               "Opcion 2: desencriptar archivo\n"
               "Opcion 3: salir\n");
        
        printf("Ingrese la opcion que desea ejecutar: ");
        scanf("%d", &ejec);

        if (ejec == 1)
        {
            printf("Ingrese el archivo que va a encriptar: ");
            scanf("%s", archivo);

            encriptar(llave, archivo);
        }
        else if (ejec == 2)
        {
            printf("Ingrese el archivo que va a desencriptar: ");
            scanf("%s", archivo);

            desencriptar(llave, archivo);

        }
        

    } while (ejec != 3);
    


    return 0;
}

void encriptar(int llave, char archivo[20])
{
    FILE *ent, *sal;

    char carac;

    ent = fopen(archivo, "r");
    sal = fopen("archivo_encriptado.txt", "w");

    while (fscanf(ent, "%c", &carac) != EOF)
    {
        carac = (carac + llave) % 95 + 33;
   
        fprintf(sal,"%c", carac);
    }
    


    fclose(ent);
    fclose(sal);
}

void desencriptar(int llave, char archivo[20])
{
    FILE *ent, *sal;

    unsigned char carac;

    ent = fopen(archivo, "r");
    sal = fopen("archivo_desencriptado.txt", "w");

    while (fscanf(ent, "%c", &carac) != EOF)
    {
        carac = 62 + carac;

        if (carac > 126 + llave)
        {
            carac -= 95;
        }
        

        carac -= llave;
        
        fprintf(sal,"%c", carac);
    }
    


    fclose(ent);
    fclose(sal);
}