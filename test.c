
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "operaciones_alu.h"
#include <curses.h>
#include "decoder.h"
#include <stdint.h>
extern uint8_t irq[16];
char** instructions;
int main()
{
    unsigned long r[17]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint8_t memoria[256],codinter[17]={1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1},data;
    int i, j, h, num_instructions,interrupcion=0;
    keypad(stdscr, TRUE);

    for(i=0; i<256; i++)
    {
        memoria[i]=255;
    }
    for(i=0; i<32; i++)
    {
        irq[i]=0;
    }
    r[16]=0 ;// registro reservado para las banderas
    r[13]=256;// SP
    r[14]=0;//LR
    r[15]=0;//PC

	int c,pas_dire,k=0;

	ins_t read;

	instruction_t instruction;
	/************ lee el programa a ejecutar *****/
			//------- No modificar ------//
	num_instructions = readFile("code.txt", &read);
	if(num_instructions==-1)
		return 0;
	if(read.array==NULL)
		return 0;
		instructions = read.array; /* Arreglo con las instrucciones */
	//---------------------------//
    /****+ declaraciones de interfaz**/
    initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */

	noecho();		/* No imprimir los caracteres leidos */

	start_color();	/* Permite manejar colores */
    init_pair(1, COLOR_GREEN, COLOR_WHITE);	/* Pair 1 -> Texto verde
											   fondo blanco */
	 //se activa el color de fondo y de las letras
    init_pair(2, COLOR_BLACK, COLOR_WHITE);

    initIO();
    attron(COLOR_PAIR(1));
    bkgd(COLOR_PAIR(1));

    while(1)
	{

        instruction = getInstruction(instructions[r[15]]); // Instrucción en la posición del PC
        interfaz(r);


	    /*************** rutinas de salida  y entrada***/
        if(k==0)// si se quiere en forma directa o paso a paso
	    {
            pas_dire=getch();
            k=1;
        }


        // forma para que el usuario termine el programa

        if(pas_dire!='d')
        {
            c=getch();

            switch(c)
                {
                    case 'r':
                        main();
                        break;
                    case 'm':
                          // borrar pantalla
                        for(i=0;i<40;i++)
                        {
                            for(k=0;k<100;k++)
                            {
                                move(i,k);
                                printw(" ");
                            }
                        }
                        mostrar_memoria(memoria);// funcion donde se muesta la memoria
                        interfaz(r);
                        break;
                    case 't':
                        // borra toda la pantalla
                        for(i=0;i<40;i++)
                        {
                            for(k=0;k<100;k++)
                            {
                                move(i,k);
                                printw(" ");
                            }
                        }
                        attroff(COLOR_PAIR(1));
                        showPorts();// funcion donde se muesta los puertos
                        getch();
                        attron(COLOR_PAIR(1));
                        interfaz(r);
                        break;
                    case 's':
                        for(i=0; i<num_instructions; i++)
                        {
                            free(read.array[i]);
                        }
                        free(read.array);
                        endwin();	/* Finaliza el modo curses */
                        exit(0);
                        break;
                    case 'a':
                        if(c==KEY_F(1))
                        {
                            if(h=0)
                            {
                              changePinPortA(0,HIGH);
                              h=1;
                            }
                            else
                            {
                                changePinPortA(0,LOW);
                                h=0;
                            }

                        }
                        break;
                    case 'b':

                }

        }



	if(r[15]==num_instructions+1)
	{
		c='s';
	}
	if(c=='s')
	{
		for(i=0; i<num_instructions; i++)
		{
			free(read.array[i]);
        }
		free(read.array);
		endwin();	/* Finaliza el modo curses */
		exit(0);
	}


    // borra toda la pantalla
	for(i=0;i<40;i++)
	{
		for(k=0;k<100;k++)
		{
			move(i,k);
			printw(" ");
		}
	}


    /****************** verificacion de interrupcion***/

    for(i=0; i<16; i++)
    {
        if(irq[i]==1)
        {
             interrupcion=1;
              break;
        }
    }
    if(interrupcion==1)
    {
        if(r[15]==0xffffffff)
        {
            POPINT(codinter,r,memoria);
            interrupcion=0;
        }
    }
    else
    {
        for(i=0; i<16; i++)
        {
            if(irq[i]==1)
            {
                PUSHINT(codinter,r,memoria);
                r[14]=0xffffffff;
                r[15]=i+1;
                break;
            }

        }

    }

    /******************** decodificacion y ejecucion *************************/

    if((c=='p')||(c=='d'))
    {
        decodeInstruction(instruction,&r,&r[16],&r[15],&r[14],memoria); // decodificacion del memonico y ejecucion, se le debe pasar las banderas y los registros
        r[15]=r[15]+1;// aumentar el pc
    }

    }
}
interfaz(unsigned long r[16])
{
int c,i;
	mostrar_registros(r);



    refresh();// refresca pantalla


	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);
			// primero dos for hacen el recuedro de los registros
			c=95;//caracter ascci horizontal
   for(i=1;i<=20;i++)
   {
      //linea horizontal superior
      move(6,i);  //Aqui estamos moviendo el cursor para a linea 6 columna i.
      printw("%c",c);  //Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move(28,i);  //Aqui estamos moviendo el cursor para a linea 28 columna i.
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
   // recuadro donde se imprime los resultados

	c=95;//caracter ascci horizontal
   for(i=30;i<=50;i++)
   {
      //linea horizontal superior
      move(6,i);  //Aqui estamos moviendo el cursor para a linea 6 columna i.
      printw("%c",c);  //Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move(9,i);  //Aqui estamos moviendo el cursor para a linea 9 columna i.
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


	move(12,30);	/* Mueve el cursor a la posición y=12, x=30*/
	    /************* para las banderas ***/
	printw("banderas.");
	if(r[16]==15)
    {
    move(14,28);
	printw("N=1");
	move(16,40);
	printw("Z=1");
	move(14,40);
	printw("C=1");
	move(16,28);
	printw("V=1");
    }
    else if(r[16]==14)
    {
    move(14,28);
	printw("N=0");
	move(16,40);
	printw("Z=1");
	move(14,40);
	printw("C=1");
	move(16,28);
	printw("V=1");

    }
    else if(r[16]==13)
    {
    move(14,28);
	printw("N=1");
	move(16,40);
	printw("Z=0");
	move(14,40);
    printw("C=1");
	move(16,28);
	printw("V=1");

    }
    else if(r[16]==12)
    {
    move(14,28);
	printw("N=0");
	move(16,40);
	printw("Z=0");
	move(14,40);
	printw("C=1");
	move(16,28);
	printw("V=1");

    }
    else if(r[16]==11)
    {
	move(14,28);
	printw("N=1");
	move(16,40);
	printw("Z=1");
	move(14,40);
	printw("C=0");
	move(16,28);
	printw("V=1");

    }
    else if(r[16]==10)
    {
    move(14,28);
	printw("N=0");
	move(16,40);
	printw("Z=1");
	move(14,40);
	printw("C=0");
	move(16,28);
	printw("V=1");

    }
    else if(r[16]==9)
    {
    move(14,28);
	printw("N=1");
	move(16,40);
	printw("Z=0");
	move(14,40);
	printw("C=0");
	move(16,28);
	printw("V=1");

    }
    else if(r[16]==8)
    {
    move(14,28);
	printw("N=0");
	move(16,40);
	printw("Z=0");
	move(14,40);
	printw("C=0");
	move(16,28);
	printw("V=1");

    }

    else if(r[16]==7)
    {
    move(14,28);
	printw("N=1");
	move(16,40);
	printw("Z=1");
	move(14,40);
	printw("C=1");
	move(16,28);
	printw("V=0");

    }
    else if(r[16]==6)
    {
    move(14,28);
	printw("N=0");
	move(16,40);
	printw("Z=1");
	move(14,40);
	printw("C=1");
	move(16,28);
	printw("V=0");

    }
    else if(r[16]==5)
    {
    move(14,28);
	printw("N=1");
	move(16,40);
	printw("Z=0");
	move(14,40);
	printw("C=1");
	move(16,28);
	printw("V=0");

    }
    else if(r[16]==4)
    {
    move(14,28);
	printw("N=0");
	move(16,40);
	printw("Z=0");
	move(14,40);
	printw("C=1");
	move(16,28);
	printw("V=0");

    }
    else if(r[16]==3)
    {
    move(14,28);
	printw("N=1");
	move(16,40);
	printw("Z=1");
	move(14,40);
	printw("C=0");
	move(16,28);
	printw("V=0");

    }
    else if(r[16]==2)
    {
    move(14,28);
	printw("N=0");
	move(16,40);
	printw("Z=1");
	move(14,40);
	printw("C=0");
	move(16,28);
	printw("V=0");

    }
    else if(r[16]==1)
    {
    move(14,28);
	printw("N=1");
	move(16,40);
	printw("Z=0");
	move(14,40);
	printw("C=0");
	move(16,28);
	printw("V=0");

    }
    else
    {
    move(14,28);
	printw("N=0");
	move(16,40);
	printw("Z=0");
	move(14,40);
	printw("C=0");
	move(16,28);
	printw("V=0");

    }
    /***** titulos ***/
	move(1, 30);
	printw("EMULADOR ARM CORTEX M0");
	move(5, 34);
	printw("resultado");
	move(5, 5);
	printw("valor registros");
	move(8, 60);
	printw("linea de codigo en ejecucion");
	move(10, 60);
	printw("%s",instructions[r[15]]);
	move(34, 3);
	printw("s:: salir");
	move(34, 15);
	printw("r::reset");
	move(34, 25);
	printw("p::paso a paso");
	move(34, 42);
	printw("d::directo");
	move(34, 58);
	printw("m::mostrar memoria/pro");
	move(14,60);
	printw("PC=%d",2*r[15]);
	move(16,60);
	printw("LR=%d",2*r[14]);
	move(18,60);
	printw("SP=0x%0.8X",536870912+r[13]);


	refresh();	/* Imprime en la pantalla
					Sin esto el printw no es mostrado */

}