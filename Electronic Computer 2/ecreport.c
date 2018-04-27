#include <stdio.h>

int main(){
	FILE *fp;
	char fn[20],fn2[20];
	int i=0,num=0;

	printf("Enter template filename:");
	scanf("%s",fn);
	//printf("Amount of files to make:");
	//scanf("%d",&num);
	//for(i=1;i<=num;i++){
		sprintf(fn,"%s.txt",fn);
		fp=fopen(fn,"w");
		if (fp == NULL) printf("Can't open the file.");
		fprintf(fp,"%s\ns15062 4J14 š —FN‹P\n\n1.‰Û‘è\n\n2.ì¬‚µ‚½ƒvƒƒOƒ‰ƒ€EŒ‹‰Ê\n\n3.lŽ@\n",fn);
		fclose(fp);
	//}
	return 0;
}