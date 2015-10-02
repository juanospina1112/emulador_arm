#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "operaciones_alu.h"
#include "mostrar_resultado.h"
#include <curses.h>

#include <stdint.h>

void mostrar(unsigned long resultado)
{
    move(8,32);
    printw("%d",resultado);
}
void mostrar_memoria(uint8_t *memoria)
{
    /***** imprimir memoria******/

    int i,j,h=255,s=0;
    for(i=0; i<28; i+=2)
    { attroff(COLOR_PAIR(1));
      attron(COLOR_PAIR(2));
        move(5+i,5);


        printw("%0.2X",255-4*s);
        s+=1;
 attroff(COLOR_PAIR(2));
 attron(COLOR_PAIR(1));

        for(j=0; j<10; j+=3)
        {
            move(5+i,8+j);
            printw("%0.2X",memoria[h]);
            h--;
        }
    }
    move(34, 6);
	printw("m::pro");
    getch();
}
