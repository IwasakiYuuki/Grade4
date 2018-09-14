//課題2 2147483647回　INTの最大値であるため。
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
int main(){

    int a1=0;
    int a2=0;
    int a3=0;
    for(int n=0;n<INT_MAX;n++){
        int A=0;
        int B=0;
        int C=0;
        int D=0;
        if(rand()%100 < 80) A=1;
        if(rand()%100<15) B=1;
        if(A==0 && B==0 && rand()%100<90) C=1;
        if(A==0 && B==1 && rand()%100<25) C=1;
        if(A==1 && B==0 && rand()%100<70) C=1;
        if(A==1 && B==1 && rand()%100<5) C=1;
        if(C==0 && rand()%100<5) D=1;
        if(C==1 && rand()%100<20) D=1;

        if(D==1 && B==1) a1++;
        if(C==0 && A==0 && D==1) a2++;
        if(D==0 && A==1) a3++;
    }
    double r1=(double)a1/INT_MAX;
    double r2=(double)a2/INT_MAX;
    double r3=(double)a3/INT_MAX;
    printf("%0.4lf %0.4lf %0.4lf",r1,r2,r3);
    return 0;
}
//実行結果: 0.0095 0.0020 0.6879[Finished in 174.5s]