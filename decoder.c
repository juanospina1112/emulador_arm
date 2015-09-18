#include "decoder.h"
#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "operaciones_alu.h"
#include <curses.h>
#include "decoder.h"
#include "branch.h"



void decodeInstruction(instruction_t instruction,unsigned long *r[],unsigned long *bandera,unsigned long *pc)
{
    int c;
              /********** codificacion funciones de la alu *****/
	if( strcmp(instruction.mnemonic,"ADDS") == 0 ){


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
                    r[instruction.op1_value]=ADD(r[instruction.op2_value],instruction.op3_value,&bandera);
                }
           if((instruction.op2_type == '#' )&&(instruction.op3_type == '#' ))
                {
                    ADD(instruction.op2_value,instruction.op3_value,&bandera);
                }
                 mostrar(r[instruction.op1_value]);

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

    /************************************** decodificacion funciones branch *********/


    //----- >> andres



    /********************************** decodificacion funciones de desplazamiento********/


//------>> jhon


}


instruction_t getInstruction(char* instStr)
{
	instruction_t instruction;
	char* split = (char*)malloc(strlen(instStr));
	int num=0;

	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucci�n */
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);

	/* Separa los operandos */
	while (split != NULL)
	{
		switch(num){
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

	if(num==3){
		instruction.op3_type  = 'N';
		instruction.op3_value = 0;
	}

	free(split);

	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de l�neas del archivo */
	int line=0;	/* L�nea leida */
	char buffer[50]; /* Almacena la cadena leida */

	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */

	lines = countLines(fp)-1;	/* Cantidad de l�neas*/

	/* Asignaci�n din�mica de memoria para cada instrucci�n */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc(strlen(buffer)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}

	fclose(fp);	/* Cierra el archivo */

	return lines;
}


int countLines(FILE* fp)
{
	int lines=0;
	int ch;

	while(!feof(fp))
	{
	  ch = fgetc(fp);
	  if(ch == '\n')
		lines++;
	}
	rewind(fp);

	return lines;
}