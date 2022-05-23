#include<stdio.h>
main()
{
	short int x;
	unsigned char *p=&x;
	*p=44;
	*(p+1)=1;
	printf("%d\n",x);
}
