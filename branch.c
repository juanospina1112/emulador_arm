#include "branch.h"

void B(unsigned long *PC, unsigned long numeroSaltos)
{
    *PC+=1<<numeroSaltos; //realiza el salto correspondiente
}
void BEQ(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==2)||(bandera==3)||(bandera==6)||(bandera==7)||(bandera==10)||(bandera==11)||(bandera==14)||(bandera==15)) //verifica la condición igual
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BNE(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==0)||(bandera==1)||(bandera==4)||(bandera==5)||(bandera==8)||(bandera==9)||(bandera==12)||(bandera==13)) //verifica la condición diferente
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BCS(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==4)||(bandera==5)||(bandera==6)||(bandera==7)||(bandera==12)||(bandera==13)||(bandera==14)||(bandera==15)) //verifica la condición para mayor o igual (unsigned)
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BCC(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==0)||(bandera==1)||(bandera==2)||(bandera==3)||(bandera==8)||(bandera==9)||(bandera==10)||(bandera==11)) //verifica la condición para menor (unsigned)
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BMI(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==1)||(bandera==3)||(bandera==5)||(bandera==7)||(bandera==9)||(bandera==11)||(bandera==13)||(bandera==15)) //verifica la condición para negativo
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BPL(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==0)||(bandera==2)||(bandera==4)||(bandera==6)||(bandera==8)||(bandera==10)||(bandera==12)||(bandera==14)) //verifica la condición para positivo
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BVS(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==8)||(bandera==9)||(bandera==10)||(bandera==11)||(bandera==12)||(bandera==13)||(bandera==14)||(bandera==15)) //verifica la condición para sobreflujo
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BVC(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==0)||(bandera==1)||(bandera==2)||(bandera==3)||(bandera==4)||(bandera==5)||(bandera==6)||(bandera==7)) //verifica la condición para no sobreflujo
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BHI(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==4)||(bandera==5)||(bandera==12)||(bandera==13)) //verifica la condición para meyor (unsigned)
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BLS(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==2)||(bandera==3)||(bandera==10)||(bandera==11)) //verifica la condición para menor o igual (unsigned)
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BGE(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==0)||(bandera==2)||(bandera==4)||(bandera==6)||(bandera==9)||(bandera==11)||(bandera==13)||(bandera==15)) //verifica la condición para mayor o igual
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BLT(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==1)||(bandera==3)||(bandera==5)||(bandera==7)||(bandera==8)||(bandera==10)||(bandera==12)||(bandera==14)) //verifica la condición para menor
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BGT(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==0)||(bandera==4)||(bandera==9)||(bandera==13)) //verifica la condición para mayor
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}
void BLE(unsigned long *PC, unsigned long numeroSaltos, unsigned long bandera)
{
    if((bandera==1)||(bandera==5)||(bandera==8)||(bandera==12)) //verifica la condición para menor o igual
    {
        *PC+=1<<numeroSaltos; //realiza el salto correspondiente
    }
    else
    {
        *PC+=1<<1; //pasa a la otra instrucción sin realizar el salto
    }
}