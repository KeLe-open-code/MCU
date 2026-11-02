#include <REG51.H>

unsigned char i = 0;

void timer(void) interrupt 1
{
    TH0 = 0x3C;
    TL0 = 0xB0;
    i++;

    if (i == 20)
    {
        i = 0;
        if (P2 == 0xF0)
            P2 = 0x0F;
        else
            P2 = 0xF0;
    }
}

void main(void)
{
    P2 = 0xF0;
    TMOD = 0x01;
    TH0 = 0x3C;
    TL0 = 0xB0;
    ET0 = 1;
    EA = 1;
    TR0 = 1;

    while (1);
}
