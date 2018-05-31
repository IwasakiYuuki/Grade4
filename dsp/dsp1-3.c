#include <stdio.h>
#include <math.h>


//innner product
double ip( double v1[],double v2[],int n){
	double ip=0;
	int i=0;
	for(i=0;i<n;i++) ip+=v1[i]*v2[i];
	return ip;
}

void show(double v[],int n){
	printf("(%lf",v[0]);
	int i=0;
	for(i=1;i<n;i++) printf(",%lf",v[i]);
	printf(")\n");

}

int main(){
	double g[3]={2,-1,1};
	double u1[3]={1,0,0};
	double u2[3]={0,sqrt(2)/2,sqrt(2)/2};
	double u3[3]={0,sqrt(2)/2,-sqrt(2)/2};
	double a1=0;
	double a2=0;
	double a3=0;
	int i=0;
	double ug[3];


	show(u1,3);
	show(u2,3);
	show(u3,3);
	printf("u1Eu1=%lf\n",ip(u1,u1,3));
	printf("u1Eu2=%lf\n",ip(u1,u2,3));
	printf("u2Eu2=%lf\n",ip(u2,u2,3));
	printf("u2Eu3=%lf\n",ip(u2,u3,3));
	printf("u3Eu3=%lf\n",ip(u3,u3,3));
	printf("u3Eu1=%lf\n",ip(u3,u1,3));
	a1=ip(u1,g,3);
	printf("a1=%lf\n",a1);
	a2=ip(u2,g,3);
	printf("a2=%lf\n",a2);
	a3=ip(u3,g,3);
	printf("a3=%lf\n",a3);
	printf("g=");
	for(i=0;i<3;i++) ug[i]+=a1*u1[i]+a2*u2[i]+a3*u3[i];
	show(ug,3);
	return 0;
}
