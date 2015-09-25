#include "decoder.h"
#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "operaciones_alu.h"
#include <curses.h>
#include "decoder.h"
#include "branch.h"
#include "instrucciones_desplazamiento.h"

void decodeInstruction(instruction_t instruction,unsigned long *r[],unsigned long *bandera,unsigned long *PC,unsigned long*LR)
{
    int c;
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
			BX(&PC,instruction.op1_value);
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
		if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
		{
			r[instruction.op1_value]=LSL(r[instruction.op2_value],r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='#')&&(instruction.op3_type=='R'))
		{
			r[instruction.op1_value]=LSL(instruction.op2_value,r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
		{
			r[instruction.op1_value]=LSL(r[instruction.op2_value],instruction.op3_value);
			BDES(r[instruction.op1_value],&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"LSRS")==0)
	{
		if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
		{
			r[instruction.op1_value]=LSR(r[instruction.op2_value],r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='#')&&(instruction.op3_type=='R'))
		{
		r[instruction.op1_value]=LSR(instruction.op2_value,r[instruction.op3_value]);
		BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
		{
		r[instruction.op1_value]=LSR(r[instruction.op2_value],instruction.op3_value);
		BDES(r[instruction.op1_value],&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"RORS")==0)
	{
		if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
		{
			r[instruction.op1_value]=ROR(r[instruction.op2_value],r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='#')&&(instruction.op3_type=='R'))
		{
			r[instruction.op1_value]=ROR(instruction.op2_value,r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
		{
			r[instruction.op1_value]=ROR(r[instruction.op2_value],instruction.op3_value);
			BDES(r[instruction.op1_value],&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"ASRS")==0)
	{
		if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
		{
			r[instruction.op1_value]=ASR(r[instruction.op2_value],r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='#')&&(instruction.op3_type=='R'))
		{
			r[instruction.op1_value]=ASR(instruction.op2_value,r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
		{
			r[instruction.op1_value]=ASR(r[instruction.op2_value],instruction.op3_value);
			BDES(r[instruction.op1_value],&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"BICS")==0)
	{
		if((instruction.op2_type=='R'))
		{
			r[instruction.op1_value]=BIC(r[instruction.op2_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='#'))
		{
			r[instruction.op1_value]=BIC(instruction.op2_value);
			BDES(r[instruction.op1_value],&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"MVNS")==0)
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
		if((instruction.op2_type=='#')&&(instruction.op3_type=='R'))
		{
			r[instruction.op1_value]=RSBS(instruction.op2_value,r[instruction.op3_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='R')&&(instruction.op3_type=='#'))
		{
			r[instruction.op1_value]=RSBS(r[instruction.op2_value],instruction.op3_value);
			BDES(r[instruction.op1_value],&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"REVS")==0)
	{
		if((instruction.op2_type=='R'))
		{
			r[instruction.op1_value]=REV(r[instruction.op2_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='#'))
		{
			r[instruction.op1_value]=REV(instruction.op2_value);
			BDES(r[instruction.op1_value],&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"REV16S")==0)
	{
		if((instruction.op2_type=='R'))
		{
			r[instruction.op1_value]=REV16(r[instruction.op2_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='#'))
		{
			r[instruction.op1_value]=REV16(instruction.op2_value);
			BDES(r[instruction.op1_value],&bandera);
		}
	}
	if(strcmp(instruction.mnemonic,"REVSHS")==0)
	{
		if((instruction.op2_type=='R'))
		{
			r[instruction.op1_value]=REVSH(r[instruction.op2_value]);
			BDES(r[instruction.op1_value],&bandera);
		}
		if((instruction.op2_type=='#'))
		{
			r[instruction.op1_value]=REVSH(instruction.op2_value);
			BDES(r[instruction.op1_value],&bandera);
		}
	}
}
instruction_t getInstruction(char* instStr)
{
	instruction_t instruction;
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;
	strcpy(split, instStr);
	// Obtiene el mnemonico de la instrucción
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);
	// Separa los operandos
	while (split != NULL)
	{
		switch(num)
		{
			case 1:
				instruction.op1_type  = split[0];
				instruction.op1_value = (uint32_t)strtol(split+1, NULL, 0);
			break;
			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtol(split+1, NULL, 0);
				break;
			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtol(split+1, NULL, 0);
				break;
		}
		split = strtok(NULL, " ,.");
		num++;
	}
	if(num==3)
	{
		instruction.op3_type  = 'N';
		instruction.op3_value = 0;
	}
	free(split);
	return instruction;
}
int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	// Puntero a un archivo
	int lines;	// Cantidad de líneas del archivo
	int line=0;	// Línea leida
	char buffer[50]; // Almacena la cadena leida
	fp = fopen(filename, "r");	// Abrir el archivo como solo lectura
	if( fp==NULL )
		return -1;	// Error al abrir el archivo
	lines = countLines(fp);	// Cantidad de líneas
	// Asignación dinámica de memoria para cada instrucción
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines )
	{
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}
	fclose(fp);	// Cierra el archivo
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

