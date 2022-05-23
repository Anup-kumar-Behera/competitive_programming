#include<stdio.h>
main()
{
	int a,b,temp;
	printf("Enter two integgers:");
	scanf("%d%d",&a,&b);
	temp=b;
	b=a;
	a=temp;
	printf("\n");
	printf("a=%d ,	b=%d\n",a,b);
}
