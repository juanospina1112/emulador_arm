#include "funciones_pila.h"

void PUSH(unsigned long registros[16], unsigned long *R, unsigned long *memoria)
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
    posicion=*(R+13)-contador; //cambiar 1*contador a 4*contador
    for(i=0; i<15; i++)
    {
        if(registros[i]==1)
        {
            *(memoria+posicion)=*(R+i);
            posicion+=1;  // cambiar 1 por 4
        }
    }
    *(R+13)-=contador; // cambiar 1 por 4
}
void POP(unsigned long registros[16], unsigned long *R, unsigned long *memoria)
{
    unsigned long posicion;
    int i=0, contador=0;
    posicion=*(R+13);
    for(i=0; i<16; i++)
    {
        if(registros[i]==1)
        {
            *(R+i)=*(memoria+posicion);
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
    *(R+13)+=contador;  //revisar
}