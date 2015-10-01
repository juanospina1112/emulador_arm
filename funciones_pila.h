/**
* \brief Funcion encargada de pasar datos registro-memoria
* \param unsigned long registros[16]
* \param unsigned long *R
* \param uint8_t *memoria
* \return Funcion tipo void pues modifica directamente el valor de la memoria
*/
void PUSH(unsigned long registros[16], unsigned long *R, uint8_t *memoria);
/**
* \brief Funcion encargada de pasar datos memoria-registro
* \param unsigned long registros[16]
* \param unsigned long *R
* \param uint8_t *memoria
* \return Funcion tipo void pues modifica directamente el valor de los registros
*/
void POP(unsigned long registros[16], unsigned long *R, uint8_t *memoria);