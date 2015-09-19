#include <stdio.h>
#include "operaciones_alu.h"
#include <math.h>
int resultado;
// a todas las funciones se les debe pasar un puntero banderas el cual es r[12]
unsigned long ADD(unsigned long op1,unsigned long op2,unsigned long **bandera)
{

    resultado=op1+op2;
    if((1<<31)&resultado) //bandera negativo
    {
       **bandera=1;
    }
     if(resultado==0) // bandera cero
    {
       if(**bandera==1)
       {
           **bandera=3;
       }
       else
       {
           **bandera=2;
       }
    }

    if((op1>=pow(2,31))&&(op2>=pow(2,31)))// bandera de carry
    {
        if(**bandera==3)
       {
           **bandera=7;
       }
       else if(**bandera==1)
       {
           **bandera=5;
       }
       else if(**bandera==2)
       {
           **bandera=6;
       }
       else
       {
           **bandera=4;
       }
    }


     if(((1<<31)&op1)&&((1<<31)&op2)&&((1<<31)&resultado)) //bandera sobre flujo
    {

    }
     else if((op1>>31==0)&&(op2>>31==0)&&(resultado>>31==0))
    {

    }
    else
    {
        if(**bandera==7)
       {
           **bandera=15;
       }
       else if(**bandera==6)
       {
           **bandera=14;
       }
       else if(**bandera==5)
       {
           **bandera=13;
       }
        else if(**bandera==4)
       {
           **bandera=12;
       }
        else if(**bandera==3)
       {
           **bandera=11;
       }
        else if(**bandera==2)
       {
           **bandera=10;
       }
        else if(**bandera==1)
       {
           **bandera=9;
       }
       else
       {
           **bandera=8;
       }

    }


	return resultado;

}
unsigned long ADC(unsigned long op1,unsigned long op2,unsigned long **bandera)
{
     resultado=op1+op2;
     if((1<<31)&resultado) //bandera negativo
    {
       **bandera=1;
    }
     if(resultado==0) // bandera cero
    {
       if(**bandera==1)
       {
           **bandera=3;
       }
       else
       {
           **bandera=2;
       }
    }
	if((op1>=pow(2,31))&&(op2>=pow(2,31)))// bandera de carry
    {
        if(**bandera==3)
       {
           **bandera=7;
       }
       else if(**bandera==1)
       {
           **bandera=5;
       }
       else if(**bandera==2)
       {
           **bandera=6;
       }
       else
       {
           **bandera=4;
       }
    }


    if(((1<<31)&op1)&&((1<<31)&op2)&&((1<<31)&resultado)) //bandera sobre flujo
    {

    }
    else if((op1>>31==0)&&(op2>>31==0)&&(resultado>>31==0))
    {

    }
    else
    {
        if(**bandera==7)
		{
           **bandera=15;
		}
		else if(**bandera==6)
		{
			**bandera=14;
		}
		else if(**bandera==5)
		{
			**bandera=13;
		}
		else if(**bandera==4)
		{
			**bandera=12;
		}
		else if(**bandera==3)
		{
			**bandera=11;
		}	
		else if(**bandera==2)
		{
			**bandera=10;
		}
        else if(**bandera==1)
		{
			**bandera=9;
		}
		else
		{
			**bandera=8;
		}

    }


    if((**bandera==15)||(**bandera==14)||(**bandera==13)||(**bandera==12))
    {
        resultado=resultado+1;
    }
    return resultado;
}
unsigned long AND(unsigned long op1,unsigned long op2,unsigned long **bandera)
{

    resultado=op1&op2;
    if((1<<31)&resultado) //bandera negativo
    {
		**bandera=1;
    }
    if(resultado==0) // bandera cero
    {
		if(**bandera==1)
		{
			**bandera=3;
		}
		else
		{
			**bandera=2;
		}
    }

	return resultado;
}
unsigned long EOR(unsigned long op1,unsigned long op2,unsigned long **bandera)
{
	resultado=op1^op2;
    if((1<<31)&resultado) //bandera negativo
    {
		**bandera=1;
    }
    if(resultado==0) // bandera cero
    {
		if(**bandera==1)
		{
			**bandera=3;
		}
		else
		{
			**bandera=2;
		}
    }

    if((op1>=pow(2,31))&&(op2>=pow(2,31)))// bandera de carry
    {
		if(**bandera==3)
		{
			**bandera=7;
		}
		else if(**bandera==1)
		{
			**bandera=5;
		}
		else if(**bandera==2)
		{
			**bandera=6;
		}
		else
		{
			**bandera=4;
		}
    }


    if(((1<<31)&op1)&&((1<<31)&op2)&&((1<<31)&resultado)) //bandera sobre flujo
    {

    }
    else if((op1>>31==0)&&(op2>>31==0)&&(resultado>>31==0))
    {

    }
    else
    {
		if(**bandera==7)
		{
			**bandera=15;
		}
		else if(**bandera==6)
		{
			**bandera=14;
		}
		else if(**bandera==5)
		{
			**bandera=13;
		}
		else if(**bandera==4)
		{
			**bandera=12;
		}
		else if(**bandera==3)
		{
			**bandera=11;
		}
		else if(**bandera==2)
		{
			**bandera=10;
		}
		else if(**bandera==1)
		{
			**bandera=9;
		}
		else
		{
			**bandera=8;
		}

    }
    return resultado;
}
unsigned MOV(unsigned long op1,unsigned long op2,unsigned long **bandera)
{
    op1=op2;
    if((1<<31)&op1) //bandera negativo
    {
		**bandera=1;
    }
    if(op1==0) // bandera cero
    {
		if(**bandera==1)
		{
			**bandera=3;
		}
		else
		{
			**bandera=2;
		}
    }

    if((op1>=pow(2,31))&&(op2>=pow(2,31)))// bandera de carry
    {
		if(**bandera==3)
		{

           **bandera=7;
		}
		else if(**bandera==1)
		{
			**bandera=5;
		}
		else if(**bandera==2)
		{
			**bandera=6;
		}
		else
		{
			**bandera=4;
		}
    }


    if(((1<<31)&op1)&&((1<<31)&op2)&&((1<<31)&op1)) //bandera sobre flujo
    {

    }
    else if((op1>>31==0)&&(op2>>31==0)&&(resultado>>31==0))
    {

    }
    else
    {
		if(**bandera==7)
		{
			**bandera=15;
		}
		else if(**bandera==6)
		{
			**bandera=14;
		}
		else if(**bandera==5)
		{
			**bandera=13;
		}
		else if(**bandera==4)
		{
			**bandera=12;
		}
        else if(**bandera==3)
		{
			**bandera=11;
		}
		else if(**bandera==2)
		{
			**bandera=10;
		}
		else if(**bandera==1)
		{
			**bandera=9;
		}
		else
		{
			**bandera=8;
		}

    }
    return op1;

}
unsigned long ORR(unsigned long op1,unsigned long op2,unsigned long **bandera)
{
    resultado=op1|op2;
    if((1<<31)&resultado) //bandera negativo
    {
		**bandera=1;
    }
	if(resultado==0) // bandera cero
    {
		if(**bandera==1)
		{
			**bandera=3;
		}
		else
		{
			**bandera=2;
		}
    }
	return resultado;
}
unsigned long SUB(unsigned long op1,unsigned long op2,unsigned long **bandera)
{
    resultado=op1+(~op2+1);
    if((1<<31)&resultado) //bandera negativo
    {
		**bandera=1;
    }
    if(resultado==0) // bandera cero
    {
		if(**bandera==1)
		{
			**bandera=3;
		}
		else
		{
			**bandera=2;
		}
    }

    if((op1>=pow(2,31))&&(op2>=pow(2,31)))// bandera de carry
    {
		if(**bandera==3)
		{
			**bandera=7;
		}
		else if(**bandera==1)
		{
			**bandera=5;
		}
		else if(**bandera==2)
		{
			**bandera=6;
		}
		else
		{
			**bandera=4;
		}
    }


    if(((1<<31)&op1)&&((1<<31)&op2)&&((1<<31)&resultado)) //bandera sobre flujo
    {

    }
    else if((op1>>31==0)&&(op2>>31==0)&&(resultado>>31==0))
    {

    }
    else
    {
		if(**bandera==7)
		{
			**bandera=15;
		}
		else if(**bandera==6)
		{
			**bandera=14;
		}
		else if(**bandera==5)
		{
			**bandera=13;
		}
		else if(**bandera==4)
		{
			**bandera=12;
		}
        else if(**bandera==3)
		{
			**bandera=11;
		}
        else if(**bandera==2)
		{
			**bandera=10;
		}
		else if(**bandera==1)
		{
			**bandera=9;
		}
		else
		{
			**bandera=8;
		}

    }

	return resultado;
}
