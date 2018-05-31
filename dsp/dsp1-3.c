#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



//average of v1*v21
double ave( double v1[],double v2[]){
	double ip=0;
	int i=0;
	for(i=0;i<86;i++) ip+=v1[i]*v2[i];
	return ip/86;
}

//correlation coefficent
double cc(double x[] ,double y[]){
	return ave(x,y)/(sqrt(ave(x,x))*sqrt(ave(y,y)));
}
// read file and pretreatment
void file(double d[86],int i){
	FILE *fp;
	int j;
	double s=0,ave=0;
	char fn[20];
	sprintf(fn,"rdata%d.txt",i);
	fp=fopen(fn,"r");
	if(fp==NULL){
		printf("can't open the file \n");
		exit(1);
	}
	for(j=0;j<86;j++){
		fscanf(fp,"%lf",&d[j]);
		s+=d[j];
	}
	fclose(fp);
	ave=s/86;
	for(j=0;j<86;j++) d[j]-=ave;
}

int main(){
	double d1[86];
	double d2[86];
	double d3[86];
	double d4[86];
	double ave[4];
	int i=0,j=0,k=0,sum=0;
	double ug[3];
	
	file(d1,1);
	file(d2,2);
	file(d3,3);
	file(d4,4);

	printf("d1 & d2 r=%lf\n",cc(d1,d2));
	printf("d1 & d3 r=%lf\n",cc(d1,d3));
	printf("d1 & d4 r=%lf\n",cc(d1,d4));
	//printf("d2 & d3 r=%lf\n",cc(d2,d3));
	//printf("d2 & d4 r=%lf\n",cc(d2,d4));
	//printf("d3 & d4 r=%lf\n",cc(d3,d4));
	return 0;
}
