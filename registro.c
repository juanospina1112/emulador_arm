#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include <curses.h>

void mostrar_registros(unsigned long r[16])
{
    int i;
    for(i=0;i<16;i++)
    {
		move(i+8,2);
		printw("r[%d]=%0.8X\t",i,r[i]);
    }
}
