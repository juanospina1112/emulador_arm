/**
* \brief Función encargada sumar
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long **bandera
* \return Un dato tipo long sin signo con el resultado de la operación
*/
unsigned long ADD(unsigned long op1,unsigned long op2,unsigned long **bandera);
/**
* \brief Función encargada de ralizar una multiplicación lógica
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long **bandera
* \return Un dato tipo long sin signo con el resultado de la operación
*/
unsigned long  AND(unsigned long op1,unsigned long op2,unsigned long **bandera);
/**
* \brief Función encargada de ralizar una EX-OR lógica
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long **bandera
* \return Un dato tipo long sin signo con el resultado de la operación
*/
unsigned long  EOR(unsigned long op1,unsigned long op2,unsigned long **bandera);
/**
* \brief Función encargada copiar un dato en una variable diferente
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long **bandera
* \return Un dato tipo long sin signo con el resultado de la operación
*/
unsigned MOV(unsigned long op1,unsigned long op2,unsigned long **bandera);
/**
* \brief Función encargada de ralizar una OR lógica
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long **bandera
* \return Un dato tipo long sin signo con el resultado de la operación
*/
unsigned long ORR(unsigned long op1,unsigned long op2,unsigned long **bandera);
/**
* \brief Función encargada restar
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long **bandera
* \return Un dato tipo long sin signo con el resultado de la operación
*/
unsigned long SUB(unsigned long op1,unsigned long op2,unsigned long **bandera);
/**
* \brief Función encargada de sumar teniendo en cuenta el carry
* \param unsigned long op1
* \param unsigned long op2
* \param unsigned long **bandera
* \return Un dato tipo long sin signo con el resultado de la operación
*/
unsigned long ADC(unsigned long op1,unsigned long op2,unsigned long **bandera);
/**
* \brief Función encagada de modificar las banderas de las funciones desplazamiento
* \param unsigned long op1
* \param unsigned long **bandera
* \return nada
*/
void BDES(unsigned long op1,unsigned long **bandera);
