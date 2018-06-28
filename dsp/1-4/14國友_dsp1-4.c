//＊＊＊H30年度・DSP1-4・番号14＊＊＊

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//correlation coefficent
double cf(double x[] ,double y[], int m, int n)
{
	double r=0;
	int i=0;
	for(i=0;i<n;i++){
		if(i+m>n) break;
		r+=x[i]*y[i+m];
	}
	return r/n;
}

//make file
void output(double x[], double y[], int n)
{
	FILE *fp;
	int i,num;
	char fn[20];
	if(n==3)num=71;
	else num=701;
	sprintf(fn,"result%d.txt",n);
	fp=fopen(fn,"w");
	if(fp==NULL)
	{
		printf("can't open the file \n");
		exit(1);
	}
	for(i=0;i<num;i++) fprintf(fp,"%lf\n",cf(x,y,i,num));
	fclose(fp);
	return;
}

// read file
void file(double d[],int i)
{
	FILE *fp;
	int j,num;
	char fn[20];
	if(i==3)num=71;
	else num=701;
	sprintf(fn,"data%d.txt",i);
	fp=fopen(fn,"r");
	if(fp==NULL)
	{
		printf("can't open the file \n");
		exit(1);
	}
	for(j=0;j<num;j++)
	{
		fscanf(fp,"%lf",&d[j]);
	}
	fclose(fp);
}

int main()
{
	double d1[701];
	double d2[701];
	double d3[71];
	int i=0;
	
	file(d1,1);
	file(d2,2);
	file(d3,3);
	output(d1,d2,1);
	output(d3,d3,3);

	printf("＊＊＊H30年度・DSP1-4・番号14＊＊＊\n");
	printf("相互相関用のデータはdata1とdata2, 自己相関用のデータはdata3にファイル名を変えて実行してください。\n");
	for(i=0;i<=700;i+=100)	printf("Rxy(%d)=%lf\n",i,cf(d1,d2,i,701));
	printf("\n");
	for(i=0;i<=70;i+=10)	printf("Rxx(%d)=%lf\n",i,cf(d3,d3,i,71));
	return 0;
}
