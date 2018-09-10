#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 500
#define pi 3.14

struct x{
    double re;
    double im;
};

struct x xn[N];
struct x Xk[N];
double am[N];
double ph[N];

void dft(int o1,int o3){
    int i,j,a,b;
    double win[N];
    if (o1==0)
    {
        a=1;
        b=1;
    }else{
        a=-1;
        b=N;
    }
    for(i=0;i<N;i++){
        double sum1=0,sum2=0;
        for(j=0;j<N;j++){
            sum1+=xn[j].re*cos((2*pi/N)*j*i)+a*xn[j].im*sin((2*pi/N)*j*i);
            sum2+=xn[j].im*cos((2*pi/N)*j*i)-a*xn[j].re*sin((2*pi/N)*j*i);
        }
        Xk[i].re =sum1/b;
        Xk[i].im =sum2/b;
    }
    if(o3==1){
        for(i=0;i<N;i++){
            win[i]=0.54-0.46*cos(2*pi*i/N);
            Xk[i].re*=win[i];
            fprintf(, "%s\n", );
        }
    }
}


void file()
{
    FILE *fp;
    int i,j;
    //char fn[20];
    //sprintf(fn,"a_wav.txt",i);
    fp=fopen("a_wav.txt","r");
    if(fp==NULL)
    {
        printf("can't open the file \n");
        exit(1);
    }
    for(j=0;j<N;j++)
    {
        fscanf(fp,"%lf",&xn[j].re);
        xn[j].im=0;
    }
    fclose(fp);
}

void output(char name[256],int o2)
{
    FILE *fp;
    int i,num;
    fp=fopen(name,"w");
    if(fp==NULL)
    {
        printf("can't open the file \n");
        exit(1);
    }
    for(i=0;i<N;i++){
        if(o2==0){
            fprintf(fp,"%0.3lf , %0.3lf\n",Xk[i].re,Xk[i].im);
        }else if(o2==1){
            am[i]=20*log10(sqrt(Xk[i].re*Xk[i].re+Xk[i].im*Xk[i].im));
            ph[i]=atan2(Xk[i].im,Xk[i].re);
            num=(i+1)*16;
            fprintf(fp,"%d , %0.3lf , %0.3lf\n",num,am[i],ph[i]);
        }else{
            fprintf(fp,"%lf\n",xn[i].re );
        }
    }
    fclose(fp);
    return;
}

int main(){
    
    int o1,o2,o3;
    char fn[256];
    file();
    printf("DFT->0 or IDFT->1\n");
    scanf("%d",&o1);
    if(o1==0){
        printf("Output DFT result->0\nOutput amplitude & phase spectrum->1\n");
        scanf("%d",&o2);
        printf("Use window function->1 else 0\n");
        scanf("%d",&o3);
        printf("Please enter output name\n");
        scanf("%s",fn);
        dft(o1,o3);
        output(fn,o2);
    }else if(o1==1){
        printf("Please enter output name\n");
        scanf("%s",fn);
        dft(o1,0);
        output(fn,0);
    }else{
        for(i=0;i<N;i++){
            win[i]=0.54-0.46*cos(2*pi*i/N);
            xn[i].re*=win[i];
        }
        printf("Please enter output name\n");
        scanf("%s",fn);
        output(2);
    }
    return 0;
}