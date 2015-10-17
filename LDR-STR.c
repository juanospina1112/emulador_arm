#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "LDR-STR.h"
unsigned long address;
// s debe recibir la direccion osease Rn+Rm desplazaar para saber en q lugar de la memory esta luego casting 8 a la direccion para manejarla con la memory real
unsigned long LDR(unsigned long Rn,unsigned long Rm,uint8_t *memoria)
{
    unsigned long Rt,address;
    int i;
    address=Rn+Rm;
    if(address>>31==1)
    {
       /* address=address<<28;  
        address=address>>28;*/
        IOAccess(address,Rn,Read);  //eliminar el comentario anterior si funciona. el profesor nos ahorra trabajo
    }
    for(i=0;i>=4;i++)//  ??????  4-0 antiguo
    {
        Rt=*(memoria+(address+i));

        Rt=Rt<<8;
    }
    return Rt;
}

unsigned long LDRB(unsigned long Rn,unsigned long Rm,uint8_t *memoria)
{
    unsigned long Rt,aux=0;
    address=Rn+Rm;
	if(address>>31==1)
    {
       /* address=address<<28;  
        address=address>>28;*/
        IOAccess(address,Rn,Read);  //eliminar el comentario anterior si funciona. el profesor nos ahorra trabajo
    }
    Rt=*(memoria+address);
    Rt=aux+Rt;
    return Rt;

}

unsigned long LDRH(unsigned long Rn,unsigned long Rm,uint8_t *memoria)
{
    unsigned long Rt;
    int i;
    address=Rn+Rm;
	if(address>>31==1)
    {
       /* address=address<<28;  
        address=address>>28;*/
        IOAccess(address,Rn,Read);  //eliminar el comentario anterior si funciona. el profesor nos ahorra trabajo
    }
    for(i=1;i>=0;i--)
    {
        Rt=*(memoria+(address+i));

        Rt=Rt<<8;
    }
    return Rt;
}


unsigned long LDRSB(unsigned long Rn,unsigned long Rm,uint8_t *memoria)
{
    unsigned long Rt,aux=0;
    int i;
    address=Rn+Rm;
	if(address>>31==1)
    {
       /* address=address<<28;  
        address=address>>28;*/
        IOAccess(address,Rn,Read);  //eliminar el comentario anterior si funciona. el profesor nos ahorra trabajo
    }
    Rt=*(memoria+address);
    if((1<<7)&Rt)
    {
        aux=4294967040;

    }
    Rt=Rt+aux;
    return Rt;
}

unsigned long LDRSH(unsigned long Rn,unsigned long Rm,uint8_t *memoria)
{
    unsigned long Rt,aux=0;
    int i;
    address=Rn+Rm;
	if(address>>31==1)
    {
       /* address=address<<28;  
        address=address>>28;*/
        IOAccess(address,Rn,Read);  //eliminar el comentario anterior si funciona. el profesor nos ahorra trabajo
    }
    for(i=1;i>=0;i--)
    {
        Rt=*(memoria+(address+i));

        Rt=Rt>>8;
    }
    if((1<<15)&Rt)
    {
        aux=4294901760;
    }
    Rt=Rt+aux;
    return Rt;
}

STR(unsigned long Rt,unsigned long Rn,unsigned long Rm,uint8_t *memoria)
{
    int i;
    address=Rn+Rm;
	if(address>>31==1)
    {
       /* address=address<<28;  
        address=address>>28;*/
        IOAccess(address,Rn,Write);  //eliminar el comentario anterior si funciona. el profesor nos ahorra trabajo
    }
    for(i=0;i<4;i++)
    {
        *(memoria+address+i)=(uint8_t)(Rt>>(i*8));
    }
}

STRB(unsigned long Rt,unsigned long Rn,unsigned long Rm,uint8_t *memoria)
{
    address=Rn+Rm;
	if(address>>31==1)
    {
       /* address=address<<28;  
        address=address>>28;*/
        IOAccess(address,Rn,Write);  //eliminar el comentario anterior si funciona. el profesor nos ahorra trabajo
    }
    *(memoria+address)=(uint8_t) (Rt);

}

STRH(unsigned long Rt,unsigned long Rn,unsigned long Rm,uint8_t *memoria)
{
    int i;
    address=Rn+Rm;
	if(address>>31==1)
    {
       /* address=address<<28;  
        address=address>>28;*/
        IOAccess(address,Rn,Write);  //eliminar el comentario anterior si funciona. el profesor nos ahorra trabajo
    }
    for(i=0;i<1;i++)
    {
        *(memoria+address+i)=(uint8_t)(Rt>>(i*8));
    }
}
