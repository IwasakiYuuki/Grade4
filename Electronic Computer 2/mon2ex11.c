unsigned short int x00,x10,y;

unsigned short int div(unsigned short int x0,unsigned short int x1)
{
    unsigned short int x2,x3;
    x2=0;
    x3=1;
    while (x1<x0 && (x1&0x8000)!=0x8000) {
        x1<<=1;
        x3<<=1;
    }
    while (x3!=0) {
        if(x1<=x0) {
            x0-=x1;
            x2+=x3;
        }
        x1>>=1;
        x3>>=1;
    }
    return x2;
}

int main()
{
    y=div(x00,x10);
}