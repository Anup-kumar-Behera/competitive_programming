#include<stdio.h>
int main()
{
	int a=50;
	int *p;
	p=&a;
	printf("%d %d \n",a,*p);
	printf("%d %d \n",p,&a);
	return 0;
}
