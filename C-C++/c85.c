#include<stdio.h>
#include<string.h>

main()
{
	char a[20];
	char y[26]="abcdefghijklmnopqrstuvwxyz";
	
	printf("Enter a string: ");
	scanf("%s",a);
	
	int i,l = strlen(a);
	int x[26],k=0;
	
	for(i = 0; i < 26;i++)
		x[i] = 0;
	for(i = 0; i <= l;i++)
	{	
		k = a[i] - 'a';
		x[k] = x[k]+1;
	}
	
	for(i = 0;i < 26;i++)
	{
		printf("%c : %d \n",y[i],x[i]);
	}
}
