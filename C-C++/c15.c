#include<stdio.h>
main()
{
	int a,b,c;
	int (*p)(),(*q)();
	p=printf;
	q=scanf;
	(*p)("Enter first number	:");
	(*q)("%d",&a);
	(*p)("Enter second number	:");
	(*q)("%d",&b);
	(*p)("Enter third nmber		:");
	(*q)("%d",&c);
	(*p)("%d %d %d \n",a,b,c);
}
