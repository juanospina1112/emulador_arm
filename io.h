#ifndef _IO_H_
#define	_IO_H_

#include <stdint.h>
#include <curses.h>

#define XINIT 10
#define YINIT 5

/*===================================================*/

#define HIGH	1
#define LOW		0	

#define Read	1
#define Write	0

#define BLUEBLACK	10	/*Text Blue Background Black*/
#define REDBLACK	20	/*Text Red Background Black*/
#define WHITEBLACK	30  /*Text White Background White*/

typedef struct{
	uint8_t DDR;
	uint8_t PORT;
	uint8_t PIN;
	uint8_t Pins;
	uint8_t Interrupts;
}port_t;
/**
* \brief Funcion para modificar el modula de entrada y salida
* \param uint8_t direccion de memoria
* \param uint8_t registro
* \param uint8_t leer o escribir en la memoria
* \return void
*/
void IOAccess(uint8_t address, uint8_t* data, uint8_t r_w);
/**
* \brief Funcion cambia el estado fisico de los pines del puerto A
* \param uint8_t pin a cambiar
* \param uint8_t alto o bajo
* \return void
*/
void changePinPortA(uint8_t pin, uint8_t value);
/**
* \brief Funcion cambia el estado fisico de los pines del puerto B
* \param uint8_t pin a cambiar
* \param uint8_t alto o bajo
* \return void
*/
void changePinPortB(uint8_t pin, uint8_t value);
/**
* \brief Funcion que inicializa la funcion IO
* \return void
*/
void initIO(void);
/**
* \brief Funcion que muestra los pines y el estado del modulo
* \return void
*/
void showPorts(void);
/**
* \brief Funcion que complementa la funcion show
* \return void
*/
void showFrame(int x,int y,int w,int h);

#endif /*_IO_H_*/
