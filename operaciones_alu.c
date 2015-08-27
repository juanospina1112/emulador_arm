#include <stdio.h>
#include "operaciones_alu.h"

long ADD(long *resultado,long op1,long op2)
{
     int N,Z,C,V,i=0;
    *resultado=op1+op2;
    if((1<<31)&*resultado)
    {
       N=1;
    }
     if(!*resultado)
    {
       Z=1;
    }
    // falta carry
     if(((1<<31)&op1)&&((1<<31)&op2)&&((1<<31)&resultado))
    {
       V=0;
    }
    else if(((0<<31)&op1)&&((0<<31)&op2)&&((0<<31)&resultado))
    {
       V=0;
    }
    else
    {
        V=1;
    }
}
long AND(long *resultado,long op1,long op2)
{
    *resultado=op1&op2;

}
long EOR(long *resultado,long op1,long op2)
{
      *resultado=op1^op2;
}
long MOV(long op1,long op2)
{
    op1=op2;
    return op1;
}
long ORR(long *resultado,long op1,long op2)
{
        *resultado=op1|op2;
}
long SUB(long *resultado,long op1,long op2)
{
    *resultado=op1+(~op2+1);
}
