short int x00=0x55;
short int x10=0xa;
short int y0; /* x0=x00*x10 */

short int mymultifunc(short int x0,short int x1)
{
    short int x2;
    x2=0;
    do {
        if(x1&1) x2+=x0;
        x0<<=1;
        x1>>=1;
    } while (x1);
    return x2;
}


int main()
{
    y0=mymultifunc(x00,x10);
}