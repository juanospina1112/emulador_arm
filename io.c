#include "io.h"

port_t PORTA;
port_t PORTB;
uint8_t irq[16];

void initIO(void)
{
	init_pair(BLUEBLACK, COLOR_BLUE, COLOR_BLACK);
	init_pair(REDBLACK, COLOR_RED, COLOR_BLACK);
	init_pair(WHITEBLACK, COLOR_WHITE, COLOR_BLACK);

	PORTA.DDR = PORTB.DDR = 0;
	PORTA.PORT = PORTB.PORT = 0;
	PORTA.PIN = PORTB.PIN = 0;
	PORTA.Pins = PORTB.Pins = 0;
	PORTA.Interrupts = PORTB.Interrupts = 0;
}

void changePinPortA(uint8_t pin, uint8_t value)
{
	if( ( (PORTA.Pins & (1<<pin)) != (value<<pin) ) &&
		( PORTA.Interrupts & (1<<pin) ) )
		irq[pin] = 1;

	PORTA.Pins = (PORTA.Pins & ~(1<<pin)) | value<<pin;
}

void changePinPortB(uint8_t pin, uint8_t value)
{
	if( ( (PORTB.Pins & (1<<pin)) != (value<<pin) ) &&
		( PORTB.Interrupts & (1<<pin) ) )
		irq[pin+8] = 1;

	PORTB.Pins = (PORTB.Pins & ~(1<<pin)) | value<<pin;
}

void IOAccess(uint8_t address, uint8_t* data, uint8_t r_w)
{
	if(r_w){
		switch(address){
			case 0:
				*data = PORTA.DDR;
				break;
			case 1:
				*data = PORTA.PORT;
				break;
			case 2:
				PORTA.PIN = PORTA.Pins&(~PORTA.DDR);
				*data = (PORTA.PIN&(~PORTA.DDR)) | (PORTA.PORT&PORTA.DDR);
				break;
			case 3:
				*data = PORTA.Interrupts;
				break;
			case 10:
				*data = PORTB.DDR;
				break;
			case 11:
				*data = PORTB.PORT;
				break;
			case 12:
				PORTB.PIN = PORTB.Pins&(~PORTB.DDR);
				*data = (PORTB.PIN&(~PORTB.DDR)) | (PORTB.PORT&PORTB.DDR);
				break;
			case 13:
				*data = PORTB.Interrupts;
				break;
		}
	}
	else{
		switch(address){
			case 0:
				PORTA.DDR = *data;
				break;
			case 1:
				PORTA.PORT = *data;
				//PORTA.Pins = (PORTA&(~PORTA.DDR))|(PORTA.PORT&PORTA.DDR);
				break;
			case 3:
				PORTA.Interrupts = *data&(~PORTA.DDR);
				break;
			case 10:
				PORTB.DDR = *data;
				break;
			case 11:
				PORTB.PORT = *data;
				PORTB.Pins = (PORTB&(~PORTB.DDR))|(PORTB.PORT&PORTB.DDR);
				break;
			case 13:
				PORTB.Interrupts = *data&(~PORTB.DDR);
				break;
		}
	}
}

void showPorts(void)
{
	int i,j;
	int x=XINIT, y=YINIT;

	uint8_t *PA = (void*)(&PORTA);
	uint8_t *PB = (void*)(&PORTB);

	showFrame(x,y,23,9);
	showFrame(x+30,y,23,9);
	showFrame(x,y+9,23,3);
	showFrame(x+30,y+9,23,3);

	attron(COLOR_PAIR(WHITEBLACK));

	mvprintw(y+1, x+8, "7 6 5 4 3 2 1 0 ");
	mvprintw(y+3, x+2, " DDRA ");
	mvprintw(y+5, x+2, "PORTA ");
	mvprintw(y+7, x+2, " PINA ");
	mvprintw(y+10, x+2, "Pins ");

	mvprintw(y+1, x+38, "7 6 5 4 3 2 1 0 ");
	mvprintw(y+3, x+32, " DDRB ");
	mvprintw(y+5, x+32, "PORTB ");
	mvprintw(y+7, x+32, " PINB ");
	mvprintw(y+10, x+32, "Pins ");

	for(i=0; i<8; i++)
	{
		for(j=0; j<4; j++)
		{
			if(j==3)
				move(y+(j<<1)+4, x+(i<<1)+8);
			else
				move(y+(j<<1)+3, x+(i<<1)+8);
			if( PA[j] & 0x80>>i )
			{
				attron(COLOR_PAIR(REDBLACK));
				addch(ACS_CKBOARD);
				attroff(COLOR_PAIR(REDBLACK));
			}else{
				attron(COLOR_PAIR(BLUEBLACK));
				addch(ACS_CKBOARD);
				attroff(COLOR_PAIR(BLUEBLACK));
			}
		}

		for(j=0; j<4; j++)
		{
			if(j==3)
				move(y+(j<<1)+4, x+(i<<1)+38);
			else
				move(y+(j<<1)+3, x+(i<<1)+38);
			if( PB[j] & 0x80>>i )
			{
				attron(COLOR_PAIR(REDBLACK));
				addch(ACS_CKBOARD);
				attroff(COLOR_PAIR(REDBLACK));
			}else{
				attron(COLOR_PAIR(BLUEBLACK));
				addch(ACS_CKBOARD);
				attroff(COLOR_PAIR(BLUEBLACK));
			}
		}
	}

	attroff(COLOR_PAIR(WHITEBLACK));
	refresh();
}


void showFrame(int x,int y,int w,int h)
{
	int i,a;

	attron(COLOR_PAIR(WHITEBLACK));

	move(y,x);
	for(a=0;a<h;a++){

    	move(y+a,x);
	    if(a==0){
	        addch(ACS_ULCORNER);
	    }else if(a==h-1){
	        addch(ACS_LLCORNER);
	    }else{
	        addch(ACS_VLINE);
	    }
	        for(i=0;i<w;i++){
	            if(a==0 || a==h-1) {
	                addch(ACS_HLINE);
	            }else{
	                printw(" ");
	            }
	        }
	    if(a==0){
	        addch(ACS_URCORNER);
	    }else if(a==h-1){
	        addch(ACS_LRCORNER);
	    }else{
	        addch(ACS_VLINE);
	    }

	}
	attroff(COLOR_PAIR(WHITEBLACK));
	refresh();
}
