/**
* \brief Función de desplazamiento a la izquierda
* \param unsigned Variable_salida
* \param unsigned Variable_entrada
* \param unsigned constate_parametro
* \return Un registro de tipo long sin signo con la instrucción realizada
*/
unsigned long LSL(unsigned long Variable_salida,unsigned long Variable_entrada,unsigned long constate_parametro);
/**
* \brief Función de desplazamiento a la derecha
* \param unsigned Variable_salida
* \param unsigned Variable_entrada
* \param unsigned constate_parametro
* \return Un registro de tipo long sin signo con la instrucción realizada
*/
unsigned long LSR(unsigned long Variable_salida,unsigned long Variable_entrada,unsigned long constate_parametro);
/**
* \brief Función de rotación a la derecha
* \param unsigned Variable_salida
* \param unsigned Variable_entrada
* \param unsigned constate_parametro
* \return Un registro de tipo long sin signo con la instrucción realizada
*/
unsigned long ROR(unsigned long Variable_salida,unsigned long Variable_entrada,unsigned long constate_parametro);
/**
* \brief Función de desplazamiento aritmetico a la derecha
* \param unsigned Variable_salida
* \param unsigned Variable_entrada
* \param unsigned constate_parametro
* \return Un registro de tipo long sin signo con la instrucción realizada
*/
unsigned long ASR(unsigned long Variable_salida,unsigned long Variable_entrada,unsigned long constate_parametro);
/**
* \brief Función encargada de multiplicar un dato por el negado de otro
* \param unsigned Variable_salida
* \param unsigned Variable_entrada
* \return Un registro de tipo long sin signo con la instrucción realizada
*/
unsigned long BIC(unsigned long Variable_salida,unsigned long Variable_entrada);
/**
* \brief Función encargada de negar un número y almacenarlo en otra variable
* \param unsigned Variable_salida
* \param unsigned Variable_entrada
* \return Un registro de tipo long sin signo con la instrucción realizada
*/
unsigned long MVN(unsigned long Variable_salida,unsigned long Variable_entrada);
/**
* \brief Función encargada de volver negativo un número
* \param unsigned Variable_salida
* \param unsigned Variable_entrada
* \param unsigned constate_parametro
* \return Un registro de tipo long sin signo con la instrucción realizada
*/
unsigned long RSBS(unsigned long Variable_salida,unsigned long Variable_entrada,unsigned long constate_parametro);
/**
* \brief Función encargada de cambiar la posición de los bits de un dato (grupos de 8 bits)
* \param unsigned Variable_salida
* \param unsigned Variable_entrada
* \return Un registro de tipo long sin signo con la instrucción realizada
*/
unsigned long REV(unsigned long Variable_salida,unsigned long Variable_entrada);
/**
* \brief Función encargada de cambiar la posición de los bits de un dato (grupos de 16 bits)
* \param unsigned Variable_salida
* \param unsigned Variable_entrada
* \return Un registro de tipo long sin signo con la instrucción realizada
*/
unsigned long REV16(unsigned long Variable_salida,unsigned long Variable_entrada);
//NOP(long a,long b);
