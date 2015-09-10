/**
* \brief Función encargada sumar
* \param unsigned long *resultado
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long *bandera
* \return Función declarada tipo void, dado que el resultado es de tipo puntero
*/
unsigned long ADD(unsigned long op1,unsigned long op2,unsigned long *bandera);// todas tienen retorno y se quita el puntero resultado
/**
* \brief Función encargada de ralizar una multiplicación lógica
* \param unsigned long *resultado
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long *bandera
* \return Función declarada tipo void, dado que el resultado es de tipo puntero
*/
unsigned long  AND(unsigned long op1,unsigned long op2,unsigned long *bandera);
/**
* \brief Función encargada de ralizar una EX-OR lógica
* \param unsigned long *resultado
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long *bandera
* \return Función declarada tipo void, dado que el resultado es de tipo puntero
*/
unsigned long  EOR(unsigned long op1,unsigned long op2,unsigned long *bandera);
/**
* \brief Función encargada copiar un dato en una variable diferente
* \param unsigned long op1
* \param unsigned long op2
* \return Función declarada tipo void, dado que el resultado es de tipo puntero
*/
void MOV(unsigned long *op1,unsigned long op2);
/**
* \brief Función encargada de ralizar una OR lógica
* \param unsigned long *resultado
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long *bandera
* \return Función declarada tipo void, dado que el resultado es de tipo puntero
*/
unsigned long ORR(unsigned long op1,unsigned long op2,unsigned long *bandera);
/**
* \brief Función encargada restar
* \param unsigned long *resultado
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long *bandera
* \return Función declarada tipo void, dado que el resultado es de tipo puntero
*/
unsigned long SUB(unsigned long op1,unsigned long op2,unsigned long *bandera);
unsigned long ADC(unsigned long op1,unsigned long op2,unsigned long *bandera);
