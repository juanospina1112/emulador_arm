#include "instrucciones_desplazamiento.h"


unsigned long LSL(unsigned long Variable_entrada,unsigned long constate_parametro)
{
    unsigned long Variable_salida;
    Variable_salida=Variable_entrada<<constate_parametro;
    return Variable_salida;
}
unsigned long LSR(unsigned long Variable_entrada, unsigned long constate_parametro)
{
    unsigned long Variable_salida;
    Variable_salida=Variable_entrada>>constate_parametro;
    return Variable_salida;
}
unsigned long ROR(unsigned long Variable_entrada,unsigned long constate_parametro)
{
    unsigned long Variable_salida;
    Variable_salida=LSR(Variable_salida,Variable_entrada,constate_parametro)+LSL(Variable_salida,Variable_entrada,32-constate_parametro);
    return Variable_salida;
}
unsigned long ASR(unsigned long Variable_entrada,unsigned long constate_parametro)
{
    unsigned long aux,e;
    unsigned long Variable_salida;
    if((1<<31)&Variable_entrada)
    {
        aux=1;
    }
    else
	{
        aux=0;
	}
    e=(e,Variable_entrada,constate_parametro);
    Variable_salida=e|aux<<31;
    return Variable_salida;
}
unsigned long BIC(unsigned long Variable_entrada)
{
    unsigned long Variable_salida;
    return Variable_salida&=~Variable_entrada;
}
unsigned long MVN(unsigned long Variable_entrada)
{
    unsigned long Variable_salida;
    return Variable_salida=~Variable_entrada;
}
unsigned long RSBS(unsigned long Variable_entrada,unsigned long constate_parametro)
{
    unsigned long Variable_salida;
    return Variable_salida=constate_parametro-Variable_entrada;
}
unsigned long REV(unsigned long Variable_entrada)
{
    unsigned long constate_parametro,aux1,aux2,Variable_salida;
    constate_parametro=24;
    Variable_salida=LSR(Variable_salida,Variable_entrada,constate_parametro)+LSL(Variable_salida,Variable_entrada,constate_parametro);
    constate_parametro=16;
    aux1=LSR(aux1,Variable_entrada,constate_parametro);
    aux2=LSL(aux2,Variable_entrada,constate_parametro);
    constate_parametro=24;
    aux1=LSL(aux1,aux1,constate_parametro);
    aux2=LSR(aux2,aux2,constate_parametro);
    constate_parametro=16;
    aux1=LSR(aux1,aux1,constate_parametro);
    aux2=LSL(aux2,aux2,constate_parametro);
    Variable_salida=Variable_salida+aux1+aux2;
	return Variable_salida;
}
unsigned long REV16(unsigned long Variable_entrada)
{
    unsigned long constate_parametro,aux1,aux2,aux3,aux4,Variable_salida;
    constate_parametro=16;
    aux1=LSR(Variable_salida,Variable_entrada,constate_parametro);
    aux3=LSL(Variable_salida,Variable_entrada,constate_parametro);
    constate_parametro=24;
    aux2=LSL(Variable_salida,aux1,constate_parametro);
    aux4=LSR(Variable_salida,aux3,constate_parametro);
    constate_parametro=8;
    aux1=LSR(Variable_salida,aux1,constate_parametro);
    aux3=LSL(Variable_salida,aux3,constate_parametro);
    constate_parametro=16;
    aux1=LSL(Variable_salida,aux1,constate_parametro);
    aux3=LSR(Variable_salida,aux3,constate_parametro);
    Variable_salida=(aux1+aux2)+(aux3+aux4);
}
unsigned long REVSH(unsigned long Variable_entrada)
{
    unsigned long Variable_salida,aux,aux1,aux2,constate_parametro;
    if((1<<7)&Variable_entrada)
    {
        aux=4294967295;
        aux=LSL(aux,constate_parametro=16);
    }
    else
        aux=0;
    aux1=LSL(Variable_entrada,constate_parametro=16);
    aux2=LSR(aux1,constate_parametro=24);
    aux1=LSL(aux1,constate_parametro=8);
    aux1=LSR(aux1,constate_parametro=16);
    Variable_salida=aux1+aux2+aux;
    return Variable_salida;
}
