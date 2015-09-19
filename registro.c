#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include <curses.h>

void mostrar_registros(unsigned long r[13])
{
    int i;
    for(i=0;i<13;i++)
    {
		move(i+8,2);
		printw("r[%d]=%0.8X\t",i,r[i]);
    }
}