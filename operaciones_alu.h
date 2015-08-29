/**
* \brief Función encargada sumar
* \param unsigned long *resultado
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long *bandera
* \return Función declarada tipo void, dado que el resultado es de tipo puntero
*/
void ADD(unsigned long *resultado,unsigned long op1,unsigned long op2,unsigned long *bandera);
/**
* \brief Función encargada de ralizar una multiplicación lógica
* \param unsigned long *resultado
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long *bandera
* \return Función declarada tipo void, dado que el resultado es de tipo puntero
*/
void AND(unsigned long *resultado,unsigned long op1,unsigned long op2,unsigned long *bandera);
/**
* \brief Función encargada de ralizar una EX-OR lógica
* \param unsigned long *resultado
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long *bandera
* \return Función declarada tipo void, dado que el resultado es de tipo puntero
*/
void EOR(unsigned long *resultado,unsigned long op1,unsigned long op2,unsigned long *bandera);
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
void ORR(unsigned long *resultado,unsigned long op1,unsigned long op2,unsigned long *bandera);
/**
* \brief Función encargada restar
* \param unsigned long *resultado
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long *bandera
* \return Función declarada tipo void, dado que el resultado es de tipo puntero
*/
void SUB(unsigned long *resultado,unsigned long op1,unsigned long op2,unsigned long *bandera);