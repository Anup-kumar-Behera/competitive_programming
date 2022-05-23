#include<stdio.h>
#include<string.h>
main()
{
	char x[]="anup";
	char y[10];
	
	int i,j;
	i=strlen(x);
	j=sizeof(x);
	printf("%d %d \n",i,j);
	strcpy(y,x);
	printf("%s %s \n",x,y);
	
	char *p,*q;
	p=x,q=y;
	strcpy(*q,*p);
	printf("%s %s \n",*p,*q);
}
