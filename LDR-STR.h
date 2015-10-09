/**
* \bref función que carga los cuatros bytes de registro de la memoria
* \param Rn es un registro inicial, quien lleva la direccion del mismo
* \param Rm es un registro es un registro modificado que me modifica la direccion para acceder a la direccion para cargar
* \return Es el registro en el cual se carga el valor
*/
unsigned long LDR(unsigned long Rn,unsigned long Rm,uint8_t *memoria);
/**
* \bref función que carga solo el primer byte de registro de la memoria y los 3 bytes restantes son extendidos con ceros
* \param Rn es un registro inicial, quien lleva la direccion del mismo
* \param Rm es un registro es un registro modificado que me modifica la direccion para acceder a la direccion para cargar
* \return Es el registro en el cual se carga el valor
*/
unsigned long LDRB(unsigned long Rn,unsigned long Rm,uint8_t *memoria);
/**
* \bref función que carga solo los dos primeros bytes de registro de la memoria y los 2 bytes restantes son extendidos con ceros
* \param Rn es un registro inicial, quien lleva la direccion del mismo
* \param Rm es un registro es un registro modificado que me modifica la direccion para acceder a la direccion para cargar
* \return Es el registro en el cual se carga el valor
*/
unsigned long LDRH(unsigned long Rn,unsigned long Rm,uint8_t *memoria);
/**
* \bref función que carga solo el primer byte de registro de la memoria y los 3 bytes restantes son extendidos con signo
* \param Rn es un registro inicial, quien lleva la direccion del mismo
* \param Rm es un registro es un registro modificado que me modifica la direccion para acceder a la direccion para cargar
* \return Es el registro en el cual se carga el valor
*/
unsigned long LDRSB(unsigned long Rn,unsigned long Rm,uint8_t *memoria);
/**
* \bref función que carga solo los dos primeros bytes de registro de la memoria y los 2 bytes restantes son extendidos con signo
* \param Rn es un registro inicial, quien lleva la direccion del mismo
* \param Rm es un registro es un registro modificado que me modifica la direccion para acceder a la direccion para cargar
* \return Es el registro en el cual se carga el valor
*/
unsigned long LDRSH(unsigned long Rn,unsigned long Rm,uint8_t *memoria);
/**
* \bref función que guarda los cuatros bytes de un registro en la memoria
* \param Rn es un registro inicial, quien lleva la direccion del mismo
* \param Rm es un registro es un registro modificado que me modifica la direccion para acceder a la direecion para guardar
* \return Es el registro en el cual se carga el valor
*/
STR(unsigned long Rt,unsigned long Rn,unsigned long Rm,uint8_t *memoria);
/**
* \bref función que guarda el primer byte de un registro en la memoria
* \param Rn es un registro inicial, quien lleva la direccion del mismo
* \param Rm es un registro es un registro modificado que me modifica la direccion para acceder a la direecion para guardar
* \return Es el registro en el cual se carga el valor
*/
STRB(unsigned long Rt,unsigned long Rn,unsigned long Rm,uint8_t *memoria);
/**
* \bref función que guarda los dos primeros bytes de un registro en la memoria
* \param Rn es un registro inicial, quien lleva la direccion del mismo
* \param Rm es un registro es un registro modificado que me modifica la direccion para acceder a la direecion para guardar
* \return Es el registro en el cual se carga el valor
*/
STRH(unsigned long Rt,unsigned long Rn,unsigned long Rm,uint8_t *memoria);
