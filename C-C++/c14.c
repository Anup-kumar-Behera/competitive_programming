#include<stdio.h>
main()
{
	int x=5, *p;
	p=&x;
	printf("%d \n",++*p);
}
