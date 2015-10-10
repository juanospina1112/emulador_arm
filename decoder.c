#include "decoder.h"
#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "operaciones_alu.h"
#include <curses.h>
#include "decoder.h"
#include "branch.h"
#include "instrucciones_desplazamiento.h"
#include <math.h>

void decodeInstruction(instruction_t instruction,unsigned long *r[],unsigned long *bandera,unsigned long *PC,unsigned long*LR,uint8_t*memoria)
{
    int auxban;
    unsigned long aux1,aux2,des;
	//            codificacion funciones de la alu
	if(strcmp(instruction.mnemonic,"ADDS") == 0)
	{
		if(instruction.op1_type=='R')
        {
            if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
            {
				r[instruction.op1_value]=ADD(r[instruction.op2_value],r[instruction.op3_value],&bandera);
			}
            if((instruction.op2_type== '#' )&&(instruction.op3_type =='R' ))
            {
				r[instruction.op1_value]=ADD(instruction.op2_value,r[instruction.op3_value],&bandera);
            }
            if((instruction.op2_type== 'R' )&&(instruction.op3_type =='#' ))
            {
				r[instruction.op1_value]=ADD(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
            if((instruction.op2_type== '#' )&&(instruction.op3_type =='#' ))
			{
				r[instruction.op1_value]=ADD(instruction.op2_value,instruction.op3_value,&bandera);
            }
            mostrar(r[instruction.op1_value]);
        }
		if(instruction.op1_type=='N')
		{
			if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
			{
				ADD(r[instruction.op2_value],r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type== 'R' ))
            {
				ADD(instruction.op2_value,r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == 'R' )&&(instruction.op3_type == '#' ))
            {
				ADD(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
            {
				ADD(instruction.op2_value,instruction.op3_value,&bandera);
            }
			mostrar(r[instruction.op1_value]);
		}
	}
	if(strcmp(instruction.mnemonic,"CMN") == 0)
	{
        if((instruction.op1_type== 'R' )&&(instruction.op2_type =='R' ))
        {
            ADD(r[instruction.op1_value],r[instruction.op2_value],&bandera);
        }
        if((instruction.op1_type == '#' )&&(instruction.op2_type== 'R' ))
        {
            ADD(instruction.op1_value,r[instruction.op2_value],&bandera);
        }
        if((instruction.op1_type == 'R' )&&(instruction.op2_type == '#' ))
        {
            ADD(r[instruction.op1_value],instruction.op2_value,&bandera);
        }
        if((instruction.op1_type == '#' )&&(instruction.op2_type == '#' ))
        {
            ADD(instruction.op1_value,instruction.op2_value,&bandera);
        }
	}
	if( strcmp(instruction.mnemonic,"ADCS") == 0)
	{
		if(instruction.op1_type=='R')
		{
            if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
			{
				r[instruction.op1_value]=ADC(r[instruction.op2_value],r[instruction.op3_value],&bandera);
            }
            if((instruction.op2_type == '#' )&&(instruction.op3_type== 'R' ))
			{
				r[instruction.op1_value]=ADC(instruction.op2_value,r[instruction.op3_value],&bandera);
            }
            if((instruction.op2_type == 'R' )&&(instruction.op3_type == '#' ))
			{
                r[instruction.op1_value]=ADC(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
            if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
            {
				r[instruction.op1_value]=ADC(instruction.op2_value,instruction.op3_value,&bandera);
            }
			mostrar(r[instruction.op1_value]);
		}
        if(instruction.op1_type=='N')
        {
            if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
            {
				ADC(r[instruction.op2_value],r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type== 'R' ))
            {
				ADC(instruction.op2_value,r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == 'R' )&&(instruction.op3_type == '#' ))
            {
				ADC(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
            {
				ADC(instruction.op2_value,instruction.op3_value,&bandera);
            }
            mostrar(r[instruction.op1_value]);
		}
    }
    if( strcmp(instruction.mnemonic,"ANDS") == 0)
    {
        if(instruction.op1_type=='R')
        {
            if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
            {
                r[instruction.op1_value]=AND(r[instruction.op2_value],r[instruction.op3_value],&bandera);
            }
            if((instruction.op2_type == '#' )&&(instruction.op3_type== 'R' ))
            {
                r[instruction.op1_value]=AND(instruction.op2_value,r[instruction.op3_value],&bandera);
			}
            if((instruction.op2_type == 'R' )&&(instruction.op3_type == '#' ))
            {
                r[instruction.op1_value]=AND(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
            {
                r[instruction.op1_value]=AND(instruction.op2_value,instruction.op3_value,&bandera);
            }
           mostrar(r[instruction.op1_value]);
		}
        if(instruction.op1_type=='N')
        {
			if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
			{
                AND(r[instruction.op2_value],r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type== 'R' ))
            {
                AND(instruction.op2_value,r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == 'R' )&&(instruction.op3_type == '#' ))
            {
                AND(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
            {
                AND(instruction.op2_value,instruction.op3_value,&bandera);
            }
            mostrar(r[instruction.op1_value]);
		}
    }
    if(strcmp(instruction.mnemonic,"TEST") == 0)
    {
        if((instruction.op1_type== 'R' )&&(instruction.op2_type =='R' ))
        {
            AND(r[instruction.op1_value],r[instruction.op2_value],&bandera);
        }
        if((instruction.op1_type == '#' )&&(instruction.op2_type== 'R' ))
        {
            AND(instruction.op1_value,r[instruction.op2_value],&bandera);
        }
        if((instruction.op1_type == 'R' )&&(instruction.op2_type == '#' ))
        {
            AND(r[instruction.op1_value],instruction.op2_value,&bandera);
        }
        if((instruction.op1_type == '#' )&&(instruction.op2_type == '#' ))
        {
            AND(instruction.op1_value,instruction.op2_value,&bandera);
        }
    }
    if( strcmp(instruction.mnemonic,"EORS") == 0)
    {
        if(instruction.op1_type=='R')
       {
            if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
			{
                r[instruction.op1_value]=EOR(r[instruction.op2_value],r[instruction.op3_value],&bandera);
            }
            if((instruction.op2_type == '#' )&&(instruction.op3_type== 'R' ))
			{
                r[instruction.op1_value]=EOR(instruction.op2_value,r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == 'R' )&&(instruction.op3_type == '#' ))
            {
                r[instruction.op1_value]=EOR(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
            if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
            {
                r[instruction.op1_value]=EOR(instruction.op2_value,instruction.op3_value,&bandera);
            }
           mostrar(r[instruction.op1_value]);
		}
        if(instruction.op1_type=='N')
        {
            if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
            {
                EOR(r[instruction.op2_value],r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type== 'R' ))
            {
				EOR(instruction.op2_value,r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == 'R' )&&(instruction.op3_type == '#' ))
            {
				EOR(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
            {
                EOR(instruction.op2_value,instruction.op3_value,&bandera);
            }
			mostrar(r[instruction.op1_value]);
		}
    }
    if( (strcmp(instruction.mnemonic,"MOVS") == 0)||(strcmp(instruction.mnemonic,"MOV") == 0))
    {

		if((instruction.op1_type == 'R')&&(instruction.op2_type=='R') )
		{
			r[instruction.op1_value]=MOV(r[instruction.op1_value],r[instruction.op2_value],&bandera);
			mostrar(r[instruction.op1_value]);
		}
        if((instruction.op1_type == 'R')&&(instruction.op2_type=='#') )
        {
            r[instruction.op1_value]=MOV(instruction.op1_value,instruction.op2_value,&bandera);
            mostrar(r[instruction.op1_value]);
        }
    }
    if( strcmp(instruction.mnemonic,"ORRS") == 0)
    {
        if(instruction.op1_type=='R')
        {
            if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
            {
                r[instruction.op1_value]=ORR(r[instruction.op2_value],r[instruction.op3_value],&bandera);
			}
            if((instruction.op2_type == '#' )&&(instruction.op3_type== 'R' ))
            {
                r[instruction.op1_value]=ORR(instruction.op2_value,r[instruction.op3_value],&bandera);
            }
            if((instruction.op2_type == 'R' )&&(instruction.op3_type == '#' ))
            {
                r[instruction.op1_value]=ORR(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
            {
                r[instruction.op1_value]=ORR(instruction.op2_value,instruction.op3_value,&bandera);
            }
			mostrar(r[instruction.op1_value]);
		}
        if(instruction.op1_type=='N')
        {
            if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
            {
                ORR(r[instruction.op2_value],r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type== 'R' ))
            {
                ORR(instruction.op2_value,r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == 'R' )&&(instruction.op3_type == '#' ))
            {
				ORR(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
            {
                ORR(instruction.op2_value,instruction.op3_value,&bandera);
            }
			mostrar(r[instruction.op1_value]);
        }
    }
	if( strcmp(instruction.mnemonic,"SUBS") == 0)
    {
        if(instruction.op1_type== 'R' )
		{
            if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
            {
                r[instruction.op1_value]=SUB(r[instruction.op2_value],r[instruction.op3_value],&bandera);
            }
            if((instruction.op2_type == '#' )&&(instruction.op3_type== 'R' ))
            {
                r[instruction.op1_value]=SUB(instruction.op2_value,r[instruction.op3_value],&bandera);
            }
           if((instruction.op2_type == 'R' )&&(instruction.op3_type == '#' ))
            {
                r[instruction.op1_value]=SUB(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
            {
                r[instruction.op1_value]=SUB(instruction.op2_value,instruction.op3_value,&bandera);
            }
			mostrar(r[instruction.op1_value]);
		}
        if(instruction.op1_type=='N')
        {
            if((instruction.op2_type== 'R' )&&(instruction.op3_type =='R' ))
			{
                SUB(r[instruction.op2_value],r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type== 'R' ))
            {
                SUB(instruction.op2_value,r[instruction.op3_value],&bandera);
            }
			if((instruction.op2_type == 'R' )&&(instruction.op3_type == '#' ))
            {
                SUB(r[instruction.op2_value],instruction.op3_value,&bandera);
            }
			if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
            {
                SUB(instruction.op2_value,instruction.op3_value,&bandera);
            }
			mostrar(r[instruction.op1_value]);
        }
    }
    if(strcmp(instruction.mnemonic,"CMP") == 0)
    {
        if((instruction.op1_type== 'R' )&&(instruction.op2_type =='R' ))
        {
            SUB(r[instruction.op1_value],r[instruction.op2_value],&bandera);
        }
        if((instruction.op1_type == '#' )&&(instruction.op2_type== 'R' ))
        {
            SUB(instruction.op1_value,r[instruction.op2_value],&bandera);
        }
        if((instruction.op1_type == 'R' )&&(instruction.op2_type == '#' ))
		{
            SUB(r[instruction.op1_value],instruction.op2_value,&bandera);
        }
		if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
        {
            SUB(instruction.op1_value,instruction.op2_value,&bandera);
        }
    }
    //                 decodificacion funciones branch
	if(strcmp(instruction.mnemonic,"B")==0)
	{
		if(instruction.op1_type=='#')
		{
			B(&PC,instruction.op1_value);
		}
	}
	if(strcmp(instruction.mnemonic,"BEQ")==0)
	{
		if(instruction.op1_type=='#')
		{
			BEQ(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BNE")==0)
	{
		if(instruction.op1_type=='#')
		{
			BNE(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BCS")==0)
	{
		if(instruction.op1_type=='#')
		{
			BCS(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BCC")==0)
	{
		if(instruction.op1_type=='#')
		{
			BCC(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BMI")==0)
	{
		if(instruction.op1_type=='#')
		{
			BMI(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BPL")==0)
	{
		if(instruction.op1_type=='#')
		{
			BPL(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BVS")==0)
	{
		if(instruction.op1_type=='#')
		{
			BVS(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BVC")==0)
	{
		if(instruction.op1_type=='#')
		{
			BVC(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BHI")==0)
	{
		if(instruction.op1_type=='#')
		{
			BHI(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BLS")==0)
	{
		if(instruction.op1_type=='#')
		{
			BLS(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BGE")==0)
	{
		if(instruction.op1_type=='#')
		{
			BGE(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BLT")==0)
	{
		if(instruction.op1_type=='#')
		{
			BLT(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BGT")==0)
	{
		if(instruction.op1_type=='#')
		{
			BGT(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BLE")==0)
	{
		if(instruction.op1_type=='#')
		{
			BLE(&PC,instruction.op1_value,&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BL")==0)
	{
		if(instruction.op1_type=='#')
		{
			BL(&PC,instruction.op1_value,&LR);
		}
	}
	if(strcmp(instruction.mnemonic,"BX")==0)
	{
		if(instruction.op1_type=='R')
		{
			BX(&PC,r[instruction.op1_value]);
		}
	}
	if(strcmp(instruction.mnemonic,"BLX")==0)
	{
		if(instruction.op1_type=='R')
		{
			BLX(&PC,instruction.op1_value,&LR);
		}
	}
    //                       decodificacion funciones de desplazamiento
	if(strcmp(instruction.mnemonic,"NOP")==0)
	{
		NOP();
	}
	if(strcmp(instruction.mnemonic,"LSLS")==0)
	{


	        auxban=*bandera;
    if((*bandera==15)||(*bandera==14)||(*bandera==13)||(*bandera==12)||(*bandera==11)||(*bandera==10)||(*bandera==9)||(*bandera==8))
    {
        *bandera=8;
    }
    else
    {
          *bandera=0;
    }


		if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
		{
			aux1=r[instruction.op3_value];
			aux2=r[instruction.op2_value];
			r[instruction.op1_value]=LSL(r[instruction.op2_value],r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);

			if((1<<(32-aux1))&aux2)// bandera de carry
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
		else if(*bandera==8)
        {
            *bandera=12;
        }
        else if(*bandera==9)
        {
            *bandera=13;
        }
         else if(*bandera==11)
        {
            *bandera=15;
        }
        else
		{
			*bandera=4;
		}
    }
		}

		if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
		{
		    aux1=instruction.op3_value;
			aux2=r[instruction.op2_value];
			r[instruction.op1_value]=LSL(r[instruction.op2_value],instruction.op3_value);
			BDES(r[instruction.op1_value],&bandera);



			if((1<<(32-aux1))&aux2)// bandera de carry
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
		else if(*bandera==8)
        {
            *bandera=12;
        }
        else if(*bandera==9)
        {
            *bandera=13;
        }
         else if(*bandera==11)
        {
            *bandera=15;
        }
        else
		{
			*bandera=4;
		}
    }

	}
	}
	if(strcmp(instruction.mnemonic,"LSRS")==0)
	{

    if((*bandera==15)||(*bandera==14)||(*bandera==13)||(*bandera==12)||(*bandera==11)||(*bandera==10)||(*bandera==9)||(*bandera==8))
    {
        *bandera=8;
    }
    else
    {
          *bandera=0;
    }

		if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
		{
		    aux1=r[instruction.op3_value];
			aux2=r[instruction.op2_value];
			r[instruction.op1_value]=LSR(r[instruction.op2_value],r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);

					if((1<<(aux1-1))&aux2)// bandera de carry
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
		else if(*bandera==8)
        {
            *bandera=12;
        }
        else if(*bandera==9)
        {
            *bandera=13;
        }
         else if(*bandera==11)
        {
            *bandera=15;
        }
        else
		{
			*bandera=4;
		}
    }

		}
		if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
		{
		    aux1=instruction.op3_value;
			aux2=r[instruction.op2_value];
		r[instruction.op1_value]=LSR(r[instruction.op2_value],instruction.op3_value);
		BDES(r[instruction.op1_value],&bandera);

					if((1<<(aux1-1))&aux2)// bandera de carry
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
		else if(*bandera==8)
        {
            *bandera=12;
        }
        else if(*bandera==9)
        {
            *bandera=13;
        }
         else if(*bandera==11)
        {
            *bandera=15;
        }
        else
		{
			*bandera=4;
		}
    }

		}
	}
	if(strcmp(instruction.mnemonic,"RORS")==0)//carry negativo  cero
	{

		if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
		{
			r[instruction.op1_value]=ROR(r[instruction.op2_value],r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);
		}

		if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
		{
			r[instruction.op1_value]=ROR(r[instruction.op2_value],instruction.op3_value);
			BDES(r[instruction.op1_value],&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"ASRS")==0)//lo mismo
	{
		if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
		{
			r[instruction.op1_value]=ASR(r[instruction.op2_value],r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);
		}

		if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
		{
			r[instruction.op1_value]=ASR(r[instruction.op2_value],instruction.op3_value);
			BDES(r[instruction.op1_value],&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BICS")==0)// negatio y cero
	{
		if((instruction.op2_type=='R'))
		{
			r[instruction.op1_value]=BIC(r[instruction.op2_value]);
			BDES(r[instruction.op1_value],&bandera);
		}

	}
	if(strcmp(instruction.mnemonic,"MVNS")==0) //cero y negativo
	{
		if((instruction.op2_type=='R'))
		{
			r[instruction.op1_value]=MVN(r[instruction.op2_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='#'))
		{
			r[instruction.op1_value]=MVN(instruction.op2_value);
			BDES(r[instruction.op1_value],&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"RSBS")==0)
	{
		if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
		{
			r[instruction.op1_value]=RSBS(r[instruction.op2_value],r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);
		}

	}
	if(strcmp(instruction.mnemonic,"REVS")==0)
	{
		if((instruction.op2_type=='R'))
		{
			r[instruction.op1_value]=REV(r[instruction.op2_value]);

		}

	}
	if(strcmp(instruction.mnemonic,"REV16S")==0)
	{
		if((instruction.op2_type=='R'))
		{
			r[instruction.op1_value]=REV16(r[instruction.op2_value]);

		}

	}
	if(strcmp(instruction.mnemonic,"REVSHS")==0)
	{
		if((instruction.op2_type=='R'))
		{
			r[instruction.op1_value]=REVSH(r[instruction.op2_value]);

		}

	}

	/**************************** funciones de pila****/
	if(strcmp(instruction.mnemonic,"PUSH")==0)
    {
        PUSH(instruction.registers_list,r,memoria);
    }
	if(strcmp(instruction.mnemonic,"POP")==0)
    {
        POP(instruction.registers_list,r,memoria);
    }

/************ funciones load***/

if(strcmp(instruction.mnemonic,"LDR")==0)
{
    if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
    {
        r[instruction.op1_value]=LDR(r[instruction.op2_value],r[instruction.op3_value],memoria);


    }
     if((instruction.op2_type=='PC')&&(instruction.op3_type=='#'))
     {
         instruction.op3_value= instruction.op3_value<<2;
         r[instruction.op1_value]=LDR(r[15],(uint32_t) (instruction.op3_value),memoria);
     }
      if((instruction.op2_type=='SP')&&(instruction.op3_type=='#'))
     {
         instruction.op3_value= instruction.op3_value<<2;
         r[instruction.op1_value]=LDR(r[13],(uint32_t) (instruction.op3_value),memoria);
     }
     if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
     {
         instruction.op3_value= instruction.op3_value<<2;
         r[instruction.op1_value]=LDR(r[instruction.op2_value],(uint32_t) (instruction.op3_value),memoria);
     }


}
if(strcmp(instruction.mnemonic,"LDRB")==0)
{
    if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
     {
         r[instruction.op1_value]=LDRB(r[instruction.op2_value],r[instruction.op3_value],memoria);
     }
     if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
     {
         r[instruction.op1_value]=LDR(r[instruction.op2_value],(uint32_t) (instruction.op3_value),memoria);
     }

}
if(strcmp(instruction.mnemonic,"LDRH")==0)
{
    if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
     {
         r[instruction.op1_value]=LDRH(r[instruction.op2_value],r[instruction.op3_value],memoria);
     }
      if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
     {
         instruction.op3_value= instruction.op3_value<<1;
         r[instruction.op1_value]=LDRH(r[instruction.op2_value],(uint32_t) (instruction.op3_value),memoria);
     }
}
if(strcmp(instruction.mnemonic,"LDRSB")==0)
{
     if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
     {
         r[instruction.op1_value]=LDRSB(r[instruction.op2_value],r[instruction.op3_value],memoria);
     }
}
if(strcmp(instruction.mnemonic,"LDRSH")==0)
{
     if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
     {
         r[instruction.op1_value]=LDRSH(r[instruction.op2_value],r[instruction.op3_value],memoria);
     }
}
if(strcmp(instruction.mnemonic,"STR")==0)
{
     if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
     {
         r[instruction.op1_value]=STR(r[instruction.op2_value],r[instruction.op3_value],memoria);
     }
      if((instruction.op2_type=='SP')&&(instruction.op3_type=='#'))
     {
         instruction.op3_value=instruction.op3_value<<2;
         r[instruction.op1_value]=STR(r[13],(uint32_t)(instruction.op3_value),memoria);
     }
      if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
     {
         instruction.op3_value=instruction.op3_value<<2;
         r[instruction.op1_value]=STR(r[instruction.op2_value],(uint32_t)(instruction.op3_value),memoria);
     }
}
if(strcmp(instruction.mnemonic,"STRB")==0)
{
     if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
     {
         r[instruction.op1_value]=STRB(r[instruction.op2_value],r[instruction.op3_value],memoria);
     }
     if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
     {

         r[instruction.op1_value]=STRB(r[instruction.op2_value],(uint32_t)(instruction.op3_value),memoria);
     }

}
if(strcmp(instruction.mnemonic,"STRH")==0)
{
  if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
     {
         r[instruction.op1_value]=STRH(r[instruction.op2_value],r[instruction.op3_value],memoria);
     }
      if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
     {
         instruction.op3_value=instruction.op3_value<<1;
         r[instruction.op1_value]=STR(r[instruction.op2_value],(uint32_t)(instruction.op3_value),memoria);
     }
}


}

instruction_t getInstruction(char* instStr)
{
	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;

	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);

	/* Separa los operandos */
	while (split != NULL)
	{
		switch(num){
			case 1:
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;

						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}
				break;

			case 2:
				if(split[0] == '[')
					split++;

				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}
	}

	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}

	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
	}

	free(split);

	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */

	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */

	lines = countLines(fp);	/* Cantidad de líneas*/

	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}

	fclose(fp);	/* Cierra el archivo */

	return lines;
}


int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];

	while( fgets(buffer, 50, fp) != NULL )
		lines++;

	rewind(fp);

	return lines;
}

