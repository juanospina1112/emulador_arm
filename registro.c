#include <stdio.h>
#include <stdlib.h>
#include "registro.h"

void mostrar_registros(unsigned long r[13])
{
    int i,k=0; //variables para mostrar los registros en cuadricula mediante for anidados
    for(i=0;i<13;i++)
    {
        printf("r[%d]=%0.8X\t",i,r[i]); //impresión de los datos en los registros
        k+=1;
        if(k==4)
        {
            printf("\n");
            k=0;
        }
    }
}