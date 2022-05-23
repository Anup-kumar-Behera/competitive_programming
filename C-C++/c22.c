#include<stdio.h>
#include<string.h>
main()
{
	char x[]="anup";
	char y[]="kumar";
	char z[]="anup";
	
	int i,j,k;
	i=strcmp(x,y);
	j=strcmp(y,z);
	k=strcmp(x,z);
	printf("%d %d %d \n",i,j,k);
}
