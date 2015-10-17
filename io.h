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

void IOAccess(uint8_t address, uint8_t* data, uint8_t r_w);
void changePinPortA(uint8_t pin, uint8_t value);
void changePinPortB(uint8_t pin, uint8_t value);
void initIO(void);
void showPorts(void);
void showFrame(int x,int y,int w,int h);

#endif /*_IO_H_*/
