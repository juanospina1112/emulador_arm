/**
* \brief Función encargada de saltar sin condición
* \param unsigned **PC
* \param unsigned numeroSaltos
* \return Función tipo void pues modifica el valor del puntero PC
*/
void B(unsigned long **PC, unsigned long numeroSaltos);
/**
* \brief Función encargada de saltar si los datos son iguales
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BEQ(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si los datos no son iguales
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BNE(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si un dato es mayor o igual al otro (unsigned)
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BCS(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si un dato es menor al otro (unsigned)
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BCC(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si el dato es negativo
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BMI(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si el dato es positivo
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BPL(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si hay sobreflujo
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BVS(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si no hay sobreflujo
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BVC(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si un dato es mayor al otro (unsigned)
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BHI(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si un dato es menor o igual al otro (unsigned)
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BLS(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si un dato es mayor o igual al otro
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BGE(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si un dato es menor al otro
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BLT(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si un dato es mayor al otro
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BGT(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar si un dato es menor o igual al otro
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned **bandera
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BLE(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera);
/**
* \brief Función encargada de saltar sin condición y modificar LR
* \param unsigned **PC
* \param unsigned numeroSaltos
* \param unsigned *LR
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BL(unsigned long **PC, unsigned long numeroSaltos, unsigned long **LR);
/**
* \brief Función encargada de ir a una posición específica sin condición
* \param unsigned **PC
* \param unsigned posicionSiguiente
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BX(unsigned long **PC, unsigned long posicionSiguiente);
/**
* \brief Función encargada de ir a una posición específica sin condición y modificar LR
* \param unsigned **PC
* \param unsigned posicionSiguiente
* \param unsigned *LR
* \return Función tipo void pues modifica el valor del puntero PC
*/
void BLX(unsigned long **PC, unsigned long posicionSiguiente, unsigned long **LR);
