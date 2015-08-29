#include <stdio.h>
#include <math.h>
#include "operaciones_alu.h"

void ADD(unsigned long *resultado,unsigned long op1,unsigned long op2,unsigned long *bandera)
{
    *resultado=op1+op2;
    if((1<<31)&*resultado) //bandera negativo
    {
        *bandera=1;
    }
    if(*resultado==0) // bandera cero
    {
        if(*bandera==1)
        {
            *bandera=3;
        }
        else
        {
            *bandera=2;
        }
    }
    if((op1>=pow(2,31))&&(op2>=pow(2,31)))// bandera de carry
    {
        if(*bandera==3)
        {
            *bandera=7;
        }
        else if(*bandera==1)
        {
            *bandera=5;
        }
        else if(*bandera==2)
        {
            *bandera=6;
        }
        else
        {
            *bandera=6;
        }
    }
    if(((1<<31)&op1)&&((1<<31)&op2)&&((1<<31)&*resultado)) //bandera sobre flujo
    {
        //se entiende que no hay sobre flujo
    }
    else if(((1<<31)|op1)||((1<<31)|op2)||((1<<31)|*resultado))
    {
        //se entiende que no hay sobre flujo
    }
    else
    {
        if(*bandera==7)
        {
            *bandera=15;
        }
        else if(*bandera==6)
        {
            *bandera=14;
        }
        else if(*bandera==5)
        {
            *bandera=13;
        }
        else
        {
            *bandera=12;
        }
    }
}
void AND(unsigned long *resultado,unsigned long op1,unsigned long op2,unsigned long *bandera)
{
    *resultado=op1&op2;
    if((1<<31)&*resultado) //bandera negativo
    {
        *bandera=1;
    }
    if(*resultado==0) // bandera cero
    {
        if(*bandera==1)
        {
            *bandera=3;
        }
        else
        {
            *bandera=2;
        }
    }
}
void EOR(unsigned long *resultado,unsigned long op1,unsigned long op2,unsigned long *bandera)
{
    *resultado=op1^op2;
    if((1<<31)&*resultado) //bandera negativo
    {
        *bandera=1;
    }
    if(*resultado==0) // bandera cero
    {
        if(*bandera==1)
        {
            *bandera=3;
        }
        else
        {
            *bandera=2;
        }
    }
    if((op1>=pow(2,31))&&(op2>=pow(2,31)))// bandera de carry
    {
        if(*bandera==3)
        {
            *bandera=7;
        }
        else if(*bandera==1)
        {
            *bandera=5;
        }
        else if(*bandera==2)
        {
            *bandera=6;
        }
        else
        {
            *bandera=6;
        }
    }
    if(((1<<31)&op1)&&((1<<31)&op2)&&((1<<31)&*resultado)) //bandera sobre flujo
    {
        //se entiende que no hay sobre flujo
    }
    else if(((1<<31)|op1)||((1<<31)|op2)||((1<<31)|*resultado))
    {
        //se entiende que no hay sobre flujo
    }
    else
    {
        if(*bandera==7)
        {
            *bandera=15;
        }
        else if(*bandera==6)
        {
            *bandera=14;
        }
        else if(*bandera==5)
        {
            *bandera=13;
        }
        else
        {
            *bandera=12;
        }
    }
}
void MOV(unsigned long *op1,unsigned long op2)
{
    op1=op2;
}
void ORR(unsigned long *resultado,unsigned long op1,unsigned long op2,unsigned long *bandera)
{
    *resultado=op1|op2;
    if((1<<31)&*resultado) //bandera negativo
    {
        *bandera=1;
    }
    if(*resultado==0) // bandera cero
    {
        if(*bandera==1)
        {
            *bandera=3;
        }
        else
        {
            *bandera=2;
        }
    }
}
void SUB(unsigned long *resultado,unsigned long op1,unsigned long op2,unsigned long *bandera)
{
    *resultado=op1+(~op2+1);
    if((1<<31)&*resultado) //bandera negativo
    {
        *bandera=1;
    }
    if(*resultado==0) // bandera cero
    {
        if(*bandera==1)
        {
            *bandera=3;
        }
        else
        {
            *bandera=2;
        }
    }
    if((op1>=pow(2,31))&&(op2>=pow(2,31)))// bandera de carry
    {
        if(*bandera==3)
        {
            *bandera=7;
        }
        else if(*bandera==1)
        {
            *bandera=5;
        }
        else if(*bandera==2)
        {
            *bandera=6;
        }
        else
        {
            *bandera=6;
        }
    }
    if(((1<<31)&op1)&&((1<<31)&op2)&&((1<<31)&*resultado)) //bandera sobre flujo
    {
        //se entiende que no hay sobre flujo
    }
    else if(((1<<31)|op1)||((1<<31)|op2)||((1<<31)|*resultado))
    {
        //se entiende que no hay sobre flujo
    }
    else
    {
        if(*bandera==7)
        {
            *bandera=15;
        }
        else if(*bandera==6)
        {
            *bandera=14;
        }
        else if(*bandera==5)
        {
            *bandera=13;
        }
        else
        {
            *bandera=12;
        }
    }
}