#include <REG51.H>

sbit K1 = P3^0;
sbit K2 = P3^1;
sbit K3 = P3^2;
sbit K4 = P3^3;

void main(void)
{
    P2 = 0xFF;

    while (1)
    {
        if (K1 == 0)
            P2 = 0xFE;
        else if (K2 == 0)
            P2 = 0xFC;
        else if (K3 == 0)
            P2 = 0xF8;
        else if (K4 == 0)
            P2 = 0xF0;
        else
            P2 = 0xFF;
    }
}
