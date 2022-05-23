#include<stdio.h>
main()
{
	int a[5]={12,34,56,78,90};
	int *p;
	p=a;
	printf("%d %d %d \n",*p,*a,a[0]);
	*p=20;
	printf("%d %d %d \n",*p,*a,a[0]);
	printf("%d %d \n",*(p+3),a[3]);
	*(p+3)=99;
	printf("%d %d \n",*(p+3),a[3]);
	int i;
	for(i=0;i<5;i++)
	{
		printf("%u 	",(p+i));
	}
}
