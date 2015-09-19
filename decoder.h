#ifndef _DECODER_H_
#define	_DECODER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct
{
	char** array;
}ins_t;

typedef struct
{
	char mnemonic[10];
	char op1_type;
	char op2_type;
	char op3_type;
	uint32_t op1_value;
	uint32_t op2_value;
	uint32_t op3_value;
}instruction_t;

void decodeInstruction(instruction_t instruction,unsigned long *r[],unsigned long *bandera,unsigned long *PC,unsigned long *LR);

instruction_t getInstruction(char* instStr);

int readFile(char* filename, ins_t* instructions);

int countLines(FILE* fp);

#endif /*_DECODER_H_*/
