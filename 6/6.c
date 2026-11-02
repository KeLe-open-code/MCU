#include <REG51.H>

sbit RS = P2^6;
sbit RW = P2^5;
sbit E  = P2^7;

void delayMs(unsigned int i)
{
    unsigned char t;
    while (i--)
    {
        for (t = 0; t < 120; t++);
    }
}

void cmd(unsigned char x)
{
    RS = 0;
    RW = 0;
    P0 = x;
    E = 1;
    delayMs(1);
    E = 0;
    delayMs(1);
}

void dat(unsigned char x)
{
    RS = 1;
    RW = 0;
    P0 = x;
    E = 1;
    delayMs(1);
    E = 0;
    delayMs(1);
}

void main(void)
{
    delayMs(15);
    cmd(0x38);
    cmd(0x0C);
    cmd(0x06);
    cmd(0x01);
    delayMs(2);

    cmd(0x80);
    dat('M');
    dat('C');
    dat('U');
    dat(':');
    dat('8');
    dat('0');
    dat('5');
    dat('1');

    cmd(0xC0);
    dat('M');
    dat('C');
    dat('U');
    dat(' ');
    dat('T');
    dat('E');
    dat('S');
    dat('T');

    while (1);
}
