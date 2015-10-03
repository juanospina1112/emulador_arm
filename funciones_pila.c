#include <stdint.h>
#include "funciones_pila.h"

void PUSH(uint8_t registros[16], unsigned long *R, uint8_t *memoria)
{
    unsigned long posicion;
    int i, contador=0;
    for(i=0; i<16; i++)
    {
        if(registros[i]==1)
        {
            contador+=1;
        }
    }
    posicion=*(R+13)-4*contador;
    for(i=0; i<15; i++)
    {
        if(registros[i]==1)
        {
            *(memoria+posicion)=(uint8_t)(R[i]);
             posicion+=1;
            *(memoria+posicion)=(uint8_t)(R[i]>>8);
             posicion+=1;
            *(memoria+posicion)=(uint8_t)(R[i]>>16);
             posicion+=1;
            *(memoria+posicion)=(uint8_t)(R[i]>>24);
            posicion+=1;
        }
    }
    *(R+13)-=4*contador;
}
void POP(uint8_t registros[16], unsigned long *R, uint8_t *memoria)
{
    unsigned long posicion;
    int i=0, contador=0;
    posicion=*(R+13);
    for(i=0; i<16; i++)
    {
        if(registros[i]==1)
        {
            R[i]=(unsigned long)(memoria[posicion]);
            posicion+=1;
            R[i]+=(unsigned long)(memoria[posicion]<<8);
            posicion+=1;
            R[i]+=(unsigned long)(memoria[posicion]<<16);
            posicion+=1;
            R[i]+=(unsigned long)(memoria[posicion]<<32);
            posicion+=1;
        }
    }
    for(i=0; i<16; i++)
    {
        if(registros[i]==1)
        {
            contador+=1;
        }
    }
    *(R+13)+=4*contador;
}