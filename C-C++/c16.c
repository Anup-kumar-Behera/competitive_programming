#include<stdio.h>
main()
{
	int a,b,c;
	int (*p)(),(*q)();
	p=printf;
	q=scanf;
	(*p)("Enter your roll nos.	:	");
	(*q)("%d%d",&a,&b);
	(*p)("%d %d \n",a,b);
}
