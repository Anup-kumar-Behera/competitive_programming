#include"stdio.h"
main()
{
	int a,b;
	printf("Enter two integers: ");
	scanf("%d %d",&a,&b);
	printf("before swap\t a=%d and b=%d\n",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("after swap\t a=%d and b=%d\n",a,b);
}
