#include<stdio.h>
int main()
{
	int a;
	printf("Enter an integer to check for even or odd : ");
	scanf("%d ",&a);
	/*if((a&1)==1)
		printf("a=%d is odd\n",a);
	else
		printf("a=%d id even \n",a);*/
	(a&1)==0 && printf("%d is even \n",a) || printf("%d is odd\n",a);
	return 0;
}
