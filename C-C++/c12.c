#include<stdio.h>
main()
{
		int a,b;
		printf("Enter two integers:	");
		scanf("%d %d",&a,&b);
		int *p,*q;
		p=&a,q=&b;
		int temp;
		temp=*q;
		*q=*p;
		*p=temp;
		printf("a=%d  ,  b=%d\n",*p,*q);
}

