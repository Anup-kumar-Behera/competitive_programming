#include<stdio.h>
#include<string.h>
main()
{
	char name[20];
	printf("Enter name: ");
	scanf("%[^\n]s",name);
	char *p;
	p=name;
	printf("%c \n",*(p+5));
	int i;
	for(i=0;i<20;i++)
	{
		printf("%u	",(p+i));
	}
	int k=strlen(name);
	printf("%d \n",k);
}
