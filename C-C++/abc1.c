#include"stdio.h"
#include"string.h"
main()
{
	char ch,a[20];
	printf("Enter a string:");
	scanf("%s",a);
	int i=strlen(a)-1,j=0;
	while(j<i)
	{
		ch=a[i];
		a[i]=a[j];
		a[j]=ch;
			j++;
			i--;
	}
		printf("%s\n",a);
}
