#include<stdio.h>
void swap(int *,int *);

main()
{
	int  a,b;
	int *p,*q;
	p=&a,q=&b;
	printf("Enter two integers: ");
	scanf("%d %d",p,q);
	swap(*p,*q);
}
void swap(int *p,int *q)
{
	int temp;
	temp=*q;
	*q=*p;
	*p=temp;
	printf("a=%d , b=%d\n",*p,*q);
}
