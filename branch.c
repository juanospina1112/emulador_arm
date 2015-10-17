﻿#include "branch.h"

void B(unsigned long **PC, unsigned long numeroSaltos)
{
    **PC+=numeroSaltos-1; //realiza el salto correspondiente
}
void BEQ(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==2)||(**bandera==3)||(**bandera==6)||(**bandera==7)||(**bandera==10)||(**bandera==11)||(**bandera==14)||(**bandera==15)) //verifica la condición igual
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BNE(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==0)||(**bandera==1)||(**bandera==4)||(**bandera==5)||(**bandera==8)||(**bandera==9)||(**bandera==12)||(**bandera==13)) //verifica la condición diferente
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BCS(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==4)||(**bandera==5)||(**bandera==6)||(**bandera==7)||(**bandera==12)||(**bandera==13)||(**bandera==14)||(**bandera==15)) //verifica la condición para mayor o igual (unsigned)
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BCC(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==0)||(**bandera==1)||(**bandera==2)||(**bandera==3)||(**bandera==8)||(**bandera==9)||(**bandera==10)||(**bandera==11)) //verifica la condición para menor (unsigned)
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BMI(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==1)||(**bandera==3)||(**bandera==5)||(**bandera==7)||(**bandera==9)||(**bandera==11)||(**bandera==13)||(**bandera==15)) //verifica la condición para negativo
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BPL(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==0)||(**bandera==2)||(**bandera==4)||(**bandera==6)||(**bandera==8)||(**bandera==10)||(**bandera==12)||(**bandera==14)) //verifica la condición para positivo
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BVS(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==8)||(**bandera==9)||(**bandera==10)||(**bandera==11)||(**bandera==12)||(**bandera==13)||(**bandera==14)||(**bandera==15)) //verifica la condición para sobreflujo
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BVC(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==0)||(**bandera==1)||(**bandera==2)||(**bandera==3)||(**bandera==4)||(**bandera==5)||(**bandera==6)||(**bandera==7)) //verifica la condición para no sobreflujo
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BHI(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==4)||(**bandera==5)||(**bandera==12)||(**bandera==13)) //verifica la condición para meyor (unsigned)
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BLS(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==2)||(**bandera==3)||(**bandera==10)||(**bandera==11)) //verifica la condición para menor o igual (unsigned)
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BGE(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==0)||(**bandera==2)||(**bandera==4)||(**bandera==6)||(**bandera==9)||(**bandera==11)||(**bandera==13)||(**bandera==15)) //verifica la condición para mayor o igual
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BLT(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==1)||(**bandera==3)||(**bandera==5)||(**bandera==7)||(**bandera==8)||(**bandera==10)||(**bandera==12)||(**bandera==14)) //verifica la condición para menor
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BGT(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==0)||(**bandera==4)||(**bandera==9)||(**bandera==13)) //verifica la condición para mayor
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BLE(unsigned long **PC, unsigned long numeroSaltos, unsigned long **bandera)
{
    if((**bandera==1)||(**bandera==5)||(**bandera==8)||(**bandera==12)) //verifica la condición para menor o igual
    {
        **PC+=numeroSaltos-1; //realiza el salto correspondiente
    }

}
void BL(unsigned long **PC, unsigned long numeroSaltos, unsigned long **LR)
{
	**LR=**PC+2; //almacenamiento de posición de la instrucción seguida a BL
	**PC+=numeroSaltos-1; //realiza el salto correspondiente
}
void BX(unsigned long **PC, unsigned long posicionSiguiente)
{
	**PC=posicionSiguiente-1; //realiza el salto correspondiente
}
void BLX(unsigned long **PC, unsigned long posicionSiguiente, unsigned long **LR)
{
	**LR=**PC+2; //almacenamiento de posición de la instrucción seguida a BL
	**PC=posicionSiguiente-1; //realiza el salto correspondiente
}
