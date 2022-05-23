#include<stdio.h>
void swapv(int a,int b);

main()
{
	int a,b;
	printf("Enter two integers: \n");
	scanf("%d %d",&a,&b);
	
	swapv(a,b);
	
}
void swapv(int a,int b)
{
	int temp;
	temp=b;
	b=a;
	a=temp;
	printf("a=%d   ,   b=%d	\n",a,b);
}
