#include <string.h>
#include <stdint.h>

/**
* \struct ins_t;
* \brief arreglo para almacenar el archivo a ejecutar
*/
typedef struct
{
	char** array;
}ins_t;
/**
* \struct ins_t;
* \brief arreglo para dividir las lineas de c�digo
*/
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
/**
* \brief Decodifica la instrucci�n y la ejecuta.
* \param instruction instrucci�n a decodificar y ejecutar.
*/
void decodeInstruction(instruction_t instruction,unsigned long *r[],unsigned long *bandera,unsigned long *PC,unsigned long *LR);
/**
* \brief Obtiene la instrucci�n separada por partes.
* \param instrStr cadena que contiene la instrucci�n.
* \return instruction_t la instrucci�n separada por partes.
*/
instruction_t getInstruction(char* instStr);
/**
* \brief Lee instrucciones de un archivo.
* \param filename Nombre del archivo.
* \param instructions estructura con arreglo con las instrucciones leidas.
* \return Entero indicando la cantidad de l�neas.
*/
int readFile(char* filename, ins_t* instructions);
/**
* \brief Cuenta la cantidad de l�neas de un archivo.
* \param fp Puntero al archivo.
* \return Entero con la cantidad de l�neas del archivo.
*/
int countLines(FILE* fp);
#endif /*_DECODER_H_*/