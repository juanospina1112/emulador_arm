#include "instrucciones_desplazamiento.h"
#include <math.h>

unsigned long LSL(unsigned long Variable_salida,unsigned long Variable_entrada,unsigned long constate_parametro)
{

    unsigned long d;
    d=pow(2,constate_parametro);
    Variable_salida=d*Variable_entrada;
    return Variable_salida;
}

unsigned long LSR(unsigned long Variable_salida,unsigned long Variable_entrada, unsigned long constate_parametro)
{
    unsigned long d;
    d=pow(2,constate_parametro);
    Variable_salida=d/Variable_entrada;
    return Variable_salida;

}

unsigned long ROR(unsigned long Variable_salida,unsigned long Variable_entrada,unsigned long constate_parametro)
{
    unsigned long e, f;
     e=LSR(e,Variable_entrada,constate_parametro);
    constate_parametro=32-constate_parametro;
    f=LSL(f,Variable_entrada,constate_parametro);
    Variable_salida=e+f;

    return Variable_salida;
}

unsigned long ASR(unsigned long Variable_salida,unsigned long Variable_entrada,unsigned long constate_parametro)

{
    unsigned long aux,e;
    if((1<<31)&Variable_entrada)
    {
        aux=1;
    }
    else
        aux=0;
    e=(e,Variable_entrada,constate_parametro);
    Variable_salida=e|aux<<31;
    return Variable_salida;
}
unsigned long BIC(unsigned long Variable_salida,unsigned long Variable_entrada)
{
    return Variable_salida&=~Variable_entrada;
}
unsigned long MVN(unsigned long Variable_salida,unsigned long Variable_entrada)
{
    return Variable_salida=~Variable_entrada;
}
unsigned long RSBS(unsigned long Variable_salida,unsigned long Variable_entrada,unsigned long constate_parametro)
{
    return Variable_salida=constate_parametro-Variable_entrada;
}




