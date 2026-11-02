#include <REG51.H>

sbit LED = P2^0;

void int0(void) interrupt 0
{
    LED = !LED;
}

void main(void)
{
    LED = 1;
    IT0 = 1;
    EX0 = 1;
    EA = 1;

    while (1);
}
