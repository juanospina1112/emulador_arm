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
    r[2]=21;

int c,i;
    r[10]=ADD(r[2],2,&r[12]);



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
mostrar();
    refresh();


	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);
			c=95;//caracter ascci horizontal
   for(i=1;i<=20;i++)
   {
      //linea horizontal superior
      move(3,i);  //Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw("%c",c);  //Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move(22,i);  //Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw("%c",c);  //Imprimimos un  texto en la posición establecida.
   }
   c=124 ; //caracter ascci vertical
   for(i=4;i<=22;i++)
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
      move(3,i);  //Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw("%c",c);  //Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move(6,i);  //Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw("%c",c);  //Imprimimos un  texto en la posición establecida.
   }
   c=124 ; //caracter ascci vertical
   for(i=4;i<=6;i++)
   {
      //linea vertical izquierda
      move(i,30);
      printw("%c",c);
      //linea vertical derecha
      move(i,50);
      printw("%c",c);
   }


	move(2, 34);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("resultado");

	move(2, 5);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("valor registros");
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
