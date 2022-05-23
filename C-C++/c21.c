#include<stdio.h>
#include<string.h>
void xstrcpy(char *,char *);
main()
{
	char x[]="anup";
	char y[10];
	xstrcpy(y,x);
	printf("%s \n",x);
	printf("%s \n",y);
}
void xstrcpy(char *x,char *y)
{
	while(*y!='\0')
	{
		*x=*y;
		y++;
		x++;
	}
	*x='\0';
}
