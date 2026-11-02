#include <REG51.H>

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
        for (i = 0; i < 7; i++)
        {
            P2 = ~(1 << i);
            delayMs(500);
        }
        for (i = 5; i > 0; i--)
        {
            P2 = ~(1 << i);
            delayMs(500);
        }
        for (i = 0; i < 7; i++)
        {
            P2 = ~(1 << i);
            delayMs(500);
        }
    }
}