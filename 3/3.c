#include <REG51.H>

sbit a = P3^0;
sbit b = P3^1;
sbit c = P3^2;

unsigned char code seg[10] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66,
    0x6D, 0x7D, 0x07, 0x7F, 0x6F
};
unsigned char code num[4] = {1, 2, 3, 4};

void delayMs(unsigned int i)
{
    unsigned char t;
    while (i--)
    {
        for (t = 0; t < 120; t++);
    }
}

void main(void)
{
    unsigned char i;

    while (1)
    {
        for (i = 0; i < 4; i++)
        {
            P0 = 0x00;
            a = i & 0x01;
            b = (i >> 1) & 0x01;
            c = (i >> 2) & 0x01;
            P0 = seg[num[i]];
            delayMs(2);
        }
    }
}
