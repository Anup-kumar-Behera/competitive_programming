#include<stdio.h>
main()
{
	int a[5]={12,4,5,78,90};
	int *p;
	p=a;
	printf("%d %d \n",a,p);
	printf("%d %d",a[0],*p);
	int i;
	for(i=0;i<5;i++)
	{
		printf("%d %d \n",a[i],*(p+i));
		
	}
}
