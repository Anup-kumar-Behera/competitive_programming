#include<stdio.h>
main()
{
	char c;
	unsigned char d;
	int i;
	unsigned int j;
	short int k;
	unsigned short int l;
	long int m;
	unsigned long int n;
	float x;
	double y;
	long double z;
	
	/*char*/
	scanf("%c %c",&c,&d);
	printf("%c %c\n",c,d);
	
	/*int */
	scanf("%d%u",&i,&j);
	printf("%d %d \n",i,j);
	
	/*short int */
	scanf("%d %u",&k,&l);
	printf("%d %d \n",k,l);
	
	//long int
	scanf("%ld %lu",&m,&n);
	printf("%ld %ld \n",m,n);
	
	/*float,double,long double*/
	scanf("%f %lf %Lf \n",&x,&y,&z);
	printf("%f %lf %Lf",x,y,z);
}
