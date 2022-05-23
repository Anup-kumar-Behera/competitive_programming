#include<stdio.h>
#include<string.h>

main()
{
	char x[20];
	printf("Enter a string: ");
	scanf("%s",x);
	
	int l = strlen(x);
	printf("Length of the string: %d\n",l);
	int i;
	for(i = 0;i<l;i++)
	{
		printf("%c ",x[i]);
	}
}
