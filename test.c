#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "operaciones_alu.h"
#include <curses.h>
int main()
{
    unsigned long r[13];

    while(1)
  {



    r[12]=0;
    r[2]=-21;

int c,i;
    r[10]=ADC(r[2],-2,&r[12]);



    initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	//raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */

	start_color();	/* Permite manejar colores */

	init_pair(1, COLOR_GREEN, COLOR_WHITE);	/* Pair 1 -> Texto verde
											   fondo Negro */
 bkgd(COLOR_PAIR(1));
 mostrar_registros(r);
mostrar(r[10]);
    refresh();


	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);
			c=95;//caracter ascci horizontal
   for(i=1;i<=20;i++)
   {
      //linea horizontal superior
      move(6,i);  //Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw("%c",c);  //Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move(28,i);  //Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw("%c",c);  //Imprimimos un  texto en la posición establecida.
   }
   c=124 ; //caracter ascci vertical
   for(i=7;i<=28;i++)
   {
      //linea vertical izquierda
      move(i,1);
      printw("%c",c);
      //linea vertical derecha
      move(i,20);
      printw("%c",c);
   }
c=95;//caracter ascci horizontal
   for(i=30;i<=50;i++)
   {
      //linea horizontal superior
      move(6,i);  //Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw("%c",c);  //Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move(9,i);  //Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw("%c",c);  //Imprimimos un  texto en la posición establecida.
   }
   c=124 ; //caracter ascci vertical
   for(i=7;i<=9;i++)
   {
      //linea vertical izquierda
      move(i,30);
      printw("%c",c);
      //linea vertical derecha
      move(i,50);
      printw("%c",c);
   }
	move(12,30);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("banderas.");
	if(r[12]==15)
    {
       move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=1");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=1");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=1");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=1");
    }
    else if(r[12]==14)
    {
           move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=0");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=1");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=1");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=1");

    }
    else if(r[12]==13)
    {
           move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=1");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=0");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=1");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=1");

    }
    else if(r[12]==12)
    {
           move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=0");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=0");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=1");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=1");

    }
    else if(r[12]==11)
    {   move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=1");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=1");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=0");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=1");

    }
    else if(r[12]==10)
    {
           move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=0");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=1");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=0");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=1");

    }
    else if(r[12]==9)
    {
           move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=1");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=0");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=0");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=1");

    }
    else if(r[12]==8)
    {
            move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=0");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=0");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=0");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=1");

    }

    else if(r[12]==7)
    {
            move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=1");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=1");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=1");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=0");

    }
    else if(r[12]==6)
    {
          move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=0");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=1");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=1");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=0");

    }
    else if(r[12]==5)
    {
          move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=1");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=0");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=1");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=0");

    }
    else if(r[12]==4)
    {
          move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=0");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=0");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=1");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=0");

    }
    else if(r[12]==3)
    {
          move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=1");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=1");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=0");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=0");

    }
    else if(r[12]==2)
    {
          move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=0");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=1");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=0");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=0");

    }
    else if(r[12]==1)
    {
          move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=1");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=0");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=0");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=0");

    }
    else
    {
          move(14,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("N=0");
	move(16,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Z=0");
	move(14,40);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("C=0");
	move(16,28);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("V=0");

    }
	move(1, 30);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("EMULADOR ARM CORTEX M0");
	move(5, 34);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("resultado");
	move(5, 5);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("valor registros");
	move(8, 60);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("linea de codigo en ejecucion");
	refresh();	/* Imprime en la pantalla
					Sin esto el printw no es mostrado */





	salir();



    }
}

void salir()
{


    if(	getch()=='1')
    {
        endwin();	/* Finaliza el modo curses */
        exit(1);

    }

}