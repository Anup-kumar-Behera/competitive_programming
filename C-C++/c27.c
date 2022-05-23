#include<stdio.h>
#include<stdlib.h>
void update(int *a,int *b)
{
	int *c;
	*c=*a;
	*a=*a+*b;
	*b=*c-*b;
	printf("%d %d \n",*a,abs(*b));
}
main()
{
	int a,b;
	a=4,b=5;
	int *pa,*pb;
	pa=&a,pb=&b;
	
	printf("a=%d, b=%d \n",*pa,*pb);
	update(pa,pb);
//	printf("a=%d, c=%d \n");
}
