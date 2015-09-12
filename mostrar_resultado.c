#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "operaciones_alu.h"
#include "mostrar_resultado.h"
#include <curses.h>

void mostrar(unsigned long resultado)
{
    move(8,32);
    printw("%d",resultado);
}
