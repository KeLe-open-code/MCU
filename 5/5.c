#include <REG51.H>

sbit C1 = P3^3;
sbit C2 = P3^2;
sbit C3 = P3^1;
sbit C4 = P3^0;

unsigned char code led[8] = {
    0xFE, 0xFC, 0xF8, 0xF0,
    0xE0, 0xC0, 0x80, 0x00
};

void delayMs(unsigned int i)
{
    unsigned char t;
    while (i--)
    {
        for (t = 0; t < 120; t++);
    }
}

unsigned char scan(void)
{
    unsigned char k = 0;

    P3 = 0x7F;
    if (C1 == 0) k = 1;
    else if (C2 == 0) k = 2;
    else if (C3 == 0) k = 3;
    else if (C4 == 0) k = 4;

    if (k == 0)
    {
        P3 = 0xBF;
        if (C1 == 0) k = 5;
        else if (C2 == 0) k = 6;
        else if (C3 == 0) k = 7;
        else if (C4 == 0) k = 8;
    }

    P3 = 0xFF;
    return k;
}

void main(void)
{
    unsigned char k;
    P2 = 0xFF;

    while (1)
    {
        k = scan();
        if (k != 0)
        {
            delayMs(10);
            if (scan() == k)
                P2 = led[k - 1];
        }
    }
}
