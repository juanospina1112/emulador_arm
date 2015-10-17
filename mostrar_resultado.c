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

    int i,j,h=255,s=0,k;
    //primer columna de datos empezando por la direccion FF
    for(i=0; i<32; i+=2)
    {
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));// se inicializa el color negro para la direccion de memoria
        move(2+i,5);


        printw("%0.2X",255-4*s);//imprime direccion de memoria
        s+=1;
 attroff(COLOR_PAIR(2)); // se inicializa el color verde para los datos en memoria
 attron(COLOR_PAIR(1));

        for(j=0; j<10; j+=3)
        {
            move(2+i,8+j);
            printw("%0.2X",memoria[h]);// imprime la memoria
            h--;
        }
    }
       //segunda columna de datos empezando por la direccion BF
    for(i=0; i<32; i+=2)
    { attroff(COLOR_PAIR(1));
      attron(COLOR_PAIR(2));
        move(2+i,23);


        printw("%0.2X",255-4*s);
        s+=1;
 attroff(COLOR_PAIR(2));
 attron(COLOR_PAIR(1));

        for(j=0; j<10; j+=3)
        {
            move(2+i,26+j);
            printw("%0.2X",memoria[h]);
            h--;
        }
    }
       //tercera columna de datos empezando por la direccion 7F
     for(i=0; i<32; i+=2)
    { attroff(COLOR_PAIR(1));
      attron(COLOR_PAIR(2));
        move(2+i,41);


        printw("%0.2X",255-4*s);
        s+=1;
 attroff(COLOR_PAIR(2));
 attron(COLOR_PAIR(1));

        for(j=0; j<10; j+=3)
        {
            move(2+i,44+j);
            printw("%0.2X",memoria[h]);
            h--;
        }
    }
       //cuarta columna de datos empezando por la direccion 3F
     for(i=0; i<32; i+=2)
    { attroff(COLOR_PAIR(1));
      attron(COLOR_PAIR(2));
        move(2+i,59);


        printw("%0.2X",255-4*s);
        s+=1;
 attroff(COLOR_PAIR(2));
 attron(COLOR_PAIR(1));

        for(j=0; j<10; j+=3)
        {
            move(2+i,62+j);
            printw("%0.2X",memoria[h]);
            h--;
        }
    }


    move(34, 6);
	printw("m::pro"); // imprimir en pantalla el comando de salida
    getch();
    // borrar pantalla
    for(i=0;i<40;i++)
	{
		for(k=0;k<100;k++)
		{
			move(i,k);
			printw(" ");
		}
	}
}
